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

