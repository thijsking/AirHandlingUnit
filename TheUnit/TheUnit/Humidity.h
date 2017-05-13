#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "iSensor.h"

class Humidity : public iSensor
{
public:
	Humidity(string);
	virtual  ~Humidity();
	virtual void Initialize(string);
};




#endif