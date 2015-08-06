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

#ifndef KOMODO_VECTOR3_H
#define KOMODO_VECTOR3_H


class Vector3 {

public:
    Vector3();

    Vector3(int x, int y, int z);

    int getX();

    int getY();

    int getZ();

private:
    int xVal;
    int yVal;
    int zVal;


};


#endif //KOMODO_VECTOR3_H
