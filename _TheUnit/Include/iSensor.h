#ifndef ISENSOR_H
#define ISENSOR_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "iCommunication.h"

class iCommunication;

class iSensor
{
public:
	virtual ~iSensor() = 0;
	virtual double GetValue() = 0;
};

#endif 
