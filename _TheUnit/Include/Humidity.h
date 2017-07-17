#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "iSensor.h"

/**
* \brief This class controls a humidity sensor. The current implementation
* assumes a Si7021 sensor connected to a TCA9548 i2c multiplexer. For more
* information on the multiplexer, see the I2C class.
*/
class Humidity : public iSensor
{
public:
/**
* \brief Create a Humidity sensor object, and connect it to the Communication
* device.
*
* @param communication A pointer to the communication object, expected to be an
* I2C object.
* @param address The data line of the multiplexer that this sensor is connected
* to, should be a number from 0 to 7.
*/
	Humidity(iCommunication*, uint8_t);
/**
* \brief Destroys the Humidity sensor object.
*/
	virtual  ~Humidity();
/**
* \brief Get the current humidity as measured by the sensor
*
* @return The relative humidity in percent
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
