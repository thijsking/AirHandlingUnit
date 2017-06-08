#include "Humidity.h"

Humidity::Humidity(iCommunication* comm, uint8_t address):
	address(address){
	this->Communication = comm;
}

void Humidity::Initialize(){} //Empty on purpose

//TODO: should return double
int Humidity::GetValue(){
//TODO: use results of bool functions for error checking

	//Measure RH, No-hold master mode
	Communication->Write(0xF5, address);

	//Get result
	uint8_t buffer[2] = {0};
	Communication->Read(buffer, 2);

	int result = (buffer[0] <<9) + buffer[1];
	double humidity = (125.0*result)/65536 - 6;
	return humidity;
}