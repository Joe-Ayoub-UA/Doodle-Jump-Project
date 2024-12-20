//
// Created by s0230501 on 14/11/24.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_ENTITY_MODEL_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_ENTITY_MODEL_H

#include "../../Logic Library/Subject/Subject.h"

namespace Logic_Library {

    class Entity_Model : public Subject {
    public:
        Entity_Model() = default;

        void assignObserver(std::shared_ptr<Observer> observer) override =0;

        void deleteObserver() override =0;

        void notifyObserver() override =0;
    };

}



#endif //INC_2024_PROJECT_JOE_AYOUB_UA_ENTITY_MODEL_H
