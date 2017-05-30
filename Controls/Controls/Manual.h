#ifndef MANUAL_H
#define MANUAL_H

#include "Control.h"

class Manual : public Control
{
public:
	Manual();
	virtual ~Manual();
	virtual void InitializeController();
	virtual void Update();
private:
	Controller* Controller;
	ControllerBuilder* Builder;
};

#endif