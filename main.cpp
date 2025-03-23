#include <iostream>
#include "src/Game.hpp"
#include <unistd.h>

int main() {
    Game game;

    bool gameFinished = false;
    while (!gameFinished) {
        game.createRandomTile();
        game.printBoard();
        sleep(1);
        if (game.isFinished()) {
            gameFinished = true;
        }
    }

    return 0;
}