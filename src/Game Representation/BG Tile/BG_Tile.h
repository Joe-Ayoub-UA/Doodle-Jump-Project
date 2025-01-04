//
// Created by Joe Ayoub on 16/11/24 at 19:19.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_BG_TILE_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_BG_TILE_H
#include <memory>

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
    public:
        /**
         * @brief Constructor for the BG_Tile class
         */
        BG_Tile();
    };

} // Logic_Library

#endif //INC_2024_PROJECT_JOE_AYOUB_UA_BG_TILE_H
