#include "HeatingElement.h"
/**
* Create the HeatingElement object and assign the provided parameter data to the corresponding variables.
*/
HeatingElement::HeatingElement(iCommunication* communication, uint8_t address) : iActuator(communication,address)
{
}
/**
* Destroy the HeatingElement object
*/
HeatingElement::~HeatingElement()
{
}
/**
* It first checks if the value isn't to high, because our setup can't handle that. It also checks if it isn't a negative number.
* After that it calls the SetValue function of his base class.
*/
void HeatingElement::SetValue(uint8_t value)
{
	if (value < 0)
		value = 0;
	else if (value > 30)
		value = 30;

	iActuator::SetValue(value);
}
