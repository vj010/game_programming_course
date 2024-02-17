#include <game.h>

void Game::run()
{
    std::cout << "hello world" << std::endl;
}

int main()
{
    Game game;
    game.run();
    std::cin.get();
}
