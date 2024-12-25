//
// Created by Joe Ayoub on 16/11/24 at 19:16.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_H
#include <SFML/Graphics.hpp>
#include <memory>
#include "../Entity View/Entity_View.h"
#include "../../Config.h"
#include "../../Utilities/Coordinates/Coordinates.h"

namespace Game_Repr {
    class Player : public Entity_View {
    private:
        int radius;
        Coordinates position;
        sf::Color color;
        std::shared_ptr<sf::CircleShape> mPlayer;


    public:
        Player();

        Player(int radius, const Coordinates &position, const sf::Color &color);

        [[nodiscard]] const std::shared_ptr<sf::CircleShape> &getMPlayer() const;

        void setMPlayer(const std::shared_ptr<sf::CircleShape> &mPlayer);

        void update() override {
            //mPlayer->move(0.f, 0.f);
        }

        const Coordinates &getPosition() const;

        void setPosition(const Coordinates &n_position);

        void notifyPosition(const Coordinates& coordinates) override;

        virtual ~Player();
    };
}



#endif //INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_H
