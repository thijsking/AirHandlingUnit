bool Serial::Read(uint8_t* data, uint8_t length)
{
	bool doneReading = false;


	while (!doneReading)
	{
		if (uart0_filestream != -1)
		{
			unsigned char rx_buffer[length];
			int rx_lenght = read(uart0_filestream, (void*)rx_buffer, length);
			if (rx_lenght > 0)
			{
				uint8_t high = (uint8_t)rx_buffer[2];
				uint8_t low = (uint8_t)rx_buffer[3];
				data[0] = high;
				data[1] = low;
				doneReading = true;
			}
		}
	}
	return true;
}

