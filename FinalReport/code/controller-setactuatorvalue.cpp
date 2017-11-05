void Controller::SetActuatorValue(std::string name, uint8_t value){
	std::map<std::string, iActuator*>::iterator f(ActuatorMap.find(name));
	if (f != ActuatorMap.end())
	{
		f->second->SetValue(value);
	}
	else
		std::cout << "ERROR: actuator " << name << " doesn't exist" << std::endl;
}

