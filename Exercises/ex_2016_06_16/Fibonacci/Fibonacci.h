#ifndef FIBONACCI_H
#define FIBONACCI_H

#include<iostream>
#include<vector>

using namespace std;


class Fibonacci {
	public:
		Fibonacci();
		
		void getMaxNumber();
		void findFibonacciNumbers();
		void printResults();
		
	private:
		int maxNumber;
		vector<int> numbers;
		int sum;
		
		int fibonacci(const int &index);
};

#endif

