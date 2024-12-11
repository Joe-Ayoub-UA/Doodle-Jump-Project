//
// Created by s0230501 on 14/11/24.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_H

#include "../Entity Model/Entity_Model.h"

namespace Logic_Library {
    class Player : public Entity_Model {
    private:
        float horizontalSpeed = 350.f;
    };
}



#endif //INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_H
