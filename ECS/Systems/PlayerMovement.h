#pragma once

#include "../Constants.h"
#include "System.h"

class PlayerMovement : public System {

    public:

        void update(ComponentManager&);
        int getPriority() override;

    private:

        int updatePriority;

};