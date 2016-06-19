/**
 * Nguyen Minh Trang
 * 2016/06/17
 * Program: Square Sum
 */

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;


/*--------- CONSTANTS ----------*/
const int NUMBERS_LENGTH = 10;


/*--------- FUNCTIONS DECLARATIONS -----------*/
void generateNumbers(int count, string fileName);
void readNumbersFromFile(float* numbers, int count, string fileName);
float sumOfSquares(float* numbers, int count);


int main() {
	float* numbers;
	numbers = new float[NUMBERS_LENGTH];

	// generate numbers and put them to 'input.txt'
	generateNumbers(NUMBERS_LENGTH, "input.txt");

	// read from 'input.txt' to array
	readNumbersFromFile(numbers, NUMBERS_LENGTH, "input.txt");

	// print results
	cout << "Input: ";
	for (int i=0; i < NUMBERS_LENGTH; i++) {
		cout << numbers[i] <<  " ";
	}
	cout << endl;
	cout << "Output: " << sumOfSquares(numbers, NUMBERS_LENGTH) << endl;
	
	return 0;
}


/*--------- FUNCTIONS DEFINITIONS -----------*/
void generateNumbers(int count, string fileName) {
	srand(time(NULL)); // seed

	ofstream outStream;
	outStream.open(fileName.c_str());

	for (int i=0; i < count; i++) {
		// generate real numbers from 0 to 100
		outStream << float(rand() % 100) / (float(rand() % 100) + 1) << " ";
	}
	
	outStream.close();
}

void readNumbersFromFile(float* numbers, int count, string fileName) {
	ifstream inStream;
	inStream.open(fileName.c_str());
	
	for (int i=0; i < count; i++) {
		inStream >> numbers[i];
	}
	
	inStream.close();
}

float sumOfSquares(float* numbers, int count) {
	float sum = 0;
	
	for (int i=0; i < count; i++) {
		sum += numbers[i] * numbers[i];
	}
	
	return sum;
}

