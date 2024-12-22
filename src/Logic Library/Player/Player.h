//
// Created by s0230501 on 14/11/24.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_LOGIC_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_LOGIC_H

#include "../Entity Model/Entity_Model.h"
#include "../../Config.h"


namespace Logic_Library {
    class Player : public Entity_Model {
    private:
        std::shared_ptr<Observer> observer;
        float horizontalSpeed = Config::horizontalSpeed;
        float verticalSpeed = 0.f; // Add this line
        const float gravity = Config::gravity; // Add this line
    public:
        Player() = default;

        void assignObserver(std::shared_ptr<Observer> newObserver) override;

        void deleteObserver() override;

        void notifyObserver() override;
    };
}



#endif //INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_LOGIC_H
