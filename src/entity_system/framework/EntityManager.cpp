//
// Created by Komodoman on 8/5/2015.
//

#include "EntityManager.h"

EntityManager &EntityManager::getInstance() {
    static EntityManager kem;
    return kem;
}

EntityManager::~EntityManager() {

}

int EntityManager::generateNewEid() {
    return 0;
}

Entity EntityManager::createEntity() {
    return Entity(0);
}

void EntityManager::addComponent(Component *any_component, Entity *game_entity) {

}

Component *EntityManager::getEntityComponent(Component *any_component, Entity *game_entity) {
    return nullptr;
}

void EntityManager::removeEntity(Entity *game_entity) {

}

Entity *EntityManager::getAllEntitiesPosessingComponent(Component *any_component) {
    return nullptr;
}
