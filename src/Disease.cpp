/*
 * Disease.cpp
 *
 *  Created on: May 12, 2020
 *      Author: Erik Schafer
 */

#include "Disease.h"

Disease::Disease(float rateInfection, int daysLatent, int daysInfectious) {
	this->rateInfection = rateInfection;
	this->daysLatent = daysLatent;
	this->daysInfectious = daysInfectious;
}

Disease::~Disease() {
	// TODO Auto-generated destructor stub
}

