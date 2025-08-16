//
// Created by Joe Ayoub on 14/11/24 at 15:40.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_ENTITY_VIEW_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_ENTITY_VIEW_H

#include "../../logic/Observer/Observer.h"
#include "../SFML/Graphics.hpp"

/**
 * @brief Class that is responsible for the view of the entity
 */
class Entity_View : public Observer {
public:
    /**
     * @brief Function to update the entity
     */
    Entity_View() = default;

    /**
     * @brief Function to update the entity
     */
    void update() override = 0;

    /**
     * @brief Function to notify the position of the entity
     * @param coordinates: Coordinates, which are the new coordinates of the entity
     */
    void notifyPosition(const Coordinates& coordinates) override = 0;

    /**
     * @brief Function to get the position of the entity
     * @return Coordinates, which are the position of the entity
     */
    virtual sf::FloatRect getGlobalBounds() const = 0;

    /**
     * @brief Destructor for the Entity_View class
     */
    virtual ~Entity_View() = default;
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_ENTITY_VIEW_H
