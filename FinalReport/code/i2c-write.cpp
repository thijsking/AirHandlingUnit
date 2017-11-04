bool I2C::Write(uint8_t data, uint8_t address){
	if(address != currentTarget){
		if(!_setSlave(address)){
			std::cerr << "Did not try to write " << data << " to " << address << std::endl;
			return false;
		}
	}
	return _write(SENSOR_ADDRESS, data);
}

