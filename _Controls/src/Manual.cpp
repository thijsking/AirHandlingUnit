#include "Manual.h"
#include "SettingReader.h"

Manual::Manual()
{
	InitializeController();
}

Manual::~Manual()
{}

void Manual::InitializeController()
{
	// mController = ControllerBuilder::GetController();
}

void Manual::Update()
{
	map<string, bool> changed = SettingReader::CheckChangedSettings();

	if (changed["fan"])
	{
		LogSensorValues("fan");
	}
	if (changed["heating"])
	{
		LogSensorValues("heating");
	}
	if (changed["cooling"])
	{
		LogSensorValues("cooling");
	}
	if (changed["vents"])
	{
		LogSensorValues("vents");
	}

	//SettingReader::WriteSensorValues(mController->GetSensorValue());
	LogSensorValues();
}

void Manual::LogSensorValues(string actuator)
{
	map<string, int> componentsValue;

	componentsValue = SettingReader::ReadSetings(actuator);
	for (map<string, int>::const_iterator i = componentsValue.begin(); i != componentsValue.end(); i++)
		//mController->SetActuatorValue(i->first, i->second);
		cout << "update " << i->first << "with value " << i->second << endl;
}

void Manual::LogSensorValues()
{
	static std::clock_t startTime = std::clock();
	
	double timePassed = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
	if (timePassed > 10.0)
	{
		//SettingReader::LogSensorValues(mController->GetSensorValue);
		startTime = std::clock();
		cout << "logging because duration is " << timePassed << endl;
	}
}

