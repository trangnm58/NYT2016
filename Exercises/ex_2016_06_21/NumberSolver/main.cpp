/**
 * Nguyen Minh Trang
 * 2016/06/21
 * Project: Number Solver
 */


#include "NumberSolver.h"


int main()
{
	NumberSolver numberSolver;
	
	// get numbers
	numberSolver.getNumbers();

	// find min and max
	numberSolver.findMin();
	numberSolver.findMax();
	
	// find the number has largest frequent existence
	numberSolver.findMostFrequent();
	
	// sort ascending/descending
	numberSolver.insertionSortASC();
	//insertionSortDESC(numbers, count);
	
	// print the results
	numberSolver.printResults();

	return 0;
}
