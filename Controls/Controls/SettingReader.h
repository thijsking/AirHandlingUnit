#ifndef XMLREADER_H
#define XMLREADER_H

#include <fstream>
#include <stdlib.h>
#include <string>
#include <map>
#include "Automatic.h"
#include "Manual.h"

class SettingReader
{
public:
	static std::map<std::string,int> ReadSetings(std::string);
	static std::string ReadControlMode();
	static void CheckControlMode(Control*);
	static std::map<std::string, bool> CheckChangedSettings();
	static void WriteSensorValues(std::map < std::string, int>);
	static void LogSensorValues(std::map <std::string, int>);
	static void CreateAFile(std::string);
};





#endif // !XMLREADER_H
