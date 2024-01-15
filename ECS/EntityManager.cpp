#include "EntityManager.h"

EntityManager::EntityManager() {
    for (Entity i = 0; i < MAX_ENTITIES; i++) {
        availableEntities.push(i);
    }
}

Entity EntityManager::createEntity() {
    Entity newEntity = availableEntities.front(); // Assign first available id to new entity
    availableEntities.pop(); // Remove selected id from available id's
    livingEntities++; // Increment living entities count

    return newEntity; // Return id of new entity
}

void EntityManager::destroyEntity(Entity id) {
    componentTrackers[id].reset(); // Reset the component tracker for entity to be destroyed
    availableEntities.push(id); // Put destroyed entity id on back of array of available id's
    livingEntities--; // Decrement living entities count
}

ComponentTracker EntityManager::getComponentTracker(Entity id) {
    return componentTrackers[id];
}