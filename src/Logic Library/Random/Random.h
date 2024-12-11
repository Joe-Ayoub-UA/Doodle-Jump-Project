//
// Created by Joe Ayoub on 14/11/24 at 15:20.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_RANDOM_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_RANDOM_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <memory>
class Random {
private:
    int sizeX;
    int sizeY;
    int prevX;
    int prevY;
public:
    Random(int sizeX, int sizeY);

    virtual ~Random();

    std::pair<int,int> generateCoor();

    int getSizeX() const;

    void setSizeX(int sizeX);

    int getSizeY() const;

    void setSizeY(int sizeY);

};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_RANDOM_H
