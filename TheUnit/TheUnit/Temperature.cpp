#include "Temperature.h"

Temperature::Temperature(string com) : iSensor()
{
	Initialize(com);
}

Temperature::~Temperature()
{
}

void Temperature::Initialize(string communication)
{
	//initialisatie voor de fan stoppen
	iSensor::Initialize(communication);
}