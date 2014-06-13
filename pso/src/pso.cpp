//============================================================================
// Name        : pso.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <vector>
#include <iostream>
//#include <mpi.h>
#include "RandomPSO.h"
#include "particle.h"
#include "pso.h"
using namespace std;
vector<particle> czastki;

int dim;
int size;
int iterations;
double* gbest;
int naj;
double minDistance;

void generateParticles(RandomPSO *rand)
{
	for(int i=0;i<size;i++)
	{
		particle* temp= new particle(dim, rand->random());
		czastki.push_back(*temp);
	}
}



int main() {

	dim=10;
	size=500;
	iterations=500;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	RandomPSO *rand= new RandomPSO(SEED);
	//cout << rand->random01()<<endl;
	cout<<"generowanie czastek (odleglosci):"<<endl;

	generateParticles(rand);

	gbest=czastki[0].getLocationArray();
	minDistance=czastki[0].getDistance();
	for(int i=0;i<size;i++)
	{
		if(czastki[i].getDistance()<minDistance || i==0)
		{
			//cout<<minDistance<<" na "<<czastki[i].getDistance()<<endl;
			gbest=czastki[i].getLocationArray();
			minDistance=czastki[i].getDistance();
			cout<<czastki[i].getDistance()<<" "<<endl;
		}
	}
cout<<endl;
	for(int i=0; i<iterations;i++)
	{
		for(int j=0;j<size;j++)
		{
			czastki[j].calculateVelocity(gbest);
		}

		for(int j=0;j<size;j++)
		{
			//cout<<czastki[j].getDistance()<<" od ";
			if(czastki[j].getDistance()<minDistance)
			{
				double temp=minDistance;
				minDistance=czastki[j].getDistance();
				naj=j;
				gbest=czastki[j].getLocationArray();
				cout<<temp<<" "<<minDistance<<" zmiana"<<endl;
			}
		}
		cout<<minDistance<<endl;
//		for(int j=0;j<dim;j++)
//		{
//			cout<<gbest[j]<<" ";
//		}
//		cout<<"wymiary najlepszej "<<"odleglosc "<<czastki[naj].getDistance()<<endl;
	}

	cout<<"rozwiazanie"<<endl;
	for(int i=0; i<dim;i++)
	{
		cout<<gbest[i]<<" ";
	}
	cout<<endl<<"odleglosc "<<minDistance<<endl;
	return 0;
}




