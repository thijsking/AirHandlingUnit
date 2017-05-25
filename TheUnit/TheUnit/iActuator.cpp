#include "iActuator.h"

iActuator::iActuator()
{

}

iActuator::~iActuator()
{
}

void iActuator::Initialize(string communication)
{
	if (communication == "Serial")
		Communication = new Serial();
	else if (communication == "I2C")
		Communication = new I2C();
	else if (communication == "PWM")
		Communication = new PWM();
	else
		cout << "ERROR Wrong communication method used" << endl;
}