#ifndef ISENSOR_H
#define ISENSOR_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "PWM.h"
#include "I2C.h"
#include "Serial.h"

using namespace std;

class iCommunication;

class iSensor
{
public:
	iSensor();
	virtual ~iSensor();
	virtual void Initialize(string);
	virtual int GetValue();
protected:
	iCommunication *Communication;

};



#endif