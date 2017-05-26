#ifndef AUTOMATIC_H
#define AUTOMATIC_H

#include "Control.h"
//#include "Conroller.h"

class Automatic : public Control
{
public:
	Automatic();
	virtual ~Automatic();
	virtual void InitializeController();
	virtual void Update();
private:
	//Controller* Controller
};

#endif