#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_pwm.h"
#include "driverlib/pwm.h"
int main(void)
{
	//Buoc2:
	SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_OSC|SYSCTL_XTAL_8MHZ|SYSCTL_OSC_MAIN);
	SysCtlPWMClockSet(SYSCTL_PWMDIV_1);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM);
	//Buoc3:
	GPIOPinTypePWM(GPIO_PORTD_BASE,GPIO_PIN_0);
	//Buoc4:
	PWMGenConfigure(PWM_BASE,PWM_GEN_0,PWM_GEN_MODE_DOWN);
	PWMGenPeriodSet(PWM_BASE,PWM_GEN_0,1000);
	PWMPulseWidthSet(PWM_BASE, PWM_OUT_0, 700);
	PWMOutputState(PWM_BASE,PWM_OUT_0_BIT,true);
	PWMGenEnable(PWM_BASE, PWM_GEN_0);
while(1)
{
	PWMPulseWidthSet(PWM_BASE, PWM_OUT_0, 300);
	SysCtlDelay(1333333);
	PWMPulseWidthSet(PWM_BASE, PWM_OUT_0, 500);
	SysCtlDelay(1333333);
	PWMPulseWidthSet(PWM_BASE, PWM_OUT_0, 700);
	SysCtlDelay(1333333);
}
}