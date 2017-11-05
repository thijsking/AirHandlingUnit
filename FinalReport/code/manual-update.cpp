void Manual::Update(){
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

