//============================================================================
// Name        : pso.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <vector>
#include <iostream>
#include <string.h>
#include "RandomPSO.h"
#include "particle.h"
#include "pso.h"
#include <fstream>
#include <stdlib.h>
using namespace std;
vector<particle> czastki;

int dim;
int size;
int iterations;
int c1, c2;
double maxSpeed;
double seed;
std::vector<double>gbest;
std::vector<double> temp;
int naj;
double minDistance;

void generateParticles(RandomPSO *rand)
{
	for(int i=0;i<size;i++)
	{
		particle* temp= new particle(dim, rand->random());
		temp->setMaxVelocity(maxSpeed);
		temp->setC1(c1);
		temp->setC2(c2);
		czastki.push_back(*temp);
	}
}


int main(int argc, char** argv) {

	dim=DIM;
	size=SIZE;
	c1=C1;
	c2=C2;
	iterations=ITERATIONS;
	maxSpeed=MAXSPEED;
	seed=SEED;
	cout<<argc;
	for(int i=1;i<argc;i++)
	{
		if(strcmp(argv[i],"D")==0)
		{
			i++;
			dim=atoi(argv[i]);
		}
		else if(strcmp(argv[i],"m")==0)
		{
			i++;
			size=atoi(argv[i]);
		}
		else if(strcmp(argv[i],"c")==0)
		{
			i++;
			c1=atoi(argv[i]);
		}
		else if(strcmp(argv[i],"C")==0)
		{
			i++;
			c2=atoi(argv[i]);
		}
		else if(strcmp(argv[i],"V")==0)
		{
			i++;
			maxSpeed=atof(argv[i]);
		}
		else if(strcmp(argv[i],"i")==0)
		{
			i++;
			iterations=atoi(argv[i]);
		}
		else if(strcmp(argv[i],"s")==0)
		{
			i++;
			seed=atof(argv[i]);
		}
	}
	cout<<"parametry"<<endl<<"D="<<dim<<" m="<<size<<" c="<<c1<<" C="<<c2<<" V="<<maxSpeed<<" i="<<iterations<<" s="<<seed<<endl;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	RandomPSO *rand= new RandomPSO(seed);
	cout<<"generowanie czastek (odleglosci):"<<endl;
	ofstream plik;
	plik.open("wymiary.txt");
	plik<<"#Dimension="<<dim<<" #Size="<<size<<" #Iterations="<<iterations<<endl;
	generateParticles(rand);

	gbest=czastki[0].getLocationArray();
	minDistance=czastki[0].getDistance();
	for(int i=0;i<size;i++)
	{
		if(czastki[i].getDistance()<minDistance)
		{

			gbest=czastki[i].getLocationArray();
			minDistance=czastki[i].getDistance();
		}
	}
cout<<"petle"<<endl;
	for(int i=0; i<iterations;i++)
	{
		for(int j=0;j<size;j++)
		{
			czastki[j].calculateVelocity(gbest);
		}

		for(int j=0;j<size;j++)
		{
			if(czastki[j].getDistance()<minDistance)
			{
				double temp=minDistance;
				minDistance=czastki[j].getDistance();
				naj=j;
				gbest=czastki[j].getLocationArray();
				cout<<temp<<" "<<minDistance<<" zmiana"<<endl;
			}
		}
//		for(int j=0;j<dim;j++)
//		{
//			cout<<gbest[j]<<" ";
//		}
		cout<<endl<<"wyzej wymiary najlepszej "<<"odleglosc "<<minDistance<<" iteracja: "<<i<<endl;
		temp=czastki[naj].getLocationArray();
//		for(int j=0;j<dim;j++)
//		{
//			plik<<temp[j]<<"\t"<<endl;
//		}
//
//		plik<<"\t"<<czastki[naj].getDistance()<<" "<<naj<<endl;
	}
	plik.close();
	cout<<"rozwiazanie"<<endl;
	for(int i=0; i<dim;i++)
	{
		cout<<gbest[i]<<" ";
	}
	cout<<endl<<"odleglosc "<<minDistance<<endl;

	double sum=0;
	for(int i=0;i<dim;i++)
	{
		sum+=abs(gbest[i]);
	}
	cout<<sum<<" suma, "<<sum/dim<<" srednia"<<endl;
	return 0;
}



