#ifndef FLAPS_H
#define FLAPS_H

#include "iActuator.h"
/**
* \brief This class handles a Flaps
*/
class Flaps : public iActuator
{
public:
/**
* \brief Construct a Flaps object
*
* @param iCommunication* is the type of communication that the Flaps uses.
* @param uint8_t Unique address that the specific Flaps has.
*/
	Flaps(iCommunication*, uint8_t);
/**
* \brief Destroy the Flaps object
*/
	virtual	 ~Flaps();
/**
* Sets a value to the Flaps
*
* @param uint8_t The value to set
*/
	virtual void SetValue(uint8_t);
};




#endif