#ifndef COOLINGELEMENT_H
#define COOLINGELEMENT_H

#include "iActuator.h"

class CoolingElement : public iActuator
{
public:
	CoolingElement(string);
	virtual	 ~CoolingElement();
	virtual void Initialize(string);
};




#endif