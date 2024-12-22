//
// Created by Joe Ayoub on 14/11/24 at 16:06.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_ABSTRACT_FACTORY_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_ABSTRACT_FACTORY_H
#include <iostream>
#include <memory>
#include <string>


#include "../../Logic Library/Player/Player.h"
#include "../../Logic Library/Platform/Platform.h"
#include "../../Logic Library/BG Tile/BG_Tile.h"
#include "../../Logic Library/Bonus/Bonus.h"


class Abstract_Factory {
public:
    virtual std::shared_ptr<Logic_Library::Player> createPlayer()=0;

    virtual std::shared_ptr<Logic_Library::Platform> createPLatform(std::string type, float x, float y)=0;

    virtual std::shared_ptr<Logic_Library::BG_Tile> createBG_Tile()=0;

    virtual std::shared_ptr<Logic_Library::Bonus> createBonus()=0;
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_ABSTRACT_FACTORY_H
