#include "Telephone.h"


Telephone::Telephone()
{
	cost = CONSTANT_COST;
	minutes = 0;
	min0 = min50 = min200 = 0;
}


void Telephone::getMinutes()
{
	cout << "Input: ";
	cin >> minutes;
	
	minutes >= 0 ? minutes = minutes : minutes = 0;
}


void Telephone::findTelephoneCost()
{
	int minutes = this->minutes;

	if (minutes > 200) {
		// more 200 minutes
		min200 = minutes - 200;
		cost += min200 * PHONE_COST_OVER_200;
		
		minutes -= min200;
	}
	if (minutes > 50) {
		// from 51 to 200 minutes
		min50 = minutes - 50;
		cost += min50 * PHONE_COST_OVER_50;
		
		minutes -= min50;
	}
	if (minutes > 0) {
		// from 0 to 50 minutes
		min0 = minutes;
		cost += min0 * PHONE_COST_OVER_0;
	}
}


void Telephone::printResult()
{
	cout << "Output: 25000";
	
	if (min0 > 0) {
		cout << " + " << min0 << "*" << PHONE_COST_OVER_0;
	}
	if (min50 > 0) {
		cout << " + " << min50 << "*" << PHONE_COST_OVER_50;
	}
	if (min200 > 0) {
		cout << " + " << min200 << "*" << PHONE_COST_OVER_200;
	}
	cout << " = " << cost << endl;
}

