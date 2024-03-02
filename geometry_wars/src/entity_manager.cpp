#include "entity_manager.h"

std::shared_ptr<Entities> EntityManager ::createEntity(std ::string tag)
{
    std::shared_ptr<Entities> entity(new Entities(tag));
    entityList.push_back(entity);
    entitiesByTag[tag] = entity;
    return entity;
}
