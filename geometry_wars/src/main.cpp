#include <game.h>

int main()
{
    Game game;
    game.init("../config.txt");
    game.run();
}
