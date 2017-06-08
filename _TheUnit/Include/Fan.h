#ifndef FAN_H
#define FAN_H

#include "iActuator.h"

class Fan : public iActuator
{
public:
	Fan(string);
	virtual	 ~Fan();
	virtual void Initialize(string);
};




#endif