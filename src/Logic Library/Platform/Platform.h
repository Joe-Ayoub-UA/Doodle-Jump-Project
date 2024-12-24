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

namespace Logic_Library {
    /// @brief Enum for the type of the platform
    /**
     * @brief Platform class: This class is responsible for the logic of the platform, it has the movement of the platform and the type of the platform.
     */
    class Platform : public Entity_Model {
    private:
        /// @brief x-coordinate of the platform
        float x{};

        /// @brief y-coordinate of the platform
        float y{};

        /// @brief Type of the platform
        Enums::PlatformType pType{};

        /// @brief Observer of the platform
        std::shared_ptr<Game_Repr::Platform> observer;

        /// @brief Horizontal speed of the platform
        float horizontalSpeed = Config::platformHorizontalSpeed;

        /// @brief Vertical speed of the platform
        float verticalSpeed = Config::platformVerticalSpeed;

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
        explicit Platform(float x=0.f, float y=0.f) : x(x), y(y) {createPlatform();}
        /**
         * @brief Getter for the x-coordinate of the platform.
         * @return float, which is the x-coordinate of the platform.
         */
        float getX() const;
        /**
         * @brief Setter for the x-coordinate of the platform.
         * @param n_x: float, which is the new x-coordinate of the platform.
         */
        void setX(float n_x);
        /**
         * @brief Getter for the y-coordinate of the platform.
         * @return float, which is the y-coordinate of the platform.
         */
        float getY() const;
        /**
         * @brief Setter for the y-coordinate of the platform.
         * @param n_y: float, which is the new y-coordinate of the platform.
         */
        void setY(float n_y);
        /**
         * @brief Setter for the position of the platform.
         * @param n_x: float, which is the new x-coordinate of the platform.
         * @param n_y: float, which is the new y-coordinate of the platform.
         */
        void setPosition(float n_x, float n_y);
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
