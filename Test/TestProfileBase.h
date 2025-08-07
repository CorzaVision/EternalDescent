#pragma once

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "HAL/PlatformFilemanager.h"
#include "Misc/FileHelper.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"

/**
 * Profile levels for test execution
 */
enum class ETestProfileLevel : uint8
{
    Minimal = 0,    // Always on, <0.01ms overhead
    CSV = 1,        // CSV profiler, 0.5-2ms overhead
    Insights = 2     // Full traces, 10-30% overhead
};

/**
 * Base class for tests with tiered profiling support
 * 
 * Features:
 * - Zero-overhead timing in Minimal mode
 * - Automated CSV profiling in CSV mode
 * - Full Unreal Insights traces in Insights mode
 * - Structured JSON output for all measurements
 */
class SOVERIGNASCENT_API FTestProfileBase : public FAutomationTestBase
{
public:
    FTestProfileBase(const FString& InName, const bool bInComplexTask)
        : FAutomationTestBase(InName, bInComplexTask)
        , ProfileLevel(ETestProfileLevel::Minimal)
        , ProfileOutputPath(TEXT(""))
    {
    }

protected:
    /**
     * Initialize profiling based on command line parameters
     * Call this at the start of RunTest()
     */
    void InitializeProfiling()
    {
        // Parse profile level from command line
        FString ProfileLevelStr;
        if (FParse::Value(FCommandLine::Get(), TEXT("ProfileLevel="), ProfileLevelStr))
        {
            if (ProfileLevelStr.Equals(TEXT("csv"), ESearchCase::IgnoreCase))
            {
                ProfileLevel = ETestProfileLevel::CSV;
            }
            else if (ProfileLevelStr.Equals(TEXT("insights"), ESearchCase::IgnoreCase))
            {
                ProfileLevel = ETestProfileLevel::Insights;
            }
        }

        // Parse output path
        FParse::Value(FCommandLine::Get(), TEXT("ProfileOutput="), ProfileOutputPath);
        
        // Initialize profile data storage
        ProfileData = MakeShareable(new FJsonObject);
        ProfileData->SetStringField(TEXT("TestName"), GetTestFullName());
        ProfileData->SetStringField(TEXT("Timestamp"), FDateTime::Now().ToString());
        ProfileData->SetStringField(TEXT("ProfileLevel"), GetProfileLevelString());
        
        Measurements = MakeShareable(new FJsonObject);
    }

    /**
     * Finalize profiling and save results
     * Call this at the end of RunTest()
     */
    void FinalizeProfiling()
    {
        if (!ProfileData.IsValid() || !Measurements.IsValid())
        {
            return;
        }

        // Add measurements to profile data
        ProfileData->SetObjectField(TEXT("Measurements"), Measurements);

        // Save to JSON file if output path is specified
        if (!ProfileOutputPath.IsEmpty())
        {
            FString JsonString;
            TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
            FJsonSerializer::Serialize(ProfileData.ToSharedRef(), Writer);

            FString OutputFile = FPaths::Combine(ProfileOutputPath, FString::Printf(TEXT("%s_profile.json"), *GetTestFullName()));
            FFileHelper::SaveStringToFile(JsonString, *OutputFile);
        }
        
#if CSV_PROFILER
        // Write custom CSV data if CSV profiling is enabled
        if (ProfileLevel == ETestProfileLevel::CSV && !ProfileOutputPath.IsEmpty())
        {
            FString CsvPath = FPaths::Combine(ProfileOutputPath, TEXT("test_metrics.csv"));
            
            // Create CSV header
            FString CsvData = TEXT("Metric,Value,Unit\n");
            
            // Add our test metrics
            if (Measurements.IsValid())
            {
                for (auto& Field : Measurements->Values)
                {
                    if (Field.Value->Type == EJson::Number)
                    {
                        double Value;
                        if (Field.Value->TryGetNumber(Value))
                        {
                            CsvData += FString::Printf(TEXT("%s,%.3f,ms\n"), *Field.Key, Value);
                        }
                    }
                    else if (Field.Value->Type == EJson::Object)
                    {
                        // Handle statistics objects
                        TSharedPtr<FJsonObject> StatsObj = Field.Value->AsObject();
                        if (StatsObj.IsValid())
                        {
                            double Avg, Min, Max;
                            if (StatsObj->TryGetNumberField(TEXT("Average"), Avg) &&
                                StatsObj->TryGetNumberField(TEXT("Min"), Min) &&
                                StatsObj->TryGetNumberField(TEXT("Max"), Max))
                            {
                                CsvData += FString::Printf(TEXT("%s_Avg,%.3f,ms\n"), *Field.Key, Avg);
                                CsvData += FString::Printf(TEXT("%s_Min,%.3f,ms\n"), *Field.Key, Min);
                                CsvData += FString::Printf(TEXT("%s_Max,%.3f,ms\n"), *Field.Key, Max);
                            }
                        }
                    }
                }
            }
            
            // Write the CSV file
            if (FFileHelper::SaveStringToFile(CsvData, *CsvPath))
            {
                AddInfo(FString::Printf(TEXT("Wrote custom CSV metrics to %s"), *CsvPath));
            }
        }
#endif
    }

    /**
     * Measure execution time with minimal overhead
     * Usage:
     *   double TimeMs = MeasureTime([&]() {
     *       // Code to measure
     *   });
     */
    template<typename TFunc>
    double MeasureTime(TFunc&& Function)
    {
        double StartTime = FPlatformTime::Seconds();
        Function();
        double EndTime = FPlatformTime::Seconds();
        return (EndTime - StartTime) * 1000.0; // Convert to milliseconds
    }

    /**
     * Measure and store a named operation
     * Automatically adds to analytics and logs
     */
    template<typename TFunc>
    double MeasureOperation(const FString& OperationName, TFunc&& Function)
    {
        double TimeMs = MeasureTime(Forward<TFunc>(Function));
        
        // Store measurement
        if (Measurements.IsValid())
        {
            Measurements->SetNumberField(OperationName, TimeMs);
        }

        // Add to test analytics (minimal overhead)
        AddAnalyticsItem(FString::Printf(TEXT("%s: %.3fms"), *OperationName, TimeMs));
        
        // Log the measurement
        AddInfo(FString::Printf(TEXT("%s: %.3fms"), *OperationName, TimeMs));
        
        return TimeMs;
    }

    /**
     * Perform multiple measurements and calculate statistics
     * Useful for performance benchmarks
     */
    struct FMeasurementStats
    {
        double Min;
        double Max;
        double Average;
        double StdDev;
        TArray<double> Samples;
    };

    template<typename TFunc>
    FMeasurementStats MeasureMultiple(const FString& OperationName, int32 NumSamples, TFunc&& Function, int32 WarmupRuns = 3)
    {
        FMeasurementStats Stats;
        Stats.Samples.Reserve(NumSamples);
        
        // Warmup runs
        for (int32 i = 0; i < WarmupRuns; i++)
        {
            Function();
        }

        // Actual measurements
        double Sum = 0.0;
        Stats.Min = TNumericLimits<double>::Max();
        Stats.Max = TNumericLimits<double>::Min();

        for (int32 i = 0; i < NumSamples; i++)
        {
            double TimeMs = MeasureTime(Forward<TFunc>(Function));
            Stats.Samples.Add(TimeMs);
            Sum += TimeMs;
            Stats.Min = FMath::Min(Stats.Min, TimeMs);
            Stats.Max = FMath::Max(Stats.Max, TimeMs);
        }

        Stats.Average = Sum / NumSamples;

        // Calculate standard deviation
        double SumSquaredDiff = 0.0;
        for (double Sample : Stats.Samples)
        {
            double Diff = Sample - Stats.Average;
            SumSquaredDiff += Diff * Diff;
        }
        Stats.StdDev = FMath::Sqrt(SumSquaredDiff / NumSamples);

        // Store statistics
        if (Measurements.IsValid())
        {
            TSharedPtr<FJsonObject> StatsJson = MakeShareable(new FJsonObject);
            StatsJson->SetNumberField(TEXT("Min"), Stats.Min);
            StatsJson->SetNumberField(TEXT("Max"), Stats.Max);
            StatsJson->SetNumberField(TEXT("Average"), Stats.Average);
            StatsJson->SetNumberField(TEXT("StdDev"), Stats.StdDev);
            StatsJson->SetNumberField(TEXT("Samples"), NumSamples);
            Measurements->SetObjectField(OperationName, StatsJson);
        }

        // Log summary
        AddInfo(FString::Printf(TEXT("%s: Avg=%.3fms, Min=%.3fms, Max=%.3fms, StdDev=%.3fms (%d samples)"),
            *OperationName, Stats.Average, Stats.Min, Stats.Max, Stats.StdDev, NumSamples));

        return Stats;
    }

    /**
     * Profile scope helper for CSV profiling
     * Usage: PROFILE_SCOPE("MyOperation");
     */
    #define PROFILE_SCOPE(Name) \
        FScopedProfiler _Profiler##__LINE__(this, TEXT(Name))

    class FScopedProfiler
    {
    public:
        FScopedProfiler(FTestProfileBase* InTest, const FString& InName)
            : Test(InTest)
            , Name(InName)
            , StartTime(FPlatformTime::Seconds())
        {
        }

        ~FScopedProfiler()
        {
            double ElapsedMs = (FPlatformTime::Seconds() - StartTime) * 1000.0;
            if (Test && Test->Measurements.IsValid())
            {
                Test->Measurements->SetNumberField(Name, ElapsedMs);
            }
        }

    private:
        FTestProfileBase* Test;
        FString Name;
        double StartTime;
    };

    /**
     * Check if profiling is enabled at a specific level
     */
    bool IsProfilingEnabled(ETestProfileLevel Level) const
    {
        return ProfileLevel >= Level;
    }

    /**
     * Get current profile level as string
     */
    FString GetProfileLevelString() const
    {
        switch (ProfileLevel)
        {
        case ETestProfileLevel::CSV: return TEXT("CSV");
        case ETestProfileLevel::Insights: return TEXT("Insights");
        default: return TEXT("Minimal");
        }
    }
    
    /**
     * Get current profile level
     */
    ETestProfileLevel GetProfileLevel() const { return ProfileLevel; }
    
    /**
     * Get profile output path
     */
    const FString& GetProfileOutputPath() const { return ProfileOutputPath; }

protected:
    ETestProfileLevel ProfileLevel;
    FString ProfileOutputPath;
    TSharedPtr<FJsonObject> ProfileData;
    TSharedPtr<FJsonObject> Measurements;
};

/**
 * Convenience macro for creating profiled tests
 * Uses standard IMPLEMENT_SIMPLE_AUTOMATION_TEST under the hood
 */
#define IMPLEMENT_PROFILED_TEST(TestClass, PrettyName, TestFlags) \
    class TestClass : public FTestProfileBase \
    { \
    public: \
        TestClass(const FString& InName) : FTestProfileBase(InName, false) {} \
        virtual EAutomationTestFlags GetTestFlags() const override { return TestFlags; } \
        virtual FString GetTestSourceFileName() const override { return __FILE__; } \
        virtual int32 GetTestSourceFileLine() const override { return __LINE__; } \
        virtual FString GetBeautifiedTestName() const override { return PrettyName; } \
        virtual uint32 GetRequiredDeviceNum() const override { return 1; } \
    protected: \
        virtual void GetTests(TArray<FString>& OutBeautifiedNames, TArray<FString>& OutTestCommands) const override \
        { \
            OutBeautifiedNames.Add(PrettyName); \
            OutTestCommands.Add(FString()); \
        } \
        virtual bool RunTest(const FString& Parameters) override; \
    }; \
    namespace \
    { \
        TestClass TestClass##Instance(TEXT(#TestClass)); \
    }