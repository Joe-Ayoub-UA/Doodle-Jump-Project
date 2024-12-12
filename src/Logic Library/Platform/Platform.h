//
// Created by s0230501 on 14/11/24.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_PLATFORM_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_PLATFORM_H

#include "../Entity Model/Entity_Model.h"
#include <string>

namespace Logic_Library {
    class Platform : Entity_Model {
    private:
        int x{};
        int y{};
        std::string pType{};
    public:
        Platform() = default;

        explicit Platform(std::string type,int x, int y) : pType(std::move(type)), x(x), y(y) {}

        std::string getPType() { return pType; }
    };
}



#endif //INC_2024_PROJECT_JOE_AYOUB_UA_PLATFORM_H
