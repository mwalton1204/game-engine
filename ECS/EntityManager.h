#pragma once

#include <queue>
#include <array>
#include "Constants.h"

class EntityManager {

    public:

    EntityManager();

    Entity createEntity();
    void destroyEntity(Entity);
    ComponentTracker getComponentTracker(Entity);

    private:

    std::queue<Entity> availableEntities{};
    std::array<ComponentTracker, MAX_ENTITIES> componentTrackers{};

    int livingEntities;

};