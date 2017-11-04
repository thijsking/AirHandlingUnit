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

