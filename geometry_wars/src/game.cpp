#include <game.h>
Game::Game()
{
    window.create(sf::VideoMode(700, 500), "Sfml test");
}
void Game::run()
{
    std::cout << "hello world" << std::endl;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }

    std::cin.get();
}
