//Brandon Angell
//12/3/2023
//to make a snake game

#include <iostream>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::vector;

// maze dimensions
const int mazeLength = 6;
const int mazeWidth = 6;

void printMaze(const vector<vector<bool>>& maze) {
    for (int i = 0; i < maze.size(); ++i) {
        for (int j = 0; j < maze[i].size(); ++j) {
            cout << (maze[i][j] ? '*' : ' ') << ' ';
        }
        cout << endl;
    }
}

int main() {
    int mouseX = 0; // current mouse X index
    int mouseY = 0; // current mouse Y index

    vector<vector<bool>> maze(mazeLength, vector<bool>(mazeWidth, false)); // declare mouse maze tracking vector
    maze[mouseX][mouseY] = true;  // place mouse in the top-left corner

    char op;

    do {
        // Display the maze with the mouse's path
        printMaze(maze);

        cout << "Enter direction (l)eft, (r)ight, (u)p, (d)own or (q)uit: ";
        cin >> op;

        // Update the position based on the current move
        int newMouseX = mouseX;
        int newMouseY = mouseY;

        if (op == 'u' && newMouseX > 0) {
            newMouseX--;
        }
        else if (op == 'd' && newMouseX < mazeLength - 1) {
            newMouseX++;
        }
        else if (op == 'r' && newMouseY < mazeWidth - 1) {
            newMouseY++;
        }
        else if (op == 'l' && newMouseY > 0) {
            newMouseY--;
        }

        // Apply the mouse's path to the maze
        maze[newMouseX][newMouseY] = true;

        // Update the current position
        mouseX = newMouseX;
        mouseY = newMouseY;

    } while (op != 'q');

    return 0;
}
