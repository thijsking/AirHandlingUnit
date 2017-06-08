#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "iSensor.h"

class Humidity : public iSensor
{
public:
	Humidity(iCommunication* comm, uint8_t address);
	virtual  ~Humidity();
	void Initialize();
//TODO should be double
	int GetValue();
private:
	uint8_t address;
};




#endif
