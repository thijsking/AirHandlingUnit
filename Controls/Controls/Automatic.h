#ifndef AUTOMATIC_H
#define AUTOMATIC_H

#include "Control.h"

class Automatic : public Control
{
public:
	Automatic();
	virtual ~Automatic();
	virtual void Initialize();
	virtual void Update();
private:
	Controller* mController;
};

#endif