//Brandon Angell
//10/31/2023
//To implement the class functions of lab9

#include "maze.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cin; using std::cout; using std::endl;

Room::Room() : x_(-1), y_('*') {}

void Room::pick() {
    x_ = rand() % mazeSize_ + 1;
    y_ = 'a' + rand() % mazeSize_;
}

bool Room::goodDirection(const char dr) const {
    if (dr == 'u' && y_ > 'a') {
        return true;
    }
    else if (dr == 'd' && y_ < 'a' + mazeSize_ - 1) {
        return true;
    }
    else if (dr == 'l' && x_ > 1) {
        return true;
    }
    else if (dr == 'r' && x_ < mazeSize_) {
        return true;
    }
    return false;
}

const Room Room::createAdjacent(const char dr) const {
    Room adjRoom = *this;
    switch (dr) {
    case 'u':
        adjRoom.y_--;
        break;
    case 'd':
        adjRoom.y_++;
        break;
    case 'l':
        adjRoom.x_--;
        break;
    case 'r':
        adjRoom.x_++;
        break;
    }
    return adjRoom;
}

const Room Room::pickAdjacent() {
    char directions[] = { 'u', 'd', 'l', 'r' };
    char randomDirection;
    do {
        randomDirection = directions[rand() % 4];
    } while (!goodDirection(randomDirection));

    return createAdjacent(randomDirection);
}

const Room Room::nextMove() const {
    char direction;
    cout << "Enter your move (u)p, (d)own, (l)eft, (r)ight, or (q)uit: ";
    cin >> direction;

    if (direction == 'q') {
        return Room(); // Return default-constructed Room object {-1, '*'}
    }

    Room newRoom = createAdjacent(direction);
    if (goodDirection(direction)) {
        return newRoom;
    }
    else {
        cout << "Invalid move! ";
        return *this;
    }
}

void Room::print() const {
    cout << y_ << "" << x_;
}

bool matchRoom(const Room& r1, const Room& r2) {
    return r1.x_ == r2.x_ && r1.y_ == r2.y_;
}

bool matchPair(const RoomPair& rp1, const RoomPair& rp2) {
    return (matchRoom(rp1.one_, rp2.one_) && matchRoom(rp1.two_, rp2.two_)) ||
        (matchRoom(rp1.one_, rp2.two_) && matchRoom(rp1.two_, rp2.one_));
}

bool Maze::checkMaze(const RoomPair& rp) const {
    for (int i = 0; i < numWalls_; ++i) {
        if (matchPair(walls_[i], rp)) {
            return true;
        }
    }
    return false;
}

void RoomPair::pick() {
    one_.pick();
    two_ = one_.pickAdjacent();
}

void RoomPair::print() const {
    one_.print();
    cout << "|";
    two_.print();
    cout << " ";
}

Maze::Maze() {
    currentRoom_.makeStartRoom();
}

void Maze::print() const {
    cout << "Maze walls:" << endl;
    for (int i = 0; i < numWalls_; ++i) {
        walls_[i].print();
    }
    cout << endl;
    cout << "Current mouse location: ";
    currentRoom_.print();
    cout << endl;
}

void Maze::build() {
    for (int i = 0; i < numWalls_; ++i) {
        RoomPair Candidate;
        do {
            Candidate.pick();
        } while (checkMaze(Candidate));
        walls_[i] = Candidate;
    }

}

bool Maze::move(const Room& r) {
    RoomPair moveAttempt = { currentRoom_, r };
    if (!checkMaze(moveAttempt)) {
        currentRoom_ = r;
        return true;
    }
    else {
        cout << "Wall! Mouse cannot move there." << endl;
        return false;
    }
}