#ifndef SERIAL_H
#define SERIAL_H

#include "iCommunication.h"

/**
* \brief This class handles all communication with components that require serial
* communication.
*/
class Serial : public iCommunication
{
public:
/**
* \brief Construct the serial object.
*/
	Serial();
/**
* \brief Destroy the serial object. 
*/
	virtual ~Serial();
/**
* \brief Initialization for serial communication, gets executed automaticly when constructing
* the serial object
*
* @return `false` the initialization goes wrong, `true` when everything is OK
*/
	virtual bool Initialize();
/**
* \brief Write data to the receiving component
*
* @param data Not used, added for future uasge. When in use: used for passing on desired data to be send.
* @param address Serial address used to specify which component is the receiver.
*
* @return `true` on success, `false` on failure
*/
	virtual bool Write(uint8_t data, uint8_t address);
/**
* \brief Read data
*
* @param data* Pointer variable to the data. Will contain received data when reading is finished.
* @param length Specify the length of data to be read.
*
* @return always `true`, will remain within function until something is received.
*/
	virtual bool Read(uint8_t* data, uint8_t length);
private:
	int uart0_filestream = -1;
};



#endif
