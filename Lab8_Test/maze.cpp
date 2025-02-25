// Brandon Angell
//10/29/23
//To create a maze

#include "maze.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cin; using std::cout; using std::endl;

RoomPair walls[numWalls];
RoomPair myMaze[numWalls];


void clearWalls(RoomPair walls[]) {
    for (int i = 0; i < numWalls; ++i) {
        walls[i] = { {-1, '*'}, { -1, '*'} };
    }
}

bool goodDirection(const Room& rm, const char dr) {
    if (dr == 'u' && rm.y > 'a') {
        return true;
    }
    else if (dr == 'd' && rm.y < 'a' + mazeSize - 1) {
        return true;
    }
    else if (dr == 'l' && rm.x > 1) {
        return true;
    }
    else if (dr == 'r' && rm.x < mazeSize) {
        return true;
    }
    return false;
}


Room createAdjacent(const Room& rm, const char dr) {
    Room adjRoom = rm;
    switch (dr) {
    case 'u':
        adjRoom.y--;
        break;
    case 'd':
        adjRoom.y++;
        break;
    case 'l':
        adjRoom.x--;
        break;
    case 'r':
        adjRoom.x++;
        break;
    }
    return adjRoom;
}

const Room pickAdjacent(const Room& rm) {
    char directions[] = { 'u', 'd', 'l', 'r' };
    char randomDirection;
    randomDirection = directions[rand() % 4];
    Room adjacentRoom = createAdjacent(rm, randomDirection);

    while (!goodDirection(rm, randomDirection)) {
        randomDirection = directions[rand() % 4];
        adjacentRoom = createAdjacent(rm, randomDirection);
    }

    return adjacentRoom;
}

const RoomPair pickPair() {
    RoomPair pair;
    do {
        pair.one = { (char)(rand() % mazeSize + 1), (char)('a' + rand() % mazeSize) };
        pair.two = pickAdjacent(pair.one);
    } while (pair.one.x == pair.two.x && pair.one.y == pair.two.y);

    return pair;
}


bool matchRoom(const Room& r1, const Room& r2) {
    return r1.x == r2.x && r1.y == r2.y;
}

bool matchPair(const RoomPair& rp1, const RoomPair& rp2) {
    return (matchRoom(rp1.one, rp2.one) && matchRoom(rp1.two, rp2.two)) ||
        (matchRoom(rp1.one, rp2.two) && matchRoom(rp1.two, rp2.one));
}

//Checks if a copy of walls matches
bool checkMaze(const RoomPair walls[], const RoomPair& rp) {
    for (int i = 0; i < numWalls; ++i) {
        if ((matchRoom(walls[i].one, rp.one) && matchRoom(walls[i].two, rp.two)) ||
            (matchRoom(walls[i].one, rp.two) && matchRoom(walls[i].two, rp.one))) {
            return false;
        }
    }
    return true;
}




void build(RoomPair walls[]) {
    clearWalls(walls);

    int builtWalls = 0;
    while (builtWalls < numWalls) {
        RoomPair candidate = pickPair();

        // Check if adding this wall isolates any section in the maze
        RoomPair tempMaze[numWalls];
        for (int j = 0; j < builtWalls; ++j) {
            tempMaze[j] = walls[j];
        }

        if (checkMaze(tempMaze, candidate)) {

            bool isolated = false;
            for (int j = 0; j < builtWalls + 1; ++j) {
                if (checkMaze(tempMaze, tempMaze[j])) {
                    isolated = true;
                    break;
                }
            }

            if (!isolated) {
                walls[builtWalls++] = candidate;
            }
        }
    }
}



void printRoom(const Room& room) {
    cout << room.x << room.y << " ";
}

void printPair(const RoomPair& rp) {
    printRoom(rp.one);
    cout << "|";
    printRoom(rp.two);
}

void printMaze(const RoomPair walls[]) {
    for (int i = 0; i < numWalls; ++i) {
        printPair(walls[i]);
        cout << "  ";
    }
    cout << endl;
}

const Room nextMove(const Room& currentRoom) {
    char direction;
    cout << "Enter your move (u)p, (d)own, (l)eft, (r)ight, or (q)uit: ";
    cin >> direction;

    if (direction == 'q') {
        return { -1, '*' };
    }

    Room newRoom = createAdjacent(currentRoom, direction);
    RoomPair moveAttempt = { currentRoom, newRoom };

    // Check if there is a wall between the current room and the new room
    if (!checkMaze(myMaze, moveAttempt)) {
        return currentRoom;
    }

    return newRoom;
}

