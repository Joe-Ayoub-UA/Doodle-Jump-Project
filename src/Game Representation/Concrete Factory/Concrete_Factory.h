//
// Created by Joe Ayoub on 14/11/24 at 16:06.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_CONCRETE_FACTORY_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_CONCRETE_FACTORY_H

#include "../../Logic Library/Abstract Factory/Abstract_Factory.h"
#include <iostream>
#include <memory>
#include "../../Game Representation/Player/Player.h"
#include "../../Game Representation/Platform/Platform.h"

class Concrete_Factory : public Abstract_Factory {
public:
    std::shared_ptr<Game_Repr::Player> createPlayer() override;

    std::shared_ptr<Game_Repr::Platform> createPLatform(int x, int y) override;
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_CONCRETE_FACTORY_H
