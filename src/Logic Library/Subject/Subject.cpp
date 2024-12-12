//
// Created by Joe Ayoub on 11/12/24 at 11:43.
//

#include "Subject.h"


namespace Logic_Library {

    void Subject::notifyObserver() {
            observer->update();
    }
}