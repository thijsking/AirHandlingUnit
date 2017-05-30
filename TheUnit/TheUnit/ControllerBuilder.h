#ifndef CONTROLLERBUILDER_H
#define CONTROLLERBUILDER_H

#include <stdio.h>;
#include <stdlib.h>;
#include "Controller.h";

using namespace std;

class ControllerBuilder
{
public:
	ControllerBuilder();
	virtual ~ControllerBuilder();
	virtual Controller* GetController();
	static void Dispose();
private:
	static Controller* Instance;
};

#endif