#include "Automatic.h"

Automatic::Automatic()
{
	InitializeController();
}

Automatic::~Automatic()
{}

void Automatic::InitializeController()
{
	//Controller = ControlBuilder::GetController();
}

void Automatic::Update()
{
	//sensor waardes opvragen en pid regeling uitvoeren hier
}