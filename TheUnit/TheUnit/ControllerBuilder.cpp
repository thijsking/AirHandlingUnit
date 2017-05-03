#include "ControllerBuilder.h"

ControllerBuilder::ControllerBuilder()
{

}

ControllerBuilder::~ControllerBuilder()
{
	Dispose();
}

Controller ControllerBuilder::GetController()
{
	if (Instance == NULL)
		Instance = new Controller();

	return *Instance;
}

Controller ControllerBuilder::BuildController()
{
	// alleen nodig als er meerdere dingen nog moeten worden meegegeven aan de controller
	// nieuwe objecten ofzo
}

void ControllerBuilder::Dispose()
{
	Instance = NULL;
}
