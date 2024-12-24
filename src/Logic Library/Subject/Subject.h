//
// Created by Joe Ayoub on 11/12/24 at 11:43.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_SUBJECT_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_SUBJECT_H
#include "../Observer/Observer.h"
#include <vector>
#include <memory>
#include "../../Utilities/Coordinates/Coordinates.h"

namespace Logic_Library{
    class Subject {
    private:
        std::shared_ptr<Observer> observer;
    public:
        Subject() = default;

//        virtual void assignObserver(std::shared_ptr<Observer> observer);
//
        virtual void deleteObserver();

        virtual void notifyObserver();

        virtual void notifyPosition(const Coordinates& coordinates)=0;

    };
}

#endif //INC_2024_PROJECT_JOE_AYOUB_UA_SUBJECT_H
