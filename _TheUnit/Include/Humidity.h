#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "iSensor.h"

class Humidity : public iSensor
{
public:
	Humidity(iCommunication*, uint8_t);
	virtual  ~Humidity();
	virtual double GetValue();
private:
	iCommunication* Communication;
	uint8_t Address;
};




#endif
