//
// Created by Joe Ayoub on 16/11/24 at 20:04.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_CONTROLLER_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_CONTROLLER_H
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include "../Logic Library/_World/World.h"


/**
 * @brief Class that is responsible of handling changes
 */
class Controller {
private:
    ///@brief World of the game
    std::shared_ptr<World> world;
public:
    /**
     * @brief Default constructor for the Controller class
     */
    Controller();

    /**
     * @brief Constructor for the Controller class
     * @param world
     */
    explicit Controller(const std::shared_ptr<World>& world) : world(world) {}

    /**
     * @brief Function to move the player to the right
     */
    void movePlayerRight();

    /**
     * @brief Function to move the player to the left
     */
    void movePlayerLeft();

    /**
     * @brief Function to handle the situation when the player is out of bounds
     */
    void outOfBounds() {world->getMPlayer()->teleportPlayer(world->getMPlayer()->getObserver()->getPosition());}

    /**
     * @brief Function to check if there is a collision
     * @return true if there is a collision, false otherwise
     */
    bool checkCollision() {return world->checkCollision();}

    /**
     * @brief Function to make the player jump
     */
    void jumpPlayer();

    /**
     * @brief Function to apply gravity to the player
     */
    void applyGravity();

    /**
     * @brief Function to move the platform to the right
     * @param platform
     */
    void movePlatformRight(std::shared_ptr<Logic_Library::Platform>& platform);

    /**
     * @brief Function to move the platform to the left
     * @param platform
     */
    void movePlatformLeft(std::shared_ptr<Logic_Library::Platform>& platform);

    /**
     * @brief Function to move the platform up
     * @param platform
     */
    void movePlatformUp(std::shared_ptr<Logic_Library::Platform>& platform);

    /**
     * @brief Function to move the platform down
     * @param platform
     */
    void movePlatformDown(std::shared_ptr<Logic_Library::Platform>& platform);

    /**
     * @brief Function to move the background tile up
     * @param bgTile
     */
    void moveBGTileUp(std::shared_ptr<Logic_Library::BG_Tile>& bgTile);

    /**
     * @brief Function to move the background tile down
     * @param bgTile
     */
    void moveBGTileDown(std::shared_ptr<Logic_Library::BG_Tile>& bgTile);

//    void handlePlayerInputs(sf::Keyboard::Key key, bool isPressed);

    /**
     * @brief Getter for the world
     * @return the world
     */
    const std::shared_ptr<World>& getWorld() const {return world;}

    /**
     * @brief Setter for the world
     * @param n_world
     */
    void setWorld(const std::shared_ptr<World>& n_world) {Controller::world = n_world;}

    /**
     * @brief Function to remove a platform
     * @param platform
     */
    void removePlatform(std::shared_ptr<Logic_Library::Platform>& platform) {world->removePlatform(platform);}

    /**
     * @brief Function to freeze the world
     */
    void freezeWorld() {world->freezeWorld();}

    /**
     * @brief Function to update the world
     */
    void updateWorld() {world->updateWorld();}

//    /**
//     * @brief Function to check if a platform is needed
//     * @return true if a platform is needed, false otherwise
//     */
//    bool isPlatformNeeded() {return world->isPlatformNeeded();}
//
//    /**
//     * @brief Function to check if a platform is not needed
//     * @return true if a platform is not needed, false otherwise
//     */
//    bool isPlatformNotNeeded() {return world->isPlatformNotNeeded();}

    /**
     * @brief Default destructor for the Controller class
     */
    virtual ~Controller();
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_CONTROLLER_H
