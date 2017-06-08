#include "Fan.h"

Fan::Fan(string com) : iActuator()
{
	Initialize(com);
}

Fan::~Fan()
{
}

void Fan::Initialize(string communication)
{
	//initialisatie voor de fan stoppen
	iActuator::Initialize(communication);
}