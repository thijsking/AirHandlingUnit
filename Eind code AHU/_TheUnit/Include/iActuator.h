#ifndef IACTUATOR_H
#define IACTUATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "iCommunication.h"
class iCommunication;
/**
* \brief This is the base class for all the Actuators
*/
class iActuator
{
public:
/**
* \brief Construt a iActuator object.
*
* @param iCommunication* is the type of communication that the actuator uses.
* @param uint8_t Unique address that the specific actuator has.
*/
	iActuator(iCommunication*, uint8_t);
/**
* \brief Destroy the iActuator object
*/
	virtual ~iActuator();
/**
* \brief Set a value to the actuator
*
* @param uint8_t the value to set
*/
	virtual void SetValue(uint8_t);
protected:
/**
* \brief The communication type the acuator uses
*/
	iCommunication* Communication;
/**
* \brief Unique address that the specific actuator has.
*/
	uint8_t Address;
};


#endif