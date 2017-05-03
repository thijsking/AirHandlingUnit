#ifndef IACTUATOR_H
#define IACTUATOR_H

#include <stdio.h>
#include <stdlib.h>

using namespace std;

class iCommunication;

class iActuator
{
public:
	virtual ~iActuator() = 0;
	virtual void Initialize() = 0;
	virtual void SetValue(int) = 0;
protected:
	iCommunication *Communication;
};



#endif