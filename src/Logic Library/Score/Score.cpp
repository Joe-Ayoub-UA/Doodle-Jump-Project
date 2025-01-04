//
// Created by Joe Ayoub on 14/11/24 at 15:22.
//

#include "Score.h"

int Score::highScore = 0;

Score::Score() : mScore(0) {
    loadHighScore();
}

void Score::update() {}

Score &Score::getInstance() {
    static Score instance;
    return instance;
}

void Score::updateHighScore(int newScore) {
    if (highScore < newScore) {
        highScore = newScore;
        saveHighScore();
    }
    // Read the highscore from the file
//    std::ifstream fileIn("highscore.txt");
//    int highScore;
//    fileIn >> highScore;
//    fileIn.close();
//    // Update the highscore if the new score is higher
//    if (newScore > highScore) {
//        std::ofstream file("highscore.txt");
//        file << newScore;
//        file.close();
//    }
}

int Score::getMScore() const {
    return mScore;
}

void Score::setMScore(int n_mScore) {
    Score::mScore = n_mScore;
}

void Score::saveHighScore() {
    std::ofstream file(highScoreFile);
    if (file.is_open()) {
        file << highScore;
        file.close();
    }
    else {
        std::cerr << "Unable to open file for writing high score." << std::endl;
    }
}

void Score::loadHighScore() {
    std::ifstream fileIn("../src/Logic Library/Score/highscore.txt");
    if (fileIn.is_open()) {
        fileIn >> highScore;
        fileIn.close();
    }
    else {
        highScore = 0;
    }
}

int Score::getHighScore() {
    return highScore;
//    std::ifstream fileIn("highscore.txt");
//    int highScore;
//    fileIn >> highScore;
//    fileIn.close();
//    return highScore;
}

void Score::notifyPosition(const Coordinates &coordinates) {}

