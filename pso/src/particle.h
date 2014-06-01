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
	double *velocity; //predkosc wielowymiarowa
	double pbest; //najmniejsza odleglosc
	double *pbestLoc; //najlepsza wlasna pozycja
	double *loc; //aktualna pozycja
	int dim;
	int c1, c2;
	double maxVelocity;
	RandomPSO random;


public:
	particle(int dim, double seed);
	double* getVelocity();
	double* getLocationArray();
	double getDistance();
	double* getpbestLoc();
	void setpbestLoc();
	void calculateVelocity(double* gbest);
	void setC1(int c1);
	void setC2(int c2);
	void setMaxVelocity(double MaxVelocity);
};


#endif /* PARTICLE_H_ */
