//Brandon Angell
//10/30/2023
//To implement the mice and cheese game


#include "maze.h"
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() {
    RoomPair myMaze[numWalls];
    srand(time(nullptr)); // Seed for randomization

    clearWalls(myMaze);
    build(myMaze); // Build the maze with random walls

    char showWalls;
    cout << "Do you want to see the maze walls? (y/n): ";
    cin >> showWalls;

    if (showWalls == 'y' || showWalls == 'Y') {
        cout << "Maze walls:" << endl;
        printMaze(myMaze);
    }

    Room mouseLocation = startRoom;
    char playAgain = 'y';

    while (!(mouseLocation.x == cheeseRoom.x && mouseLocation.y == cheeseRoom.y) && (playAgain == 'y' || playAgain == 'Y')) {
        cout << "Current mouse location: ";
        printRoom(mouseLocation);
        cout << endl;

        Room nextRoom = nextMove(mouseLocation);
        RoomPair moveAttempt = { mouseLocation, nextRoom };

        if (checkMaze(myMaze, moveAttempt)) {
            mouseLocation = nextRoom;
        }
        else {
            cout << "Wall! Mouse cannot move there." << endl;
        }

        cout << "Continue? (y/n): ";
        cin >> playAgain;
    }

    if (mouseLocation.x == cheeseRoom.x && mouseLocation.y == cheeseRoom.y) {
        cout << "Congratulations! Mouse found the cheese!" << endl;
    }
    else {
        cout << "Game over. Mouse did not find the cheese." << endl;
    }

    return 0;
}

