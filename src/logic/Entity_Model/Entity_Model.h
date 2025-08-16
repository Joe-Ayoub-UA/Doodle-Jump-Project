//
// Created by s0230501 on 14/11/24.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_ENTITY_MODEL_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_ENTITY_MODEL_H

#include "../../logic/Subject/Subject.h"

namespace Logic_Library {

/**
 * @brief Class that is responsible for the model of the entity
 */
class Entity_Model : public Subject {
public:
    /**
     * @brief Default constructor for the Entity_Model class
     */
    Entity_Model() = default;

    //
    void deleteObserver() override = 0;

    void notifyObserver() override = 0;

    void notifyPosition(const Coordinates& coordinates) override = 0;
};

} // namespace Logic_Library

#endif // INC_2024_PROJECT_JOE_AYOUB_UA_ENTITY_MODEL_H
