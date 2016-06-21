#include "NumberSolver.h"


NumberSolver::NumberSolver()
{
	max = min = mostFreq = freq = 0;
}


void NumberSolver::getNumbers()
{
	// get numbers from user
	int numOfNumbers = 0;
	cout << "Number of numbers: ";
	cin >> numOfNumbers;
	
	cout << "Input: ";
	for (int i=0; i < numOfNumbers; i++) {
		int number = 0;
		cin >> number;
		numbers.push_back(number);
	}
}


void NumberSolver::printResults()
{
	cout << "Output:" << endl;
	cout << "Min: " << min << ", Max: " << max << endl;
	cout << "Most Freq: " << mostFreq << " (" << freq << " times)" << endl;
	cout << "Sort ASC: ";
	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;
}


void NumberSolver::findMax()
{
	if (numbers.size() > 0) {
		max = numbers[0];
		for (int i = 0; i < numbers.size(); i++) {
			if (numbers[i] > max) {
				max = numbers[i];
			}
		}
	}
}


void NumberSolver::findMin()
{
	if (numbers.size() > 0) {
		min = numbers[0];
		for (int i = 0; i < numbers.size(); i++) {
			if (numbers[i] < min) {
				min = numbers[i];
			}
		}
	}
}


void NumberSolver::findMostFrequent()
{
	if (numbers.size() > 0) {
		freq = 1;
		mostFreq = numbers[0];
		
		for (int i = 0; i < numbers.size(); i++) {
			int temp_freq = 1;
			for (int j = i + 1; j < numbers.size(); j++) {
				if (numbers[j] == numbers[i]) {
					temp_freq++;
				}
			}
			
			if (temp_freq > freq) {
				freq = temp_freq;
				mostFreq = numbers[i];
			}
		}
	}
}


void NumberSolver::insertionSortASC()
{
	if (numbers.size() > 0) {
		for (int i = 1; i < numbers.size(); i++) {
			int pos = i - 1;
			while (pos >= 0 && numbers[pos] > numbers[i]) {
				pos--;
			}
			pos++;
			int temp = numbers[i];
			for (int j = i - 1; j >= pos; j--) {
				numbers[j+1] = numbers[j];
			}
			numbers[pos] = temp;
		}
	}
}


void NumberSolver::insertionSortDESC()
{
	if (numbers.size() > 0) {
		for (int i = 1; i < numbers.size(); i++) {
			int pos = i - 1;
			while (pos >= 0 && numbers[pos] < numbers[i]) {
				pos--;
			}
			pos++;
			int temp = numbers[i];
			for (int j = i - 1; j >= pos; j--) {
				numbers[j+1] = numbers[j];
			}
			numbers[pos] = temp;
		}
	}
}

void NumberSolver::swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

