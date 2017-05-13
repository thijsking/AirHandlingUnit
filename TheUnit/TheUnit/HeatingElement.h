#ifndef HEATINGELEMENT_H
#define HEATINGELEMENT_H

#include "iActuator.h"

class HeatingElement : public iActuator
{
public:
	HeatingElement(string);
	virtual	 ~HeatingElement();
	virtual void Initialize(string);
};




#endif