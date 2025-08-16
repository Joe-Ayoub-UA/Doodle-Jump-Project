//
// Created by Joe Ayoub on 14/11/24 at 15:16.
//

#include "Bonus.h"

const char* bonusTypeToString(Enums::BonusType type) {
    switch (type) {
    case Enums::BonusType::JETPACK:
        return "JETPACK";
    case Enums::BonusType::SPRING:
        return "SPRING";
    default:
        return "NONE";
    }
}

namespace Logic_Library {

Bonus::Bonus(Enums::BonusType bonusType) { setBType(bonusType); }

void Bonus::createBonus() {}

void Bonus::assignObserver(std::shared_ptr<Game_Repr::Bonus> newObserver) { this->observer = std::move(newObserver); }

void Bonus::deleteObserver() { this->observer = nullptr; }

void Bonus::notifyObserver() {
    //        observer->update();
}

void Bonus::notifyPosition(const Coordinates& coordinates) {
    //        observer->notifyPosition(coordinates);
}

Enums::BonusType Bonus::getBType() const { return bType; }

void Bonus::setBType(Enums::BonusType n_bType) { Bonus::bType = n_bType; }

} // namespace Logic_Library