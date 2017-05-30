#include "Automatic.h"

Automatic::Automatic()
{
	//Builder = new ControllerBuilder();
	InitializeController();
}

Automatic::~Automatic()
{}

void Automatic::InitializeController()
{

	//Controller = Builder->GetController();
}

void Automatic::Update()
{
	cout << "updating" << endl;
}
