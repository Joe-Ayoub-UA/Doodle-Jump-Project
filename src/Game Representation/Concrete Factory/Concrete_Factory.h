//
// Created by Joe Ayoub on 14/11/24 at 16:06.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_CONCRETE_FACTORY_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_CONCRETE_FACTORY_H

#include <iostream>
#include <memory>
#include <string>
#include "../../Logic Library/Abstract Factory/Abstract_Factory.h"
#include "../../Game Representation/Player/Player.h"
#include "../../Game Representation/Platform/Platform.h"
#include "../../Game Representation/BG Tile/BG_Tile.h"
#include "../../Game Representation/Bonus/Bonus.h"


class Concrete_Factory : public Abstract_Factory {
public:
    std::shared_ptr<Logic_Library::Player> createPlayer() override;

    std::shared_ptr<Logic_Library::Platform> createPLatform(std::string type, float x, float y) override;

    std::shared_ptr<Logic_Library::BG_Tile> createBG_Tile() override;

    std::shared_ptr<Logic_Library::Bonus> createBonus() override;
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_CONCRETE_FACTORY_H
