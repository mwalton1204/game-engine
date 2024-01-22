#pragma once

#include <set>
#include "../ComponentManager.h"
#include "../Constants.h"

class System {

    public:

        virtual void update(float);
        virtual int getPriority();

};