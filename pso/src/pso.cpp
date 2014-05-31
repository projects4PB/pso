//============================================================================
// Name        : pso.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "RandomPSO.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	RandomPSO* rand = new RandomPSO();
	cout << rand->random()<<endl;
	//cout << "wynik" <<endl;
	return 0;
}
