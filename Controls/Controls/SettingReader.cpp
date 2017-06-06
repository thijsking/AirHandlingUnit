#include "SettingReader.h"
#include <iostream>

#define PATH "./config/"

map<string,int> SettingReader::ReadSetings(string component)
{
	map<string, int> mapComponent;
	ifstream file;
	string path = PATH;
	path += component + ".txt";

file.open(path.c_str());
if (file.is_open())
{
	string line;
	while (getline(file, line))
	{
		int comma = line.find(',');
		string name = line.substr(0, comma);
		string valueStr = line.substr(comma + 1);
		int value = atoi(valueStr.c_str());
		mapComponent[name] = value;
		cout << name << ":" << value << endl;
	}
}
file.close();
return mapComponent;
}

string SettingReader::ReadControlMode()
{
	ifstream file;
	string path = PATH;
	path += "mode.txt";

	file.open(path.c_str());
	if (file.is_open())
	{
		string mode;
		getline(file, mode);
		//cout << "mode: " << mode << endl;
		return mode;
	}
	file.close();
}


/**
* checks if the mode in the config file is equel to the current mode
*/
void SettingReader::CheckControlMode(Control* control)
{
	static string currentMode;
	string newMode;

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
		cout << "ERROR: wrong mode type written to the config file" << endl;

}

map<string, bool> SettingReader::CheckChangedSettings()
{
	map<string, bool> changed;
	ifstream file;
	string path = PATH;
	path += "settingChanged.txt";
	bool changedHappend = false;

	file.open(path.c_str());
	if (file.is_open())
	{
		cout << "open" << endl;
		string component;
		while (getline(file, component))
		{
			changed[component] = true;
			changedHappend = true;
		}
		if (changedHappend)
			remove(path.c_str());
	}
	file.close();
	return changed;
}

void SettingReader::WriteSensorValues(map<string, int> sensorValues)
{
	fstream file;
	string path = PATH;
	path += "sensorValues.txt";

	file.open(path.c_str(), fstream::out | fstream::trunc);
	if (file.is_open())
	{
		for (map<string, int>::const_iterator i = sensorValues.begin(); i != sensorValues.end(); i++)
		{
			file << i->first << "," << i->second;
		}
	}
	file.close();
}