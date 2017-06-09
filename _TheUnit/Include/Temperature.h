#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "iSensor.h"

class Temperature : public iSensor
{
public:
	Temperature(iCommunication*, uint8_t);
	virtual ~Temperature();
	virtual double GetValue();
private:
	iCommunication* Communication;
	uint8_t Address;
};




#endif
