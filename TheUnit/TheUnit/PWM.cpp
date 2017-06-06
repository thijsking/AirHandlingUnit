#include "PWM.h"

// Get useful return values from wiringPi functions. Must be defined before
// including wiringPi.h
#define WIRINGPI_CODES
#include <wiringPi.h>
#include <softPwm.h>

PWM::PWM(int pin, int initialValue, int pwmRange): pin(pin) {
/* It's okay to call wiringPiSetup more than once:
https://github.com/WiringPi/WiringPi/blob/master/wiringPi/wiringPi.c#L2142-L2151
*/
	if(!wiringPiSetup()){
		//TODO: handle error
	}
	if(!softPwmCreate(pin, initialValue, pwmRange)){
		//TODO: handle error (use errno)
	}
}

void PWM::Write(int value){
	softPwmWrite(pin, value);
}
