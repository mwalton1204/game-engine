#include "EntityManager.h"

EntityManager::EntityManager() {
    for (Entity i = 0; i < MAX_ENTITIES; i++) {
        availableIDs.push(i);
    }
}

Entity EntityManager::createEntity() {
    Entity newEntity = availableIDs.front(); // Assign first available id to new entity
    availableIDs.pop(); // Remove selected id from available id's

    ComponentTracker newTracker; // Create new component tracker
    livingEntities.push_back({newEntity, newTracker}); // Add new entity and its tracker to vector of living entites

    return newEntity; // Return id of new entity
}

void EntityManager::destroyEntity(Entity id) {

    for (auto it = livingEntities.begin(); it != livingEntities.end(); ++it) {
        if(id == it->first) {
            it = livingEntities.erase(it);
        }
    }
    availableIDs.push(id); // Put destroyed entity id on back of array of available id's
}

ComponentTracker EntityManager::getComponentTracker(Entity id) {
    ComponentTracker tracker;
    
    for(const auto& pair : livingEntities) {
        if(id == pair.first) {
            tracker = pair.second;
        }
    }

    return tracker;
}

std::vector<int> EntityManager::getLivingEntities() {
    std::vector<int> entities;

    for(const auto& pair : livingEntities) {
        entities.push_back(pair.first);
    }

    return entities;
}