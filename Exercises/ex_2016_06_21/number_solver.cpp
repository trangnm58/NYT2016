/**
 * Nguyen Minh Trang
 * 2016/06/17
 * Program: Number Solver
 */

#include <iostream>
using namespace std;


/*--------- FUNCTIONS DECLARATIONS -----------*/
void findMin(int* numbers, int count, int& min);
void findMax(int* numbers, int count, int& max);
void findMostFrequent(int* numbers, int count, int &mostFreq, int &freq);
void insertionSortASC(int* numbers, int count);
void insertionSortDESC(int* numbers, int count);


int main() {
	int* numbers;
	int count = 0;
	int min, max, mostFreq, freq;
	
	// get 10 numbers from user
	cout << "Number of numbers: ";
	cin >> count;
	if (count <= 0) {
		cout << "Invalid input!" << endl;
		return 1;
	}
	
	numbers = new int[count];
	cout << "Input: ";
	for (int i = 0; i < count; i++) {
		cin >> numbers[i];
	}
	
	// find min and max
	findMin(numbers, count, min);
	findMax(numbers, count, max);
	
	// find the number has largest frequent existence
	findMostFrequent(numbers, count, mostFreq, freq);
	
	// sort ascending/descending
	insertionSortASC(numbers, count);
	//insertionSortDESC(numbers, count);
	
	// print the results
	cout << "Output:" << endl;
	cout << "Min: " << min << ", Max: " << max << endl;
	cout << "Most Freq: " << mostFreq << " (" << freq << " times)" << endl;
	cout << "Sort ASC: ";
	for (int i = 0; i < count; i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;
}


/*--------- FUNCTIONS DEFINITIONS -----------*/
void findMin(int* numbers, int count, int& min) {
	min = numbers[0];
	for (int i = 0; i < count; i++) {
		if (numbers[i] < min) {
			min = numbers[i];
		}
	}
}

void findMax(int* numbers, int count, int& max) {
	max = numbers[0];
	for (int i = 0; i < count; i++) {
		if (numbers[i] > max) {
			max = numbers[i];
		}
	}
}

void findMostFrequent(int* numbers, int count, int& mostFreq, int& freq) {
	freq = 1;
	mostFreq = numbers[0];
	
	for (int i = 0; i < count; i++) {
		int temp_freq = 1;
		for (int j = i + 1; j < count; j++) {
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

void swap(int& num1, int& num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void insertionSortASC(int* numbers, int count) {
	for (int i = 1; i < count; i++) {
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

void insertionSortDESC(int* numbers, int count) {
	for (int i = 1; i < count; i++) {
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

