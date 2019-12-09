#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include "Types.h"


// Macro
// Video memory attribute

#define CONSOLE_BACKGROUND_BLACK			0x00
#define CONSOLE_BACKGROUND_BLUE				0x10
#define CONSOLE_BACKGROUND_GREEN			0x20
#define CONSOLE_BACKGROUND_CYAN				0x30
#define CONSOLE_BACKGROUND_RED				0x40
#define CONSOLE_BACKGROUND_MAGENTA			0x50
#define CONSOLE_BACKGROUND_BROWN			0x60
#define CONSOLE_BACKGROUND_WHITE			0x70
#define CONSOLE_BACKGROUND_BLINK			0x80
#define CONSOLE_FOREGROUND_DARKBLACK		0x00
#define CONSOLE_FOREGROUND_DARKBLUE			0x01
#define CONSOLE_FOREGROUND_DARKGREEN		0x02
#define CONSOLE_FOREGROUND_DARKCYAN			0x03
#define CONSOLE_FOREGROUND_DARKRED			0x04
#define CONSOLE_FOREGROUND_DARKMAGENTA		0x05
#define CONSOLE_FOREGROUND_DARKBROWN		0x06
#define CONSOLE_FOREGROUND_DARKWHITE		0x07
#define CONSOLE_FOREGROUND_BRIGHTBLACK		0x08
#define CONSOLE_FOREGROUND_BRIGHTBLUE		0x09
#define CONSOLE_FOREGROUND_BRIGHTGREEN		0x0A
#define CONSOLE_FOREGROUND_BRIGHTCYAN		0x0B
#define CONSOLE_FOREGROUND_BRIGHTRED		0x0C
#define CONSOLE_FOREGROUND_BRIGHTMAGENTA	0x0D
#define CONSOLE_FOREGROUND_BRIGHTYELLOW		0x0E
#define CONSOLE_FOREGROUND_BRIGHTWITE		0x0F

// Default text color
#define CONSOLE_DEFAULTTEXTCOLOR			(CONSOLE_BACKGROUND_BLACK | CONSOLE_FOREGROUND_DARKWHITE)

#define CONSOLE_WIDTH				80
#define CONSOLE_HEIGHT				25
#define CONSOLE_VIDEOMEMORYADDRESS	0xB8000

// Video controller I/O port address/register
#define VGA_PORT_INDEX			0x3D4
#define VGA_PORT_DATA			0x3D5
#define VGA_INDEX_UPPERCURSOR	0x0E
#define VGA_INDEX_LOWERCURSOR	0x0F

// Structure
#pragma pack(push,1)

typedef struct ConsoleManagerStruct{
	int CurrentPrintOffset;
} CONSOLEMANAGER;

#pragma pack(pop)

// Function
void InitializeConsole(int X, int Y);
void SetCursor(int X, int Y);
void GetCursor(int *pX, int *pY);
void Printf(const char* pcFormatString, ...);
int ConsolePrintString(const char* pcBuffer);
void ClearScreen(void);
BYTE GetCh(void);
void PrintStringXY(int X, int Y, const char* pcString);


#endif /*__CONSOLE_H__*/