#ifndef entitiesH
#define entitiesH
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
class Entities
{

public:
    std::shared_ptr<InputComponent> inputComponent;
    std::shared_ptr<TransformComponent> transformComponent;
    std::shared_ptr<LifeSpanComponent> transformComponent;
    std::shared_ptr<LifeSpanComponent> transformComponent;
    std::shared_ptr<sf::CircleShape> circleShape;
    std::string tag;

    Entities(std::string &&tag);
};

#endif
