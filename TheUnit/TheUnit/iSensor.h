#ifndef ISENSOR_H
#define ISENSOR_H

#include <stdio.h>
#include <stdlib.h>

class iCommunication;

class iSensor
{
public:
	virtual ~iSensor() = 0;
	virtual void Initialize() = 0;
	virtual int GetValue() = 0;
protected:
	iCommunication *Communication;

};

#endif
