//
// Created by kuukie on 2021/11/24.
//

#include "Calculate.h"

int Calculate::centralPosition(int outside, int inside) {
    if(outside <= inside) {
        return 0;
    } else {
        outside = outside / 2;
        inside = inside / 2;
        return outside - inside;
    }
}
