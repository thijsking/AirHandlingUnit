#include "HeatingElement.h"

HeatingElement::HeatingElement(string com) : iActuator()
{
	Initialize(com);
}

HeatingElement::~HeatingElement()
{
}

void HeatingElement::Initialize(string communication)
{
	//initialisatie voor de fan stoppen
	iActuator::Initialize(communication);
}