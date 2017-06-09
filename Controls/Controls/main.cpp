#include <iostream>
#include <Windows.h>
#include "Automatic.h"
#include "Manual.h"
#include "Control.h"
#include "SettingReader.h"

int main()
{
	Control* ControlMode = NULL;
	SettingReader::CreateAFile("mode");

	while (ControlMode == NULL)
	{
		std::string mode = SettingReader::ReadControlMode();
		if (mode == "manual")
			ControlMode = new Manual();
		else if (mode == "automatic")
			ControlMode = new Automatic();
		Sleep(5000);
	}
	std::cout << "mode reconigized" << std::endl;

	while (1)
	{
		SettingReader::CheckControlMode(ControlMode);
		ControlMode->Update();
	}
	
	system("PAUSE");
	return 0;
}
