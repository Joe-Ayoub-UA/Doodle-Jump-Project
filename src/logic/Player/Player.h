//
// Created by s0230501 on 14/11/24.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_LOGIC_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_LOGIC_H

#include "../Entity_Model/Entity_Model.h"
#include "../../Config.h"
#include "../../view/Player/Player.h"

/**
 * @brief Namespace Logic_Library: Contains the classes that are responsible for the logic of the game.
 */
namespace Logic_Library {
    /**
     * @brief Class that is responsible for the logic of the player
     */
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

        /// @brief Jump force of the player
        float jumpForce = Config::jumpForce;

        /// @brief boolean to check if the jetpack is active
        bool mJetpackActive = false;

        /// @brief Jetpack frame count
        int mJetpackFrameCount = 0;

        /// @brief Constants for the jetpack
        const int JETPACK_FRAMES = Config::jetPackFrameDuration;
        const float JETPACK_FORCE = Config::jetpackForce; // Upward force, negative because y-axis is inverted
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
         * @param coordinate
         * @return New coordinates if the player is out of bounds, same coordinates otherwise
         */
        Coordinates teleportPlayer(const Coordinates& coordinate);

        /**
         * @brief Function to check if the player is out of bounds
         * @param coordinates
         * @return true if the player is out of bounds, false otherwise
         */
        bool checkOutOfBounds(const Coordinates& coordinates);

        /**
         * @brief Function to make the player jump
         */
        void jump();

        /**
         * @brief Function to apply gravity to the player
         */
        void applyGravity();

        /**
         * @brief Funtion to activate the jetpack
         * This function sets the jetpack active state and initializes the time remaining.
         */
        void activateJetpack();

        /**
         * @brief Funtion to update the jetpack state
         * This function applies the jetpack force and updates the frames remaining.
         */
        void updateJetpack();

        /**
         * @brief Function to check if the jetpack is active
         * @return true if the jetpack is active, false otherwise
         */
        bool isJetpackActive() const { return mJetpackActive; }

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

        /**
         * @brief Function to get the horizontal speed of the player
         * @return horizontal speed of the player
         */
        float getVerticalSpeed() const;

        /**
         * @brief Function to get the jump force of the player
         * @return jump force of the player
         */
        float getJumpForce() const;

        /**
         * @brief Function to set the vertical speed of the player
         * @param n_verticalSpeed
         */
        void setVerticalSpeed(float n_verticalSpeed);

        /**
         * @brief Function to set the jump force of the player
         * @param n_jumpForce
         */
         void setJumpForce(float n_jumpForce);

        /**
         * @brief Function to get the horizontal speed of the player
         * @return horizontal speed of the player
         */
        float getHorizontalSpeed() const;

        /**
         * @brief Function to set the horizontal speed of the player
         * @param n_horizontalSpeed
         */
        void setHorizontalSpeed(float n_horizontalSpeed);
    };
}



#endif //INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_LOGIC_H
