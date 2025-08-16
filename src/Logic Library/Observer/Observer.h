//
// Created by Joe Ayoub on 14/11/24 at 15:22.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_OBSERVER_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_OBSERVER_H
#include "../../Utilities/Coordinates/Coordinates.h"
/**
 * @brief Class that is responsible for the observer
 */
class Observer {
public:
    /**
     * @brief Default constructor for the Observer class
     */
    Observer() = default;

    /**
     * @brief Function to update the observer
     */
    virtual void update() = 0;

    /**
     * @brief Function to notify the position of the observer
     * @param coordinates: Coordinates, which are the new coordinates of the observer
     */
    virtual void notifyPosition(const Coordinates& coordinates) = 0;

    /**
     * @brief Virtual destructor for the Observer class
     */
    virtual ~Observer() = default;

};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_OBSERVER_H
