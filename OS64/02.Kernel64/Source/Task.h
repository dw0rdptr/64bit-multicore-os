#ifndef __TASK_H__
#define __TASK_H__

#include "Types.h"
#include "List.h"

// Macro
// SS, RSP, RFLAGS, CS, RIP, 19 register
#define TASK_REGISTERCOUNT		24
#define TASK_REGISTERSIZE		8

// Register offset of Context structure
#define TASK_GSOFFSET		0
#define TASK_FSOFFSET		1
#define TASK_ESOFFSET		2
#define TASK_DSOFFSET		3
#define TASK_R15OFFSET		4
#define TASK_R14OFFSET		5
#define TASK_R13OFFSET		6
#define TASK_R12OFFSET		7
#define TASK_R11OFFSET		8
#define TASK_R1OOFFSET		9
#define TASK_R9OFFSET		10
#define TASK_R8OFFSET		11
#define TASK_RSIOFFSET		12
#define TASK_RDIOFFSET		13
#define TASK_RDXOFFSET		14
#define TASK_RCXOFFSET		15
#define TASK_RBXOFFSET		16
#define TASK_RAXOFFSET		17
#define TASK_RBPOFFSET		18
#define TASK_RIPOFFSET		19
#define TASK_CSOFFSET		20
#define TASK_RFLAGSOFFSET	21
#define TASK_RSPOFFSET		22
#define TASK_SSOFFSET		23

// TCB pool address - after 8MB (size < 1MB)
#define TASK_TCBPOOLADDRESS		0x800000
#define TASK_MAXCOUNT			1024

// Stack pool address - after 8MB + TCB size * TASK_MAXCOUNT (size = TASK_MAXCOUNT * 8KB)
#define TASK_STACKPOOLADDRESS	(TASK_TCBPOOLADDRESS + sizeof(TCB) * TASK_MAXCOUNT)
#define TASK_STACKSIZE			8192
#define TASK_INVALIDID			0xFFFFFFFFFFFFFFFF
// Maximum processor time task can use
#define TASK_PROCESSORTIME		5

// Structure
#pragma pack(push, 1)


typedef struct ContextStruct{
	QWORD vqRegister[TASK_REGISTERCOUNT];
} CONTEXT;


// Control task status
typedef struct TaskControlBlockStruct{
	// Next Node
	LINKEDLIST stLink;

	// Flag
	QWORD qwFlags;

	// Context
	CONTEXT stContext;


	//QWORD qwID;
	//QWORD qwFlags;

	// Address/Size of stack
	void* pvStackAddress;
	QWORD qwStackSize;
} TCB;

// Task pool status manager structure
typedef struct TCBPoolManagerStruct{
	// Task pool info
	TCB* pstStartAddress;
	int iMaxCount;
	int iUseCount;

	// TCB allocated count
	int iAllocatedCount;
} TCBPOOLMANAGER;

// Scheduler status manager structure
typedef struct SchedulerStruct{
	// Running Task
	TCB* pstRunningTask;
	// Processor time task can use
	int iProcessorTime;
	// Task list ready to run
	LIST stReadyList;

} SCHEDULER;


#pragma pack(pop)




// Function
//=================================
//  Task pool / Task
//=================================
void InitializeTCBPool(void);
TCB* AllocateTCB(void);
void FreeTCB(QWORD qwID);
TCB* CreateTask(QWORD qwFlags, QWORD qwEntryPointAddress);
void SetUpTask(TCB* pstTCB, QWORD qwFlags, QWORD qwEntryPointAddress, void* pvStackAddress, QWORD qwStackSize);

//=================================
// Scheduler
//=================================
void InitializeScheduler(void);
void SetRunningTask(TCB* pstTask);
TCB* GetRunningTask(void);
TCB* GetNextTaskToRun(void);
void AddTaskToReadyList(TCB* pstTask);
void Schedule(void);
BOOL ScheduleInInterrupt(void);
void DecreaseProcessorTime(void);
BOOL IsProcessorTimeExpired(void);

#endif /*__TASK_H__*/


