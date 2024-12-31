//
// Created by Joe Ayoub on 14/11/24 at 15:16.
//

#include "Bonus.h"

namespace Logic_Library {
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

}