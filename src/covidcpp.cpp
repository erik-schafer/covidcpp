//============================================================================
// Name        : covidcpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Simulation.h"

#include <stdlib.h>

using namespace std;



int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Disease covid(0.005, 8, 14);
	Simulation sim(covid, 100000);
	sim.seedDisease(1);
	for(int i = 0; i < 800; i++) {
		sim.processDay();
		cout << sim.getData();
	}
	return 0;
}


