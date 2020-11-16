#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
int main(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_OSC|SYSCTL_XTAL_8MHZ|SYSCTL_OSC_MAIN);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE,GPIO_PIN_0);
while(1)
{
	GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_0,0);
	SysCtlDelay(1333333);
	GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_0,1);
	SysCtlDelay(1333333);
}
}