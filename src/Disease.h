/*
 * Disease.h
 *
 *  Created on: May 12, 2020
 *      Author: Erik Schafer
 */

#ifndef DISEASE_H_
#define DISEASE_H_

class Disease {
public:
	float rateInfection;
	int daysLatent;
	int daysInfectious;
	Disease(float, int, int);
	virtual ~Disease();
};

#endif /* DISEASE_H_ */
