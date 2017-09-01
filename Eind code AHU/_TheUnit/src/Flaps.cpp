#include "Flaps.h"
/**
* Create the Flaps object and assign the provided parameter data to the corresponding variables.
*/
Flaps::Flaps(iCommunication* communication, uint8_t address) : iActuator(communication, address)
{
}
/**
* Destroy the Flaps object
*/
Flaps::~Flaps()
{
}
/**
* It first checks if it's a valid value, so between 0 and 100.
* After that it calls the SetValue function of his base class.
*/
void Flaps::SetValue(uint8_t value)
{
	if (value < 50)
		value = 50;
	else if (value > 170)
		value = 170;

	iActuator::SetValue(value);
}
