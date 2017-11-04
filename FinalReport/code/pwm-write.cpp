bool PWM::Write(uint8_t data, uint8_t address){
	softPwmWrite(address, data);
	return true;
}

