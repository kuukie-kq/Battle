//
// Created by kuukie on 2022/1/29.
//

#include "Random.h"

int Random::randInt() {
    srand((unsigned int)time(0));
    return rand() % 100000;
}
