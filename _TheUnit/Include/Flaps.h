#ifndef FLAPS_H
#define FLAPS_H

#include "iActuator.h"

class Flaps : public iActuator
{
public:
	Flaps(string);
	virtual	 ~Flaps();
	virtual void Initialize(string);
};




#endif