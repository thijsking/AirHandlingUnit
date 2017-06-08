#include "CoolingElement.h"

CoolingElement::CoolingElement(iCommunication* communication, uint8_t address) :
	Communication(communication), Address(address)
{
}

CoolingElement::~CoolingElement()
{
}

void CoolingElement::SetValue(uint8_t)
{

}