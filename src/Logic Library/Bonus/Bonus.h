//
// Created by Joe Ayoub on 14/11/24 at 15:16.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_BONUS_LOGIC_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_BONUS_LOGIC_H

#include "../Entity Model/Entity_Model.h"
#include "../../Game Representation/Bonus/Bonus.h"
#include "../../Utilities/Enums/Enums.h"
#include "../../Utilities/Random/Random.h"

/**
 * @brief Namespace Logic_Library: Contains the classes that are responsible for the logic of the game.
 */
namespace Logic_Library {
    /**
     * @brief Bonus class: This class is responsible for the logic of the bonus, it has the type of the bonus and the creation of the bonus.
     */
    class Bonus : public Entity_Model{
    private:
        /// @brief Observer of the bonus
        std::shared_ptr<Game_Repr::Bonus> observer;

        /// @brief Type of the bonus
        Enums::BonusType bType{};

        /// @brief This function creates a bonus with a random type.
        void createBonus();
    public:

        /**
         * @brief Constructor for the bonus class.
         */
        explicit Bonus();

        /**
         * @brief Getter for the type of the bonus.
         * @return BonusType, which is the type of the bonus.
         */
        Enums::BonusType getBType() const;

        /**
         * @brief Setter for the type of the bonus.
         * @param n_bType: BonusType, which is the new type of the bonus.
         */
        void setBType(Enums::BonusType n_bType);

        /**
         * @brief Function to assign an observer to the bonus.
         * @param newObserver: std::shared_ptr<Observer>, which is the new observer of the bonus.
         */
        void assignObserver(std::shared_ptr<Game_Repr::Bonus> newObserver);


        /**
         * @brief Function to delete the observer of the bonus.
         */
        void deleteObserver() override;

        /**
         * @brief Function to notify the observer of the bonus.
         */
        void notifyObserver() override;

        /**
         * @brief Function to notify the observer of the bonus.
         * @param coordinates: Coordinates, which are the new coordinates of the bonus.
         */
        void notifyPosition(const Coordinates& coordinates) override;
    };
}



#endif //INC_2024_PROJECT_JOE_AYOUB_UA_BONUS_LOGIC_H
