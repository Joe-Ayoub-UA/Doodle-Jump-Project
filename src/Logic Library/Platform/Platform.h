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
    /// @brief Enum for the type of the platform
    /**
     * @brief Platform class: This class is responsible for the logic of the platform, it has the movement of the platform and the type of the platform.
     */
    class Platform : public Entity_Model {
    private:
        /// @brief Coordinates of the platform
        Coordinates pCoordinates;

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
         * @brief Setter for the position of the platform.
         * @param: coordinates: Coordinates, which is the new position of the platform.oo
         */
        void setPosition(Coordinates &coordinates) { pCoordinates = coordinates; };

        /**
         * @brief Getter for the position of the platform.
         * @return Coordinates, which is the position of the platform.
         */
        const Coordinates &getPosition() const { return pCoordinates; }
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

        bool isGoingLeft() const;

        void setGoingLeft(bool n_goingLeft);

        bool isGoingUp() const;

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
