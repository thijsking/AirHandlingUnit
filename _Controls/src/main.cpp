#include <iostream>
//#include <Windows.h>
#include "Automatic.h"
#include "Manual.h"
#include "Control.h"
#include "SettingReader.h"

int main()
{
	Control* ControlMode = NULL;
	while (ControlMode == NULL)
	{
		string mode = SettingReader::ReadControlMode();
		if (mode == "manual")
			ControlMode = new Manual();
		else if (mode == "automatic")
			ControlMode = new Automatic();
//		Sleep(5000);
	}
	cout << "mode reconigized" << endl;

	while (1)
	{
		SettingReader::CheckControlMode(ControlMode);
		ControlMode->Update();
	}
	
	system("PAUSE");
	return 0;
}
