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

/**
* To write a byte to the slave device, this function first checks if the
* multiplexer is already set to the correct address. If it is, it immediately
* calls `_write()`, otherwise it first calls `_setSlave()`
*/
bool I2C::Write(uint8_t data, uint8_t address){
	if(address != currentTarget){
		if(!_setSlave(address)){
			std::cerr << "Did not try to write " << data << " to " << address << std::endl;
			return false;
		}
	}
	return _write(SENSOR_ADDRESS, data);
}

/**
* This function sets the multiplexer to the correct target. It first creates a
* bitmask by using a bitshift. Next, it calls `_write`, and it updates the
* `currentTarget`.
*/
bool I2C::_setSlave(uint8_t target){
	int data = 1 << target; // create bitmask from target number
	if(_write(MULTIPLEXER_ADDRESS, data)){
		currentTarget = target;
		return true;
	}
	std::cerr << "Failed to set slave to " << target << std::endl;
	return false;
}

/**
* This function configures the i2c device file with an i2c address, using the
* `ioctl()` system call. Next, it calls `_writeByte()` to actually write the
* byte.
*/
bool I2C::_write(uint8_t address, uint8_t data){
	if((ioctl(filedescriptor, I2C_SLAVE, address)) < 0)
	{
		std::cerr << "Failed to acquire bus access and/or talk to slave.\n";
		std::cerr << strerror(errno) << std::endl;
		return false;
	}
	return _writeByte(data);
}

/**
* This function writes the data byte to the i2c device file. It first creates a
* two-character buffer containing the data byte and a null character, so that
* the `write()` syscall has a null-terminated string to work with.
*/
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

/**
* This function reads `length` bytes from the i2c device. It should always be
* called after a call to `Write()`, so that a) the multiplexer is configured
* correctly; and b) the slave device is actually about to send data.
*
* First, this function creates a temporary buffer of size `lenght + 1` to store
* the data in. Next, it keeps trying to read data from the i2c device until it
* is successful. Finally, it copies the read data into `buffer`.
*/
bool I2C::Read(uint8_t* buffer, uint8_t length){
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
	return true;
}

bool I2C::Initialize(){
	return true;
}

