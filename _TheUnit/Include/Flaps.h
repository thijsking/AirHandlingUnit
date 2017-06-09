#ifndef FLAPS_H
#define FLAPS_H

#include "iActuator.h"

class Flaps : public iActuator
{
public:
	Flaps(iCommunication*, uint8_t);
	virtual	 ~Flaps();
	virtual void SetValue(uint8_t);
};




#endif