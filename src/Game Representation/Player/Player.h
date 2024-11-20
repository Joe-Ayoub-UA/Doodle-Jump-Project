//
// Created by Joe Ayoub on 16/11/24 at 19:16.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_H
#include <SFML/Graphics.hpp>µ
#include <memory>

namespace Game_Repr {
    class Player {
    private:
        std::shared_ptr<sf::CircleShape> mPlayer;
    public:
        Player();

        const std::shared_ptr<sf::CircleShape> &getMPlayer() const;

        void setMPlayer(const std::shared_ptr<sf::CircleShape> &mPlayer);
    };
}



#endif //INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_H
