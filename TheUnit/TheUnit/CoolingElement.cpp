#include "CoolingElement.h"

CoolingElement::CoolingElement(string com) : iActuator()
{
	Initialize(com);
}

CoolingElement::~CoolingElement()
{
}

void CoolingElement::Initialize(string communication)
{
	//initialisatie voor de fan stoppen
	iActuator::Initialize(communication);
}