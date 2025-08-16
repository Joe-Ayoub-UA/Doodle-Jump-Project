//
// Created by Joe Ayoub on 14/11/24 at 15:16.
//

#include "Bonus.h"

const char* bonusTypeToString(Enums::BonusType type) {
    switch(type) {
        case Enums::BonusType::JETPACK: return "JETPACK";
        case Enums::BonusType::SPRING: return "SPRING";
        default: return "NONE";
    }
}

namespace Logic_Library {

    Bonus::Bonus(Enums::BonusType bonusType) {
//        int random2 = Random::getInstance().randomInt(1,10);
//        if (random2 == 1) {
//            // 10% probability of a creating jetpack bonus
//
//            std::cout << "Creating jetpack bonus" << std::endl;
//            setBType(Enums::BonusType::JETPACK);
//        }
//        else if (random2 == 2) {
//            // 10% probability of a creating spring bonus
//
//            std::cout << "Creating spring bonus" << std::endl;
//            setBType(Enums::BonusType::SPRING);
//        }
//        else {
//            // 80% probability of no bonus
//            setBType(Enums::BonusType::NONE);
//        }
        setBType(bonusType);
//        std::cout << "creating bonus of type: " << bonusTypeToString(bType) << std::endl;
        }

    void Bonus::createBonus() {}

    void Bonus::assignObserver(std::shared_ptr<Game_Repr::Bonus> newObserver) {
        this->observer = std::move(newObserver);
    }

    void Bonus::deleteObserver() {
        this->observer = nullptr;
    }

    void Bonus::notifyObserver() {
//        observer->update();
    }

    void Bonus::notifyPosition(const Coordinates &coordinates) {
//        observer->notifyPosition(coordinates);
    }

    Enums::BonusType Bonus::getBType() const {
        return bType;
    }

    void Bonus::setBType(Enums::BonusType n_bType) {
        Bonus::bType = n_bType;
    }

}