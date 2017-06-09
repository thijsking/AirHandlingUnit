#ifndef CO2_H
#define CO2_H

#include "iSensor.h"

class CO2 : public iSensor
{
public:
	CO2(iCommunication*, uint8_t);
	virtual  ~CO2();
	virtual double GetValue();
private:
	iCommunication* Communication;
	uint8_t Address;
};




#endif