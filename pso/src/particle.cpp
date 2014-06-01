/*
 * particle.cpp
 *
 *  Created on: 31 maj 2014
 *      Author: darkon
 */


#include <cmath>
#include <iostream>

#include "particle.h"
#include "RandomPSO.h"
using namespace std;

particle::particle(int dim, RandomPSO *&rand) {
	loc= new double[dim];

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
	for(int i=0; i<dim;i++)
	{
		cout<<loc[i]<<" ";
	}
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
double* particle::getpbestLoc()
{
	return loc;
}

void particle::setpbestLoc()
{
	pbestLoc=loc;
}
