//
// Created by Joe Ayoub on 24/12/24 at 17:11.
//
#include "Config.h"

int Config::amountOfPlatforms = 15;

const std::pair<float, float> Config::minPlatformDistance = getMinPlatformDistance();

const std::pair<float, float> Config::maxPlatformDistance = getMaxPlatformDistance();

const std::map<Enums::PlatformType, std::string> Config::platformColor = {
        {Enums::PlatformType::STATIC, "Red"},
        {Enums::PlatformType::HORIZONTAL, "Green"},
        {Enums::PlatformType::VERTICAL, "Blue"},
        {Enums::PlatformType::TEMPORARY, "Yellow"}
};