//
// Created by Joe Ayoub on 14/11/24 at 15:22.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_OBSERVER_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_OBSERVER_H
#include "../../Utilities/Coordinates/Coordinates.h"

class Observer {
public:
    Observer() = default;

    virtual void update() = 0;

    virtual void notifyPosition(const Coordinates& coordinates) = 0;
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_OBSERVER_H
