/*
           _
          ' )   _/                                          /'
          /' _/~                                          /'
        /'_/~    ____    ,__________     ____     _____,/' ____
      /\/~     /'    )--/'    )     )  /'    )--/'    /' /'    )--
    /'  \    /'    /' /'    /'    /' /'    /' /'    /' /'    /'
(,/'     \_,(___,/' /'    /'    /(__(___,/'  (___,/(__(___,/' engine
Position Component, Created by Kyle the Komodoman on 8/5/2015.
*/

#ifndef KOMODO_POSITIONCOMPONENT_H
#define KOMODO_POSITIONCOMPONENT_H


#include "../../utils/Vector3.h"

class PositionComponent {

private:
    Vector3 position;

public:
    PositionComponent(Vector3 init_position);

    Vector3 getPosition();
};


#endif //KOMODO_POSITIONCOMPONENT_H
