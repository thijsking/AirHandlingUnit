#include "Fan.h"

Fan::Fan(iCommunication* communication, uint8_t address) :
	Communication(communication), Address(address)
{
}

Fan::~Fan()
{
}

void Fan::SetValue(uint8_t value)
{

}