#ifndef MANUAL_H
#define MANUAL_H

#include "Control.h"
#include <ctime>

class Manual : public Control
{
public:
	Manual();
	virtual ~Manual();
	virtual void InitializeController();
	virtual void Update();
private:
	void LogSensorValues();
	Controller* mController;
};

#endif