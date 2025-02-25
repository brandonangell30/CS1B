//Brandon Angell
//11/06/23
//To implement the functions and classes of lab9
#include "maze.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cin;using std::cout;using std::endl;

int main() {
    srand(time(nullptr)); // Seed the random number generator
    Maze testMaze;
    Room moveRoom;
    Room r1;
    Room cheese;
    cheese.makeCheeseRoom();
    testMaze.start();
    testMaze.build();
    cout << "Do you want to see the wall positions (y/n)?" << endl;
    char input;
    cin >> input;
    if (input == 'y' || input == 'Y') {
        testMaze.print();
    }

    while ((!matchRoom(testMaze.getCurrentRoom(), cheese)) &&
        (!matchRoom(testMaze.getCurrentRoom(), r1))) {
        cout << "The mouse is in ";
        testMaze.getCurrentRoom().print();
        cout << endl;
        moveRoom = testMaze.getCurrentRoom().nextMove();
        testMaze.move(moveRoom);
    }
    if (matchRoom(testMaze.getCurrentRoom(), cheese)) {
        cout << "You found the cheese room!";
    }
}