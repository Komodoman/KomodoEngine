/*
           _
          ' )   _/                                          /'
          /' _/~                                          /'
        /'_/~    ____    ,__________     ____     _____,/' ____
      /\/~     /'    )--/'    )     )  /'    )--/'    /' /'    )--
    /'  \    /'    /' /'    /'    /' /'    /' /'    /' /'    /'
(,/'     \_,(___,/' /'    /'    /(__(___,/'  (___,/(__(___,/' engine
Entity Manager, Created by Kyle the Komodoman on 8/5/2015.
*/

#ifndef KOMODO_ENTITYMANAGER_H
#define KOMODO_ENTITYMANAGER_H


#include "../../Manager.h"
#include "Entity.h"
#include "../components/Component.h"

//TODO: add functionality
class EntityManager : Manager {

private:
    EntityManager() { }                         // Singleton
    EntityManager(EntityManager const &) { }    // No Copying
    void operator=(EntityManager const &) { }   // No Assignment

public:
    ~EntityManager();

    // Get the one and only instance of the Entity Manager
    static EntityManager &getInstance();

    // Generate a new entity ID based on the # of entites in game
    int generateNewEid();

    // Create a new entity
    Entity createEntity();

    // Add a component to a entity
    void addComponent(Component *any_component, Entity *game_entity);

    // Get certain component from entity
    Component *getEntityComponent(Component *any_component, Entity *game_entity);

    // Remove entity from game
    void removeEntity(Entity *game_entity);

    Entity *getAllEntitiesPosessingComponent(Component *any_component);

};


#endif //KOMODO_ENTITYMANAGER_H
