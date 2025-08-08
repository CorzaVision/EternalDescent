void AGridDungeonVisualizer::GenerateSimpleLayout()
{
    // First, fill entire grid with walls (cubes)
    for (int32 Y = 0; Y < GridSizeY; ++Y)
    {
        for (int32 X = 0; X < GridSizeX; ++X)
        {
            SetGridCell(X, Y, EGridCellType::Wall);
        }
    }
    
    // Expand grid size if needed for 25 rooms with proper spacing
    int32 RequiredGridSize = 35; // Need larger grid for 25 rooms with 1-cell gaps
    
    if (GridSizeX < RequiredGridSize || GridSizeY < RequiredGridSize)
    {
        UE_LOG(LogTemp, Warning, TEXT("🔄 EXPANDING GRID: %dx%d -> %dx%d for 25 rooms"), 
            GridSizeX, GridSizeY, RequiredGridSize, RequiredGridSize);
        GridSizeX = RequiredGridSize;
        GridSizeY = RequiredGridSize;
        InitializeGrid();
        
        // Re-fill with walls after expansion
        for (int32 Y = 0; Y < GridSizeY; ++Y)
        {
            for (int32 X = 0; X < GridSizeX; ++X)
            {
                SetGridCell(X, Y, EGridCellType::Wall);
            }
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("🎯 GUARANTEED 25-ROOM SYSTEM: %dx%d grid"), GridSizeX, GridSizeY);
    
    // Track rooms for guaranteed placement
    TArray<FRoomData> Rooms;
    int32 RoomCount = 0;
    int32 TargetRooms = 25;
    
    // STEP 1: Place start room at (2,2)
    for (int32 Y = 2; Y <= 3; ++Y)
    {
        for (int32 X = 2; X <= 3; ++X)
        {
            SetGridCell(X, Y, EGridCellType::Floor);
        }
    }
    FRoomData StartRoom;
    StartRoom.Position = FIntPoint(2, 2);
    StartRoom.Size = 2;
    StartRoom.ConnectedTo.Empty();
    Rooms.Add(StartRoom);
    RoomCount++;
    UE_LOG(LogTemp, Warning, TEXT("[S] START Room #1: 2x2 at (2,2)"));
    
    // STEP 2: Create systematic room positions with guaranteed 1-cell spacing
    TArray<FIntPoint> PlannedPositions;
    int32 RoomSpacing = 5; // Minimum spacing: room (2-4) + gap (1) = 5
    
    // Create a grid pattern of potential room positions
    for (int32 Row = 0; Row < 5; ++Row) // 5 rows of rooms
    {
        for (int32 Col = 0; Col < 5; ++Col) // 5 columns of rooms
        {
            // Skip the start room area
            if (Row == 0 && Col == 0) continue;
            
            FIntPoint Position;
            Position.X = 2 + (Col * RoomSpacing);
            Position.Y = 2 + (Row * RoomSpacing);
            
            // Ensure position is within grid bounds
            if (Position.X + 4 < GridSizeX - 1 && Position.Y + 4 < GridSizeY - 1)
            {
                PlannedPositions.Add(Position);
            }
        }
    }
    
    // Shuffle positions for organic feel
    for (int32 i = PlannedPositions.Num() - 1; i > 0; --i)
    {
        int32 j = FMath::RandRange(0, i);
        PlannedPositions.Swap(i, j);
    }
    
    UE_LOG(LogTemp, Warning, TEXT("💪 Generated %d planned positions for %d target rooms"), 
        PlannedPositions.Num(), TargetRooms - 1);
    
    // STEP 3: Place main path rooms systematically
    int32 MainPathRooms = FMath::Min(18, PlannedPositions.Num()); // 18 main path rooms
    
    for (int32 i = 0; i < MainPathRooms && RoomCount < TargetRooms; ++i)
    {
        FIntPoint Position = PlannedPositions[i];
        
        // Determine room size and type
        int32 RoomSize;
        FString RoomType;
        
        if (i == MainPathRooms - 1 || RoomCount == TargetRooms - 1)
        {
            RoomSize = 3;
            RoomType = TEXT("END");
        }
        else
        {
            // Size distribution for variety
            int32 SizeRoll = FMath::RandRange(0, 100);
            if (SizeRoll < 60) // 60% small rooms
            {
                RoomSize = 2;
                RoomType = TEXT("SMALL");
            }
            else if (SizeRoll < 85) // 25% medium rooms
            {
                RoomSize = 3;
                RoomType = TEXT("MEDIUM");
            }
            else // 15% elite rooms
            {
                RoomSize = 4;
                RoomType = TEXT("ELITE");
            }
        }
        
        // Place the room floors
        for (int32 Y = Position.Y; Y < Position.Y + RoomSize; ++Y)
        {
            for (int32 X = Position.X; X < Position.X + RoomSize; ++X)
            {
                SetGridCell(X, Y, EGridCellType::Floor);
            }
        }
        
        // Create room data
        FRoomData NewRoom;
        NewRoom.Position = Position;
        NewRoom.Size = RoomSize;
        
        // Connect to previous room in sequence
        int32 PrevRoom = RoomCount - 1;
        NewRoom.ConnectedTo.Add(PrevRoom);
        Rooms[PrevRoom].ConnectedTo.Add(RoomCount);
        
        Rooms.Add(NewRoom);
        RoomCount++;
        
        FString PathNotation = (RoomType == TEXT("END")) ? TEXT("[E]") : TEXT("[R]");
        UE_LOG(LogTemp, Warning, TEXT("%s MAIN Room #%d: %dx%d %s at (%d,%d)"), 
            *PathNotation, RoomCount, RoomSize, RoomSize, *RoomType, Position.X, Position.Y);
    }
    
    // STEP 4: Add branch rooms to reach exactly 25
    int32 RemainingSlots = TargetRooms - RoomCount;
    UE_LOG(LogTemp, Warning, TEXT("🌿 Adding %d branch rooms to reach 25 total"), RemainingSlots);
    
    for (int32 BranchIndex = 0; BranchIndex < RemainingSlots && MainPathRooms + BranchIndex < PlannedPositions.Num(); ++BranchIndex)
    {
        FIntPoint BranchPos = PlannedPositions[MainPathRooms + BranchIndex];
        
        // Branch rooms are always small (2x2)
        int32 BranchSize = 2;
        
        // Place branch room floors
        for (int32 Y = BranchPos.Y; Y < BranchPos.Y + BranchSize; ++Y)
        {
            for (int32 X = BranchPos.X; X < BranchPos.X + BranchSize; ++X)
            {
                SetGridCell(X, Y, EGridCellType::Floor);
            }
        }
        
        // Connect to nearest main room
        int32 NearestRoom = 0;
        float NearestDistance = FLT_MAX;
        for (int32 i = 0; i < Rooms.Num(); ++i)
        {
            float Distance = FVector2D::DistSquared(
                FVector2D(BranchPos.X, BranchPos.Y),
                FVector2D(Rooms[i].Position.X, Rooms[i].Position.Y)
            );
            if (Distance < NearestDistance)
            {
                NearestDistance = Distance;
                NearestRoom = i;
            }
        }
        
        FRoomData BranchRoom;
        BranchRoom.Position = BranchPos;
        BranchRoom.Size = BranchSize;
        BranchRoom.ConnectedTo.Add(NearestRoom);
        Rooms[NearestRoom].ConnectedTo.Add(RoomCount);
        
        Rooms.Add(BranchRoom);
        RoomCount++;
        
        UE_LOG(LogTemp, Warning, TEXT("[B] BRANCH Room #%d: 2x2 SMALL at (%d,%d) - connects to Room #%d"), 
            RoomCount, BranchPos.X, BranchPos.Y, NearestRoom + 1);
    }
    
    // STEP 5: Results summary
    UE_LOG(LogTemp, Warning, TEXT("\\n🎉 GUARANTEED 25-ROOM GENERATION COMPLETE!"));
    UE_LOG(LogTemp, Warning, TEXT("📊 FINAL RESULT: %d/%d rooms generated!"), RoomCount, TargetRooms);
    
    if (RoomCount >= TargetRooms)
    {
        UE_LOG(LogTemp, Warning, TEXT("✅ SUCCESS: Exactly %d rooms as requested!"), RoomCount);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("⚠️ PARTIAL: %d/%d rooms (%.1f%% of target)"), 
            RoomCount, TargetRooms, (float)RoomCount / TargetRooms * 100.0f);
    }
    
    UE_LOG(LogTemp, Warning, TEXT("🗺️ Features:"));
    UE_LOG(LogTemp, Warning, TEXT("  - Organic layout with branch-offs"));
    UE_LOG(LogTemp, Warning, TEXT("  - Guaranteed 1-cell gaps between rooms"));  
    UE_LOG(LogTemp, Warning, TEXT("  - Room-as-path design (no corridors)"));
    UE_LOG(LogTemp, Warning, TEXT("  - Variable room sizes (2x2 to 4x4)"));
    UE_LOG(LogTemp, Warning, TEXT("  - %dx%d grid expanded for optimal spacing"), GridSizeX, GridSizeY);
    
    // Count room sizes for statistics
    TMap<int32, int32> SizeDistribution;
    for (const FRoomData& Room : Rooms)
    {
        SizeDistribution.FindOrAdd(Room.Size)++;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("📈 Room Distribution:"));
    for (const auto& Pair : SizeDistribution)
    {
        UE_LOG(LogTemp, Warning, TEXT("  - %dx%d rooms: %d"), Pair.Key, Pair.Key, Pair.Value);
    }
}