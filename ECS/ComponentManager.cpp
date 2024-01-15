#include "ComponentManager.h"

void ComponentManager::registerComponent() {
    Component newComponent = availableComponents.front(); // Assign first available id to new component
    std::array<ComponentType, MAX_ENTITIES> newComponentData{}; // Make array for new component's data
    componentData.push_back(newComponentData); // Add data to componentData array
    componentArrayKey.insert({newComponent, componentData.size() - 1}); // Pair new id with new array in key
}