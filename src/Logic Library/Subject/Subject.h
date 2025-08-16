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
    /**
     * @brief Class that is responsible for the subject
     */
    class Subject {
    private:
        /// @brief Observer of the subject
        std::shared_ptr<Observer> observer;
    public:
        /**
         * @brief Default constructor for the Subject class
         */
        Subject() = default;

//        virtual void assignObserver(std::shared_ptr<Observer> observer);
//

        /**
         * @brief Function to delete the observer of the subject
         */
        virtual void deleteObserver()=0;

        /**
         * @brief Function to notify the observer of the subject
         */
        virtual void notifyObserver();

        /**
         * @brief Function to notify the position of the subject
         * @param coordinates: Coordinates, which are the new coordinates of the subject
         */
        virtual void notifyPosition(const Coordinates& coordinates)=0;

        /**
         * @brief Destructor for the Subject class
         */
        virtual ~Subject() = default;

    };
}

#endif //INC_2024_PROJECT_JOE_AYOUB_UA_SUBJECT_H
