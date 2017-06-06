#include "Humidity.h"

Humidity::Humidity(iCommunication* comm, uint8_t address):
	Communication(comm),
	address(address){
}

void Humidity::Initialize(){} //Empty on purpose

double Humidity::GetValue(){
//TODO: use results of bool functions for error checking

	//Measure RH, No-hold master mode
	Communication->writeByte(address, 0xF5);

	//Get result
	uint8_t buffer[2] = {0};
	Communication->read(buffer, 2);

	int result = (buffer[0] <<9) + buffer[1];
	double humidity = (125.0*result)/65536 - 6;
	return humidity;
}
