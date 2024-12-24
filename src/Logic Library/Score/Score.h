//
// Created by Joe Ayoub on 14/11/24 at 15:22.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_SCORE_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_SCORE_H

#include "../Observer/Observer.h"
#include <fstream>

/**
 * @brief Class that keeps track of the score and updates the highscore
 */
class Score : public Observer {
private:
    /// @brief The score of the player
    int mScore;
public:
    /**
     * @brief Default constructor for the Score class
     */
    Score()=default;

    /**
     * @brief Default destructor for the Score class
     */
    virtual ~Score()=default;

    /**
     * @brief Function that returns the score of the player
     * @return the score of the player
     */
    int getMScore() const;

    /**
     * @brief Function that sets the score of the player
     * @param n_mScore
     */
    void setMScore(int n_mScore);

    /**
     * @brief Function that returns the instance of the Score class
     * @return the instance of the Score class
     */
    static Score& getInstance();

    /**
     * @brief Function that updates the highscore
     * @param newScore the new score to be compared with the highscore
     */
    void updateHighScore(int newScore);

    /**
     * @brief Function that updates the score
     */
    void update() override;

    /**
     * @brief Function that notifies the position of the player
     * @param coordinates the coordinates of the player
     */
    void notifyPosition(const Coordinates& coordinates) override;
};


#endif //INC_2024_PROJECT_JOE_AYOUB_UA_SCORE_H
