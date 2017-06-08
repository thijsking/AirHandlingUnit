#ifndef I2C_H
#define I2C_H

#include "iCommunication.h"
#include <cstdint>

#define FILENAME_I2C "/dev/i2c-1"
#define MULTIPLEXER_ADDRESS 0x70 //depends on A2:0 pins

class I2C : public iCommunication
{
public:
	I2C();
	virtual ~I2C();
	bool writeByte(uint8_t address, uint8_t data); //return true on succes
	bool read(uint8_t* buffer, int length);
private:
	bool _setSlave(uint8_t address); //return true on succes
	bool _write(uint8_t address, uint8_t data); //return true on succes
	bool _writeByte(uint8_t data);
	int filedescriptor;
	uint8_t currentTarget;
};

#endif

