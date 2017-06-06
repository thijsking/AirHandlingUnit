#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "iSensor.h"

class Humidity : public iSensor
{
public:
	Humidity();
	virtual  ~Humidity();
	void Initialize();
	double GetValue();
private:
	uint8_t address;
};




#endif
