#include <cstdlib>
#include "pso.h"
#include "RandomPSO.h"
#include <iostream>
using namespace std;




RandomPSO::RandomPSO() {

	srand(SEED);

}

RandomPSO::RandomPSO(double seed) {
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
	int x=rand()%1000;
	return x/1000.0;
}
