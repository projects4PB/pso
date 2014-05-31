/*
 * particle.cpp
 *
 *  Created on: 31 maj 2014
 *      Author: darkon
 */
#include <iostream>
#include "particle.h"
#include "RandomPSO.h"
#include <cmath>
using namespace std;
particle::particle(int dim, double seed) {
	loc= new double[dim];
	RandomPSO* rand = new RandomPSO(seed);
	for(int i=0;i<dim;i++)
	{
		loc[i]=rand->random();
	}
	this->dim=dim;
}


double particle::getVelocity()
{
	return velocity;
}

double* particle::getLocationArray()
{
//	for(int i=0; i<dim;i++)
//	{
//		cout<<loc[i]<<" ";
//	}
	cout<<endl;
	return loc;
}

double particle::getDistance()
{
	double distance=0;
	for(int i=0;i<dim;i++)
	{
		distance+=pow(loc[i],2);
	}
	return sqrt(distance);
}
