#ifndef SERIAL_H
#define SERIAL_H

#include "iCommunication.h"

class Serial : public iCommunication
{
public:
	Serial();
	virtual ~Serial();
	virtual bool Initialize();
	virtual bool Write(uint8_t data, uint8_t address);
	virtual bool Read(uint8_t* data, uint8_t length);
};



#endif
