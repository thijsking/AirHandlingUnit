#include "HeatingElement.h"

HeatingElement::HeatingElement(iCommunication* communication, uint8_t address) :
	Communication(communication), Address(address)
{
}

HeatingElement::~HeatingElement()
{
}

void HeatingElement::SetValue(uint8_t)
{

}