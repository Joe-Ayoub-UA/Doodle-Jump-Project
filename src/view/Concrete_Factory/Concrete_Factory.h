//
// Created by Joe Ayoub on 14/11/24 at 16:06.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_CONCRETE_FACTORY_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_CONCRETE_FACTORY_H

#include "../../logic/Abstract_Factory/Abstract_Factory.h"
#include "../../view/BG_Tile/BG_Tile.h"
#include "../../view/Bonus/Bonus.h"
#include "../../view/Platform/Platform.h"
#include "../../view/Player/Player.h"
#include <iostream>
#include <memory>
#include <string>

/**
 * @brief Concrete_Factory class that implements the Abstract_Factory class
 */
class Concrete_Factory : public Abstract_Factory {
private:
    /// @brief Shared pointer to the observer
    std::shared_ptr<Observer> observer;

    /// @brief Handles the color of the platform depending on its type
    static sf::Color handlePlatformColor(Enums::PlatformType type);

    /// @brief Handles the color of the bonus depending on its type
    static sf::Color handleBonusColor(Enums::BonusType type);

public:
    /**
     * @brief Default constructor for the Concrete_Factory class
     */
    Concrete_Factory() = default;

    /**
     * @brief Creates a player
     * @return a shared pointer to the player
     */
    std::shared_ptr<Logic_Library::Player> createPlayer() override;

    /**
     * @brief Creates a platform
     * @return a shared pointer to the platform
     */
    std::shared_ptr<Logic_Library::Platform> createPlatform(Coordinates coordinate) override;

    /**
     * @brief Creates a background tile
     * @return a shared pointer to the background tile
     */
    std::shared_ptr<Logic_Library::BG_Tile> createBGTile() override;

    /**
     * @brief Creates a bonus
     * @return a shared pointer to the bonus
     */
    std::shared_ptr<Logic_Library::Bonus> createBonus() override;

    /**
     * @brief Creates a world
     * @return a shared pointer to the world
     */
    std::shared_ptr<World> createWorld() override;

    /**
     * @brief Assigns an observer to the factory
     * @param observer: shared pointer to the observer
     */
    void assignObserver(std::shared_ptr<Observer> observer) override;

    /**
     * @brief Deletes the observer
     */
    void deleteObserver() override;

    /**
     * @brief Notifies the observer for an update
     */
    void notifyObserver() override;
};

#endif // INC_2024_PROJECT_JOE_AYOUB_UA_CONCRETE_FACTORY_H
