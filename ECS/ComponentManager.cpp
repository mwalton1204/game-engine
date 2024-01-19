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

void ComponentManager::removeComponent(Entity entityID, Component componentID) {
    assert(entityID >= 0 && entityID < MAX_ENTITIES && "removeComponent: Invalid Entity ID");
    assert(componentID >= 0 && componentID < MAX_COMPONENTS && "removeComponent: Invalid Component ID");
    assert(entityIndexKey[componentID].count(entityID) && "removeComponent: Entity does not have this component");


    // "For this component, get the index of the data for this entity"
    int indexToRemove = entityIndexKey[componentID].find(entityID)->second;
    // "For this component, erase the data for this entity"
    componentArray[componentID].erase(componentArray[componentID].begin() + indexToRemove);

    // "Remove this entity from the key"
    entityIndexKey[componentID].erase(entityID);
}

void ComponentManager::entityDestroyed(Entity entityID) {
    // For each possible component ID
    for(int i = 0; i < MAX_COMPONENTS; i++) {
        // Check if entity has the component
        auto it = entityIndexKey[i].find(entityID);
        if(it != entityIndexKey[i].end()) {
            // Remove the entity data from this component
            int indexToRemove = it->second;
            componentArray[i].erase(componentArray[i].begin() + indexToRemove);
            // Remove entity from key for this component
            entityIndexKey[i].erase(it);
        }
    }
}