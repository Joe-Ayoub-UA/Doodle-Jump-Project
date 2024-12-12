//
// Created by Joe Ayoub on 14/11/24 at 15:21.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_WORLD_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_WORLD_H
#include <iostream>
using namespace std;
#include "../Entity Model/Entity_Model.h"
#include "../Player/Player.h"
#include "../Abstract Factory/Abstract_Factory.h"
#include "../../Game Representation/Concrete Factory/Concrete_Factory.h"

class World {
public:
    World();

    void createPlayer();

    void loadWorld();
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_WORLD_H
