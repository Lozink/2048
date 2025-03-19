#include <iostream>

class Game {
    public:
        Game() {
            std::cout << "hello" << std::endl;
        }
};

int main() {
    Game game;
    return 0;
}