/**
 * Nguyen Minh Trang
 * 2016/06/16
 * Program: Telephone Cost
 */

#include <iostream>
#include <cstdlib>
using namespace std;

/*--------- CONSTANTS ----------*/
const int CONSTANT_COST = 25000;

/*--------- FUNCTIONS DECLARATIONS -----------*/
void printOutput(int min50, int min150, int min200, int cost);


int main() {
	int cost = CONSTANT_COST;
	int min;
	
	cout << "Input: ";
	cin >> min;
	
	int min50, min150, min200;
	min50 = min150 = min200 = 0;

	if (min > 200) {
		// more 200 minutes
		min200 = min - 200;
		cost += min200 * 200;
		
		min -= min200;
	}
	if (min > 50) {
		// from 51 to 200 minutes
		min150 = min - 50;
		cost += min150 * 400;
		
		min -= min150;
	}
	if (min > 0) {
		// from 0 to 50 minutes
		min50 = min;
		cost += min50 * 600;
	}

	printOutput(min50, min150, min200, cost);
	return 0;
}


/*--------- FUNCTIONS DEFINITIONS -----------*/
void printOutput(int min50, int min150, int min200, int cost) {
	cout << "Output: 25000 ";
	
	if (min50 > 0) {
		cout << "+ " << min50 << "*600 ";
	}
	if (min150 > 0) {
		cout << "+ " << min150 << "*400 ";
	}
	if (min200 > 0) {
		cout << "+ " << min200 << "*200 ";
	}
	cout << "= " << cost << endl;
}

