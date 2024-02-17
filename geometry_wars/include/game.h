#ifndef gameh
#define gameh
#include <iostream>
#include <SFML/Graphics.hpp>
#include <utility>
#include <memory>
#include "imgui.h"
#include "imgui-SFML.h"

class Game
{
    sf::RenderWindow window;

public:
    Game();
    void run();
};

#endif
