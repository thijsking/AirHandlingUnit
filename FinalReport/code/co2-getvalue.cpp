double CO2::GetValue()
{
	Communication->Write(NULL, Address);


	uint8_t* value = { 0 };
	Communication->Read(value, 9);


	double result = (256 * value[0]) + value[1];
	return result;
}

