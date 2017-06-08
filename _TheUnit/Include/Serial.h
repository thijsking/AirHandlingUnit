#ifndef SERIAL_H
#define SERIAL_H

#include "iCommunication.h"

class Serial : public iCommunication
{
public:
	Serial();
	virtual ~Serial();
	virtual void Initialize();
	virtual void Write(int);
	virtual int Read();
};



#endif