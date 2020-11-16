#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
int dem=0;
int main(void)
{
SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_OSC|SYSCTL_XTAL_8MHZ|SYSCTL_OSC_MAIN);
SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
GPIOPinTypeGPIOInput(GPIO_PORTA_BASE ,GPIO_PIN_0);
GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE ,GPIO_PIN_0);
GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE ,GPIO_PIN_1);
GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE ,GPIO_PIN_2);
GPIOPadConfigSet(GPIO_PORTA_BASE ,GPIO_PIN_0,GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_STD_WPU);
while(1)
{
	if(GPIOPinRead(GPIO_PORTA_BASE ,GPIO_PIN_0)==0)
	{
		while(GPIOPinRead(GPIO_PORTA_BASE ,GPIO_PIN_0)==0);
		dem++;
	}
	if(dem==0)
	{
		GPIOPinWrite(GPIO_PORTD_BASE ,GPIO_PIN_0,0);
		GPIOPinWrite(GPIO_PORTD_BASE ,GPIO_PIN_1,0);
		GPIOPinWrite(GPIO_PORTD_BASE ,GPIO_PIN_2,0);
	}
	else if(dem==1)
	{
		GPIOPinWrite(GPIO_PORTD_BASE ,GPIO_PIN_0,1);
		GPIOPinWrite(GPIO_PORTD_BASE ,GPIO_PIN_1,0);
		GPIOPinWrite(GPIO_PORTD_BASE ,GPIO_PIN_2,0);
	}
	else if(dem==2)
	{
		GPIOPinWrite(GPIO_PORTD_BASE ,GPIO_PIN_1,2);
		GPIOPinWrite(GPIO_PORTD_BASE ,GPIO_PIN_0,0);
		GPIOPinWrite(GPIO_PORTD_BASE ,GPIO_PIN_2,0);
	}
	else if(dem==3)
	{
		GPIOPinWrite(GPIO_PORTD_BASE ,GPIO_PIN_2,4);
		GPIOPinWrite(GPIO_PORTD_BASE ,GPIO_PIN_0,0);
		GPIOPinWrite(GPIO_PORTD_BASE ,GPIO_PIN_1,0);
	}
	else if(dem>3)
	{
		dem=0;
	}
}
}