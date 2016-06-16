/**
 * Nguyen Minh Trang
 * 2016/06/16
 * Program: Fibonacci
 */

#include <iostream>
using namespace std;


/*--------- FUNCTIONS DECLARATIONS -----------*/
//Find the fibonacci value of the index at 'number'
int fibonacci(int number);


int main() {
	int maxNumber;
	int sum = 0;

	// get user input
	cout << "Input: ";
	cin >> maxNumber;
	if (maxNumber <= 0) {
		cout << "Invalid input!" << endl;
		return 1;
	}

	cout << "Output:" << endl;

	int i = 1;  // fibonacci index
	int fib_i;  // fibonacci value at index 'i' 
	while (true) {
		fib_i = fibonacci(i);
		if (fib_i <= maxNumber) {
			sum += fib_i;
			cout << fib_i << " ";
		} else {
			break;
		}
		i++;
	}
	cout << "\nSum: " << sum << endl;
	return 0;
}


/*--------- FUNCTIONS DEFINITIONS -----------*/
int fibonacci(int number) {
	if (number == 1 || number == 2) {
		return 1;
	}
	return fibonacci(number - 1) + fibonacci(number - 2);
}

