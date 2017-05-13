#ifndef IACTUATOR_H
#define IACTUATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "PWM.h"
#include "I2C.h"
#include "Serial.h"


using namespace std;

class iCommunication;

class iActuator
{
public:
	iActuator();
	virtual ~iActuator();
	virtual void Initialize(string);
	virtual void SetValue(int);
protected:
	iCommunication *Communication;
};


#endif