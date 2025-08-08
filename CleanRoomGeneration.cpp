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
    
    // Check grid size
    int32 MinGridSize = 15;
    if (GridSizeX < MinGridSize || GridSizeY < MinGridSize)
    {
        UE_LOG(LogTemp, Warning, TEXT("Grid too small for path generation! Need at least %dx%d (current: %dx%d)"), 
            MinGridSize, MinGridSize, GridSizeX, GridSizeY);
        return;
    }
    
    // Determine target rooms
    int32 TargetRooms;
    if (GridSizeX == 30 && GridSizeY == 30)
    {
        TargetRooms = 25; // YOUR EXACT REQUIREMENT!
    }
    else if (GridSizeX >= 25)
    {
        TargetRooms = FMath::Min(20, GridSizeX * GridSizeY / 50);
    }
    else
    {
        TargetRooms = FMath::Min(12, GridSizeX * GridSizeY / 60);
    }
    
    UE_LOG(LogTemp, Warning, TEXT("🎯 PATH-BASED GENERATION: %d rooms target for %dx%d grid!"), TargetRooms, GridSizeX, GridSizeY);
    
    // Track rooms
    TArray<FRoomData> Rooms;
    int32 RoomCount = 0;
    
    // Place start room at (2, 2) - gives us 1 cell margin
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
    
    // Create main path positions
    TArray<FIntPoint> MainPath;
    int32 RoomSpacing = 6; // Room + gap spacing
    
    // Generate zigzag path
    FIntPoint CurrentPos = FIntPoint(8, 2);
    FIntPoint TargetPos = FIntPoint(GridSizeX - 8, GridSizeY - 8);
    
    // Right across
    while (CurrentPos.X < TargetPos.X - RoomSpacing && MainPath.Num() < TargetRooms - 5)
    {
        CurrentPos.X += RoomSpacing;
        MainPath.Add(CurrentPos);
    }
    
    // Down
    while (CurrentPos.Y < TargetPos.Y - RoomSpacing && MainPath.Num() < TargetRooms - 3)
    {
        CurrentPos.Y += RoomSpacing;
        MainPath.Add(CurrentPos);
    }
    
    // Back left if needed
    while (CurrentPos.X > 8 && MainPath.Num() < TargetRooms - 2)
    {
        CurrentPos.X -= RoomSpacing;
        MainPath.Add(CurrentPos);
    }
    
    // Add final position
    if (MainPath.Num() < TargetRooms - 1)
    {
        MainPath.Add(TargetPos);
    }
    
    UE_LOG(LogTemp, Warning, TEXT("💪 Main path positions: %d"), MainPath.Num());
    
    // Place rooms along path
    int32 PlacementAttempts = 0;
    
    for (int32 PathIndex = 0; PathIndex < MainPath.Num() && RoomCount < TargetRooms; ++PathIndex)
    {
        FIntPoint PathPos = MainPath[PathIndex];
        
        // Determine room size
        int32 RoomSize;
        FString RoomType;
        
        if (PathIndex == MainPath.Num() - 1 || RoomCount == TargetRooms - 1)
        {
            RoomSize = 3;
            RoomType = TEXT("END");
        }
        else
        {
            int32 RandVal = FMath::RandRange(0, 100);
            if (RandVal < 10)
            {
                RoomSize = 4;
                RoomType = TEXT("ELITE");
            }
            else if (RandVal < 40)
            {
                RoomSize = 3;
                RoomType = TEXT("MEDIUM");
            }
            else
            {
                RoomSize = 2;
                RoomType = TEXT("SMALL");
            }
        }
        
        // Check bounds
        if (PathPos.X + RoomSize > GridSizeX - 2 || PathPos.Y + RoomSize > GridSizeY - 2)
        {
            continue;
        }
        
        // Check clearance from existing rooms
        bool bCanPlace = true;
        for (const FRoomData& ExistingRoom : Rooms)
        {
            int32 DistanceX = FMath::Abs(PathPos.X - ExistingRoom.Position.X);
            int32 DistanceY = FMath::Abs(PathPos.Y - ExistingRoom.Position.Y);
            
            if (DistanceX < 4 || DistanceY < 4)
            {
                bCanPlace = false;
                break;
            }
        }
        
        if (bCanPlace)
        {
            // Place main path room
            for (int32 Y = PathPos.Y; Y < PathPos.Y + RoomSize; ++Y)
            {
                for (int32 X = PathPos.X; X < PathPos.X + RoomSize; ++X)
                {
                    SetGridCell(X, Y, EGridCellType::Floor);
                }
            }
            
            FRoomData MainRoom;
            MainRoom.Position = PathPos;
            MainRoom.Size = RoomSize;
            MainRoom.ConnectedTo.Add(RoomCount - 1); // Connect to previous
            
            if (RoomCount > 1)
            {
                Rooms[RoomCount - 1].ConnectedTo.Add(RoomCount);
            }
            
            Rooms.Add(MainRoom);
            RoomCount++;
            PlacementAttempts++;
            
            FString PathNotation = (RoomType == TEXT("END")) ? TEXT("[E]") : TEXT("[R]");
            UE_LOG(LogTemp, Warning, TEXT("%s MAIN Room #%d: %dx%d %s at (%d,%d)"), 
                *PathNotation, RoomCount, RoomSize, RoomSize, *RoomType, PathPos.X, PathPos.Y);
            
            // 25% chance for branch room (not on end room)
            if (FMath::RandRange(0, 100) < 25 && RoomCount < TargetRooms && RoomType != TEXT("END"))
            {
                TArray<FIntPoint> BranchDirs = { 
                    FIntPoint(0, -6), FIntPoint(0, 6), FIntPoint(-6, 0), FIntPoint(6, 0) 
                };
                
                for (const FIntPoint& BranchDir : BranchDirs)
                {
                    FIntPoint BranchPos = PathPos + BranchDir;
                    
                    if (BranchPos.X > 1 && BranchPos.Y > 1 && 
                        BranchPos.X + 2 < GridSizeX - 1 && BranchPos.Y + 2 < GridSizeY - 1)
                    {
                        bool bBranchClear = true;
                        for (const FRoomData& ExistingRoom : Rooms)
                        {
                            int32 BDistanceX = FMath::Abs(BranchPos.X - ExistingRoom.Position.X);
                            int32 BDistanceY = FMath::Abs(BranchPos.Y - ExistingRoom.Position.Y);
                            
                            if (BDistanceX < 4 || BDistanceY < 4)
                            {
                                bBranchClear = false;
                                break;
                            }
                        }
                        
                        if (bBranchClear)
                        {
                            // Place small branch room
                            for (int32 Y = BranchPos.Y; Y < BranchPos.Y + 2; ++Y)
                            {
                                for (int32 X = BranchPos.X; X < BranchPos.X + 2; ++X)
                                {
                                    SetGridCell(X, Y, EGridCellType::Floor);
                                }
                            }
                            
                            FRoomData BranchRoom;
                            BranchRoom.Position = BranchPos;
                            BranchRoom.Size = 2;
                            BranchRoom.ConnectedTo.Add(RoomCount - 1);
                            Rooms[RoomCount - 1].ConnectedTo.Add(RoomCount);
                            
                            Rooms.Add(BranchRoom);
                            RoomCount++;
                            
                            UE_LOG(LogTemp, Warning, TEXT("[B] BRANCH Room #%d: 2x2 SMALL at (%d,%d) - from Room #%d"), 
                                RoomCount, BranchPos.X, BranchPos.Y, RoomCount - 1);
                            
                            break; // Only one branch per main room
                        }
                    }
                }
            }
        }
    }
    
    // Results
    UE_LOG(LogTemp, Warning, TEXT("\\n🎉 PATH-BASED GENERATION COMPLETE!"));
    UE_LOG(LogTemp, Warning, TEXT("📊 FINAL RESULT: %d/%d rooms generated!"), RoomCount, TargetRooms);
    
    if (RoomCount >= TargetRooms)
    {
        UE_LOG(LogTemp, Warning, TEXT("✅ SUCCESS: Exactly %d rooms as requested!"), RoomCount);
    }
    else if (RoomCount >= TargetRooms * 0.8f)
    {
        UE_LOG(LogTemp, Warning, TEXT("✅ GOOD: %d/%d rooms (%.1f%% of target)"), 
            RoomCount, TargetRooms, (float)RoomCount / TargetRooms * 100.0f);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("⚠️ PARTIAL: %d/%d rooms (%.1f%% of target)"), 
            RoomCount, TargetRooms, (float)RoomCount / TargetRooms * 100.0f);
    }
    
    UE_LOG(LogTemp, Warning, TEXT("🗺️ Layout: Organic path with branch-offs, 1-cell gaps maintained"));
    UE_LOG(LogTemp, Warning, TEXT("⚡ Performance: %d successful placements"), PlacementAttempts);
}