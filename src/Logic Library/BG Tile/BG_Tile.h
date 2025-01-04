//
// Created by Joe Ayoub on 14/11/24.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_BG_TILE_LOGIC_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_BG_TILE_LOGIC_H

#include "../Entity Model/Entity_Model.h"
#include "../../Game Representation/BG Tile/BG_Tile.h"


namespace Logic_Library {
    /**
     * @brief Class that is responsible for the logic of the background tile
     */
    class BG_Tile : public Entity_Model {
    private:
        /// @brief Observer of the background tile
        std::shared_ptr<Game_Repr::BG_Tile> observer;
    public:
        /**
         * @brief Default constructor for the BG_Tile class
         */
        BG_Tile() = default;

        /**
         * @brief Function to assign an observer to the background tile
         * @param newObserver
         */
        void assignObserver(std::shared_ptr<Game_Repr::BG_Tile> newObserver);

        /**
         * @brief Function to delete the observer of the background tile
         */
        void deleteObserver() override;

        /**
         * @brief Function to notify the observer of the background tile
         */
        void notifyObserver() override;

        /**
         * @brief Virtual destructor for the BG_Tile class
         */
        virtual ~BG_Tile() = default;
    };
}



#endif //INC_2024_PROJECT_JOE_AYOUB_UA_BG_TILE_LOGIC_H
