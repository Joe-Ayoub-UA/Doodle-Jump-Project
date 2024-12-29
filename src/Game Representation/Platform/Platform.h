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

    class Platform : public Entity_View{
    private:
        std::shared_ptr<sf::RectangleShape> mPlatform;

        Coordinates position;

        Enums::PlatformType type;
    public:
        Platform();

        void update() override {
            //mPlayer->move(0.f, 0.f);
        }

        const std::shared_ptr<sf::RectangleShape> &getMPlatform() const;

        void setMPlatform(const std::shared_ptr<sf::RectangleShape> &mPlatform);

        const Coordinates &getPosition() const;

        void setPosition(const Coordinates &n_position);

        void setPlatformPos(float x, float y);

        void notifyPosition(const Coordinates& coordinates) override;

        sf::FloatRect getGlobalBounds() const override {return mPlatform->getGlobalBounds();}

        virtual ~Platform();

    };

}

#endif //INC_2024_PROJECT_JOE_AYOUB_UA_PLATFORM_H
