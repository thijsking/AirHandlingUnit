#include "Automatic.h"
#include "Manual.h"
#include "Control.h"
#include "SettingReader.h"

int main()
{
	SettingReader::ReadFanSetings();

	system("PAUSE");
	return 0;
}