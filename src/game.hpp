#ifndef GAME_H
#define HAME_H

class Game {
    private:
        int mSize = 4;
        int mBoard[4][4];

    public:
        Game();
        void initializeBoard();
        void createRandomTile();
        void printBoard();
        bool isFinished();
};

#endif