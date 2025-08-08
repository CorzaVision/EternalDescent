// Create a clean version without the broken code

    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Grid too small for room-path generation! Need at least %dx%d grid (current: %dx%d)."), MinGridSize, MinGridSize, GridSizeX, GridSizeY);
        
        // For small grids, create a simple 2-room layout
        if (GridSizeX >= 6 && GridSizeY >= 6)
        {
            UE_LOG(LogTemp, Warning, TEXT("Creating simple 2-room layout for small grid"));
            
            // Start room at (1,1) - already created above