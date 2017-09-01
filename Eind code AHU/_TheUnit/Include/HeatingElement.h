#ifndef HEATINGELEMENT_H
#define HEATINGELEMENT_H

#include "iActuator.h"
/**
* \brief This class handles a HeatingElement. 
*/
class HeatingElement : public iActuator
{
public:
/**
* \brief Creates a HeatingElement object.
*
* @param iCommunication* is the type of communication that the actuator uses.
* @param uint8_t Unique address that the specific Cooling element has.
*/
	HeatingElement(iCommunication*, uint8_t);
/**
* Destroy the HeatingElement object
*/
	virtual	 ~HeatingElement();
/**
* /brief Sets a value to the HeatingElement
* 
* @param uint8_t The value to set
*/
	virtual void SetValue(uint8_t);
};




#endif