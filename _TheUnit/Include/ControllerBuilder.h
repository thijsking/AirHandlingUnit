#ifndef CONTROLLERBUILDER_H
#define CONTROLLERBUILDER_H

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"

class ControllerBuilder
{
public:
	ControllerBuilder();
	virtual ~ControllerBuilder();
	static Controller* GetController();
	static void Dispose();
private:
	static Controller* Instance;
};

#endif