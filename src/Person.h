/*
 * Person.h
 *
 *  Created on: May 12, 2020
 *      Author: Erik Schafer
 */

#ifndef PERSON_H_
#define PERSON_H_

#include "State.cpp"

class Person {
public:
	State state;
	Person();
	virtual ~Person();
};

#endif /* PERSON_H_ */
