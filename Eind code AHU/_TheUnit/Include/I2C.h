#ifndef I2C_H
#define I2C_H

#include "iCommunication.h"
#include <cstdint>

/**
* \brief The filename of the i2c device. Depending on your version of the
* Raspberry Pi hardware, this is either /dev/i2c-0 or /dev/i2c-1. Use
* `i2cdetect -l` to find out which one it is.
*/
#define FILENAME_I2C "/dev/i2c-1"
/**
* \brief The i2c address of the multiplexer. This depends on the A2:0 pins of
* the TCA9548A. With A2:0 wired to GND, this is 0x70. With other wiring
* configurations, any value between 0x70 and 0x77 is possible.
*/
#define MULTIPLEXER_ADDRESS 0x70 //depends on A2:0 pins
/**
* \brief The i2c address of the Si7021 sensors.
*/
#define SENSOR_ADDRESS 0x40

/**
* \brief This class handles all communication with the i2c-based temperature
* and humidity sensors. It also deals with configuring the multiplexer.
*/
class I2C : public iCommunication
{
public:
/**
* \brief Create the I2C communicator and open the i2c bus.
*/
	I2C();

/**
* \brief Close the i2c bus and destroy the I2C communicator
*/
	virtual ~I2C();

/**
* \brief Write a byte to one of the i2c devices
*
* @param data The byte to be written
* @param address A number _N_ from 0 to 7, corresponding to which of the i2c
* channels of the multiplexer (SD_N_) the target device is connected to.
*
* @return `true` on success, `false` on failure
*/
	bool Write(uint8_t data,uint8_t address);

/**
* \brief Read bytes from the i2c device. This function blocks until `length`
* bytes have been read.
*
* @param buffer An array to read the data to. At least `length` bytes must be
* available.
* @param length The expected number of bytes to be read from the i2c device.
*
* @return `true` on success, `false` on failure
*/
	bool Read(uint8_t* buffer, uint8_t length);

/**
* \brief Does nothing. Empty on purpoes
*
* @return Always true
*/
	bool Initialize();
private:
/**
* \brief Configure the multiplexer to the correct slave bus
*
* @param address A number _N_ from 0 to 7, corresponding to which of the i2c
* channels of the multiplexer (SD_N_) the target device is connected to.
*
* @return `true` on success, `false` on failure
*/
	bool _setSlave(uint8_t address); //return true on succes

/**
* \brief Write a byte to an i2c slave device
*
* @param address The i2c address of the slave device
* @param data The byte to write
*
* @return `true` on success, `false` on failure
*/
	bool _write(uint8_t address, uint8_t data); //return true on succes

/**
* \brief Actually write the byte
*
* @param data The byte to write
*
* @return `true` on success, `false` on failure
*/
	bool _writeByte(uint8_t data);

/**
* \brief The file descriptor that points to the i2c device file
*/
	int filedescriptor;

/**
* \brief The current target of the i2c multiplexer
*/
	uint8_t currentTarget;
};

#endif

