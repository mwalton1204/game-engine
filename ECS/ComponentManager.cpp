#include "ComponentManager.h"

void ComponentManager::registerComponent() {
    assert(!availableComponentIDs.empty() && "registerComponent: No available component ID");

    Component newComponent = availableComponentIDs.front();
    availableComponentIDs.pop();

    qtyComponents++;
}

void ComponentManager::addComponent(Entity entityID, Component componentID, ComponentType data) {
    assert(entityID >= 0 && entityID < MAX_ENTITIES && "addComponent: Invalid Entity ID");
    assert(componentID >= 0 && componentID < MAX_COMPONENTS && "addComponent: Invalid Component ID");
    assert(!entityIndexKey[componentID].count(entityID) && "addComponent: Entity already has this component");

    componentArray[componentID].push_back(data);

    // "For this component, this entity's data is stored at this index"
    int entityIndex = componentArray[componentID].size() - 1;
    entityIndexKey[componentID].insert({entityID, entityIndex});
}