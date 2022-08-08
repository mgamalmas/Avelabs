

#include "GPIO_init.h"
#include "Systick_init.h"

#define CLK	1000000UL	
 void SWPWM_init(uint32_t frequency_kh, uint8_t dutyCycle)
 {
	MSTK_voidInit();
	DIO_init(0, 'A' , OUT);
	MSTK_voidSetIntervalPeriodic(frequency_kh*10,&Status(int),dutyCycle);
 }
void Status (int dutyCycle)
{
	static int i=0;
	if(dutyCycle==i)
	{
	DIO_toggle(0 ,  'A');
	}
	if(i==100)
	{
	i=0;
	DIO_toggle(0 ,  'A');
	}
	i++;

}
void main (void)
{

	while(1)
	{
	}
}
