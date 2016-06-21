#ifndef NUMBER_SOLVER_H
#define NUMBER_SOLVER_H


#include<iostream>
#include<vector>

using namespace std;


class NumberSolver
{
	public:
		NumberSolver();
		
		void getNumbers();
		void printResults();
		
		void findMin();
		void findMax();
		void findMostFrequent();
		void insertionSortASC();
		void insertionSortDESC();
	private:
		vector<int> numbers;
		int min, max, mostFreq, freq;
		
		void swap(int& num1, int& num2);
};

#endif

