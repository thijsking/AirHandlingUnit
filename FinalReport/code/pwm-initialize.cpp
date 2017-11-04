bool PWM::Initialize(uint8_t* pins, size_t size){
	for(uint8_t i = 0; i<size; i++){
		if(softPwmCreate(pins[i], 0, 100)){
			return false;
		}
	}
	return true;
}

