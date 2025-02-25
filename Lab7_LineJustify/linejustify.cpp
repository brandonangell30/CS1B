//To justify a sentence of text by adding random spaces where appropriate
//Brandon Angell
//10/17/2023

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using std::cin; using std::cout; using std::endl; using std::string;
const int LINE_LENGTH = 80;
void addSpacesAfterPunctuation(string& line);
void addRandomSpaces(string& line);

int main() {
    srand(time(nullptr)); // Seed for random number generation

    string inputLine;
    cout << "input line:\n";
    getline(cin, inputLine);

    addSpacesAfterPunctuation(inputLine);
    addRandomSpaces(inputLine);

    cout << "your line justified:\n";
    cout << inputLine << endl;


}

void addSpacesAfterPunctuation(string& line) {
    for (int i = 0; i < line.length(); ++i) {
        if (line[i] == '.' || line[i] == '!' || line[i] == '?' || line[i] == ':') {
            if (i < line.length() - 1) {
                line.insert(i + 1, "  ");
                i += 2;
            }
            else {
                i++;
            }
        }
    }
}

void addRandomSpaces(string& line) {
    while (line.length() < LINE_LENGTH) {
        int randomPos = rand() % line.length();
        if (line[randomPos] == ' ') {
            line.insert(randomPos, " ");
        }
    }
}









