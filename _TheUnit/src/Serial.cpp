#include "Serial.h"
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

/**
* Create the serial object and execute the `initialize` function.
*/
Serial::Serial() 
{
	Initialize();
}
/**
* Destroy the serial object
*/
Serial::~Serial()
{

}

/**
* This function initializes the serial communication by opening the port and setting all 
* serial parameters to the desired setting. For example, the used baudrate is set to 9600.
*/
bool Serial::Initialize()
{
	uart0_filestream = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY);
	if (uart0_filestream == -1){
		std::cout << "Error - Unable to open UART." << std::endl;
		return false;
	}

	struct termios options;
	tcgetattr(uart0_filestream, &options);
	options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
	options.c_iflag = IGNPAR;
	options.c_oflag = 0;
	options.c_lflag = 0;
	tcflush(uart0_filestream, TCIFLUSH);
	tcsetattr(uart0_filestream, TCSANOW, &options);
	return true;
}

/**
* This function writes data to the opened port. The data is hardcoded at this point but can be changed
* (with some coding) to using the provided `data` variable. The receiver is the component which uses 
* the address that has been provided.
*/
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

/**
* This function reads data from the opened port. When this function is executed, it remains within
* this funcion until data is read out. After data is read, the data is assinged to the pointer variable
* which can be used in the function which executed the read function.
*/
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
