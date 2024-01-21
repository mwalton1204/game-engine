#pragma once

#include "../Constants.h"
#include "System.h"

class PlayerMovement : public System {

    public:

        void update(ComponentManager&);
        int getPriority();

    private:

        int updatePriority;

};