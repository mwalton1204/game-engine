#pragma once

#include <set>
#include "../ComponentManager.h"
#include "../Constants.h"

class System {

    public:

        std::set<Entity> entities;
        virtual int getPriority();
};