/*
 * RandomPSO.h
 *
 *  Created on: 31 maj 2014
 *      Author: darkon
 */

#ifndef RANDOMPSO_H_
#define RANDOMPSO_H_
class RandomPSO
{
	public:
		double seed;

	public:
		RandomPSO();
		RandomPSO(double seed);
		double random();
};

#endif /* RANDOMPSO_H_ */
