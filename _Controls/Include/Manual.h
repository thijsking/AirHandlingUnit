#ifndef MANUAL_H
#define MANUAL_H

#include "Control.h"
#include <ctime>

class Manual : public Control
{
public:
	Manual();
	virtual ~Manual();
	virtual void Initialize();
	virtual void Update();
private:
	void LogSensorValues();
	void LogSensorValues(std::string);
	Controller* mController;
};

#endif
