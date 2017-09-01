#ifndef ISENSOR_H
#define ISENSOR_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "iCommunication.h"


class iCommunication;

/**
* \brief This class is a pure virtual class for the different sensor types. It contains predefined functions that the 
* different sensor types need to use. This to insure consistency between the implementation of the sensors.
*/
class iSensor
{
public:
/**
* \brief Destroy the iSensor object. 
*/
	virtual ~iSensor() = 0;
/**
* \brief Function to get value from a sensor.
*
* @return Data in form of a `double` variable.
*/
	virtual double GetValue() = 0;
};

inline iSensor::~iSensor(){}

#endif 
