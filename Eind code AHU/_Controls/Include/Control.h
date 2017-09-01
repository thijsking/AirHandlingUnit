#ifndef CONTROL_H
#define CONTROL_H

#include <stdio.h>
#include <stdlib.h>
#include <map>

#include "Controller.h"
#include "ControllerBuilder.h"


class Control
{
public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
};


#endif