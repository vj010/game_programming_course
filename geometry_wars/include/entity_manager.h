#ifndef entityManagerH
#define entityManagerH

#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>

#include "entities.h"

class EntityManager
{
private:
    long long enitityCount = 0;

public:
    std::shared_ptr<Entities> createEntity(std::string tag);
    // std::shared_ptr<Entities> getEntityByTag(const std::string &tag) const;
    std::vector<std::shared_ptr<Entities>> entityList;
    std::unordered_map<std::string, std::shared_ptr<Entities>> entitiesByTag;
};

#endif
