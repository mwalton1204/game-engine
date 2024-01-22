#include "SystemManager.h"

void SystemManager::registerSystem(System& system) {
assert(!isRegistered(system) && "registerSystem: System already registered");

systems.push_back({system.getPriority(), system});
}

void SystemManager::updateSystems(float dt) {

    for(auto pair : systems) {
        pair.second.update(dt);
    }

}

bool SystemManager::isRegistered(System& system) {
    bool isRegistered = false;
    
    for(auto pair : systems) {
        if(pair.first == system.getPriority()) {
            isRegistered = true;
        }
    }

    return isRegistered;
}