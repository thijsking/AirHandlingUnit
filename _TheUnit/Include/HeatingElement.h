#ifndef HEATINGELEMENT_H
#define HEATINGELEMENT_H

#include "iActuator.h"

class HeatingElement : public iActuator
{
public:
	HeatingElement(iCommunication*, uint8_t);
	virtual	 ~HeatingElement();
	virtual void SetValue(uint8_t);
private:
	iCommunication* Communication;
	uint8_t Address;
};




#endif