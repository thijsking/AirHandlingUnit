#include "Manual.h"
#include "SettingReader.h"

Manual::Manual()
{
	Initialize();
}

Manual::~Manual()
{}

void Manual::Initialize()
{
	// mController = ControllerBuilder::GetController();
	
	std::vector<std::string> fileNames = { "cooling","fan","vents","settingChanged","heating" };
	for (int i = 0; i < fileNames.size(); i++)
	{
		SettingReader::CreateAFile(fileNames[i]);
	}
}

void Manual::Update()
{
	std::map<std::string, bool> changed = SettingReader::CheckChangedSettings();

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

void Manual::LogSensorValues(std::string actuator)
{
	std::map<std::string, int> componentsValue;

	componentsValue = SettingReader::ReadSetings(actuator);
	for (std::map<std::string, int>::const_iterator i = componentsValue.begin(); i != componentsValue.end(); i++)
		//mController->SetActuatorValue(i->first, i->second);
		std::cout << "update " << i->first << "with value " << i->second << std::endl;
}

void Manual::LogSensorValues()
{
	static std::clock_t startTime = std::clock();
	
	double timePassed = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
	if (timePassed > 10.0)
	{
		//SettingReader::LogSensorValues(mController->GetSensorValue);
		startTime = std::clock();
		std::cout << "logging because duration is " << timePassed << std::endl;
	}
}

