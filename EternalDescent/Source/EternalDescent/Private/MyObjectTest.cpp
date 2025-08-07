// Fill out your copyright notice in the Description page of Project Settings.


#include "MyObjectTest.h"

#include "Misc/AutomationTest.h"

// This macro goes OUTSIDE the class definition. It tells the Unreal
// Engine testing framework that a new test exists.
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMySimpleTest, "EternalDescent.MyFirstTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

// The RunTest() function is also implemented OUTSIDE the class.
// It is the body of the test that will be executed.
bool FMySimpleTest::RunTest(const FString& Parameters)
{
    // ... your test logic here ...
    return true;
}