class I2C : public iCommunication
{
public:
	I2C();
	virtual ~I2C();
	bool Write(uint8_t data,uint8_t address); //return true on succes
	bool Read(uint8_t* buffer, uint8_t length);
	bool Initialize();
private:
	bool _setSlave(uint8_t address); //return true on succes
	bool _write(uint8_t address, uint8_t data); //return true on succes
	bool _writeByte(uint8_t data);
	int filedescriptor;
	uint8_t currentTarget;
};

