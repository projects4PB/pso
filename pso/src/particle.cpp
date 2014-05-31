/*
 * particle.cpp
 *
 *  Created on: 31 maj 2014
 *      Author: darkon
 */
#include <iostream>
#include "particle.h"
#include "RandomPSO.h"
using namespace std;
particle::particle(int dim, double seed) {
	loc= new double[dim];
	RandomPSO* rand = new RandomPSO(seed);
	for(int i=0;i<dim;i++)
	{
		loc[i]=rand->random();
	}
}

particle::~particle() {
	// TODO Auto-generated destructor stub
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
