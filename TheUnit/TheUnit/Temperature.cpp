#include "Temperature.h"

Temperature::Temperature(iCommunication* communication, uint8_t address) : 
	Communication(communication), Address(address)
{
}

Temperature::~Temperature()
{
}

double Temperature::GetValue()
{

}