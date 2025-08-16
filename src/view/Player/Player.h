//
// Created by Joe Ayoub on 16/11/24 at 19:16.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_H
#include <SFML/Graphics.hpp>
#include <memory>
#include "../Entity_View/Entity_View.h"
#include "../../Config.h"
#include "../../Utilities/Coordinates/Coordinates.h"

/**
 * @brief Namespace Game_Repr: Contains the classes that are responsible for the game representation.
 */
namespace Game_Repr {
    /**
     * @brief Class that is responsible for the view of the player
     */
    class Player : public Entity_View {
    private:
        /// @brief Dimensions of the player
        sf::Vector2<float> mDimensions = {50.f, 50.f};

        /// @brief Position of the player
        Coordinates position;

        /// @brief Color of the player
        sf::Color color;

        /// @brief Texture of the player
        sf::Texture mTexture;

        /// @brief Sprite of the player
        std::shared_ptr<sf::Sprite> mPlayer;

        /// @brief Debug hitbox for the player
        std::shared_ptr<sf::RectangleShape> mHitboxDebug;


    public:
        /**
         * @brief Constructor for the Player class
         */
        Player();

        /**
         * @brief Getter for the player
         * @return the player
         */
        [[nodiscard]] const std::shared_ptr<sf::Sprite> &getMPlayer() const;

        /**
         * @brief Setter for the player
         * @param n_mPlayer: std::shared_ptr<sf::Sprite>, which is the new player
         */
        void setMPlayer(const std::shared_ptr<sf::Sprite> &n_mPlayer);

        /**
         * @brief Function to update the player
         */
        void update() override {}

        /**
         * @brief Function to get the dimensions of the player
         * @return std::pair<float, float>, which are the dimensions of the player
         */
        std::pair<float,float> getMDimensions() const;

        /**
         * @brief Function to get the position of the player
         * @return Coordinates, which are the position of the player
         */
        sf::FloatRect getGlobalBounds() const override {return mPlayer->getGlobalBounds();}

        /**
         * @brief Function to get the position of the player
         * @return
         */
        const Coordinates &getPosition() const;

        /**
         * @brief Function to get the debug hitbox of the player
         * @return shared pointer to the debug hitbox of the player
         */
        const std::shared_ptr<sf::RectangleShape> &getMHitboxDebug() const;

        /**
         * @brief Function to set the position of the player
         * @param n_position: Coordinates, which are the new position of the player
         */
        void setPosition(const Coordinates &n_position);

        /**
         * @brief Function to notify the position of the player
         * @param coordinates: Coordinates, which are the new coordinates of the player
         */
        void notifyPosition(const Coordinates& coordinates) override;

        /**
         * @brief Destructor for the Player class
         */
        virtual ~Player();
    };
}



#endif //INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_H
