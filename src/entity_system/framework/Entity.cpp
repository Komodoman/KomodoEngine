//
// Created by Komodoman on 8/5/2015.
//

#include "Entity.h"

Entity::Entity(int e_id) {
    entity_id = e_id;
}

int Entity::getEntityId() {
    return entity_id;
}
