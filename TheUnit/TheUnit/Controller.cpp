#include "Controller.h"

Controller::Controller()
{
	Initialze();
}

Controller::~Controller()
{
}

void Controller::Initialze()
{

}

void Controller::SetActuatorValue(std::string name, uint8_t value)
{
	std::map<std::string, iActuator*>::iterator f(ActuatorMap.find(name));
	if (f != ActuatorMap.end())
	{
		f->second->SetValue(value);
	}
	else
		std::cout << "ERROR: actuator " << name << " doens't exist" << std::endl;
}

std::map<std::string, double> Controller::GetSensorValue()
{
	std::map<std::string, double> returnMap;

	for (std::map<std::string, iSensor*>::const_iterator i = SensorMap.begin(); i != SensorMap.end(); i++)
	{
		double value = i->second->GetValue();
		returnMap[i->first] = value;
	}

	return returnMap;
}
