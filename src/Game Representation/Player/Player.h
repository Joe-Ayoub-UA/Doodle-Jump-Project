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
        sf::Vector2<float> mDimensions = {50.f, 50.f};
        int radius;
        Coordinates position;
        sf::Color color;
        std::shared_ptr<sf::RectangleShape> mPlayer;


    public:
        Player();

        Player(int radius, const Coordinates &position, const sf::Color &color);

        [[nodiscard]] const std::shared_ptr<sf::RectangleShape> &getMPlayer() const;

        void setMPlayer(const std::shared_ptr<sf::RectangleShape> &mPlayer);

        void update() override {
            //mPlayer->move(0.f, 0.f);
        }

        std::pair<float,float> getMDimensions() const;

        sf::FloatRect getGlobalBounds() const override {return mPlayer->getGlobalBounds();}

        const Coordinates &getPosition() const;

        void setPosition(const Coordinates &n_position);

        void notifyPosition(const Coordinates& coordinates) override;

        virtual ~Player();
    };
}



#endif //INC_2024_PROJECT_JOE_AYOUB_UA_PLAYER_H
