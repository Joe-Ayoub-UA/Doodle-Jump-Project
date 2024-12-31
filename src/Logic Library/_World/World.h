//
// Created by Joe Ayoub on 14/11/24 at 15:21.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_WORLD_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_WORLD_H
#include <iostream>
#include <vector>
#include <optional>
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

#include "../../Logic Library/Score/Score.h"


/**
 * @brief Class that represents the world of the game
 */
class World {
private:
    /// @brief Concrete Factory of the World
    std::shared_ptr<Concrete_Factory> CF;

    /// @brief Player of the game
    std::shared_ptr<Logic_Library::Player> mPlayer;

    /// @brief Platforms of the game
    std::vector<std::shared_ptr<Logic_Library::Platform>> mPlatforms;

    /// @brief Background tiles of the game
    std::vector<std::shared_ptr<Logic_Library::BG_Tile>> mBG_Tiles;

    /// @brief Bonuses of the game
    std::vector<std::shared_ptr<Logic_Library::Bonus>> mBonuses;
public:
    /**
     * @brief Default constructor for the World class
     */
    World();

    /**
     * @brief Destructor for the World class
     */
    ~World()=default;

    /**
     * @brief Function to create the player
     */
    void createPlayer();

    /**
     * @brief Function to create a platform
     */
    bool createPlatform(const std::optional<Coordinates>& coordinate = std::nullopt);
    /**
     * @brief Function to create a background tile
     */
    void createBGTile();

    /**
     * @brief Function to create a bonus
     */
    void createBonus();

    /**
     * @brief Function to check if a platform's position is valid. Called before a platform is officially created
     * @param coordinate
     * @return true or false depending on the validity of the platform's positioning
     */
    bool checkValidPlatform(const Coordinates& coordinate);

    bool checkCollision();

    /**
     * @brief Function to find the lowest platform
     * @return shared pointer to the lowest platform
     */
    Logic_Library::Platform findLowestPlatform();

    /**
     * @brief Function to find the highest platform
     * @return shared pointer to the highest platform
     */
    Logic_Library::Platform findHighestPlatform();

    /**
     * @brief Function to check if a new platform is needed
     * @return true or false depending on the necessity of a new platform
     */
    bool isPlatformNeeded();

    bool isPlatformNotNeeded();

    /**
     * @brief Function to remove a platform
     * @param platform
     */
    void removePlatform(const std::shared_ptr<Logic_Library::Platform>& platform);

    /**
     * @brief Function to setup the world
     */
    void setupWorld();

    /**
     * @brief Function to update the world
     */
    void updateWorld();

    /**
     * @brief Function to move the platforms down when the player reaches the half of the window
     * @param moveDownDistance
     */
    void movePlatformsDown(float moveDownDistance);

    /**
     * @brief Function to update the platforms depending on their type
     */
    void updatePlatforms();

    /**
     * @brief Function to get the concrete factory
     * @return shared pointer to the concrete factory
     */
    const std::shared_ptr<Concrete_Factory> &getCf() const;

    /**
     * @brief Function to set the concrete factory
     * @param cf
     */
    void setCf(const std::shared_ptr<Concrete_Factory> &cf);

    /**
     * @brief Function to get the player
     * @return shared pointer to the player
     */
    const std::shared_ptr<Logic_Library::Player> &getMPlayer() const;

    /**
     * @brief Function to set the player
     * @param mPlayer
     */
    void setMPlayer(const std::shared_ptr<Logic_Library::Player> &mPlayer);

    /**
     * @brief Function to get the platforms
     * @return vector of shared pointers to the platforms
     */
    const std::vector<std::shared_ptr<Logic_Library::Platform>> &getMPlatforms() const;

    /**
     * @brief Function to set the platforms
     * @param mPlatforms
     */
    void setMPlatforms(const std::vector<std::shared_ptr<Logic_Library::Platform>> &mPlatforms);

    /**
     * @brief Function to get the platform
     * @param platform
     * @return shared pointer to the platform
     */
    std::shared_ptr<Logic_Library::Platform> getMPlatform(std::shared_ptr<Logic_Library::Platform>& platform);

    /**
     * @brief Function to get the background tiles
     * @return vector of shared pointers to the background tiles
     */
    const std::vector<std::shared_ptr<Logic_Library::BG_Tile>> &getMbgTiles() const;

    /**
     * @brief Function to set the background tiles
     * @param mBgTiles
     */
    void setMbgTiles(const std::vector<std::shared_ptr<Logic_Library::BG_Tile>> &mBgTiles);

    /**
     * @brief Function to get the background tile
     * @param bgTile
     * @return shared pointer to the background tile
     */
    std::shared_ptr<Logic_Library::BG_Tile> getMBGTile(std::shared_ptr<Logic_Library::BG_Tile>& bgTile);

    /**
     * @brief Function to get the bonuses
     * @return vector of shared pointers to the bonuses
     */
    const std::vector<std::shared_ptr<Logic_Library::Bonus>> &getMBonuses() const;

    /**
     * @brief Function to set the bonuses
     * @param mBonuses
     */
    void setMBonuses(const std::vector<std::shared_ptr<Logic_Library::Bonus>> &mBonuses);

    /**
     * @brief Function to get the score
     * @return shared pointer to the score
     */

    /**
     * @brief Function to set the score
     * @param mScore
     */
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_WORLD_H
