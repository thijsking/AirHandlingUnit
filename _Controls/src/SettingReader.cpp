#include "SettingReader.h"
#include <iostream>

#define PATH "./config/"

std::map<std::string,int> SettingReader::ReadSetings(std::string component)
{
	std::map<std::string, int> mapComponent;
	std::ifstream file;
	std::string path = PATH;
	path += component + ".txt";

file.open(path.c_str());
if (file.is_open())
{
	std::string line;
	while (getline(file, line))
	{
		int comma = line.find(',');
		std::string name = line.substr(0, comma);
		std::string valueStr = line.substr(comma + 1);
		int value = atoi(valueStr.c_str());
		mapComponent[name] = value;
		std::cout << name << ":" << value << std::endl;
	}
}
file.close();
return mapComponent;
}

std::string SettingReader::ReadControlMode()
{
	std::ifstream file;
	std::string path = PATH;
	path += "mode.txt";

	file.open(path.c_str());
	if (file.is_open())
	{
		std::string mode;
		getline(file, mode);
		//std::cout << "mode: " << mode << std::endl;
		return mode;
	}
	file.close();
}


/**
* checks if the mode in the config file is equel to the current mode
*/
void SettingReader::CheckControlMode(Control* control)
{
	static std::string currentMode;
	std::string newMode;

	newMode = ReadControlMode();
	if (newMode == currentMode)
		return;
	else if (newMode == "manual")
	{
		//delete control;
		control = new Manual();
		currentMode = "manual";
	}
	else if (newMode == "automatic")
	{
		//delete control;
		control = new Automatic();
		currentMode = "automatic";
	}
	else
		std::cout << "ERROR: wrong mode type written to the config file" << std::endl;

}

std::map<std::string, bool> SettingReader::CheckChangedSettings()
{
	std::map<std::string, bool> changed;
	std::ifstream file;
	std::string path = PATH;
	path += "settingChanged.txt";
	bool changedHappend = false;

	file.open(path.c_str());
	if (file.is_open())
	{
		std::string component;
		while (getline(file, component))
		{
			changed[component] = true;
			changedHappend = true;
		}
	}
	file.close();
	if (changedHappend)
	{
		file.open(path.c_str(), std::fstream::out | std::fstream::trunc);
		file.close();
	}
	return changed;
}

void SettingReader::WriteSensorValues(std::map<std::string, int> sensorValues)
{
	std::fstream file;
	std::string path = PATH;
	path += "sensorValues.txt";

	file.open(path.c_str(), std::fstream::out | std::fstream::trunc);
	if (file.is_open())
	{
		for (std::map<std::string, int>::const_iterator i = sensorValues.begin(); i != sensorValues.end(); i++)
		{
			file << i->first << "," << i->second << ";" << std::endl;
		}
	}
	file.close();
}

void SettingReader::LogSensorValues(std::map<std::string, int> sensorValues)
{
	std::fstream file;
	std::string path = PATH;
	std::string date = __TIMESTAMP__;
	path += "log/" + date;

	file.open(path.c_str(), std::fstream::out);
	if (file.is_open())
	{
		for (std::map<std::string, int>::const_iterator i = sensorValues.begin(); i != sensorValues.end(); i++)
		{
			file << i->first << "," << i->second << std::endl;
		}
	}
}

void SettingReader::CreateAFile(std::string fileName)
{
	std::fstream file;
	std::string path = PATH;
	path += fileName + ".txt";

	file.open(path.c_str(), std::fstream::out);
	file.close();
}
