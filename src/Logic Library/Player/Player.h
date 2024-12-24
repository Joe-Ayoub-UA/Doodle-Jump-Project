//
// Created by s0230501 on 14/11/24.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_LOGIC_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_LOGIC_H

#include "../Entity Model/Entity_Model.h"
#include "../../Config.h"
#include "../../Game Representation/Player/Player.h"


namespace Logic_Library {
    class Player : public Entity_Model {
    private:
        std::shared_ptr<Game_Repr::Player> observer;
        float horizontalSpeed = Config::horizontalSpeed;
        float verticalSpeed = 0.f; // Add this line
        const float gravity = Config::gravity; // Add this line

        std::shared_ptr<Logic_Library::Player> mPlayer;
    public:
        Player() = default;

        void moveLeft();

        void moveRight();

        void assignObserver(std::shared_ptr<Game_Repr::Player> newObserver);

        void deleteObserver() override;

        void notifyObserver() override;

        void notifyPosition(const Coordinates& coordinates) override;

        std::shared_ptr<Game_Repr::Player> getObserver();
    };
}



#endif //INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_LOGIC_H
