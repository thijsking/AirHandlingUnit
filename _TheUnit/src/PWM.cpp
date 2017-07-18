#include "PWM.h"

// Get useful return values from wiringPi functions. Must be defined before
// including wiringPi.h
#define WIRINGPI_CODES
#include <wiringPi.h>
#include <softPwm.h>

PWM::PWM(){
/* It's okay to call wiringPiSetup more than once:
https://github.com/WiringPi/WiringPi/blob/master/wiringPi/wiringPi.c#L2142-L2151
*/
	if(!wiringPiSetup()){
		//TODO: handle error
	}
}

PWM::~PWM(){}

bool PWM::Initialize(){
	return false; //DO NOT USE
}

/**
* This function loops through all the entries in the pins array, and
* initializes them with WiringPi's `softPwmCreate()` function, using an initial
* value of 0 and a range of 100.
*/
bool PWM::Initialize(uint8_t* pins, size_t size){
	for(uint8_t i = 0; i<size; i++){
		if(softPwmCreate(pins[i], 0, 100)){
			return false;
		}
	}
	return true;
}

/**
* This function uses WiringPi's `softPwmWrite()` function to set a pwm value to
* a pin. Since `softPwmWrite()` has no error checking, this function will
* always return `true`.
*/
bool PWM::Write(uint8_t data, uint8_t address){
	softPwmWrite(address, data);
	return true;
}

bool PWM::Read(uint8_t* buffer, uint8_t length){
	return false;
	//Empty on purpose
}
