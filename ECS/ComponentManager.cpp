#include "ComponentManager.h"

void ComponentManager::registerComponent() {
    Component newComponent = availableComponents.front(); // Assign first available id to new component
    availableComponents.pop(); // Remove selected id from available id's
    std::array<ComponentType, MAX_ENTITIES> newComponentData{}; // Make array for new component's data
    dataArray.push_back(newComponentData); // Add data to componentData array
    componentArrayKey.insert({newComponent, dataArray.size() - 1}); // Pair new id with array index
}

void ComponentManager::addComponent(Entity entityID, Component componentID, ComponentType data) {
    assert(entityID >= 0 && entityID < MAX_ENTITIES && "Invalid entityID");
    assert(componentID >= 0 && componentID < MAX_COMPONENTS && "Invalid componentID");

    auto it = componentArrayKey.find(componentID); // Verify component exists

    assert(it != componentArrayKey.end() && "Component not found in componentArrayKey");

    int componentIndex = it->second; // Get index of component to be added

    assert(componentIndex >= 0 && componentIndex < dataArray.size() && "Invalid componentIndex");
    dataArray[componentIndex][entityID] = data;
}