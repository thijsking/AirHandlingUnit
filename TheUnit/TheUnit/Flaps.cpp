#include "Flaps.h"

Flaps::Flaps(iCommunication* communication, uint8_t address) : iActuator(communication, address)
}

Flaps::~Flaps()
{
}

void Flaps::SetValue(uint8_t value)
{
	if (value < 50)
		value = 50;
	else if (value > 170)
		value = 170;

	iActuator::SetValue(value);
}