//
// Created by Joe Ayoub on 11/12/24 at 11:43.
//

#include "Subject.h"

#include <utility>


namespace Logic_Library {

    void Subject::deleteObserver() {
        observer = nullptr;
    }

    void Subject::notifyObserver() {
            observer->update();
    }
}