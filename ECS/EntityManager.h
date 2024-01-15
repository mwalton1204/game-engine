#pragma once

#include <queue>
#include "Constants.h"

class EntityManager {

    public:

    EntityManager();
    ~EntityManager();

    private:

    std::queue<Entity> availableEntities{};

};