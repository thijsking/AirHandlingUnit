#include "Humidity.h"

Humidity::Humidity(string com) : iSensor()
{
	Initialize(com);
}

Humidity::~Humidity()
{
}

void Humidity::Initialize(string communication)
{
	//initialisatie voor de fan stoppen
	iSensor::Initialize(communication);
}