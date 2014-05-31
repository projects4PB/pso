#include <cstdlib>
#import "pso.h"
#import "RandomPSO.h"
#include <iostream>
using namespace std;




RandomPSO::RandomPSO() {
	seed = SEED;
	srand(seed);
}

RandomPSO::RandomPSO(double seed2) {
	seed = seed2;
	srand(seed);
}

double RandomPSO::random()
{

	int x = rand();

	x=x%65536-32768;
	return x/1000.0;
}

