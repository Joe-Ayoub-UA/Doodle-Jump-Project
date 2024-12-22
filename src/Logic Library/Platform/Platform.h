//
// Created by s0230501 on 14/11/24.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_PLATFORM_LOGIC_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_PLATFORM_LOGIC_H

#include "../Entity Model/Entity_Model.h"
#include <string>

namespace Logic_Library {

    enum PlatformType {
        STATIC,
        HORIZONTAL,
        VERTICAL,
        TEMPORARY
    };

    class Platform : public Entity_Model {
    private:
        int x{};
        int y{};
        std::string pType{};
        std::shared_ptr<Observer> observer;
    public:
        Platform() = default;

        explicit Platform(std::string type,int x, int y) : pType(std::move(type)), x(x), y(y) {}

        int getX() const;

        void setX(int x);

        int getY() const;

        void setY(int y);

        std::string getPType() { return pType; }

        void assignObserver(std::shared_ptr<Observer> newObserver) override;

        void deleteObserver() override;

        void notifyObserver() override;
    };
}



#endif //INC_2024_PROJECT_JOE_AYOUB_UA_PLATFORM_LOGIC_H
