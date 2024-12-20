//
// Created by Joe Ayoub on 16/11/24 at 19:16.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_H
#include <SFML/Graphics.hpp>
#include <memory>
#include "../Entity View/Entity_View.h"

namespace Game_Repr {
    class Player : public Entity_View {
    private:
        std::shared_ptr<sf::CircleShape> mPlayer;
    public:
        Player();

        const std::shared_ptr<sf::CircleShape> &getMPlayer() const;

        void setMPlayer(const std::shared_ptr<sf::CircleShape> &mPlayer);

        void update() override {
            //mPlayer->move(0.f, 0.f);
        }
    };
}



#endif //INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_H
