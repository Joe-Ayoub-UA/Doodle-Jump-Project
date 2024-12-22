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


namespace Game_Repr {

    class Platform : public Entity_View{
    private:
        std::shared_ptr<sf::RectangleShape> mPlatform;
    public:
        Platform();

        void update() override {
            //mPlayer->move(0.f, 0.f);
        }

    };

}

#endif //INC_2024_PROJECT_JOE_AYOUB_UA_PLATFORM_H
