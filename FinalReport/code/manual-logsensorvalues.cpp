void Manual::LogSensorValues(){
	static std::time_t startTime = std::time(nullptr);
	std::time_t timePassed = std::time(nullptr) - startTime;
	if (timePassed > 10.0)
	{
		SettingReader::LogSensorValues(mController->GetSensorValue());
		startTime = std::time(nullptr);
		std::cout << "logging because duration is " << timePassed << std::endl;
	}
}

