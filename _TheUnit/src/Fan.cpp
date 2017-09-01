#include "Fan.h"
/**
* Create the Fan object and assign the provided parameter data to the corresponding variables.
*/
Fan::Fan(iCommunication* communication, uint8_t address) : iActuator(communication, address)
{
}
/**
* Destroy the Fan object
*/
Fan::~Fan()
{
}
/**
* It first checks if it's a valid value, so between 0 and 100.
* After that it calls the SetValue function of his base class.
*/
void Fan::SetValue(uint8_t value)
{
	if (value < 0)
		value = 0;
	else if (value > 100)
		value = 100;

	iActuator::SetValue(value);
}