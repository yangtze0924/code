#include <REGX52.H>
#include "Key.h"
#include "Delay.h"
#include "Buzzer.h"
#include "Nixie.h"



unsigned char KeyNum;


void main()
{
	Nixie(1,0);
	while(1)
	{
		KeyNum=Key();
		if(KeyNum)
		{	
			Buzzer_Time(100);
			Nixie(1,KeyNum);
		}
	}
}