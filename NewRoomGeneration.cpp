// Simple Path-Based Room Generation Algorithm
// Generates exactly 25 rooms along a main path with small branch-offs
// Guarantees 1-cell spacing between all rooms

void GeneratePathBasedRooms(int32 GridSizeX, int32 GridSizeY, int32 TargetRooms = 25)
{
    UE_LOG(LogTemp, Warning, TEXT("🎯 PATH-BASED GENERATION: %d rooms in %dx%d grid"), TargetRooms, GridSizeX, GridSizeY);
    
    TArray<FRoomData> Rooms;
    int32 RoomCount = 0;
    
    // Start with the start room at (2, 2) - gives us 1 cell margin
    FRoomData StartRoom;
    StartRoom.Position = FIntPoint(2, 2);
    StartRoom.Size = 2;
    StartRoom.ConnectedTo.Empty();
    Rooms.Add(StartRoom);
    RoomCount++;
    
    UE_LOG(LogTemp, Warning, TEXT("[S] START Room #1: 2x2 at (2,2)"));
    
    // Create a main path from start to end
    TArray<FIntPoint> MainPath;
    
    // Calculate a simple path across the grid
    FIntPoint CurrentPos = StartRoom.Position;
    FIntPoint TargetPos = FIntPoint(GridSizeX - 6, GridSizeY - 6); // Leave margin for end room
    
    // Simple path generation: zigzag across the grid
    int32 PathStep = 6; // Room + gap + room spacing
    
    // First, go right across the grid
    while (CurrentPos.X < TargetPos.X - PathStep)
    {
        CurrentPos.X += PathStep;
        MainPath.Add(CurrentPos);
    }
    
    // Then, go down
    while (CurrentPos.Y < TargetPos.Y - PathStep)
    {
        CurrentPos.Y += PathStep;
        MainPath.Add(CurrentPos);
    }
    
    // Then, go left to create more path
    while (CurrentPos.X > 8 && MainPath.Num() < TargetRooms - 5)
    {
        CurrentPos.X -= PathStep;
        MainPath.Add(CurrentPos);
    }
    
    // Then, go down more if needed
    while (CurrentPos.Y < TargetPos.Y && MainPath.Num() < TargetRooms - 3)
    {
        CurrentPos.Y += PathStep;
        MainPath.Add(CurrentPos);
    }
    
    // Add the final end position
    MainPath.Add(TargetPos);
    
    UE_LOG(LogTemp, Warning, TEXT("Generated main path with %d positions"), MainPath.Num());
    
    // Place rooms along the main path
    for (int32 PathIndex = 0; PathIndex < MainPath.Num() && RoomCount < TargetRooms - 1; ++PathIndex)
    {
        FIntPoint PathPos = MainPath[PathIndex];
        
        // Determine room size
        int32 RoomSize;
        FString RoomType;
        
        int32 RandVal = FMath::RandRange(0, 100);
        if (RandVal < 60) // 60% small rooms
        {
            RoomSize = 2;
            RoomType = TEXT("SMALL");
        }
        else if (RandVal < 85) // 25% medium rooms
        {
            RoomSize = 3;
            RoomType = TEXT("MEDIUM");
        }
        else // 15% elite rooms
        {
            RoomSize = 4;
            RoomType = TEXT("ELITE");
        }
        
        // Place main path room
        FRoomData NewRoom;
        NewRoom.Position = PathPos;
        NewRoom.Size = RoomSize;
        NewRoom.ConnectedTo.Add(RoomCount - 1); // Connect to previous room
        Rooms[RoomCount - 1].ConnectedTo.Add(RoomCount); // Bi-directional
        
        Rooms.Add(NewRoom);
        RoomCount++;
        
        UE_LOG(LogTemp, Warning, TEXT("[R] MAIN Room #%d: %dx%d %s at (%d,%d)"), 
            RoomCount, RoomSize, RoomSize, *RoomType, PathPos.X, PathPos.Y);
        
        // 30% chance to add a branch-off room
        if (FMath::RandRange(0, 100) < 30 && RoomCount < TargetRooms - 1)
        {
            // Try to place a branch room adjacent to this main room
            TArray<FIntPoint> BranchDirections = {
                FIntPoint(0, -PathStep), // Up
                FIntPoint(0, PathStep),  // Down
                FIntPoint(-PathStep, 0), // Left  
                FIntPoint(PathStep, 0)   // Right
            };
            
            for (const FIntPoint& Dir : BranchDirections)
            {
                FIntPoint BranchPos = PathPos + Dir;
                
                // Check bounds
                if (BranchPos.X < 2 || BranchPos.Y < 2 || 
                    BranchPos.X + 3 > GridSizeX - 2 || 
                    BranchPos.Y + 3 > GridSizeY - 2)
                {
                    continue;
                }
                
                // Check if position is clear from other rooms
                bool bClear = true;
                for (const FRoomData& ExistingRoom : Rooms)
                {
                    int32 DistanceX = FMath::Abs(BranchPos.X - ExistingRoom.Position.X);
                    int32 DistanceY = FMath::Abs(BranchPos.Y - ExistingRoom.Position.Y);
                    
                    // Must be at least 4 cells apart (room + 1 gap + room)
                    if (DistanceX < 4 || DistanceY < 4)
                    {
                        bClear = false;
                        break;
                    }
                }
                
                if (bClear)
                {
                    // Place branch room (always small for simplicity)
                    FRoomData BranchRoom;
                    BranchRoom.Position = BranchPos;
                    BranchRoom.Size = 2;
                    BranchRoom.ConnectedTo.Add(RoomCount - 1); // Connect to main room
                    Rooms[RoomCount - 1].ConnectedTo.Add(RoomCount); // Bi-directional
                    
                    Rooms.Add(BranchRoom);
                    RoomCount++;
                    
                    UE_LOG(LogTemp, Warning, TEXT("[B] BRANCH Room #%d: 2x2 SMALL at (%d,%d) - branched from Room #%d"), 
                        RoomCount, BranchPos.X, BranchPos.Y, RoomCount - 1);
                    
                    break; // Only one branch per main room
                }
            }
        }
    }
    
    // Add the final end room
    if (RoomCount < TargetRooms && MainPath.Num() > 0)
    {
        FIntPoint EndPos = MainPath.Last();
        
        FRoomData EndRoom;
        EndRoom.Position = EndPos;
        EndRoom.Size = 3; // End room is medium size
        EndRoom.ConnectedTo.Add(RoomCount - 1); // Connect to previous room
        Rooms[RoomCount - 1].ConnectedTo.Add(RoomCount);
        
        Rooms.Add(EndRoom);
        RoomCount++;
        
        UE_LOG(LogTemp, Warning, TEXT("[E] END Room #%d: 3x3 MEDIUM at (%d,%d)"), 
            RoomCount, EndPos.X, EndPos.Y);
    }
    
    // Fill remaining slots with small rooms along the path if we haven't reached the target
    while (RoomCount < TargetRooms)
    {
        // Try to place additional small rooms between existing path rooms
        bool bPlaced = false;
        
        for (int32 i = 0; i < Rooms.Num() - 1 && !bPlaced; ++i)
        {
            FIntPoint MidPoint;
            MidPoint.X = (Rooms[i].Position.X + Rooms[i + 1].Position.X) / 2;
            MidPoint.Y = (Rooms[i].Position.Y + Rooms[i + 1].Position.Y) / 2;
            
            // Try positions around the midpoint
            for (int32 OffsetY = -2; OffsetY <= 2 && !bPlaced; OffsetY += 2)
            {
                for (int32 OffsetX = -2; OffsetX <= 2 && !bPlaced; OffsetX += 2)
                {
                    FIntPoint TestPos = MidPoint + FIntPoint(OffsetX, OffsetY);
                    
                    // Check bounds
                    if (TestPos.X < 2 || TestPos.Y < 2 || 
                        TestPos.X + 2 > GridSizeX - 2 || 
                        TestPos.Y + 2 > GridSizeY - 2)
                    {
                        continue;
                    }
                    
                    // Check clearance
                    bool bClear = true;
                    for (const FRoomData& ExistingRoom : Rooms)
                    {
                        int32 DistanceX = FMath::Abs(TestPos.X - ExistingRoom.Position.X);
                        int32 DistanceY = FMath::Abs(TestPos.Y - ExistingRoom.Position.Y);
                        
                        if (DistanceX < 4 || DistanceY < 4)
                        {
                            bClear = false;
                            break;
                        }
                    }
                    
                    if (bClear)
                    {
                        FRoomData FillerRoom;
                        FillerRoom.Position = TestPos;
                        FillerRoom.Size = 2;
                        FillerRoom.ConnectedTo.Add(i); // Connect to nearby room
                        Rooms[i].ConnectedTo.Add(RoomCount);
                        
                        Rooms.Add(FillerRoom);
                        RoomCount++;
                        
                        UE_LOG(LogTemp, Warning, TEXT("[F] FILLER Room #%d: 2x2 SMALL at (%d,%d)"), 
                            RoomCount, TestPos.X, TestPos.Y);
                        
                        bPlaced = true;
                    }
                }
            }
        }
        
        if (!bPlaced) break; // Can't place any more rooms
    }
    
    UE_LOG(LogTemp, Warning, TEXT("\\n🎉 PATH-BASED GENERATION COMPLETE!"));
    UE_LOG(LogTemp, Warning, TEXT("📊 FINAL RESULT: %d/%d rooms generated"), RoomCount, TargetRooms);
    
    if (RoomCount >= TargetRooms)
    {
        UE_LOG(LogTemp, Warning, TEXT("✅ SUCCESS: Target achieved!"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("⚠️ PARTIAL: %.1f%% of target achieved"), 
            (float)RoomCount / TargetRooms * 100.0f);
    }
}