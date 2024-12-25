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
class World;
/**
 * Abstract Factory class that creates the player, platform, background tile, bonus etc...
 */
class Abstract_Factory {
public:
    /**
     * @brief Creates a player
     * @return a shared pointer to the player
     */
    virtual std::shared_ptr<Logic_Library::Player> createPlayer()=0;

    /**
     * @brief Creates a platform
     * @return a shared pointer to the platform
     */
    virtual std::shared_ptr<Logic_Library::Platform> createPlatform(float x, float y)=0;

    /**
     * @brief Creates a background tile
     * @return a shared pointer to the background tile
     */
    virtual std::shared_ptr<Logic_Library::BG_Tile> createBGTile()=0;

    /**
     * @brief Creates a bonus
     * @return a shared pointer to the bonus
     */
    virtual std::shared_ptr<Logic_Library::Bonus> createBonus()=0;

    /**
     * @brief Creates a world
     * @return a shared pointer to the world
     */
    virtual std::shared_ptr<World> createWorld()=0;

    virtual void assignObserver(std::shared_ptr<Observer> observer)=0;

    virtual void deleteObserver()=0;

    virtual void notifyObserver()=0;
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_ABSTRACT_FACTORY_H
