#include "SquareSum.h"


SquareSum::SquareSum()
{
	squareSum = 0;
}


void SquareSum::generateNumbers(string fileName)
{
	srand(time(NULL)); // seed

	ofstream outStream;
	outStream.open(fileName.c_str());

	for (int i=0; i < NUMBERS_LENGTH; i++) {
		// generate real numbers from 0 to 100
		outStream << float(rand() % 100) / (float(rand() % 100) + 1) << " ";
	}
	
	outStream.close();
}


void SquareSum::readNumbersFromFile(string fileName)
{
	ifstream inStream;
	inStream.open(fileName.c_str());
	
	for (int i=0; i < NUMBERS_LENGTH; i++) {
		float number = 0;
		
		inStream >> number;
		
		numbers.push_back(number);
	}
	
	inStream.close();
}


void SquareSum::sumOfSquares()
{
	for (int i=0; i < numbers.size(); i++) {
		squareSum += numbers[i] * numbers[i];
	}
}


void SquareSum::printResult()
{
	cout << "Input: ";
	for (int i=0; i < numbers.size(); i++) {
		cout << numbers[i] <<  " ";
	}
	cout << endl;
	cout << "Output: " << squareSum << endl;
}

