#include <iostream>
#include "src/Game.hpp"
#include <unistd.h> 
#include <conio.h>

int main() {
    Game game;
    game.createRandomTile();
    game.printBoard();
    bool gameFinished = false;
    while (!gameFinished) {
        switch (_getch()) {
            case 122:    // key up
                game.moveUp();
                break;
            case 115:    // key down
                game.moveDown();
                break;
            case 100:    // key right
                game.moveRight();
                break;
            case 113:    // key left
                game.moveLeft();
                break;
            case 101:
                std::cout << "Quitting game." << std::endl;
                gameFinished = true;
                break;
        }

        if (game.isWon()) {
            std::cout << "Game won !" << std::endl;
            gameFinished = true;
        } else if (!gameFinished && game.getMoveMade()) {
            game.createRandomTile();
            game.printBoard();
            if (game.isBoardFull()) {
                if (game.isLost()) {
                    std::cout << "Game is lost." << std::endl;
                    gameFinished = true;
                }
            }
        }
    }

    return 0;
}