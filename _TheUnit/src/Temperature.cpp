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
	Communication->Write(0xE0, Address);
	uint8_t buffer[2] = {0};
	Communication->Read(buffer, 2);
	int result = (buffer[0] <<8) + buffer[1];
	double temperature = (175.72*result)/65536 - 46.85;
	return temperature;
}
