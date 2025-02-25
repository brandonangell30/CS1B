//To justify a paragraph of text
//Brandon Angell
//10/20/2023

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using std::cin; using std::cout; using std::endl; using std::string;
const int LINE_LENGTH = 80;

void addSpacesAfterPunctuation(string& line);
void addRandomSpaces(string& line);
void justifyText();

int main() {
    justifyText();
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

void justifyText() {
    //despite using fstream, i keep getting errors if I dont use std:: before ifstream and ofstream
    std::ifstream inputFile("unjustified.txt");
    std::ofstream outputFile("justified.txt");

    string line;
    while (getline(inputFile, line)) {
        addSpacesAfterPunctuation(line);
        addRandomSpaces(line);
        outputFile << line << endl;
    }

    cout << "Text justified and written to justified.txt.\n";

    inputFile.close();
    outputFile.close();
}
