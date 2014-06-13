//============================================================================
// Name        : pso.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <vector>
#include <iostream>
#include <mpi.h>
#include "RandomPSO.h"
#include "particle.h"
#include "pso.h"
using namespace std;
vector<particle> czastki;

int dim;
int size;
int iterations;
double* gbest;

double minDistance;

void generateParticles(RandomPSO *rand)
{
	for(int i=0;i<size;i++)
	{
		particle* temp= new particle(dim, rand->random());
		czastki.push_back(*temp);
	}
}



int main(int argc, char* argv[]) {

	int npes;
	int myrank;


	dim=65536;
	size=1024;
	iterations=10;
	RandomPSO *rand= new RandomPSO(SEED);
	//cout << rand->random01()<<endl;
	cout<<"generowanie czastek (odleglosci):"<<endl;

	generateParticles(rand);

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &npes);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

	MPI_Request reqs[2];
	MPI_Status statuses[2];

	if(myrank == 0) {
		//wyslij do 1 i 2
	}
	else {
		// ustal pozycje w drzewie na podstawie myrank
		int leaf_id = myrank

		// ustal numer procesu nadrzednego
		int parent_id = leaf_id - ((leaf_id - 1) % 2) - 1

		// odbierz numer procesu nadrzednego
		MPI_Recv(&parent_id, sizeof(int), MPI_INT,
				0, 13,MPI_COMM_WORLD,&status);

		// oblicz pBest
		particle particle = czastki[myrank]
		particle.calculateVelocity(qBest)
		double pBest = particle.getDistance()

		// wyslij zadanie wykonania obliczen
		// do dwoch kolejnych lisci w drzewie
		next_leafs = int[2] = { leaf_id + 1, leaf_id + 2 }
		if(next_leafs[0] <= npes)
		{
			MPI_Send(&leaf_id, sizeof(int), MPI_INT,
					next_leafs[0], 80, MPI_COMM_WORLD);
		}
		if(next_leafs[1] <= npes)
		{
			MPI_Send(&leaf_id, sizeof(int), MPI_INT,
					next_leafs[1], 80, MPI_COMM_WORLD);
		}
		// odeslij wynik do req_rank
		// jesli pBest lepszy od gBest to zamien
	}
	particle czastka = czastki[myrank];
	double dist = czastka.getDistance();
	cout << "dist: " << dist << endl;

	MPI_Finalize();
/*
	gbest=czastki[0].getLocationArray();
	minDistance=czastki[0].getDistance();
	for(int i=0;i<size;i++)
	{
		if(czastki[i].getDistance()<minDistance)
		{
			gbest=czastki[i].getLocationArray();
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
			cout<<czastki[j].getDistance()<<" od ";
			if(czastki[j].getDistance()<minDistance)
			{
				double temp=minDistance;
				minDistance=czastki[j].getDistance();
				gbest=czastki[j].getLocationArray();
				cout<<temp<<" "<<minDistance<<" zmiana"<<endl;
			}
		}
		cout<<minDistance<<endl;
		for(int j=0;j<dim;j++)
		{
			cout<<gbest[j]<<" ";
		}
		cout<<endl;
	}

	cout<<"rozwiazanie"<<endl;
	for(int i=0; i<dim;i++)
	{
		cout<<gbest[i]<<" ";
	}
	cout<<endl<<"odleglosc "<<minDistance<<endl; */
	return 0;
}




