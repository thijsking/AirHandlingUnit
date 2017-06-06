#include "I2C.h"
#include <fcntl.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <cstring>
#include <iostream>

I2C::I2C(): currentTarget(0x00){
	filedescriptor = open(FILENAME_I2C, O_RDWR);
	if(filedescriptor < 0){
		std::cerr << "Failed to open the i2c bus\n";
		std::cerr << strerror(errno) << std::endl;
	}
}

I2C::~I2C(){
	close(filedescriptor);
	// reset multiplexer?
}

bool I2C::writeByte(uint8_t address, uint8_t data){
	if(address != currentTarget){
		if(!_setSlave(address)){
			std::cerr << "Did not try to write " << data << " to " << address << std::endl;
			return false;
		}
	}
	return _write(address, data);
}

bool I2C::_setSlave(uint8_t target){
	int data = 1 << target; // create bitmask from target number
	if(_write(MULTIPLEXER_ADDRESS, data)){
		currentTarget = target;
		return true;
	}
	std::cerr << "Failed to set slave to " << target << std::endl;
	return false;
}

bool I2C::_write(uint8_t address, uint8_t data){
	if((ioctl(filedescriptor, I2C_SLAVE, address)) < 0)
	{
		std::cerr << "Failed to acquire bus access and/or talk to slave.\n";
		std::cerr << strerror(errno) << std::endl;
		return false;
	}
	return _writeByte(data);
}

bool I2C::_writeByte(uint8_t data){
	uint8_t buffer[2] = {data, 0};
	int length = 1;
	if(write(filedescriptor, buffer, length) != length)
	{
		std::cerr << "Failed to write to the i2c bus.\n";
		std::cerr << strerror(errno) << std::endl;
		return false;
	}
	return true;
}

bool I2C::read(uint8_t* buffer, int length){
	uint8_t tmpbuffer[length + 1] = {0};
	bool success = false;
	while(!success){
		if(read(filedescriptor, tmpbuffer, length+1) != length+1)
		{
			usleep(100);
		}
		else
		{
			success = true;
		}
	}
	memcpy(buffer, tmpbuffer, length);
}
