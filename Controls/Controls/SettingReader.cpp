#include "SettingReader.h"
#include <iostream>

#define PATH "./config/"

void SettingReader::ReadFanSetings()
{
	map<string, int> fans;
	ifstream file;
	string path = PATH;
	path += "fan.txt";
	cout << path << endl;

	try
	{
		file.open(path.c_str());
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				int comma = line.find(',');
				string fanName = line.substr(0, comma);
				string speedStr = line.substr(comma + 1);
				int speed = atoi(speedStr.c_str());
				fans[fanName] = speed;
				cout << fanName << ":" << speed << endl;
			}
		}
	}
	catch (exception)
	{
		 cout << "ERROR: no config file found" << endl;
	}
}