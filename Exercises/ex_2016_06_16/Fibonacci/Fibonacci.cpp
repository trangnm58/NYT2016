#include "Fibonacci.h"


Fibonacci::Fibonacci()
{
	sum = 0;
}


void Fibonacci::getMaxNumber() {
	// get user input
	cout << "Input: ";
	cin >> maxNumber;
	
	if (maxNumber <= 0) {
		cout << "Invalid input!" << endl;

		exit(1); // end the program
	}
}


int Fibonacci::fibonacci(const int &index)
{
	if (index == 1 || index == 2) {
		return 1;
	}
	return fibonacci(index - 1) + fibonacci(index - 2);
}


void Fibonacci::findFibonacciNumbers()
{
	
	int i = 1;  // fibonacci index
	int fib_i;  // fibonacci value at index 'i' 
	while (true) {
		fib_i = fibonacci(i);
		if (fib_i <= maxNumber) {
			sum += fib_i;
			numbers.push_back(fib_i);
		} else {
			break;
		}
		i++;
	}
}


void Fibonacci::printResults() {
	cout << "Output:" << endl;
	
	for (int i=0; i < numbers.size(); i++) {
		cout << numbers[i] << " ";
	}
	cout << endl << "Sum: " << sum << endl;
}

