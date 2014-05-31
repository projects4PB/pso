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
	double *loc;


public:
	particle(int dim, double seed);
	virtual ~particle();
	double getVelocity();
	double* getLocationArray();
};


#endif /* PARTICLE_H_ */
