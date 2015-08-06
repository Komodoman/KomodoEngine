//
// Created by Komodoman on 8/5/2015.
//

#include "AiComponent.h"

AiComponent::AiComponent(Vector3 init_goal, int init_enemies[MAX_ENEMIES]) {
    goal = init_goal;
    isAlive = true;
    for (int i; i < MAX_ENEMIES; i++) {
        enemies[i] = init_enemies[i];
    }
}
