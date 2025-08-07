#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestSimple, "SoverignAscent.Simple", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FTestSimple::RunTest(const FString& Parameters)
{
    UE_LOG(LogTemp, Warning, TEXT("Simple test is running!"));
    return true;
}