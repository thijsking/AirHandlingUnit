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
	static map<string,int> ReadSetings(string);
	static string ReadControlMode();
	static void CheckControlMode(Control*);
	static map<string, bool> CheckChangedSettings();
	static void WriteSensorValues(map < string, int>);
	static void LogSensorValues(map <string, int>);
	static void CreateFile(string);
};





#endif // !XMLREADER_H
