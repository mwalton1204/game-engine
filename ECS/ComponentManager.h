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

    private:

        std::vector<std::array<ComponentType, MAX_ENTITIES>> dataArray{};
        std::unordered_map<int, int> componentArrayKey{};
        std::queue<Component> availableComponents{};
        int qtyComponents = dataArray.size();
};

        
