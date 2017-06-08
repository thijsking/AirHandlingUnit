#include "Temperature.h"

Temperature::Temperature(std::string com) : iSensor()
{
	Initialize(com);
}

Temperature::~Temperature()
{
}

void Temperature::Initialize(std::string communication)
{
	//initialisatie voor de fan stoppen
	iSensor::Initialize(communication);
}
