//
// Created by Joe Ayoub on 16/11/24 at 19:17.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_PLATFORM_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_PLATFORM_H
#include <string>
#include <utility>
#include <SFML/Graphics.hpp>
#include <memory>
#include "../Entity View/Entity_View.h"
#include "../../Config.h"
#include "../../Utilities/Enums/Enums.h"

namespace Game_Repr {

    /**
     * @brief Class that is responsible for the view of the platform
     */
    class Platform : public Entity_View{
    private:
        /// @brief Platform of the game
        std::shared_ptr<sf::RectangleShape> mPlatform;

        /// @brief Position of the platform
        Coordinates position;

        /// @brief Type of the platform
        Enums::PlatformType type;
    public:
        /**
         * @brief Constructor for the Platform class
         */
        Platform();

        /**
         * @brief Function to update the platform
         */
        void update() override {}

        /**
         * @brief Function to get the platform
         * @return the platform
         */
        const std::shared_ptr<sf::RectangleShape> &getMPlatform() const;

        /**
         * @brief Function to set the platform
         * @param n_mPlatform: std::shared_ptr<sf::RectangleShape>, which is the new platform
         */
        void setMPlatform(const std::shared_ptr<sf::RectangleShape> &n_mPlatform);

        /**
         * @brief Function to get the position of the platform
         * @return Coordinates, which are the position of the platform
         */
        const Coordinates &getPosition() const;

        /**
         * @brief Function to set the position of the platform
         * @param n_position: Coordinates, which are the new position of the platform
         */
        void setPosition(const Coordinates &n_position);

        /**
         * @brief Function to get the type of the platform
         * @return PlatformType, which is the type of the platform
         */
        void setPlatformPos(float x, float y);

        /**
         * @brief Function to get the type of the platform
         * @return PlatformType, which is the type of the platform
         */
        void notifyPosition(const Coordinates& coordinates) override;

        /**
         * @brief Function to get the type of the platform
         * @return PlatformType, which is the type of the platform
         */
        sf::FloatRect getGlobalBounds() const override {return mPlatform->getGlobalBounds();}

        /**
         * @brief Destructor for the Platform class
         */
        virtual ~Platform();

    };

}

#endif //INC_2024_PROJECT_JOE_AYOUB_UA_PLATFORM_H
