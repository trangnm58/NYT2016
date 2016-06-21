/**
 * Nguyen Minh Trang
 * 2016/06/21
 * Project: Square Sum
 */


#include "SquareSum.h"


int main()
{
	SquareSum squareSum;
	
	// generate numbers and put them to 'input.txt'
	squareSum.generateNumbers("input.txt");

	// read from 'input.txt' to array
	squareSum.readNumbersFromFile("input.txt");

	// calculate
	squareSum.sumOfSquares();

	// print results
	squareSum.printResult();
	
	return 0;
}
