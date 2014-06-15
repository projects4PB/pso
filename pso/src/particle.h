/*
 * particle.h
 *
 *  Created on: 31 maj 2014
 *      Author: darkon
 */
#include "RandomPSO.h"
#include <vector>

#ifndef PARTICLE_H_
#define PARTICLE_H_

class particle
{
public:
	std::vector<double>velocity; //predkosc wielowymiarowa
	double pbest; //najmniejsza odleglosc
	std::vector<double>pbestLoc; //najlepsza wlasna pozycja
	std::vector<double>loc; //aktualna pozycja
	int dim;
	int c1, c2;
	double maxVelocity;
	RandomPSO random;


public:
	particle(int dim, double seed);
	std::vector<double> getVelocity();
	std::vector<double> getLocationArray();
	double getDistance();
	std::vector<double> getpbestLoc();
	void setpbestLoc();
	void calculateVelocity(std::vector<double> gbest);
	void setC1(int c1);
	void setC2(int c2);
	void setMaxVelocity(double MaxVelocity);
};


#endif /* PARTICLE_H_ */
