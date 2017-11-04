bool I2C::_setSlave(uint8_t target){
	int data = 1 << target; // create bitmask from target number
	if(_write(MULTIPLEXER_ADDRESS, data)){
		currentTarget = target;
		return true;
	}
	std::cerr << "Failed to set slave to " << target << std::endl;
	return false;
}

