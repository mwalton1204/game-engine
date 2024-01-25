#pragma once

#include <queue>
#include <vector>
#include <algorithm>
#include "Constants.h"

class EntityManager {

    public:

        EntityManager();

        Entity createEntity();
        void destroyEntity(Entity);
        ComponentTracker getComponentTracker(Entity);

    private:

        std::queue<Entity> availableIDs{};
        std::vector<std::pair<Entity, ComponentTracker>> livingEntities;

        int qtyEntities = livingEntities.size();
};


//TODO: convert tracker from array to vector and create key