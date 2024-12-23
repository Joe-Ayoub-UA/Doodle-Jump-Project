//
// Created by Joe Ayoub on 14/11/24 at 15:21.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_WORLD_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_WORLD_H
#include <iostream>
#include <vector>
using namespace std;
#include "../../Config.h"

#include "../Entity Model/Entity_Model.h"
#include "../../Game Representation/Entity View/Entity_View.h"

#include "../../Logic Library/Observer/Observer.h"
#include "../../Logic Library/Subject/Subject.h"

#include "../../Logic Library/Player/Player.h"
//#include "../../_Game Representation/Player_logic/Player_logic.h"

#include "../../Logic Library/BG Tile/BG_Tile.h"
//#include "../../_Game Representation/BG Tile/BG_Tile.h"

#include "../../Utilities/Random/Random.h"
#include "../../Utilities/Coordinates/Coordinates.h"

#include "../Abstract Factory/Abstract_Factory.h"
#include "../../Game Representation/Concrete Factory/Concrete_Factory.h"


/**
 * @brief Class that represents the world of the game
 */
class World {
private:
    std::shared_ptr<Concrete_Factory> CF;

    std::shared_ptr<Logic_Library::Player> mPlayer;

    std::vector<std::shared_ptr<Logic_Library::Platform>> mPlatforms;

    std::vector<std::shared_ptr<Logic_Library::BG_Tile>> mBG_Tiles;

    std::vector<std::shared_ptr<Logic_Library::Bonus>> mBonuses;
public:
    World();

    void createPlayer();

    void createPlatform();

    Logic_Library::Platform findLowestPlatform();

    Logic_Library::Platform findHighestPlatform();

    bool isPlatformNeeded();

    void removePlatform(const std::shared_ptr<Logic_Library::Platform>& platform);

    void setupWorld();
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_WORLD_H
