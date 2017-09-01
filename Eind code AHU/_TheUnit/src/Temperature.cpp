#include "Temperature.h"

Temperature::Temperature(iCommunication* communication, uint8_t address) : 
	Communication(communication), Address(address)
{
}

Temperature::~Temperature()
{
}

/**
* This function gets the current temperature as measured by the sensor. It
* first writes the byte `0xE0` to the sensor, which is the command for "Read
* Temperature Value from Previous RH Measurement". Since both the temperature
* and humidity should be read regularly, this measurement will probably not be
* very outdated. If you want an up-to-date value instead, change this to
* `0xF3`, or make sure the humidity is measured shortly before the temperature.
*
* Next, the data is read from the communication device into a two-byte buffer.
* This buffer is turned into an integer, and the temperature is calculated
* using the formula from the Si7021 datasheet.
*/
double Temperature::GetValue()
{
	Communication->Write(0xE0, Address);
	uint8_t buffer[2] = {0};
	Communication->Read(buffer, 2);
	int result = (buffer[0] <<8) + buffer[1];
	double temperature = (175.72*result)/65536 - 46.85;
	return temperature;
}
