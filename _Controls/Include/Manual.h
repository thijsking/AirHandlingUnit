#ifndef MANUAL_H
#define MANUAL_H

#include "Control.h"
#include <ctime>
#include <vector>

class Manual : public Control
{
public:
	Manual();
	virtual ~Manual();
	virtual void Initialize();
	virtual void Update();
private:
	void LogSensorValues();
	void WriteActuatorValue(std::string);
	Controller* mController;
};

#endif
