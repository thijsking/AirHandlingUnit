#ifndef FAN_H
#define FAN_H

#include "iActuator.h"

class Fan : public iActuator
{
public:
	Fan(iCommunication*, uint8_t);
	virtual	 ~Fan();
	virtual void SetValue(uint8_t);
};




#endif