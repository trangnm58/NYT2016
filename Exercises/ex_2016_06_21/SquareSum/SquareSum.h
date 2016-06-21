#ifndef SQUARE_SUM_H
#define SQUARE_SUM_H

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<vector>

using namespace std;


const int NUMBERS_LENGTH = 10;


class SquareSum
{
	public:
		SquareSum();

		void generateNumbers(string fileName);
		void readNumbersFromFile(string fileName);
		void sumOfSquares();
		
		void printResult();

	private:
		vector<float> numbers;
		float squareSum;
};

#endif

