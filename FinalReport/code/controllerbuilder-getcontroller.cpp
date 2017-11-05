Controller* ControllerBuilder::GetController()
{
	if (Instance == NULL)
		Instance = new Controller();
	return Instance;
}

