#include "iActuator.h"
/**
* Create the iActuator object and assign the provided parameter data to the corresponding variables.
*/
iActuator::iActuator(iCommunication* communication, uint8_t address) :
	Communication(communication), Address(address)
{

}
/**
* Destroy the iActuator object
*/
iActuator::~iActuator()
{
}
/**
* Sets a value to the actuator. It calls the specific write command from his communication type with the value to set and his adress as parameters.
* If it goes wrong it will print an error and writes is to the error file.
*/
void iActuator::SetValue(uint8_t value)
{
	if (!Communication->Write(value, Address))
		std::cerr << "ERROR: writing to vents went wrong" << std::endl;
}