#include "ControllerBuilder.h"

Controller* ControllerBuilder::Instance;

ControllerBuilder::ControllerBuilder()
{

}

ControllerBuilder::~ControllerBuilder()
{
	Dispose();
}

Controller* ControllerBuilder::GetController()
{
	if (Instance == NULL)
		Instance = new Controller();

	return Instance;
}

void ControllerBuilder::Dispose()
{
	Instance = NULL;
}
