#include "Flaps.h"

Flaps::Flaps(string com) : iActuator()
{
	Initialize(com);
}

Flaps::~Flaps()
{
}

void Flaps::Initialize(string communication)
{
	//initialisatie voor de fan stoppen
	iActuator::Initialize(communication);
}