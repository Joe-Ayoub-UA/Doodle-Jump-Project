//
// Created by Joe Ayoub on 16/11/24 at 19:19.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_BONUS_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_BONUS_H
#include <iostream>
#include <memory>
#include "../../Utilities/Coordinates/Coordinates.h"
#include "../../Utilities/Enums/Enums.h"
#include "../Entity_View/Entity_View.h"

/**
 * @brief Namespace Game_Repr: Contains the classes that are responsible for the game representation.
 */
namespace Game_Repr {
    /**
     * @brief Class to represent the bonus
     */
    class Bonus : public Entity_View {
    private:
        /// @brief Dimensions of the bonus
        sf::Vector2<float> mDimensions = {20.f, 50.f};

        /// @brief Observer of the bonus
        Coordinates position;

        /// @brief Circle detection of the bonus
        std::shared_ptr<sf::CircleShape> mBonus;

        /// @brief Sprite of the bonus
        std::shared_ptr<sf::Sprite> mBonusSprite;

        /// @brief Texture of the bonus sprite
        std::shared_ptr<sf::Texture> mBonusTexture;

    public:
        /**
         * @brief Constructor for the Player class
         */
        Bonus(Enums::BonusType bonusType);

        /**
         * @brief Getter for the bonus
         * @return the bonus
         */
        [[nodiscard]] const std::shared_ptr<sf::CircleShape> &getMBonus() const;

        /**
         * @brief Setter for the bonus
         * @param n_mPlayer: std::shared_ptr<sf::Sprite>, which is the new bonus
         */
        void setMBonus(const std::shared_ptr<sf::CircleShape> &n_mPlayer);

        /**
         * @brief Function to update the bonus
         */
        [[maybe_unused]] void update() {}

        /**
         * @brief Function to get the dimensions of the bonus
         * @return std::pair<float, float>, which are the dimensions of the bonus
         */
        std::pair<float,float> getMDimensions() const;

        /**
         * @brief Function to get the position of the bonus
         * @return Coordinates, which are the position of the bonus
         */
        sf::FloatRect getGlobalBounds() const {return mBonus->getGlobalBounds();}

        /**
         * @brief Function to get the sprite of the bonus
         * @return the sprite of the bonus
         */
        const std::shared_ptr<sf::Sprite> &getMBonusSprite() const;

        /**
         * @brief Function to set the position of the bonus
         * @param n_position: Coordinates, which are the new position of the bonus
         */
        void setPosition(const Coordinates &n_position);

        /**
         * @brief Function to get the position of the bonus
         * @return
         */
        const Coordinates &getPosition() const;

        /**
         * @brief Function to notify the position of the bonus
         * @param coordinates: Coordinates, which are the new coordinates of the bonus
         */
        void notifyPosition(const Coordinates& coordinates);

        /**
         * @brief Destructor for the bonus class
         */
        virtual ~Bonus();
    };

} // Game_Repr

#endif //INC_2024_PROJECT_JOE_AYOUB_UA_BONUS_H
