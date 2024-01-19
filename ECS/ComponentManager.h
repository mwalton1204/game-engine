#pragma once

#include <vector>
#include <array>
#include <unordered_map>
#include <queue>
#include <cassert>
#include "Constants.h"

class ComponentManager {

    public:

        void registerComponent();
        void addComponent(Entity, Component, ComponentType);
        void removeComponent(Entity, Component);
        void entityDestroyed(Entity);

    private:

        std::array<std::vector<ComponentType>, MAX_COMPONENTS> componentArray;
        std::array<std::unordered_map<int, int>, MAX_COMPONENTS> entityIndexKey;
        
        std::queue<Component> availableComponentIDs{};

        int qtyComponents;
};