#ifndef COOLINGELEMENT_H
#define COOLINGELEMENT_H

#include "iActuator.h"

class CoolingElement : public iActuator
{
public:
	CoolingElement(iCommunication*, uint8_t);
	virtual	 ~CoolingElement();
	virtual void SetValue(uint8_t);
private:
	iCommunication* Communication;
	uint8_t Address;
};




#endif