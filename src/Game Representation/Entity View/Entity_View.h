//
// Created by Joe Ayoub on 14/11/24 at 15:40.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_ENTITY_VIEW_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_ENTITY_VIEW_H

#include "../../Logic Library/Observer/Observer.h"

class Entity_View : public Observer {
public:
    Entity_View() = default;

    void update() override = 0;

    void notifyPosition(const Coordinates& coordinates) override = 0;

    virtual sf::FloatRect getGlobalBounds() const = 0;

};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_ENTITY_VIEW_H
