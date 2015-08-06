//
// Created by Komodoman on 8/5/2015.
//

#include "PositionComponent.h"

PositionComponent::PositionComponent(Vector3 init_position) {
    position = init_position;
}

Vector3 PositionComponent::getPosition() {
    return position;
}
