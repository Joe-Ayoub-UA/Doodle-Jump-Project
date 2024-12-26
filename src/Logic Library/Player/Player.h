//
// Created by s0230501 on 14/11/24.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_LOGIC_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_LOGIC_H

#include "../Entity Model/Entity_Model.h"
#include "../../Config.h"
#include "../../Game Representation/Player/Player.h"


namespace Logic_Library {
    class Player : public Entity_Model {
    private:
        /// @brief Observer of the player
        std::shared_ptr<Game_Repr::Player> observer;

        /// @brief Horizontal speed of the player
        float horizontalSpeed = Config::horizontalSpeed;

        /// @brief Vertical speed of the player
        float verticalSpeed = 0.f;

        /// @brief Gravity of the game
        const float gravity = Config::gravity;

        /// @brief Player of the game
        std::shared_ptr<Logic_Library::Player> mPlayer;
    public:
        /**
         * @brief Default constructor for the Player class
         */
        Player() = default;

        /**
         * @brief Destructor for the Player class
         */
        ~Player() = default;

        /**
         * @brief Function to move the player to the left
         */
        void moveLeft();

        /**
         * @brief Function to move the player to the right
         */
        void moveRight();

        /**
         * @brief Function to handle the situation when the player is out of bounds (Teleportation)
         * @param coordinates
         * @return New coordinates if the player is out of bounds, same coordinates otherwise
         */
        Coordinates teleportPlayer(const Coordinates& coordinate);

        /**
         * @brief Function to check if the player is out of bounds
         * @param coordinates
         * @return true if the player is out of bounds, false otherwise
         */
        static bool checkOutOfBounds(const Coordinates& coordinates);

        /**
         * @brief Function to make the player jump
         */
        void jump();

        /**
         * @brief Function to apply gravity to the player
         */
        void applyGravity();

        /**
         * @brief Function to assign an observer to the player
         * @param newObserver
         */
        void assignObserver(std::shared_ptr<Game_Repr::Player> newObserver);

        /**
         * @brief Function to delete the observer of the player
         */
        void deleteObserver() override;

        /**
         * @brief Function to notify the observer
         */
        void notifyObserver() override;

        /**
         * @brief Function to notify the position of the player
         * @param coordinates
         */
        void notifyPosition(const Coordinates& coordinates) override;

        /**
         * @brief Function to get the observer of the player
         * @return shared pointer to the observer of the player
         */
        std::shared_ptr<Game_Repr::Player> getObserver();

        float getVerticalSpeed() const;

        void setVerticalSpeed(float n_verticalSpeed);
    };
}



#endif //INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_LOGIC_H
