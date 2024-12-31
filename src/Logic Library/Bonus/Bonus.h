//
// Created by Joe Ayoub on 14/11/24 at 15:16.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_BONUS_LOGIC_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_BONUS_LOGIC_H

#include "../Entity Model/Entity_Model.h"
#include "../../Game Representation/Bonus/Bonus.h"

namespace Logic_Library {
    class Bonus : public Entity_Model{
    private:
        std::shared_ptr<Game_Repr::Bonus> observer;
    public:



        void assignObserver(std::shared_ptr<Game_Repr::Bonus> newObserver);

        void deleteObserver() override;

        void notifyObserver() override;

        void notifyPosition(const Coordinates& coordinates) override;
    };
}



#endif //INC_2024_PROJECT_JOE_AYOUB_UA_BONUS_LOGIC_H
