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

#ifndef KOMODO_AICOMPONENT_H
#define KOMODO_AICOMPONENT_H

#include "Component.h"
#include "../../utils/Vector3.h"

#define MAX_ENEMIES 25

class AiComponent : Component {

public:
    AiComponent(Vector3 init_goal, int init_enemies[MAX_ENEMIES]);

private:
    Vector3 goal;
    bool isAlive;
    int enemies[MAX_ENEMIES];
};


#endif //KOMODO_AICOMPONENT_H
