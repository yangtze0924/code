#include <REGX52.H>
#include "Delay.h"
#include "MatrixLED.h"

unsigned char code Animation[]={         //加code把程序放在ROM
	0x08,0x1E,0x0E,0xFE,0x1E,0x1E,0x0C,0x00,
	0x08,0x1E,0x0E,0x1E,0x1E,0x1E,0x0C,0x00

};

void main()
{
	unsigned char i,Offset=0,Count=0;
	P2_5=0;
	MatrixLED_Init();
	
	while(1)
	{
		
			for(i=0;i<8;i++)
			{
				MatrixLED_ShowColumn(i,Animation[i+Offset]);
			
			}
			Count++;
			if(Count>20)
			{
				Count=0;
				Offset+=8;
			}
			if(Offset>15)
			{
				Offset=0;
			}
	}
}