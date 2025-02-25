//To implement lab10 using classes
//Brandon Angell
//11/20/2023

#include "collection.h"
#include <iostream>

using std::cin; using std::cout; using std::endl;

//fix void constructor, somehow intitalize size and col
Collection::Collection() {
	size_ = 0;
	col_ = new double[0];
}

int Collection::check(double number) {
	for (int i = 0; i < size_; ++i) {
		if (number == col_[i])
			return i;
	}
	return -1;
}


void Collection::addNumber(double number) {
	if (check(number) == -1) {
		double* tempColPtr = new double[size_ + 1];
		for (int i = 0; i < size_; ++i) {
			tempColPtr[i] = col_[i];

		}
		tempColPtr[size_] = number;

		col_ = new double[++size_];

		for (int i = 0; i < size_; ++i) {
			col_[i] = tempColPtr[i];

		}
		delete[] tempColPtr;
	}
}

//fix temp array
void Collection::removeNumber(double number) {
	int index = check(number);

	if (index == -1) {
		cout << "Number not found in the array. No further actions required." << endl;
		return;
	}
	double* tempColPtr = new double[size_ - 1];

	// Copy elements before the found index
	for (int i = 0; i < index; ++i) {
		tempColPtr[i] = col_[i];
	}

	// Copy elements after the found index
	for (int i = index + 1; i < size_; ++i) {
		tempColPtr[i - 1] = col_[i];
	}
	delete[] col_;
	col_ = tempColPtr;
	--size_;
}

void Collection::output() const {
	for (int i = 0; i < size_; ++i) {
		cout << col_[i] << " " << endl;
	}
}


Collection::Collection(const Collection& initial) {
	size_ = initial.size_;
	col_ = new double[size_];
	for (int i = 0; i < size_; ++i) {
		col_[i] = initial.col_[i];
	}
}

const Collection& Collection::operator=(const Collection& initial) {
	if (this != &initial) {
		size_ = initial.size_;
		delete[] col_;
		col_ = new double[size_];
		for (int i = 0; i < size_; ++i) {
			col_[i] = initial.col_[i];
		}
	}
	return *this;
}

Collection::~Collection() {
	delete[] col_;
}