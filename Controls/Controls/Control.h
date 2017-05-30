#ifndef CONTROL_H
#define CONTROL_H

#include <stdio.h>
#include <stdlib.h>

#include "../../TheUnit/TheUnit/Controller.h"
#include "../../TheUnit/TheUnit/ControllerBuilder.h"

using namespace std;

class Control
{
public:
	virtual void InitializeController() = 0;
	virtual void Update() = 0;
};


#endif