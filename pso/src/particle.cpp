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

particle::particle(int dim, double seed) {
	loc= new double[dim];
	velocity=new double[dim];
	this->random = *new RandomPSO(seed);
	for(int i=0;i<dim;i++)
	{
		loc[i]=this->random.random();
	}

	this->c1=2;
	this->c2=2;
	this->maxVelocity=60;
	this->pbestLoc=loc;
	this->dim=dim;
	this->pbest=getDistance();
}


double* particle::getVelocity()
{
	return velocity;
}

double* particle::getLocationArray()
{
	for(int i=0; i<dim;i++)
	{
		cout<<loc[i]<<"la ";
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

void particle::calculateVelocity(double* gbest)
{
	double t1=0, t2=0;
	for(int i=0;i<dim;i++)
	{
		t1=pbestLoc[i]-loc[i];
		t2=gbest[i]-loc[i];
		velocity[i]+=c1*random.random01()*t1+c2*random.random01()*t2;
		if(velocity[i]>maxVelocity)
		{
			velocity[i]=maxVelocity;
		}
		else if(velocity[i]<-maxVelocity)
		{
			velocity[i]=-maxVelocity;
		}

	}
	for(int i=0;i<dim;i++)
	{
		loc[i]+=velocity[i];
	}

}

void particle::setC1(int c1)
{
	this->c1=c1;
}

void particle::setC2(int c2)
{
	this->c2=c2;
}

void particle::setMaxVelocity(double MaxVelocity)
{
	this->maxVelocity=MaxVelocity;
}
