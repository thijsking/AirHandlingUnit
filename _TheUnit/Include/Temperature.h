#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "iSensor.h"

class Temperature : public iSensor
{
public:
	Temperature(std::string);
	virtual  ~Temperature();
	virtual void Initialize(std::string);
};




#endif
