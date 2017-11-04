void Fan::SetValue(uint8_t value)
{
	if (value < 0)
		value = 0;
	else if (value > 100)
		value = 100;
	iActuator::SetValue(value);
}

