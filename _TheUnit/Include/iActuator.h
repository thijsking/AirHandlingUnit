#ifndef IACTUATOR_H
#define IACTUATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "iCommunication.h"
class iCommunication;

class iActuator
{
public:
	iActuator(iCommunication*, uint8_t);
	virtual ~iActuator();
	virtual void SetValue(uint8_t);
protected:
	iCommunication* Communication;
	uint8_t Address;
};


#endif