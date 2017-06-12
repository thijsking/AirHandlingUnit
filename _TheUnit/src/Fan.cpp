#include "Fan.h"

Fan::Fan(iCommunication* communication, uint8_t address) : iActuator(communication, address)
{
}

Fan::~Fan()
{
}

void Fan::SetValue(uint8_t value)
{
	if (value < 0)
		value = 0;
	else if (value > 100)
		value = 100;

	iActuator::SetValue(value);
}