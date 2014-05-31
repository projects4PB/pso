/*
 * particle.h
 *
 *  Created on: 31 maj 2014
 *      Author: darkon
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

class particle {
public:
	double velocity;
	double pbest;
	double *pbestLoc;
	double *loc;
	int dim;


public:
	particle(int dim, double seed);
	double getVelocity();
	double* getLocationArray();
	double getDistance();
	double* getpbestLoc();
	void setpbestLoc();
};


#endif /* PARTICLE_H_ */
