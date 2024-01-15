#pragma once

#include <vector>
#include <array>
#include <unordered_map>
#include <queue>
#include "Constants.h"

class ComponentManager {

    public:

    void registerComponent();
    void addComponent(Entity);
    void removeComponent(Entity, Component);

    private:

        std::vector<std::array<ComponentType, MAX_ENTITIES>> componentData{};
        std::unordered_map<int, int> componentArrayKey{};
        std::queue<Component> availableComponents{};
};

        
