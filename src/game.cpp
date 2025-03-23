#include "Game.hpp"
#include <iostream> 

Game::Game() {
    initializeBoard();
    printBoard();
}

void Game::initializeBoard() {
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            mBoard[i][j] = 0;
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