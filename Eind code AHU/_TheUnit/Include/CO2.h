#ifndef CO2_H
#define CO2_H

#include "iSensor.h"

/**
* \brief This class handles a CO2 sensor. Current implementation assumes the use of a Winsen MH-Z19 
* type CO2 sensor. Data that is send to trigger the component is based on the assumed type of sensor.
*/
class CO2 : public iSensor
{
public:
/**
* \brief Construct the CO2 sensor object
*
* @param iCommunication* is the type of communication that the sensor uses.
* @param uint8_t Unique address that the specific sensor has.
*/
	CO2(iCommunication*, uint8_t);
/**
* \brief Destroy the CO2 sensor object. 
*/
	virtual  ~CO2();
/**
* \brief Read data from the sensor.
*
* @return Provided data.
*/
	virtual double GetValue();
private:
/**
* \brief Communication type 
*/
	iCommunication* Communication;
/**
* \brief Unique address to approach sensor
*/
	uint8_t Address;
};




#endif