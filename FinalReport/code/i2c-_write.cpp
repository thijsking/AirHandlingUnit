bool I2C::_write(uint8_t address, uint8_t data){
	if((ioctl(filedescriptor, I2C_SLAVE, address)) < 0)
	{
		std::cerr << "Failed to acquire bus access and/or talk to slave.\n";
		std::cerr << strerror(errno) << std::endl;
		return false;
	}
	return _writeByte(data);
}

