double Humidity::GetValue()
{
	//Measure RH, No-hold master mode
	Communication->Write(0xF5, Address);

	//Get result
	uint8_t buffer[2] = {0};
	Communication->Read(buffer, 2);

	int result = (buffer[0] <<8) + buffer[1];
	double humidity = (125.0*result)/65536 - 6;
	return humidity;
}

