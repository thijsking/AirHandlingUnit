#include "Flaps.h"

Flaps::Flaps(iCommunication* communication, uint8_t address) :
	Communication(communication), Address(address)
{
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

	if (!Communication->Write(value, Address))
		std::cout << "ERROR: writing to vents went wrong" << std::endl;
}