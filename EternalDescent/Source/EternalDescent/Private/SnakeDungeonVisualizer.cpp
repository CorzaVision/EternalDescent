// SnakeDungeonVisualizer.cpp - Visual debugging implementation for SnakePathGenerator
#include "SnakeDungeonVisualizer.h"
#include "Engine/Engine.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"

ASnakeDungeonVisualizer::ASnakeDungeonVisualizer(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    PrimaryActorTick.bCanEverTick = false;
    
    // Create root component
    RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
    RootComponent = RootSceneComponent;
    
    // Create path generator instance
    PathGenerator = CreateDefaultSubobject<USnakePathGenerator>(TEXT("SnakePathGenerator"));
    
    // Initialize default values
    RandomSeed = -1;
    GridSizeX = 45;
    GridSizeY = 45;
    VisualizationScale = 100.0f;
    bAutoCalculateGridSize = true;
    bVerboseLogging = false;
    bShowRoomIndices = true;
    bShowPathConnections = true;
    bShowGenerationStats = true;
    bAutoRegenerate = true;
    
    // Initialize asset references with defaults
    InitializeDefaults();
}

void ASnakeDungeonVisualizer::InitializeDefaults()
{
    // Set default cube mesh if available
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshFinder(TEXT("/Engine/BasicShapes/Cube"));
    if (CubeMeshFinder.Succeeded())
    {
        RoomMesh = CubeMeshFinder.Object;
    }
    
    // Set default materials if available
    static ConstructorHelpers::FObjectFinder<UMaterialInterface> StartMaterialFinder(TEXT("/Engine/BasicShapes/BasicShapeMaterial"));
    if (StartMaterialFinder.Succeeded())
    {
        StartRoomMaterial = StartMaterialFinder.Object;
        EndRoomMaterial = StartMaterialFinder.Object;
        RegularRoomMaterial = StartMaterialFinder.Object;
    }
}

void ASnakeDungeonVisualizer::BeginPlay()
{
    Super::BeginPlay();
    
    if (bAutoRegenerate)
    {
        GenerateAndVisualize();
    }
}

void ASnakeDungeonVisualizer::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    
    if (bAutoRegenerate && GetWorld())
    {
        GenerateAndVisualize();
    }
}

#if WITH_EDITOR
void ASnakeDungeonVisualizer::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);
    
    if (bAutoRegenerate && PropertyChangedEvent.Property)
    {
        FName PropertyName = PropertyChangedEvent.Property->GetFName();
        
        // Regenerate on key property changes
        if (PropertyName == GET_MEMBER_NAME_CHECKED(ASnakeDungeonVisualizer, RandomSeed) ||
            PropertyName == GET_MEMBER_NAME_CHECKED(ASnakeDungeonVisualizer, GridSizeX) ||
            PropertyName == GET_MEMBER_NAME_CHECKED(ASnakeDungeonVisualizer, GridSizeY) ||
            PropertyName == GET_MEMBER_NAME_CHECKED(ASnakeDungeonVisualizer, bAutoCalculateGridSize) ||
            PropertyName == GET_MEMBER_NAME_CHECKED(ASnakeDungeonVisualizer, VisualizationScale))
        {
            GenerateAndVisualize();
        }
        
        // Update visualization on display property changes
        else if (PropertyName == GET_MEMBER_NAME_CHECKED(ASnakeDungeonVisualizer, bShowRoomIndices) ||
                 PropertyName == GET_MEMBER_NAME_CHECKED(ASnakeDungeonVisualizer, bShowPathConnections) ||
                 PropertyName == GET_MEMBER_NAME_CHECKED(ASnakeDungeonVisualizer, StartRoomMaterial) ||
                 PropertyName == GET_MEMBER_NAME_CHECKED(ASnakeDungeonVisualizer, EndRoomMaterial) ||
                 PropertyName == GET_MEMBER_NAME_CHECKED(ASnakeDungeonVisualizer, RegularRoomMaterial))
        {
            CreateRoomVisualization();
        }
    }
}
#endif

void ASnakeDungeonVisualizer::GenerateAndVisualize()
{
    if (!PathGenerator)
    {
        UE_LOG(LogTemp, Error, TEXT("SnakeDungeonVisualizer: PathGenerator is null!"));
        return;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("🐍 SnakeDungeonVisualizer: Starting generation and visualization..."));
    
    // Configure generation parameters
    FSnakeGenerationConfig Config;
    Config.RequiredRoomCount = 25;  // Always exactly 25 rooms
    Config.GridSizeX = GridSizeX;
    Config.GridSizeY = GridSizeY;
    Config.bAutoCalculateGridSize = bAutoCalculateGridSize;
    Config.bVerboseLogging = bVerboseLogging;
    Config.RoomGap = 1;
    Config.MaxRetries = 3000;
    Config.MaxBacktrackDepth = 8;
    
    // Generate the path
    CurrentResult = PathGenerator->GenerateSnakePath(Config, RandomSeed);
    
    // Check for success
    if (!CurrentResult.bGenerationSuccessful)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Generation failed: %s"), *CurrentResult.FailureReason);
        ClearVisualization();
        return;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("✅ Generation successful! Generated %d rooms in %dms"), 
        CurrentResult.Rooms.Num(), CurrentResult.GenerationTimeMs);
    
    // Create visual representation
    CreateRoomVisualization();
    
    // Show debug information
    if (bShowPathConnections)
    {
        DrawPathConnections();
    }
    
    if (bShowRoomIndices)
    {
        DrawRoomIndices();
    }
    
    if (bShowGenerationStats)
    {
        LogGenerationStatistics();
    }
}

void ASnakeDungeonVisualizer::ClearVisualization()
{
    // Remove all existing room components
    for (UStaticMeshComponent* Component : RoomComponents)
    {
        if (Component && IsValid(Component))
        {
            Component->DestroyComponent();
        }
    }
    RoomComponents.Empty();
    
    // Clear debug drawings (these are ephemeral and clear automatically)
}

void ASnakeDungeonVisualizer::RegenerateWithNewSeed()
{
    RandomSeed = FMath::Rand();
    GenerateAndVisualize();
}

void ASnakeDungeonVisualizer::CreateRoomVisualization()
{
    if (!ValidateAssets())
    {
        return;
    }
    
    // Clear existing visualization
    ClearVisualization();
    
    if (CurrentResult.Rooms.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("No rooms to visualize"));
        return;
    }
    
    // Create visualization for each room
    for (const FSnakeRoomData& Room : CurrentResult.Rooms)
    {
        UStaticMeshComponent* RoomComponent = CreateRoomComponent(Room);
        if (RoomComponent)
        {
            RoomComponents.Add(RoomComponent);
        }
    }
    
    UE_LOG(LogTemp, Log, TEXT("🎨 Created %d room visualization components"), RoomComponents.Num());
}

UStaticMeshComponent* ASnakeDungeonVisualizer::CreateRoomComponent(const FSnakeRoomData& RoomData)
{
    if (!RoomMesh.LoadSynchronous())
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to load room mesh!"));
        return nullptr;
    }
    
    // Create component at runtime using NewObject with proper FName
    FString ComponentName = FString::Printf(TEXT("Room_%d"), RoomData.PathIndex);
    UStaticMeshComponent* RoomComponent = NewObject<UStaticMeshComponent>(this, UStaticMeshComponent::StaticClass(), FName(*ComponentName));
    
    if (!ensure(RoomComponent))
    {
        UE_LOG(LogTemp, Error, TEXT("ASnakeDungeonVisualizer: Failed to create room component %s"), *ComponentName);
        return nullptr;
    }
    
    // Setup attachment before registering
    RoomComponent->SetupAttachment(RootComponent);
    
    // Register the component with the actor
    RoomComponent->RegisterComponent();
    
    // Set mesh
    RoomComponent->SetStaticMesh(RoomMesh.Get());
    
    // Set material
    UMaterialInterface* Material = GetMaterialForRoom(RoomData);
    if (Material)
    {
        RoomComponent->SetMaterial(0, Material);
    }
    
    // Calculate world position
    FVector WorldPos = GridToWorldPosition(RoomData.Center);
    
    // Calculate scale based on room size
    int32 RoomSize = (int32)RoomData.RoomSize;
    FVector Scale = FVector(RoomSize, RoomSize, 0.5f) * (VisualizationScale / 100.0f);
    
    // Set transform
    FTransform RoomTransform;
    RoomTransform.SetLocation(WorldPos);
    RoomTransform.SetScale3D(Scale);
    
    RoomComponent->SetWorldTransform(RoomTransform);
    
    // Attach to root
    RoomComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
    
    return RoomComponent;
}

UMaterialInterface* ASnakeDungeonVisualizer::GetMaterialForRoom(const FSnakeRoomData& RoomData)
{
    if (RoomData.bIsStartRoom && StartRoomMaterial.LoadSynchronous())
    {
        return StartRoomMaterial.Get();
    }
    else if (RoomData.bIsEndRoom && EndRoomMaterial.LoadSynchronous())
    {
        return EndRoomMaterial.Get();
    }
    else if (RegularRoomMaterial.LoadSynchronous())
    {
        return RegularRoomMaterial.Get();
    }
    
    return nullptr;
}

FVector ASnakeDungeonVisualizer::GridToWorldPosition(const FIntPoint& GridPos) const
{
    return FVector(
        GridPos.X * VisualizationScale,
        GridPos.Y * VisualizationScale,
        0.0f
    );
}

void ASnakeDungeonVisualizer::DrawPathConnections()
{
    if (CurrentResult.PathSequence.Num() < 2)
    {
        return;
    }
    
    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }
    
    // Draw lines between consecutive rooms in the path
    for (int32 i = 0; i < CurrentResult.PathSequence.Num() - 1; ++i)
    {
        FVector StartPos = GridToWorldPosition(CurrentResult.PathSequence[i]);
        FVector EndPos = GridToWorldPosition(CurrentResult.PathSequence[i + 1]);
        
        // Offset Z to avoid ground clipping
        StartPos.Z += 50.0f;
        EndPos.Z += 50.0f;
        
        // Use yellow for path connections
        DrawDebugLine(World, StartPos, EndPos, FColor::Yellow, true, -1.0f, 0, 3.0f);
        
        // Draw arrow at end point
        FVector Direction = (EndPos - StartPos).GetSafeNormal();
        FVector ArrowEnd = EndPos - Direction * 20.0f;
        DrawDebugDirectionalArrow(World, ArrowEnd, EndPos, 10.0f, FColor::Orange, true, -1.0f, 0, 2.0f);
    }
}

void ASnakeDungeonVisualizer::DrawRoomIndices()
{
    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }
    
    for (const FSnakeRoomData& Room : CurrentResult.Rooms)
    {
        FVector WorldPos = GridToWorldPosition(Room.Center);
        WorldPos.Z += 100.0f; // Offset above rooms
        
        FString IndexText = FString::Printf(TEXT("%d"), Room.PathIndex);
        FColor TextColor = Room.bIsStartRoom ? FColor::Green : 
                          (Room.bIsEndRoom ? FColor::Red : FColor::White);
        
        DrawDebugString(World, WorldPos, IndexText, nullptr, TextColor, -1.0f);
    }
}

void ASnakeDungeonVisualizer::LogGenerationStatistics()
{
    UE_LOG(LogTemp, Warning, TEXT("📊 GENERATION STATISTICS"));
    UE_LOG(LogTemp, Warning, TEXT("   Rooms Generated: %d"), CurrentResult.Rooms.Num());
    UE_LOG(LogTemp, Warning, TEXT("   Generation Time: %dms"), CurrentResult.GenerationTimeMs);
    UE_LOG(LogTemp, Warning, TEXT("   Retry Count: %d"), CurrentResult.RetryCount);
    UE_LOG(LogTemp, Warning, TEXT("   Backtrack Count: %d"), CurrentResult.BacktrackCount);
    UE_LOG(LogTemp, Warning, TEXT("   Grid Size: %dx%d"), CurrentResult.GridSizeX, CurrentResult.GridSizeY);
    UE_LOG(LogTemp, Warning, TEXT("   Random Seed: %d"), RandomSeed);
    
    // Log room details
    if (bVerboseLogging)
    {
        UE_LOG(LogTemp, Warning, TEXT("🏠 ROOM DETAILS:"));
        for (const FSnakeRoomData& Room : CurrentResult.Rooms)
        {
            FString RoomType = Room.bIsStartRoom ? TEXT("START") :
                              (Room.bIsEndRoom ? TEXT("END") : TEXT("REGULAR"));
            UE_LOG(LogTemp, Warning, TEXT("   Room %d: %s at (%d,%d) - Size %dx%d"), 
                Room.PathIndex, *RoomType, Room.Center.X, Room.Center.Y, 
                (int32)Room.RoomSize, (int32)Room.RoomSize);
        }
    }
}

bool ASnakeDungeonVisualizer::ValidateAssets()
{
    bool bAllAssetsValid = true;
    
    if (!RoomMesh.LoadSynchronous())
    {
        UE_LOG(LogTemp, Error, TEXT("SnakeDungeonVisualizer: Room mesh is not set or invalid!"));
        bAllAssetsValid = false;
    }
    
    if (!StartRoomMaterial.LoadSynchronous())
    {
        UE_LOG(LogTemp, Warning, TEXT("SnakeDungeonVisualizer: Start room material is not set"));
    }
    
    if (!EndRoomMaterial.LoadSynchronous())
    {
        UE_LOG(LogTemp, Warning, TEXT("SnakeDungeonVisualizer: End room material is not set"));
    }
    
    if (!RegularRoomMaterial.LoadSynchronous())
    {
        UE_LOG(LogTemp, Warning, TEXT("SnakeDungeonVisualizer: Regular room material is not set"));
    }
    
    return bAllAssetsValid;
}