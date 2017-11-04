bool Serial::Write(uint8_t data, uint8_t address)
{
	unsigned char txBuffer[20];
	unsigned char *p_tx_buffer;

	p_tx_buffer = &txBuffer[0];
	*p_tx_buffer++ = 0xFF;
	*p_tx_buffer++ = address;
	*p_tx_buffer++ = 0x86;
	*p_tx_buffer++ = 0x00;
	*p_tx_buffer++ = 0x00;
	*p_tx_buffer++ = 0x00;
	*p_tx_buffer++ = 0x00;
	*p_tx_buffer++ = 0x00;
	*p_tx_buffer++ = 0x79;
	
	if (uart0_filestream != -1)
	{
		int count = write(uart0_filestream, &txBuffer, sizeof(txBuffer) - 1);
		if (count < 0)
		{
			std::cerr << "UART TX ERROR" << std::endl;
			std::cerr << "data " << data << " ,adress " << address << std::endl;
			return false;
		}
	}
	return true;
}

