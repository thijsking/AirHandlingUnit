#include "Manual.h"

Manual::Manual()
{
	//Builder = new ControllerBuilder();
	InitializeController();
}

Manual::~Manual()
{}

void Manual::InitializeController()
{
	//Controller = Builder->GetController();
}

void Manual::Update()
{
	cout << "updating" << endl;
}