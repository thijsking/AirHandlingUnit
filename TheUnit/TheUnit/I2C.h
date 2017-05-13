#ifndef I2C_H
#define I2C_H

#include "iCommunication.h";

class I2C : public iCommunication
{
	
public:
	I2C();
	virtual ~I2C();
	virtual void Initialize();
	virtual void Write(int);
	virtual int Read();
};



#endif