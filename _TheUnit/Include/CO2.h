#ifndef CO2_H
#define CO2_H

#include "iSensor.h"

class CO2 : public iSensor
{
public:
	CO2(std::string);
	virtual  ~CO2();
	virtual void Initialize(std::string);
};




#endif