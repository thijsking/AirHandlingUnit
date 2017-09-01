 #include "Humidity.h"

Humidity::Humidity(iCommunication* comm, uint8_t address):
	Communication(comm), Address(address)
{
}

Humidity::~Humidity(){}

/**
* This function gets the current relative humidity as measured by the sensor.
* It first writes the byte `0xF5` to the sensor, which is the command for
* "Measure Relative Humidity". This starts the measuring process of the sensor,
* after which the data is read back into a buffer. This Read call is blocking
* while the sensor is measuring, which should not take more than a few
* milliseconds.
*
* The received two-byte buffer is turned into an integer, and the relative
* humidity is calculated using the formula from the Si7021 datasheet.
*/
double Humidity::GetValue()
{
	//Measure RH, No-hold master mode
	Communication->Write(0xF5, Address);

	//Get result
	uint8_t buffer[2] = {0};
	Communication->Read(buffer, 2);

	int result = (buffer[0] <<8) + buffer[1];
	double humidity = (125.0*result)/65536 - 6;
	return humidity;
}
