//
// Created by s0230501 on 14/11/24.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_PLATFORM_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_PLATFORM_H

#include "../Entity Model/Entity_Model.h"
namespace Logic_Library {
    class Platform : Entity_Model {
    private:
        int x;
        int y;
    public:
        Platform(int x, int y);
    };
}



#endif //INC_2024_PROJECT_JOE_AYOUB_UA_PLATFORM_H
