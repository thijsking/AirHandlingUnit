#ifndef COOLINGELEMENT_H
#define COOLINGELEMENT_H

#include "iActuator.h"
/**
* \brief This class handles a CoolingElement. 
*/
class CoolingElement : public iActuator
{
public:
/**
* \brief Creates a CoolingElement object.
*
* @param iCommunication* is the type of communication that the actuator uses.
* @param uint8_t Unique address that the specific Cooling element has.
*/
	CoolingElement(iCommunication*, uint8_t);
/**
* Destroy the CoolingElement object
*/
	virtual	 ~CoolingElement();
/**
* /brief Sets a value to the CoolingElement
* 
* @param uint8_t The value to set
*/
	virtual void SetValue(uint8_t);
};




#endif