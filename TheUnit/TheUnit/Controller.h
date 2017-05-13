#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdio.h>;
#include <stdlib.h>;
#include <map>
#include "iSensor.h"
#include "iActuator.h"

using namespace std;

class Controller
{
public:
	Controller();
	virtual ~Controller();
	virtual void Initialze();
private:
	map<string, iSensor*> SensorMap;
	map<string, iActuator*> ActuatorMap;
};


#endif