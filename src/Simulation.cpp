/*
 * Simulation.cpp
 *
 *  Created on: May 12, 2020
 *      Author: Erik Schafer
 */

#include <string>
#include <stdlib.h>
#include "Simulation.h"
#include "Disease.h"
#include "Person.h"

using namespace std;

Simulation::Simulation(Disease disease, int popsize) :
	disease(disease) {
	this->disease = disease;
	this->popsize = popsize;
	this->population = new Person[popsize];
	for(int i = 0; i < popsize; i++) {
		population[i] = *(new Person());
	}
	srand(time(NULL));
}

string Simulation::getData() {
	int S = 0, E = 0, I = 0, R = 0;
	for(int i = 0; i < popsize; i++) {
		Person p = population[i];
		switch(p.state) {
		case Susceptible:
			S++;
			break;
		case Exposed:
			E++;
			break;
		case Infected:
			I++;
			break;
		case Recovered:
			R++;
			break;
		}
	}
	return to_string(S) + "\t" + to_string(E) + "\t" + to_string(I) + "\t" + to_string(R) + "\n";
}

void Simulation::seedDisease(int i0) {
	for(int i = 0; i < i0; i++)
		population[i].state = Infected;
}

void Simulation::processDay() {
	for(int i = 0; i < popsize; i++) {
		Person p = population[i];
		switch(p.state) {
		case Susceptible:
		{
			// find friends to get infected by :)
			int* friendIndxs = getRandomIndexes(popsize, 30);
			for(int j = 0; j < 30; j++) {
				Person fren = population[friendIndxs[j]];
				if(fren.state == Infected && getRand() < disease.rateInfection) {
					population[i].state = Exposed;
				}
			}
			delete [] friendIndxs;
			break;
		}
		case Exposed:
			if(getRand() < (1.0/disease.daysLatent))
				population[i].state = Infected;
			// transition to infected
			break;
		case Infected:
			if(getRand() < (1.0/disease.daysInfectious))
				population[i].state = Recovered;
			// transition to recovered
			break;
		}
	}

}


Simulation::~Simulation() {
	// TODO Auto-generated destructor stub
}

float Simulation::getRand() {
	return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}

int* Simulation::getRandomIndexes(int arraySize, int sampleSize) {
	int* res = new int[sampleSize];
	for(int i = 0; i < sampleSize; i++) {
		res[i] = -1;
	}
	for(int i = 0; i < sampleSize; i++) {
		int candidate = rand() % arraySize;
		while(contains(res, sampleSize, candidate))
			candidate = rand() % arraySize;
		res[i] = candidate;
	}
	return res;
}
bool Simulation::contains(int* arr, int len, int val) {
	for(int i = 0; i < len; i++)
		if(arr[i] == val)
			return true;
	return false;
}

