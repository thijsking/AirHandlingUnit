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
	mController = ControllerBuilder::GetController();
	
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
		WriteActuatorValue("fan");
	}
	if (changed["heating"])
	{
		WriteActuatorValue("heating");
	}
	if (changed["cooling"])
	{
		WriteActuatorValue("cooling");
	}
	if (changed["vents"])
	{
		WriteActuatorValue("vents");
	}

	SettingReader::WriteSensorValues(mController->GetSensorValue());
	LogSensorValues();
}

void Manual::WriteActuatorValue(std::string actuator)
{
	std::map<std::string, int> componentsValue;

	componentsValue = SettingReader::ReadSetings(actuator);
	for (std::map<std::string, int>::const_iterator i = componentsValue.begin(); i != componentsValue.end(); i++)
		mController->SetActuatorValue(i->first, i->second);
		//std::cout << "update " << i->first << "with value " << i->second << std::endl;
}

void Manual::LogSensorValues()
{
	//static std::clock_t startTime = std::clock();
	static std::time_t startTime = std::time(nullptr);
	std::time_t timePassed = std::time(nullptr) - startTime;
	//double timePassed = (std::clock() - startTime) / (double)CLOCKS_PER_SEC;
	if (timePassed > 10.0)
	{
		SettingReader::LogSensorValues(mController->GetSensorValue());
		startTime = std::time(nullptr);
		//startTime = std::clock();
		std::cout << "logging because duration is " << timePassed << std::endl;
	}
}

