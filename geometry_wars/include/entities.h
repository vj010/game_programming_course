#ifndef entitiesH
#define entitiesH

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

class Entities
{

    Entities(std::string playerTag);

public:
    // std::shared_ptr<InputComponent> inputComponent;
    // std::shared_ptr<TransformComponent> transformComponent;
    // std::shared_ptr<LifeSpanComponent> transformComponent;
    // std::shared_ptr<LifeSpanComponent> transformComponent;
    std::shared_ptr<sf::CircleShape> circleShape;
    std::string tag;
    friend class EntityManager;
};

#endif
