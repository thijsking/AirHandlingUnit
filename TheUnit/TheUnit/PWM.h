#ifndef PWM_H
#define PWM_H

#include "iCommunication.h";

class PWM : public iCommunication
{
public:
	PWM(int pin, int initialValue, int pwmRange);
	void Write(int value);
	virtual ~PWM();
private:
	int pin;
};



#endif
