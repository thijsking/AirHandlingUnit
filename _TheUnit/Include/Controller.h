#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <iostream>
#include "iSensor.h"
#include "iActuator.h"

class Controller
{
public:
	Controller();
	virtual ~Controller();
	virtual void Initialze();
	virtual void SetActuatorValue(std::string,uint8_t);
	virtual std::map<std::string, double> GetSensorValue();
private:
	std::map<std::string, iSensor*> SensorMap;
	std::map<std::string, iActuator*> ActuatorMap;
};


#endif