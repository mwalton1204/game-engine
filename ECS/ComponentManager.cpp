#include "ComponentManager.h"

void ComponentManager::registerComponent() {
    Component newComponent = availableComponents.front(); // Assign first available id to new component
    availableComponents.pop(); // Remove selected id from available id's
    std::array<ComponentType, MAX_ENTITIES> newComponentData{}; // Make array for new component's data
    componentDataArray.push_back(newComponentData); // Add data to componentData array
    componentArrayKey.insert({newComponent, componentDataArray.size() - 1}); // Pair new id with new array in key
}

void ComponentManager::addComponent(Entity entityID, Component componentID) {
    auto it = componentArrayKey.find(componentID); // Check if there is an entry in key with the component id
    
    if (it != componentArrayKey.end()) { // if ID is in key, get index for componentDataArray
        int dataIndex = it->second;
    }

    
}