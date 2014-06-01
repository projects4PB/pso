/*
 * particle.h
 *
 *  Created on: 31 maj 2014
 *      Author: darkon
 */
#include "RandomPSO.h"

#ifndef PARTICLE_H_
#define PARTICLE_H_

class particle
{
public:
	double velocity;
	double pbest;
	double *pbestLoc;
	double *loc;
	int dim;


public:
	particle(int dim, RandomPSO *&random);
	double getVelocity();
	double* getLocationArray();
	double getDistance();
	double* getpbestLoc();
	void setpbestLoc();
};


#endif /* PARTICLE_H_ */
