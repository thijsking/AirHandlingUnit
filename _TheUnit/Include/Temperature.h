#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "iSensor.h"

class Temperature : public iSensor
{
public:
	Temperature(string);
	virtual  ~Temperature();
	virtual void Initialize(string);
};




#endif