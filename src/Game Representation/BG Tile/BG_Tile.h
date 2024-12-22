//
// Created by Joe Ayoub on 16/11/24 at 19:19.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_BG_TILE_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_BG_TILE_H
#include <memory>

namespace Game_Repr {

    class BG_Tile {
    private:
        std::unique_ptr<BG_Tile> tile;
    public:
        BG_Tile();
    };

} // Logic_Library

#endif //INC_2024_PROJECT_JOE_AYOUB_UA_BG_TILE_H
