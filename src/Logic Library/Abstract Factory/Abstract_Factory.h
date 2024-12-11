//
// Created by Joe Ayoub on 14/11/24 at 16:06.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_ABSTRACT_FACTORY_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_ABSTRACT_FACTORY_H
#include <iostream>
#include <memory>
#include "../../Game Representation/Player/Player.h"
#include "../../Game Representation/Platform/Platform.h"

namespace Game_Repr {
    class Player;   // Forward declaration
    class Platform; // Forward declaration (if needed)
}

class Abstract_Factory {
public:
    virtual std::shared_ptr<Game_Repr::Player> createPlayer()=0;

    virtual std::shared_ptr<Game_Repr::Platform> createPLatform(int x, int y)=0;
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_ABSTRACT_FACTORY_H
