#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <iostream>

#include "iSensor.h"
#include "iActuator.h"
#include "I2C.h"
#include "PWM.h"
#include "Serial.h"
#include "HeatingElement.h"
#include "CoolingElement.h"
#include "Flaps.h"
#include "Fan.h"
#include "Humidity.h"
#include "Temperature.h"
#include "CO2.h"

/**
* \brief This class handles everything that goes on in the AHU. All the communication to or from the outside goes through this class
*/
class Controller
{
public:
/**
* \brief Construct the Controller object
*/
	Controller();
/**
* \bief Destroy the Controller object
*/
	virtual ~Controller();
/**
* \bief Creates all the sensors and actuators
*/
	virtual void Initialize();
/**
* \bief writes a value the specified actuators
* @param std::string is the name of the actuator to who you want to write the value
* @param uit8_t is the value you write to the actuator
*/
	virtual void SetActuatorValue(std::string,uint8_t); 
/**
* \bief Gets all the sensor values
* @return std::map<std::string,double> is the map where all the values are located. 
	The string is the name of the sensor and the double is the value of the corresponding sensor
*/
	virtual std::map<std::string, double> GetSensorValue();
private:
/**
* \bief All the sensors in the system
*/
	std::map<std::string, iSensor*> SensorMap;
	/**
* \bief All the actuators in the system
*/
	std::map<std::string, iActuator*> ActuatorMap;
};


#endif
