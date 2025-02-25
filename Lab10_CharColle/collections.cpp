//Brandon Angell
//11/13/23
//To test out dynamic memory allocation using arrays and pointers

#include "collections.h"
#include <iostream>
using std::cin; using std::cout; using std::endl;

// prints the values in array "colPtr" of "size"
void output(const double* colPtr, const int size) {
	for (int i = 0; i < size; ++i) {
		cout << colPtr[i] << " " << endl;
	}
}

// returns the sum of all the values in array "colPtr" of "size"
double value(const double* colPtr, const int size) {
	double tracker = 0;
	for (int i = 0; i < size; ++i) {
		tracker += colPtr[i];
	}
	return tracker;
}

// returns the index of the element in array "colPtr" of "size"
// that corresponds to the element holding "number"
// if number is not in the array, returns -1
int check(const double* colPtr, const double number, const int size) {
	for (int i = 0; i < size; ++i) {
		if (number == colPtr[i])
			return i;
	}
	return -1;
}

// adds "number" to the array pointed to by "colPtr" of "size".
// if the number is not already there, if "number" is there - no action
// Note, the size of the array is thus increased.
void addNumber(double*& colPtr, const double number, int& size) {
	if (check(colPtr, number, size) == -1) {
		double* tempColPtr = new double[size + 1];
		for (int i = 0; i < size; ++i) {
			tempColPtr[i] = colPtr[i];

		}
		tempColPtr[size] = number;

		colPtr = new double[++size];

		for (int i = 0; i < size; ++i) {
			colPtr[i] = tempColPtr[i];

		}
		delete[] tempColPtr;
	}
}

//removes a "number" from array "colPtr" of "size".
//if "number" is not there -- no action
//note, "size" changes

void removeNumber(double*& colPtr, const double number, int& size) {
	int index = check(colPtr, number, size);

	if (index == -1) {
		cout << "Number not found in the array. No further actions required." << endl;
		return;
	}
	double* tempColPtr = new double[size - 1];

	// Copy elements before the found index
	for (int i = 0; i < index; ++i) {
		tempColPtr[i] = colPtr[i];
	}

	// Copy elements after the found index
	for (int i = index + 1; i < size; ++i) {
		tempColPtr[i - 1] = colPtr[i];
	}
	delete[] colPtr;
	colPtr = tempColPtr;
	--size;
}