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
	/*ControllerBuilder* builder = new ControllerBuilder();
	mController = builder->GetController();*/
}

void Manual::Update()
{
	map<string, int> componentsValue;
	map<string, bool> changed = SettingReader::CheckChangedSettings();

	if (changed["fan"])
	{
		componentsValue = SettingReader::ReadSetings("fan");
		for (map<string, int>::const_iterator i = componentsValue.begin(); i != componentsValue.end(); i++)
			//mController->SetFanSpeed(i->first, i->second);
			cout << "update " << i->first << "with value " << i->second << endl;
	}
	if (changed["heating"])
	{
		componentsValue = SettingReader::ReadSetings("heating");
		for (map<string, int>::const_iterator i = componentsValue.begin(); i != componentsValue.end(); i++)
			//mController->SetHeatingTemperature(i->first, i->second);
			cout << "update " << i->first << "with value " << i->second << endl;
	}
	if (changed["cooling"])
	{
		componentsValue = SettingReader::ReadSetings("cooling");
		for (map<string, int>::const_iterator i = componentsValue.begin(); i != componentsValue.end(); i++)
			//mController->SetCoolingTemperature(i->first, i->second);
			cout << "update " << i->first << "with value " << i->second << endl;
	}
	if (changed["vents"])
	{
		componentsValue = SettingReader::ReadSetings("vents");
		for (map<string, int>::const_iterator i = componentsValue.begin(); i != componentsValue.end(); i++)
			//mController->SetVentAngle(i->first, i->second);
			cout << "update " << i->first << "with value " << i->second << endl;
	}

	//SettingReader::WriteSensorValues(mController->GetSensorValue());
}

