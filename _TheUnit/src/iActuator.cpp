#include "iActuator.h"

iActuator::iActuator(iCommunication* communication, uint8_t address) :
	Communication(communication), Address(address)
{

}

iActuator::~iActuator()
{
}

void iActuator::SetValue(uint8_t value)
{
	if (!Communication->Write(value, Address))
		std::cerr << "ERROR: writing to vents went wrong" << std::endl;
}