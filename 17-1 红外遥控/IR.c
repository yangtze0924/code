#include <REGX52.H>
#include "Timer0.h"
#include "Int0.h"

unsigned int IR_Time;
unsigned char IR_State;

unsigned char IR_Data[4];
unsigned char IR_pData;

unsigned char IR_DataFlag;
unsigned char IR_RepeatFlag;
unsigned char IR_Address;
unsigned char IR_Command;



void IR_Init(void)
{
	Timer0_Init();
	Int0_Init();
}


void Int0_Routine(void) interrupt 0 
{
	if(IR_State==0)
	{
		
		Timer0_SetCounter(0);
		Timer0_Run(1);
		IR_State=1;
	}
	else if(IR_State==1)
	{
		IR_Time=Timer0_GetCounter();
		Timer0_SetCounter(0);
		if(IR_Time>14715-500 && IR_Time<14715+500)
		{
			
			IR_State=2;
		}
		else if(IR_Time>12262-500 && IR_Time<12262+500)
		{P2=0;
			IR_RepeatFlag=1;
			Timer0_Run(0);
			IR_State=0;
		}
		else 
		{
			IR_State=1;
		}
	}
}
