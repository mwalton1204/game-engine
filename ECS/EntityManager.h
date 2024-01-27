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
        std::vector<int> getLivingEntities();

    private:

        std::queue<Entity> availableIDs{};
        std::vector<std::pair<Entity, ComponentTracker>> livingEntities;

        int qtyEntities = livingEntities.size();
};