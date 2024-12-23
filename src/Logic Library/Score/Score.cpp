//
// Created by Joe Ayoub on 14/11/24 at 15:22.
//

#include "Score.h"

void Score::update() {}

Score &Score::getInstance() {
    static Score instance;
    return instance;
}

void Score::updateHighScore(int newScore) {
    // Read the highscore from the file
    std::ifstream fileIn("highscore.txt");
    int highScore;
    fileIn >> highScore;
    fileIn.close();
    // Update the highscore if the new score is higher
    if (newScore > highScore) {
        std::ofstream file("highscore.txt");
        file << newScore;
        file.close();
    }
}

int Score::getMScore() const {
    return mScore;
}

void Score::setMScore(int n_mScore) {
    Score::mScore = n_mScore;
}

