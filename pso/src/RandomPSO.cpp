#include <cstdlib>
#import "pso.h"

using namespace std;


class RandomPSO
{
	public:
		RandomPSO();
		RandomPSO(double);
		double seed;
};

RandomPSO::RandomPSO() {
	seed = SEED;
}

RandomPSO::RandomPSO(double seed) {
	this->seed=srand(seed);
}
