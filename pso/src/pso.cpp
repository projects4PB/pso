//============================================================================
// Name        : pso.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//#include <mpi.h>
#include "RandomPSO.h"
#include "particle.h"
using namespace std;

int main() {

	//particle czastki[100];
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	RandomPSO* rand = new RandomPSO();
	cout << rand->random()<<endl;
	cout<<"czastka:"<<endl;
	particle* part= new particle(5, 847382749798543);
	double *loc=part->getLocationArray();
	for(int i=0;i<5;i++)
	{
		cout<<loc[i]<<" ";
	}
	cout<<endl;
	cout<<"odleglosc: "<<part->getDistance()<<endl;
	//cout << "wynik" <<endl;


	return 0;
}
