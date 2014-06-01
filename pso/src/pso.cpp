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



void generateParticles(RandomPSO *rand)
{
	for(int i=0;i<size;i++)
	{
		particle* temp= new particle(dim, rand);
		czastki.push_back(*temp);
	}
}



int main() {

	dim=5;
	size=10;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	RandomPSO *rand= new RandomPSO(SEED);
	cout << rand->random01()<<endl;
	cout<<"generowanie czastek (odleglosci):"<<endl;

	generateParticles(rand);
	for(int i=0;i<size;i++)
	{
		cout<<czastki[i].getDistance()<<" ";
	}
	cout<<endl;
	return 0;
}




