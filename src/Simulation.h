/*
 * Simulation.h
 *
 *  Created on: May 12, 2020
 *      Author: Erik Schafer
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <string>
#include "Disease.h"
#include "Person.h"

class Simulation {
public:
	Person* population;
	int popsize;
	Disease disease;

	Simulation(Disease, int);
	virtual ~Simulation();

	std::string getData();

	void seedDisease(int i0);
	void processDay();

private:
	float getRand();
	int* getRandomIndexes(int, int);
	bool contains(int*, int, int);
};

#endif /* SIMULATION_H_ */
