//To implement charlies collection
//Brandon Angell
//11/20/2023

#include "collection.h"
#include <iostream>

using std::cin; using std::cout; using std::endl;

int main() {
	Collection dynArr;
	char input;
	double Num = 0.0;
	

	do {
		cout << "Charlie, enter operation [a,r,q]: ";
		cin >> input;
		if (input == 'a' || input == 'r') {
			cout << "Now input a number: ";
			cin >> Num;
		}

		if (input == 'a') {
			dynArr.addNumber(Num);
		}

		if (input == 'r') {
			dynArr.removeNumber(Num);
		}

		cout << "Your numbers: ";
		dynArr.output();

	} while (input != 'q');
}