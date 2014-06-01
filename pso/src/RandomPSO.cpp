#include <cstdlib>
#include "pso.h"
#include "RandomPSO.h"
#include <iostream>
using namespace std;




RandomPSO::RandomPSO() {

	srand(SEED);

}

RandomPSO::RandomPSO(double seed) {
	cout<<"random"<<endl;
	srand(seed);
}

double RandomPSO::random()
{

	int x = rand();
	x=x%65536-32768;
	return x/1000.0;
}

double RandomPSO::random01()
{
	cout<<"zero"<<endl;
	int x=rand()%1000;
	cout<<"jeden"<<endl;
	return x/1000.0;
}
