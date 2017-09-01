#include "CO2.h"
/**
* Create the CO2 sensor object and assign the provided parameter data to the corresponding variables.
*/
CO2::CO2(iCommunication* communication, uint8_t address) :
	Communication(communication), Address(address)
{
}
/**
* Destroy the CO2 sensor object
*/
CO2::~CO2()
{
}

/**
* This function gets data from the sensor. It first triggers the sensor so that the sensor knows it needs
* to perform a readout and then reads the output of the sensor, storing it into a variable.
* Before storing it in the variable however, the function calculates the parts per million value 
* with the given output.
*/
double CO2::GetValue()
{
	Communication->Write(NULL, Address);

	uint8_t* value = { 0 };
	Communication->Read(value, 9);

	double result = (256 * value[0]) + value[1];
	return result;
}