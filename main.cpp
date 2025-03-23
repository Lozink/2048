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
                break;
            case 115:    // key down
                break;
            case 100:    // key right
                break;
            case 113:    // key left
                game.moveLeft();
                break;
            case 101:
                gameFinished = true;
        }

        if (game.isFinished()) {
            gameFinished = true;
        }
        
        game.createRandomTile();
        game.printBoard();

    }

    return 0;
}