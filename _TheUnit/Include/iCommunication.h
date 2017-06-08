#ifndef ICOMMUNICATION_H
#define ICOMMUNICATION_H

#include <stdio.h>
#include <stdlib.h>
#include <cstdint>

class iCommunication
{
public:
	virtual ~iCommunication() = 0;
	virtual bool Initialize() = 0;
	virtual bool Write(uint8_t data, uint8_t address) = 0;
	virtual bool Read(uint8_t* data, uint8_t length) = 0;
};

inline iCommunication::~iCommunication() {}

#endif
