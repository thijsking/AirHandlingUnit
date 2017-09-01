#ifndef FAN_H
#define FAN_H

#include "iActuator.h"
/**
* \brief This class handles a Fan
*/
class Fan : public iActuator
{
public:
/**
* \brief Construct a Fan object
*
* @param iCommunication* is the type of communication that the Fan uses.
* @param uint8_t Unique address that the specific Fan has.
*/
	Fan(iCommunication*, uint8_t);
/**
* \brief Destroy the Fan object
*/
	virtual	 ~Fan();
/**
* Sets a value to the Fan
*
* @param uint8_t The value to set
*/
	virtual void SetValue(uint8_t);
};




#endif