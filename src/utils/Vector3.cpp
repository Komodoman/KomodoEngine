//
// Created by Komodoman on 8/5/2015.
//

#include "Vector3.h"


Vector3::Vector3() {
    Vector3(0, 0, 0);
}

Vector3::Vector3(int x, int y, int z) {
    xVal = x;
    yVal = y;
    zVal = z;
}

int Vector3::getX() {
    return xVal;
}

int Vector3::getY() {
    return yVal;
}

int Vector3::getZ() {
    return zVal;
}
