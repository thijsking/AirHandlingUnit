#ifndef PWM_H
#define PWM_H

#include "iCommunication.h"

/**
* \brief This class handles all communication with actuators that require a PWM
* signal
*/
class PWM : public iCommunication
{
public:
/**
* \brief Construct the PWM object and initialize WiringPi.
*/
	PWM();
/**
* \brief Destroy the PWM object. The WiringPi library does not have to be
* terminated.
*/
	virtual ~PWM();
/**
* \brief Empty Initialize function, DO NOT USE!
*
* @return always `false`
*/
	virtual bool Initialize();
/**
* \brief Initialize the PWM pins to be used
*
* @param pins An array of the pins (according to the WiringPi numbering scheme)
* that are being used. These range from 0 to 16.
* @param size The size of the `pins` array.
*
* @return `true` on success, `false` on failure
*/
	virtual bool Initialize(uint8_t* pins, size_t size);
/**
* \brief Set a pin to a certain value
*
* @param data The value to write to the pin (0-100%)
* @param address The pin to write the value to.
*
* @return `true` on success, `false` on failure
*/
	virtual bool Write(uint8_t data, uint8_t address);
/**
* \brief Empty on purpose. Not used.
*
* @param buffer Not used.
* @param length Not used.
*
* @return always `false`.
*/
	virtual bool Read(uint8_t* buffer, uint8_t length); //empty
};



#endif
