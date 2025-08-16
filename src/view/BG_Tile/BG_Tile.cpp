//
// Created by Joe Ayoub on 16/11/24 at 19:19.
//

#include "BG_Tile.h"
#include "../../Utilities/Coordinates/Coordinates.h"

namespace Game_Repr {
BG_Tile::BG_Tile() {
    if (!mTexture.loadFromFile("../textures/Tile/bg.png")) {
        throw std::runtime_error("Error loading background texture");
    } else {
        // Get the size of the texture
        sf::Vector2u textureSize = mTexture.getSize();
        float scaleX = (float)Config::windowWidth / (float)textureSize.x;
        float scaleY = (float)Config::windowHeight / (float)textureSize.y;

        // Set the texture, scale and position of the background tile
        mTileSprite.setTexture(mTexture);
        mTileSprite.setScale(scaleX, scaleY);
        mTileSprite.setPosition(0, 0);

        // Update mDimensions based on the texture size and scale
        mDimensions.x = (float)textureSize.x * mTileSprite.getScale().x;
        mDimensions.y = (float)textureSize.y * mTileSprite.getScale().y;
    }
}

const Coordinates& BG_Tile::getPosition() const { return position; }

void BG_Tile::setPosition(const Coordinates& position) { BG_Tile::position = position; }
} // namespace Game_Repr