/*
           _
          ' )   _/                                          /'
          /' _/~                                          /'
        /'_/~    ____    ,__________     ____     _____,/' ____
      /\/~     /'    )--/'    )     )  /'    )--/'    /' /'    )--
    /'  \    /'    /' /'    /'    /' /'    /' /'    /' /'    /'
(,/'     \_,(___,/' /'    /'    /(__(___,/'  (___,/(__(___,/' engine
Game manager, Created by Kyle the Komodoman on 8/5/2015.
*/

#ifndef KOMODO_ENTITY_H
#define KOMODO_ENTITY_H


class Entity {

public:
    Entity(int e_id);

    int getEntityId();

private:
    int entity_id;


};


#endif //KOMODO_ENTITY_H
