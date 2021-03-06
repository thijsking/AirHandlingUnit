#include "CoolingElement.h"

CoolingElement::CoolingElement(iCommunication* communication, uint8_t address) : iActuator(communication, address)
{
}

CoolingElement::~CoolingElement()
{
}

void CoolingElement::SetValue(uint8_t value)
{
	if (value < 0)
		value = 0;
	else if (value > 30)
		value = 30;

	iActuator::SetValue(value);
}
