//
// Created by kuukie on 2021/11/24.
//

#ifndef BATTLE_CALCULATE_H
#define BATTLE_CALCULATE_H

#pragma once

#define CENTER(out,in) ({\
    Calculate::centralPosition((out),(in)); \
})

class Calculate {
public:
    static int centralPosition(int outside, int inside);
};


#endif //BATTLE_CALCULATE_H
