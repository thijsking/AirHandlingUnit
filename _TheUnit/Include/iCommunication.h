#ifndef ICOMMUNICATION_H
#define ICOMMUNICATION_H

#include <stdio.h>
#include <stdlib.h>

class iCommunication
{
public:
	virtual ~iCommunication() = 0;
	virtual void Initialize() = 0;
	virtual void Write(int) = 0;
	virtual int Read() = 0;
};

#endif
