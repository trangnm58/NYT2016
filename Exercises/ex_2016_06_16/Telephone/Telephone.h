#ifndef TELEPHONE_H
#define TELEPHONE_H

#include <iostream>
#include <cstdlib>

using namespace std;


const int CONSTANT_COST = 25000;
const int PHONE_COST_OVER_0 = 600;
const int PHONE_COST_OVER_50 = 400;
const int PHONE_COST_OVER_200 = 200;


class Telephone {
	public:
		Telephone();
		
		void getMinutes();
		void findTelephoneCost();
		void printResult();
		
	private:
		int cost;
		int minutes;
		int min0, min50, min200;
};

#endif
