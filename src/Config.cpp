//
// Created by Joe Ayoub on 24/12/24 at 17:11.
//
#include "Config.h"

int Config::amountOfPlatforms = 15;

const std::pair<float, float> Config::minPlatformDistance = getMinPlatformDistance();

const std::pair<float, float> Config::maxPlatformDistance = getMaxPlatformDistance();

const std::map<Enums::PlatformType, std::string> Config::platformColor = {
        {Enums::PlatformType::STATIC, "Green"},
        {Enums::PlatformType::HORIZONTAL, "Blue"},
        {Enums::PlatformType::VERTICAL, "Yellow"},
        {Enums::PlatformType::TEMPORARY, "White"}
};

const std::map<Enums::BonusType, std::string> Config::bonusTexture = {
//        {Enums::BonusType::JETPACK, "textures/Bonus/Jetpack.png"},
//        {Enums::BonusType::SPRING, "textures/Bonus/Spring.png"}
        {Enums::BonusType::JETPACK, "Red"},
        {Enums::BonusType::SPRING, "Blue"}
};