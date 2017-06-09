#include "Serial.h"
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

Serial::Serial() 
{

}

Serial::~Serial()
{

}

bool Serial::Initialize()
{
	uart0_filestream = open("dev/ttyAMA0", O_RDWR | O_NOCTTY | O_NDELAY);
	if (uart0_filestream == -1)
		std::cout << "Error - Unable to open UART." << std::endl;

	struct termios options;
	tcgetattr(uart0_filestream, &options);
	options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
	options.c_iflag = IGNPAR;
	options.c_oflag = 0;
	options.c_lflag = 0;
	tcflush(uart0_filestream, TCIFLUSH);
	tcsetattr(uart0_filestream, TCSANOW, &options);
}

bool Serial::Write(uint8_t data, uint8_t address)
{

}

bool Serial::Read(uint8_t* data, uint8_t length)
{

}