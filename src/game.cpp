#include "Game.hpp"
#include <iostream> 

Game::Game() {
    srand(time(0));
    initializeBoard();
}

Game::~Game() {
    for (int i = 0; i < mSize; i++) {
        delete []mBoard[i];
    }
    delete []mBoard;
}

void Game::initializeBoard() {
    mBoard = new int*[4];
    for (int i = 0; i < mSize; i++) {
        mBoard[i] = new int[4];
        for (int j = 0; j < mSize; j++) {
            mBoard[i][j] = 0;
        }
    }
}

void Game::createRandomTile() {
    bool randomTileCreated = false;
    while (!randomTileCreated) {
        int randomLine = rand() % 4;
        int randomColumn = rand() % 4;
        if (mBoard[randomLine][randomColumn] == 0) {
            int randomValue = rand();
            if ((randomValue % 10) <= 8) {
                mBoard[randomLine][randomColumn] = 2;
            } else {
                mBoard[randomLine][randomColumn] = 4;
            }
            randomTileCreated = true;
        }
    }
}

void Game::moveLeft() {
    for (int i = 0; i < mSize; i++) {
        for (int j = 1; j < mSize; j++) {
            if (mBoard[i][j] != 0) {
                int currentPlace = j;
                while (mBoard[i][currentPlace-1] == 0) {
                    mBoard[i][currentPlace-1] = mBoard[i][currentPlace];
                    mBoard[i][currentPlace] = 0;
                    currentPlace -= 1;
                    if (currentPlace == 0) {
                        break;
                    }
                }
                if (currentPlace > 0) {
                    if (mBoard[i][currentPlace-1] == mBoard[i][currentPlace]) {
                        mBoard[i][currentPlace-1] *= 2;
                        mBoard[i][currentPlace] = 0;
                    }
                }
            }
        }
    }
}

void Game::printBoard() {
    std::cout << "_________________" << std::endl;
    for (int i = 0; i < mSize; i++) {
        std::cout << "|   |   |   |   |" << std::endl;
        std::cout << "| ";
        for (int j = 0; j < mSize; j++) {
            std::cout << mBoard[i][j] << " | ";
        }
        std::cout << std::endl << "|___|___|___|___|" << std::endl;
    }
}

bool Game::isFinished() {
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            if (mBoard[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}