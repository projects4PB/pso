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
particle *czastki;
int dim;
int size;
RandomPSO *rand;


void generateParticles()
{
	cout<<"pokaz co tam masz"<<endl;
	std::vector<particle> czastki(size, particle(dim,rand));
	//czastki= (size, particle(dim,rand));
	for(int i=0;i<size;i++)
	{
		//czastki[i]=new particle(dim, rand);
		cout<<czastki[i].getDistance()<<endl;
	}

}



int main() {

	dim=10;
	size=15;
	//particle czastki[100];
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	rand = new RandomPSO(SEED);
	cout << rand->random01()<<endl;
	cout<<"czastka:"<<endl;
	//particle* part= new particle(5, *rand);
	//double *loc=part->getLocationArray();
//	for(int i=0;i<5;i++)
//	{
//		cout<<loc[i]<<" ";
//	}
//	cout<<endl;
//	cout<<"odleglosc: "<<part->getDistance()<<endl;
	//cout << "wynik" <<endl;

	generateParticles();
	return 0;
}




