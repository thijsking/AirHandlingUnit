#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdio.h>;
#include <stdlib.h>;

using namespace std;

class Controller
{
public:
	Controller();
	virtual ~Controller();
	virtual void Initialze();
private:
	// list ofzo van alle onderdelen/components
};


#endif