//To implement charlies collection
//Brandon Angell
//11/13/2023

#include "collections.h"
#include <iostream>

using std::cin; using std::cout; using std::endl;

int main() {
	char input; 
	int size = 0; 
	double dNum = 0.0;
	double* array = new double[size]; //dynamic memory

	do {
		cout << "Charlie, enter operation [a,r,q]: ";
		cin >> input;
		if (input == 'a' || input == 'r') {
			cout << "Now input a number: ";
			cin >> dNum;
		}

		if (input == 'a') {
			addNumber(array, dNum, size);
		}

		if (input == 'r') {
			removeNumber(array, dNum, size);
		}

		cout << "Your numbers: "; 
		output(array, size);

	} while (input != 'q');
}