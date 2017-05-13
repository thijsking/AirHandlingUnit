#ifndef PWM_H
#define PWM_H

#include "iCommunication.h";

class PWM : public iCommunication
{
public:
	PWM();
	virtual ~PWM();
	virtual void Initialize();
	virtual void Write(int);
	virtual int Read();
};



#endif