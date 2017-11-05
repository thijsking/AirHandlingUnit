void Manual::WriteActuatorValue(std::string actuator){
	std::map<std::string, int> componentsValue;

	componentsValue = SettingReader::ReadSetings(actuator);
	for (std::map<std::string, int>::const_iterator i = componentsValue.begin(); i != componentsValue.end(); i++)
		mController->SetActuatorValue(i->first, i->second);
}

