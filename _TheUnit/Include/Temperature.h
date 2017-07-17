#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "iSensor.h"

/**
* \brief This class controls a temperature sensor. The current implementation
* assumes a Si7021 sensor connected to a TCA9548 i2c multiplexer. For more
* information on the multiplexer, see the I2C class.
*/
class Temperature : public iSensor
{
public:
/**
* \brief Create a Temperature sensor object, and connect it to the
* Communication device.
*
* @param communication A pointer to the communication object, expected to be an
* I2C object.
* @param address The data line of the multiplexer that this sensor is connected
* to, should be a number from 0 to 7.
*/
	Temperature(iCommunication*, uint8_t);
/**
* \brief Destroys the Temperature sensor object.
*/
	virtual ~Temperature();
/**
* \brief Get the current temperature as measured by the sensor
*
* @return The temperature in degrees Celsius
*/
	virtual double GetValue();
private:
/**
* \brief The communication device being used by this sensor
*/
	iCommunication* Communication;
/**
* \brief The data line of the multiplexer that this sensor is connected to
*/
	uint8_t Address;
};




#endif
