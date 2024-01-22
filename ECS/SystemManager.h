#pragma once

#include "Systems/System.h"
#include <vector>
#include <cassert>

class SystemManager {

    public:

        void registerSystem(System&);
        void updateSystems(float);


    private:

        bool isRegistered(System&);
        std::vector<std::pair<int, System>> systems;

};