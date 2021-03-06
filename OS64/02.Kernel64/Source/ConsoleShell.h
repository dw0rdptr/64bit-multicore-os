#ifndef __CONSOLESHELL_H__
#define __CONSOLESHELL_H__

#include "Types.h"
#include "List.h"

#define CONSOLESHELL_MAXCOMMANDBUFFERCOUNT	100
#define CONSOLESHELL_PROMPTMESSAGE			"OSLAKE$ "

// Define Function pointer type
typedef void (* CommandFunction)(const char* pcParameter);

#pragma pack(push,1)

typedef struct ShellCommandEntryStruct{
	char* pcCommand;
	char* pcHelp;
	CommandFunction pfFunction;
}SHELLCOMMANDENTRY;

typedef struct ParameterListStruct{
	const char* pcBuffer;
	int Length;
	int CurrentPosition;
}PARAMETERLIST;

typedef struct CommandHistory{
	LINKEDLIST stLink;

	char pcCommand[CONSOLESHELL_MAXCOMMANDBUFFERCOUNT];
} COMMANDHISTORY;

#pragma pack(pop)

void StartConsoleShell(void);
void ExecuteCommand(const char* pcCommandBuffer);
void InitializeParameter(PARAMETERLIST* pstList, const char* pcParameter);
int GetNextParameter(PARAMETERLIST* pstList, char* pcParameter);


// Shell command function
static void Echo(const char* pcParameterBuffer);
static int AutoComplete(const char* pcCommandBuffer);
static void* PrintPreviousCommand(const char* pcCommandBuffer, void* pstCurrent, BYTE bKey, int BufferIndex);

static void Help(const char* pcParameterBuffer);
static void Clear(const char* pcParameterBuffer);
static void ShowTotalMemorySize(const char* pcParameterBuffer);
static void StringToDecimalHex(const char* pcParameterBuffer);
static void Shutdown(const char* pcParameterBuffer);
static void SetTimer(const char* pcParameterBuffer);
static void WaitUsingPIT(const char* pcParameterBuffer);
static void ReadTimeStampCounter(const char* pcParameterBuffer);
static void MeasureProcessorSpeed(const char* pcParameterBuffer);
static void ShowDateAndTime(const char* pcParameterBuffer);
static void TestTask1(void);
static void TestTask2(void);
static void CreateTestTask(const char* pcParameterBuffer);
static void ChangeTaskPriority(const char* pcParameterBuffer);
static void ShowTaskList(const char* pcParameterBuffer);
static void KillTask(const char* pcParameterBuffer);
static void CPULoad(const char* pcParameterBuffer);
static void TestMutex(const char* pcParameterBuffer);
static void CreateThreadTask(void);
static void TestThread(const char* pcParameterBuffer);
static void TestPIE(const char* pcParameterBuffer);
static void ShowDynamicMemoryInfo(const char* pcParameterBuffer);
static void TestSequentialAllocation(const char* pcParameterBuffer);
static void TestRandomAllocation(const char* pcParameterBuffer);
static void RandomAllocationTask(void);
static void ShowHDDInformation(const char* pcParameterBuffer);
static void ReadSector(const char* pcParameterBuffer);
static void WriteSector(const char* pcParameterBuffer);
static void ShowCommandHistory(const char* pcParameterBuffer);


#endif /*__CONSOLESHELL_H__*/
