#ifndef GAME_H
#define HAME_H

class Game {
    private:
        int mSize = 4;
        int** mBoard;

    public:
        Game();
        ~Game();
        void initializeBoard();
        void createRandomTile();

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();

        void printBoard();
        bool isFinished();
};

#endif