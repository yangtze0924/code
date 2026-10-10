#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"


int Result=0;
void main()
{	
	/*	
	LCD_Init();
	Result=1916+1446;
	LCD_ShowChar(1,1,'A');
	LCD_ShowString(1,3,"ZZC");
	LCD_ShowNum(1,7,Result,5);
	LCD_ShowSignedNum(1,13,-27,2);
	LCD_ShowHexNum(2,1,0xFF,2);
	LCD_ShowBinNum(2,4,0xA8,8);
	*/
	LCD_Init();
	while(1)
	{
		Result++;
		Delay(1000);
		LCD_ShowNum(1,1,Result,3);
	}
}