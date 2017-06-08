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
	virtual ~iActuator() = 0;
	virtual void SetValue(uint8_t) = 0;
};


#endif