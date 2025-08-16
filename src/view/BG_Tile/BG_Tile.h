//
// Created by Joe Ayoub on 16/11/24 at 19:19.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_BG_TILE_VIEW_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_BG_TILE_VIEW_H
#include <memory>
#include <SFML/Graphics.hpp>
#include "../../Config.h"
#include "../../Utilities/Coordinates/Coordinates.h"


/**
 * @brief Namespace Game_Repr: Contains the classes that are responsible for the game representation.
 */
namespace Game_Repr {
    /**
     * @brief Class to represent the background tile
     */
    class BG_Tile {
    private:
        /// @brief Tile of the background
        std::unique_ptr<BG_Tile> tile;

        /// @brief Texture of the background tile
        sf::Texture mTexture;

        /// @brief Sprite of the background tile
        sf::Sprite mTileSprite;

        /// @brief Dimensions of the background tile
        sf::Vector2<float> mDimensions = {100.f, 100.f};

        /// @brief Position of the background tile
        Coordinates position; // Position of the background tile
    public:
        /**
         * @brief Constructor for the BG_Tile class
         */
        BG_Tile();

        /**
         * @brief Getter for the background tile sprite
         * @return the background tile sprite
         */
        [[nodiscard]] const sf::Sprite &getMTileSprite() const {
            return mTileSprite;
        }

        const Coordinates &getPosition() const;

        void setPosition(const Coordinates &position);

    };

}

#endif //INC_2024_PROJECT_JOE_AYOUB_UA_BG_TILE_VIEW_H
