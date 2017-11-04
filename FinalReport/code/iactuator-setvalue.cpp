void iActuator::SetValue(uint8_t value)
{
	if (!Communication->Write(value, Address))
		std::cerr << "ERROR: writing went wrong" << std::endl;
}

