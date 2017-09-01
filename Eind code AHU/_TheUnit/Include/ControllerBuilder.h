#ifndef CONTROLLERBUILDER_H
#define CONTROLLERBUILDER_H

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
/**
* \brief This class is used to get a Controller member from ouside, so everybody is talking to the same Controller, 
*  so to the same actuators and sensors behind it
*/
class ControllerBuilder
{
public:
/**
* \brief Construct a ControllerBuilder object. (unnecessarily)
*/
	ControllerBuilder();
/**
* \brief Destroy the ControllerBuilder object (unnecessarily)
*/
	virtual ~ControllerBuilder();
/**
* \brief Returns a Controller object
* @return Controller* is the Controller object you need to talk to
*/
	static Controller* GetController();
/**
* \brief Empties the Instance
*/
	static void Dispose();
private:
/**
* \brief Static member where the Controller object is stored
*/
	static Controller* Instance;
};

#endif