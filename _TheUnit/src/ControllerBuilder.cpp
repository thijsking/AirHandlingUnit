#include "ControllerBuilder.h"

Controller* ControllerBuilder::Instance;
/**
* Creates a ControllerBuilder object
*/
ControllerBuilder::ControllerBuilder()
{

}
/**
* Destroy the ControllerBuilder object and clears the Instance with the Dispose function
*/
ControllerBuilder::~ControllerBuilder()
{
	Dispose();
}
/**
* Returns a Controller object. It first checks the Instace if there is not already a Controller object. 
* If not, it will create a Controller object, stores this one in the Instance and returns it. In this way everybody talks to the same
* Controller, so to the same sensors and actuators behind it.
*/
Controller* ControllerBuilder::GetController()
{
	if (Instance == NULL)
		Instance = new Controller();

	return Instance;
}
/**
* Sets the Instace back to NULL, so clears the Instance.
*/
void ControllerBuilder::Dispose()
{
	Instance = NULL;
}
