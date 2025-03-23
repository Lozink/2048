#ifndef GAME_H
#define HAME_H

class Game {
    private:
        int mSize = 4;
        int** mBoard;
        bool mMoveMade;

    public:
        Game();
        ~Game();
        void initializeBoard();
        void createRandomTile();

        bool getMoveMade();

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();

        bool isWon();
        bool isBoardFull();
        bool isLost();
        void printBoard();
};

#endif