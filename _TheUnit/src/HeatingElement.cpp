#include "HeatingElement.h"

HeatingElement::HeatingElement(iCommunication* communication, uint8_t address) : iActuator(communication,address)
{
}

HeatingElement::~HeatingElement()
{
}

void HeatingElement::SetValue(uint8_t value)
{
	if (value < 0)
		value = 0;
	else if (value > 30)
		value = 30;

	iActuator::SetValue(value);
}
