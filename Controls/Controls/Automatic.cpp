#include "Automatic.h"

Automatic::Automatic()
{
	InitializeController();
}

Automatic::~Automatic()
{}

void Automatic::InitializeController()
{

	//mController = ControlBuilder::GetController();
}

void Automatic::Update()
{
	cout << "updating" << endl;
}
