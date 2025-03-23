#include "Game.hpp"
#include <iostream> 

Game::Game() {
    srand(time(0));
    initializeBoard();
}

void Game::initializeBoard() {
    for (int i = 0; i < mSize; i++) {
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