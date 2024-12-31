//
// Created by s0230501 on 14/11/24.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_PLATFORM_LOGIC_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_PLATFORM_LOGIC_H

#include "../Entity Model/Entity_Model.h"
#include "../../Utilities/Random/Random.h"
#include "../../Utilities/Enums/Enums.h"
#include "../../Game Representation/Platform/Platform.h"
#include <string>
#include <optional>

namespace Logic_Library {
    /**
     * @brief Platform class: This class is responsible for the logic of the platform, it has the movement of the platform and the type of the platform.
     */
    class Platform : public Entity_Model {
    private:
        /// @brief Type of the platform
        Enums::PlatformType pType{};

        /// @brief Observer of the platform
        std::shared_ptr<Game_Repr::Platform> observer;

        /// @brief Horizontal speed of the platform
        float horizontalSpeed = Config::platformHorizontalSpeed;

        /// @brief Vertical speed of the platform
        float verticalSpeed = Config::platformVerticalSpeed;

        /// @brief Boolean to check if the platform is going left
        bool goingLeft{};

        /// @brief Boolean to check if the platform is going right
        bool goingUp{};

        /**
         * @brief This function creates a platform with a random type.
         */
        void createPlatform();
    public:
        /**
         * @brief Constructor for the platform class.
         * @param x: x-coordinate of the platform.
         * @param y: y-coordinate of the platform.
         */
        explicit Platform() : goingLeft(false), goingUp(false) {createPlatform();}
        /**
         * @brief Getter for the type of the platform.
         * @return PlatformType, which is the type of the platform.
         */
        Enums::PlatformType getPType() { return pType; }
        /**
         * @brief Setter for the type of the platform.
         * @param newType: PlatformType, which is the new type of the platform.
         */
        void setPType(Enums::PlatformType newType) { pType = newType; }
        /**
         * @brief Getter for the horizontal speed of the platform.
         * @return horizontalSpeed, which is the horizontal speed of the platform.
         */
        float getHorizontalSpeed() const { return horizontalSpeed; }
        /**
         * @brief Setter for the horizontal speed of the platform.
         * @param n_horizontalSpeed: float, which is the new horizontal speed of the platform.
         */
        void setHorizontalSpeed(float n_horizontalSpeed) { horizontalSpeed = n_horizontalSpeed; }
        /**
         * @brief Getter for the vertical speed of the platform.
         * @return verticalSpeed, which is the vertical speed of the platform.
         */
        float getVerticalSpeed() const { return verticalSpeed; }
        /**
         * @brief Setter for the vertical speed of the platform.
         * @param n_verticalSpeed: float, which is the new vertical speed of the platform.
         */
        void setVerticalSpeed(float n_verticalSpeed) { verticalSpeed = n_verticalSpeed; }
        /**
         * @brief Getter for the boolean goingLeft.
         * @return true if the platform is going left, false otherwise.
         */
        bool isGoingLeft() const;
        /**
         * @brief Setter for the boolean goingLeft.
         * @param n_goingLeft: bool, which is the new goingLeft.
         */
        void setGoingLeft(bool n_goingLeft);
        /**
         * @brief Getter for the boolean goingUp.
         * @return true if the platform is going up, false otherwise.
         */
        bool isGoingUp() const;
        /**
         * @brief Setter for the boolean goingUp.
         * @param n_goingUp: bool, which is the new goingUp.
         */
        void setGoingUp(bool n_goingUp);
        /**
         * @brief Function to move the platform up.
         */
        void moveUp();
        /**
         * @brief Function to move the platform down.
         */
        void moveDown();
        /**
         * @brief Function to move the platform left.
         */
        void moveLeft();
        /**
         * @brief Function to move the platform right.
         */
        void moveRight();
        /**
         * @brief Function to move the platforms down when the player reaches the half of the window
         * @param moveDownDistance
         */
        void fixTooHigh(float moveDownDistance);
        /**
         * @brief Function to assign an observer to the platform.
         * @param newObserver: std::shared_ptr<Observer>, which is the new observer of the platform.
         */
        void assignObserver(std::shared_ptr<Game_Repr::Platform> newObserver);
        /**
         * @brief Function to delete the observer of the platform.
         */
        void deleteObserver() override;
        /**
         * @brief Function to notify the observer of the platform.
         */
        void notifyObserver() override;

        std::shared_ptr<Game_Repr::Platform> getObserver() { return observer; }

        void notifyPosition(const Coordinates& coordinates) override;
        /**
         * @brief Destructor for the platform class.
         */
        virtual ~Platform() = default;
    };
}



#endif //INC_2024_PROJECT_JOE_AYOUB_UA_PLATFORM_LOGIC_H
