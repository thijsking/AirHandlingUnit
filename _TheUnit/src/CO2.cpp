#include "CO2.h"

CO2::CO2(iCommunication* communication, uint8_t address) :
	Communication(communication), Address(address)
{
}

CO2::~CO2()
{
}

double CO2::GetValue()
{

}