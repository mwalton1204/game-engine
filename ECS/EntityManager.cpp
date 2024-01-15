#include "EntityManager.h"

EntityManager::EntityManager() {
    for (Entity i = 0; i < MAX_ENTITIES; i++) {
        availableEntities.push(i);
    }
}