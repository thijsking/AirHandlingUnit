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

