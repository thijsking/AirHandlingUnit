#ifndef XMLREADER_H
#define XMLREADER_H

#include <fstream>
#include <stdlib.h>
#include <string>
#include <map>
#include "Automatic.h"
#include "Manual.h"

using namespace std;

class SettingReader
{
public:
	static map<string,int> ReadSetings(string);
	static string ReadControlMode();
	static void CheckControlMode(Control*);
	static map<string, bool> CheckChangedSettings();
	static void WriteSensorValues(map < string, int>);
};





#endif // !XMLREADER_H
