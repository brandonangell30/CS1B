//Brandon Angell
//To implement lab 10-11 with vectors
//11/28/23

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin; using std::cout; using std::endl; using std::vector;


int main() {
    vector<double> v;
    char input;
    double num;

    do {
        cout << " Enter operation [a/r/q] and a number: ";
            cin >> input;
            cin >> num;
            cout << endl;

            if (input == 'a') {
                vector<double>::iterator it;
                it = find(v.begin(), v.end(), num);
                if (it != v.end()) {
                    cout << "Duplicate";
                }
                else {
                    v.insert(it, num);
                }
                for(vector<double>::iterator it = v.begin(); it !=v.end(); ++it){
                    cout << *it << " " << endl;
                }
            }

            if (input == 'r') {
                vector<double>::iterator it;
                it = find(v.begin(), v.end(), num);
                if (it != v.end()) {
                    cout << "Found number at location: " << it - v.begin() << endl;
                    v.erase(it);
                }
                else {
                    cout << "Not Found!" << endl;
                }
                for (vector<double>::iterator it = v.begin(); it != v.end(); ++it) {
                    cout << *it << " " << endl;
                }
            }
    } while (input != 'q');
    cout << "You have chose to exit the program";
}

