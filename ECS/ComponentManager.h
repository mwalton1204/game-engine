#pragma once

#include <vector>
#include <array>
#include <unordered_map>
#include <queue>
#include <cassert>
#include "Constants.h"

class ComponentManager {

    public:

        ComponentManager();

        template <typename T>
        void registerComponent();
        template <typename T>
        void addComponent(Entity, Component, T);
        void removeComponent(Entity, Component);
        void entityDestroyed(Entity);
        template <typename T>
        T& getComponent(Entity, Component);

    private:

        std::array<std::unordered_map<int, const char*>, MAX_COMPONENTS> componentMap; // <Component ID, Component Type>
        std::array<std::unordered_map<int, int>, MAX_COMPONENTS> entityIndexKey; // <Component ID, Vector of Entity Data>
        
        std::queue<Component> availableComponentIDs{};

        int qtyComponents;
};


template <typename T>
void ComponentManager::registerComponent() {

    const char* typeName = typeid(T).name(); // What component are you registering

    newComponentID = availableComponentIDs.front();
    availableComponentIDs.pop();



}


template <typename T>
void ComponentManager::addComponent(Entity entityID, Component componentID, T data) {

}