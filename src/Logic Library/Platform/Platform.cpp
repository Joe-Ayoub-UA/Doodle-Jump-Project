//
// Created by s0230501 on 14/11/24.
//

#include "Platform.h"

#include <utility>
namespace Logic_Library {
    void Platform::assignObserver(std::shared_ptr<Observer> newObserver) {
        this->observer = std::move(newObserver);
    }

    void Platform::deleteObserver() {
        this->observer = nullptr;
    }

    void Platform::notifyObserver() {
        observer->update();
    }

    int Platform::getX() const {
        return x;
    }

    void Platform::setX(int x) {
        Platform::x = x;
    }

    int Platform::getY() const {
        return y;
    }

    void Platform::setY(int y) {
        Platform::y = y;
    }
}
