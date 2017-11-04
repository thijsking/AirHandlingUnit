class PWM : public iCommunication
{
public:
	PWM();
	virtual ~PWM();
	virtual bool Initialize();
	virtual bool Initialize(uint8_t* pins, size_t size);
	virtual bool Write(uint8_t data, uint8_t address);
	virtual bool Read(uint8_t* buffer, uint8_t length); //empty
};

