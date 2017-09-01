#include "Controller.h"
/**
* Creates the Controller object and calls his Initialize function
*/
Controller::Controller()
{
	Initialize();
}
/**
* Destroy the Controller object
*/
Controller::~Controller()
{
}
/**
* This function creates all the sensors and actuators with there communication method
* After creation they are put in the Actuator- or SensorMap, depending on what they are, so the Controller can find them back to communicate with them
*/
void Controller::Initialize()
{
	iCommunication* i2c = new I2C();
	iCommunication* pwm = new PWM();
	iCommunication* serial = new Serial();
	
	uint8_t pinPwm[] = {0,2,3,4,5};
	(static_cast<PWM*>(pwm))->Initialize(pinPwm, sizeof(pinPwm));
	
	ActuatorMap["fan1"] = new Fan(pwm, 2);
	ActuatorMap["fan2"] = new Fan(pwm, 0);
	ActuatorMap["heating1"] = new HeatingElement(pwm, 4);
	ActuatorMap["heating2"] = new HeatingElement(pwm, 5);
	ActuatorMap["cooling"] = new CoolingElement(pwm, 3);
//	ActuatorMap["vent1"] = new Flaps(pwm, 123);
//	ActuatorMap["vent2"] = new Flaps(pwm, 123);
//	ActuatorMap["vent3"] = new Flaps(pwm, 123);
//	ActuatorMap["vent4"] = new Flaps(pwm, 123);

	SensorMap["CO2-1"] = new CO2(serial, 0x01);
//	SensorMap["CO2-2"] = new CO2(serial, 123);
//	SensorMap["temperature1"] = new Temperature(i2c, 1);
	SensorMap["temperature2"] = new Temperature(i2c, 2);
	SensorMap["temperature3"] = new Temperature(i2c, 3);
	SensorMap["temperature4"] = new Temperature(i2c, 4);
	SensorMap["temperature5"] = new Temperature(i2c, 5);
	SensorMap["temperature6"] = new Temperature(i2c, 6);
	SensorMap["temperature7"] = new Temperature(i2c, 7);
//	SensorMap["temperature8"] = new Temperature(i2c, 8);
//	SensorMap["humidity1"] = new Humidity(i2c, 1);
	SensorMap["humidity2"] = new Humidity(i2c, 2);
	SensorMap["humidity3"] = new Humidity(i2c, 3);
	SensorMap["humidity4"] = new Humidity(i2c, 4);
	SensorMap["humidity5"] = new Humidity(i2c, 5);
	SensorMap["humidity6"] = new Humidity(i2c, 6);
	SensorMap["humidity7"] = new Humidity(i2c, 7);
//	SensorMap["humidity8"] = new Humidity(i2c, 8);

}
/**
* This function sets a value to a specified actuator.
* It searches through the ActuatorMap to find the specified actuator.
* When he finds it, he will call the actuator SetValue function and gives the value as parameter
*/
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
/**
* This function returns all the sensor values.
* It goes one for one through the SensorMap to call the snesors GetValue function. This value is stored in a map with the corresponding sensor name 
*/
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
