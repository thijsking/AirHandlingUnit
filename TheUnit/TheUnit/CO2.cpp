#include "CO2.h"

CO2::CO2(string com) : iSensor()
{
	Initialize(com);
}

CO2::~CO2()
{
}

void CO2::Initialize(string communication)
{
	//initialisatie voor de fan stoppen
	iSensor::Initialize(communication);
}