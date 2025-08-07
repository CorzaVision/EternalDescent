#include "DungeonGenerator.h"
#include "Engine/World.h"
#include "Async/Async.h"

ADungeonGenerator::ADungeonGenerator()
{
	PrimaryActorTick.bCanEverTick = false;
	CurrentZone = EDungeonZone::SunkenCrypt;
}

void ADungeonGenerator::BeginPlay()
{
	Super::BeginPlay();
}

FDungeonLayout ADungeonGenerator::GenerateFloor(int32 FloorNumber)
{
	const double StartTime = FPlatformTime::Seconds();
	
	FDungeonLayout Layout;
	Layout.FloorNumber = FloorNumber;
	Layout.CurrentZone = CurrentZone;
	
	// Core generation pipeline
	GenerateLayout(Layout);
	PopulateRooms(Layout);
	GenerateConnections(Layout);
	ApplyZoneTheme(Layout);
	ApplyEntityInfluence(Layout);
	EnsureConnectivity(Layout);
	OptimizeLayout(Layout);
	
	// Record generation time
	const double EndTime = FPlatformTime::Seconds();
	Layout.GenerationTime = (EndTime - StartTime) * 1000.0f; // Convert to ms
	
	return Layout;
}

void ADungeonGenerator::GenerateFloorAsync(int32 FloorNumber, FOnDungeonGenerationComplete OnComplete)
{
	Async(EAsyncExecution::ThreadPool, [this, FloorNumber, OnComplete]()
	{
		FDungeonLayout Layout = GenerateFloor(FloorNumber);
		
		// Return to game thread for callback
		AsyncTask(ENamedThreads::GameThread, [OnComplete, Layout]()
		{
			OnComplete.ExecuteIfBound(Layout);
		});
	});
}

void ADungeonGenerator::SetActiveZone(EDungeonZone Zone)
{
	CurrentZone = Zone;
}

void ADungeonGenerator::SetEntityProfile(const FEntityProfile& Profile)
{
	EntityProfile = Profile;
}

void ADungeonGenerator::GenerateLayout(FDungeonLayout& Layout)
{
	// Create 5x5 grid of rooms (ignoring Z for now, can expand later)
	for (int32 X = 0; X < GRID_SIZE; ++X)
	{
		for (int32 Y = 0; Y < GRID_SIZE; ++Y)
		{
			FIntVector Position(X, Y, 0);
			
			FRoomData Room;
			Room.GridPosition = Position;
			Room.RoomType = SelectRoomType(Layout.FloorNumber, Position);
			Room.ZoneType = CurrentZone;
			Room.DifficultyModifier = CalculateDifficulty(Layout.FloorNumber, EntityProfile.AdaptationLevel);
			Room.EntityInfluence = EntityProfile.AdaptationLevel;
			
			Layout.Rooms.Add(Position, Room);
		}
	}
	
	// Set spawn room (center of grid)
	Layout.SpawnRoom = FIntVector(GRID_SIZE / 2, GRID_SIZE / 2, 0);
	if (FRoomData* SpawnRoom = Layout.Rooms.Find(Layout.SpawnRoom))
	{
		SpawnRoom->RoomType = ERoomType::Rest;
	}
}

void ADungeonGenerator::PopulateRooms(FDungeonLayout& Layout)
{
	// Add extraction points every 5 rooms from spawn
	TArray<FIntVector> PotentialExtractions;
	
	// Corners are good extraction points
	PotentialExtractions.Add(FIntVector(0, 0, 0));
	PotentialExtractions.Add(FIntVector(GRID_SIZE - 1, 0, 0));
	PotentialExtractions.Add(FIntVector(0, GRID_SIZE - 1, 0));
	PotentialExtractions.Add(FIntVector(GRID_SIZE - 1, GRID_SIZE - 1, 0));
	
	// Select 2 extraction points
	for (int32 i = 0; i < 2 && i < PotentialExtractions.Num(); ++i)
	{
		int32 RandomIndex = FMath::RandRange(0, PotentialExtractions.Num() - 1);
		FIntVector ExtractionPoint = PotentialExtractions[RandomIndex];
		
		Layout.ExtractionPoints.Add(ExtractionPoint);
		
		if (FRoomData* Room = Layout.Rooms.Find(ExtractionPoint))
		{
			Room->RoomType = ERoomType::Extraction;
		}
		
		PotentialExtractions.RemoveAt(RandomIndex);
	}
	
	// Add boss room far from spawn
	FIntVector BossPosition(
		Layout.SpawnRoom.X == 0 ? GRID_SIZE - 1 : 0,
		Layout.SpawnRoom.Y == 0 ? GRID_SIZE - 1 : 0,
		0
	);
	
	if (FRoomData* BossRoom = Layout.Rooms.Find(BossPosition))
	{
		BossRoom->RoomType = ERoomType::Boss;
	}
}

void ADungeonGenerator::GenerateConnections(FDungeonLayout& Layout)
{
	// Generate connections using a minimum spanning tree approach
	// This ensures all rooms are connected with no isolated sections
	
	TSet<FIntVector> ConnectedRooms;
	TArray<FIntVector> UnconnectedRooms;
	
	// Start with spawn room
	ConnectedRooms.Add(Layout.SpawnRoom);
	
	// Add all other rooms to unconnected
	for (const auto& RoomPair : Layout.Rooms)
	{
		if (RoomPair.Key != Layout.SpawnRoom)
		{
			UnconnectedRooms.Add(RoomPair.Key);
		}
	}
	
	// Connect all rooms
	while (UnconnectedRooms.Num() > 0)
	{
		int32 RandomIndex = FMath::RandRange(0, UnconnectedRooms.Num() - 1);
		FIntVector RoomToConnect = UnconnectedRooms[RandomIndex];
		
		// Find nearest connected room
		FIntVector NearestConnected = Layout.SpawnRoom;
		float MinDistance = FLT_MAX;
		
		for (const FIntVector& Connected : ConnectedRooms)
		{
			float Distance = FVector::Dist(
				FVector(Connected.X, Connected.Y, Connected.Z),
				FVector(RoomToConnect.X, RoomToConnect.Y, RoomToConnect.Z)
			);
			
			if (Distance < MinDistance && IsValidConnection(Connected, RoomToConnect))
			{
				MinDistance = Distance;
				NearestConnected = Connected;
			}
		}
		
		// Create bidirectional connection
		if (FRoomData* Room1 = Layout.Rooms.Find(RoomToConnect))
		{
			Room1->Connections.Add(NearestConnected);
		}
		
		if (FRoomData* Room2 = Layout.Rooms.Find(NearestConnected))
		{
			Room2->Connections.Add(RoomToConnect);
		}
		
		ConnectedRooms.Add(RoomToConnect);
		UnconnectedRooms.RemoveAt(RandomIndex);
	}
	
	// Add some extra connections for variety (create loops)
	int32 ExtraConnections = FMath::RandRange(3, 7);
	for (int32 i = 0; i < ExtraConnections; ++i)
	{
		TArray<FIntVector> RoomKeys;
		Layout.Rooms.GetKeys(RoomKeys);
		
		if (RoomKeys.Num() >= 2)
		{
			FIntVector Room1 = RoomKeys[FMath::RandRange(0, RoomKeys.Num() - 1)];
			FIntVector Room2 = RoomKeys[FMath::RandRange(0, RoomKeys.Num() - 1)];
			
			if (Room1 != Room2 && IsValidConnection(Room1, Room2))
			{
				if (FRoomData* R1 = Layout.Rooms.Find(Room1))
				{
					R1->Connections.AddUnique(Room2);
				}
				if (FRoomData* R2 = Layout.Rooms.Find(Room2))
				{
					R2->Connections.AddUnique(Room1);
				}
			}
		}
	}
}

void ADungeonGenerator::ApplyZoneTheme(FDungeonLayout& Layout)
{
	// Apply zone-specific properties to rooms
	for (auto& RoomPair : Layout.Rooms)
	{
		FRoomData& Room = RoomPair.Value;
		
		// 70% chance to match zone theme
		if (FMath::FRand() < 0.7f)
		{
			Room.ZoneType = CurrentZone;
			
			// Apply zone-specific modifiers
			switch (CurrentZone)
			{
				case EDungeonZone::SunkenCrypt:
					Room.DifficultyModifier *= 1.1f; // Slightly harder
					break;
				case EDungeonZone::BlightedForest:
					Room.DifficultyModifier *= 0.9f; // Slightly easier but with status effects
					break;
				case EDungeonZone::FrozenFortress:
					Room.DifficultyModifier *= 1.2f; // Harder with environmental hazards
					break;
				default:
					break;
			}
		}
	}
}

void ADungeonGenerator::ApplyEntityInfluence(FDungeonLayout& Layout)
{
	// Apply entity influence based on floor number and adaptation level
	float BaseInfluence = FMath::Clamp(Layout.FloorNumber / 50.0f, 0.0f, 1.0f);
	float TotalInfluence = BaseInfluence * EntityProfile.AdaptationLevel;
	
	for (auto& RoomPair : Layout.Rooms)
	{
		FRoomData& Room = RoomPair.Value;
		
		// Entity influence affects room difficulty and properties
		Room.EntityInfluence = TotalInfluence;
		Room.DifficultyModifier *= (1.0f + TotalInfluence * 0.5f);
		
		// Entity personality affects room selection
		if (EntityProfile.CurrentMood == EEntityPersonality::Counter && Room.RoomType == ERoomType::Combat)
		{
			// Counter personality increases combat rooms
			Room.DifficultyModifier *= 1.3f;
		}
		else if (EntityProfile.CurrentMood == EEntityPersonality::Architect && Room.RoomType == ERoomType::Puzzle)
		{
			// Architect personality increases puzzle complexity
			Room.DifficultyModifier *= 1.4f;
		}
	}
}

ERoomType ADungeonGenerator::SelectRoomType(int32 FloorNumber, const FIntVector& Position)
{
	// Room type distribution based on floor number
	float CombatChance = 0.4f;
	float TreasureChance = 0.15f;
	float PuzzleChance = 0.15f;
	float RestChance = 0.1f;
	
	// Adjust based on floor number
	if (FloorNumber > 10)
	{
		CombatChance += 0.1f;
		RestChance -= 0.05f;
	}
	
	float RandomValue = FMath::FRand();
	
	if (RandomValue < CombatChance)
	{
		return ERoomType::Combat;
	}
	else if (RandomValue < CombatChance + TreasureChance)
	{
		return ERoomType::Treasure;
	}
	else if (RandomValue < CombatChance + TreasureChance + PuzzleChance)
	{
		return ERoomType::Puzzle;
	}
	else if (RandomValue < CombatChance + TreasureChance + PuzzleChance + RestChance)
	{
		return ERoomType::Rest;
	}
	else
	{
		return ERoomType::Empty;
	}
}

float ADungeonGenerator::CalculateDifficulty(int32 FloorNumber, float EntityInfluence)
{
	// Base difficulty scales with floor
	float BaseDifficulty = 1.0f + (FloorNumber * 0.1f);
	
	// Entity influence adds additional difficulty
	float EntityModifier = 1.0f + (EntityInfluence * 0.5f);
	
	return BaseDifficulty * EntityModifier;
}

bool ADungeonGenerator::IsValidConnection(const FIntVector& From, const FIntVector& To)
{
	// Check if rooms are adjacent (including diagonals)
	int32 DX = FMath::Abs(From.X - To.X);
	int32 DY = FMath::Abs(From.Y - To.Y);
	int32 DZ = FMath::Abs(From.Z - To.Z);
	
	// Allow connections to adjacent rooms only (no diagonals for now)
	return DZ == 0 && ((DX == 1 && DY == 0) || (DX == 0 && DY == 1));
}

void ADungeonGenerator::EnsureConnectivity(FDungeonLayout& Layout)
{
	// Keep connecting isolated rooms until all are connected
	bool bAllConnected = false;
	int32 MaxIterations = 10; // Safety limit
	int32 Iteration = 0;
	
	while (!bAllConnected && Iteration < MaxIterations)
	{
		Iteration++;
		
		// Find all rooms reachable from spawn
		TSet<FIntVector> VisitedRooms;
		TQueue<FIntVector> RoomsToVisit;
		
		RoomsToVisit.Enqueue(Layout.SpawnRoom);
		
		while (!RoomsToVisit.IsEmpty())
		{
			FIntVector CurrentRoom;
			RoomsToVisit.Dequeue(CurrentRoom);
			
			if (VisitedRooms.Contains(CurrentRoom))
			{
				continue;
			}
			
			VisitedRooms.Add(CurrentRoom);
			
			if (const FRoomData* Room = Layout.Rooms.Find(CurrentRoom))
			{
				for (const FIntVector& Connection : Room->Connections)
				{
					if (!VisitedRooms.Contains(Connection))
					{
						RoomsToVisit.Enqueue(Connection);
					}
				}
			}
		}
		
		// Check if all rooms are connected
		if (VisitedRooms.Num() >= Layout.Rooms.Num())
		{
			bAllConnected = true;
			UE_LOG(LogTemp, Display, TEXT("All %d rooms connected after %d iterations"), Layout.Rooms.Num(), Iteration);
			break;
		}
		
		// Connect isolated rooms
		TArray<FIntVector> IsolatedRooms;
		for (const auto& RoomPair : Layout.Rooms)
		{
			if (!VisitedRooms.Contains(RoomPair.Key))
			{
				IsolatedRooms.Add(RoomPair.Key);
			}
		}
		
		UE_LOG(LogTemp, Warning, TEXT("Iteration %d: Found %d isolated rooms, connecting them..."), 
			Iteration, IsolatedRooms.Num());
		
		// Connect each isolated room to the nearest valid connected room
		for (const FIntVector& IsolatedRoom : IsolatedRooms)
		{
			// Find nearest VALID connected room (must be adjacent)
			FIntVector NearestConnected(-1, -1, -1);
			float MinDistance = FLT_MAX;
			bool bFoundValidConnection = false;
			
			// First try to find adjacent rooms
			for (const FIntVector& Connected : VisitedRooms)
			{
				if (IsValidConnection(IsolatedRoom, Connected))
				{
					float Distance = FVector::Dist(
						FVector(Connected.X, Connected.Y, Connected.Z),
						FVector(IsolatedRoom.X, IsolatedRoom.Y, IsolatedRoom.Z)
					);
					
					if (Distance < MinDistance)
					{
						MinDistance = Distance;
						NearestConnected = Connected;
						bFoundValidConnection = true;
					}
				}
			}
			
			// If no adjacent room found, create a chain of connections
			if (!bFoundValidConnection)
			{
				// Find the closest connected room (even if not adjacent)
				FIntVector ClosestRoom = Layout.SpawnRoom;
				float ClosestDistance = FLT_MAX;
				
				for (const FIntVector& Connected : VisitedRooms)
				{
					float Distance = FVector::Dist(
						FVector(Connected.X, Connected.Y, Connected.Z),
						FVector(IsolatedRoom.X, IsolatedRoom.Y, IsolatedRoom.Z)
					);
					
					if (Distance < ClosestDistance)
					{
						ClosestDistance = Distance;
						ClosestRoom = Connected;
					}
				}
				
				// Create a path of connections from isolated to closest
				FIntVector Current = IsolatedRoom;
				int32 PathSteps = 0; // Non-static counter for safety
				
				while (Current != ClosestRoom && PathSteps < 20)
				{
					// Move one step closer
					FIntVector Next = Current;
					if (Current.X < ClosestRoom.X)
						Next.X++;
					else if (Current.X > ClosestRoom.X)
						Next.X--;
					else if (Current.Y < ClosestRoom.Y)
						Next.Y++;
					else if (Current.Y > ClosestRoom.Y)
						Next.Y--;
					
					// Check if this intermediate room exists
					if (Layout.Rooms.Contains(Next))
					{
						// Connect current to next
						if (FRoomData* Room1 = Layout.Rooms.Find(Current))
						{
							Room1->Connections.AddUnique(Next);
						}
						if (FRoomData* Room2 = Layout.Rooms.Find(Next))
						{
							Room2->Connections.AddUnique(Current);
						}
						
						UE_LOG(LogTemp, Display, TEXT("Creating path: Connected room at (%d,%d,%d) to room at (%d,%d,%d)"), 
							Current.X, Current.Y, Current.Z, Next.X, Next.Y, Next.Z);
					}
					
					Current = Next;
					PathSteps++;
				}
				
				if (PathSteps >= 20)
				{
					UE_LOG(LogTemp, Warning, TEXT("Path creation took too many steps for room at (%d,%d,%d)"), 
						IsolatedRoom.X, IsolatedRoom.Y, IsolatedRoom.Z);
				}
			}
			else
			{
				// Create the valid adjacent connection
				if (FRoomData* Room1 = Layout.Rooms.Find(IsolatedRoom))
				{
					Room1->Connections.AddUnique(NearestConnected);
					
					if (FRoomData* Room2 = Layout.Rooms.Find(NearestConnected))
					{
						Room2->Connections.AddUnique(IsolatedRoom);
					}
					
					UE_LOG(LogTemp, Display, TEXT("Connected isolated room at (%d,%d,%d) to adjacent room at (%d,%d,%d)"), 
						IsolatedRoom.X, IsolatedRoom.Y, IsolatedRoom.Z,
						NearestConnected.X, NearestConnected.Y, NearestConnected.Z);
				}
			}
		}
	}
	
	if (!bAllConnected)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to connect all rooms after %d iterations"), MaxIterations);
	}
}

void ADungeonGenerator::OptimizeLayout(FDungeonLayout& Layout)
{
	// Performance optimization pass
	// Remove redundant connections, optimize data structures, etc.
	
	for (auto& RoomPair : Layout.Rooms)
	{
		FRoomData& Room = RoomPair.Value;
		
		// Remove duplicate connections
		TSet<FIntVector> UniqueConnections(Room.Connections);
		Room.Connections = UniqueConnections.Array();
		
		// Limit connections to prevent performance issues
		if (Room.Connections.Num() > 4)
		{
			Room.Connections.SetNum(4);
		}
	}
}