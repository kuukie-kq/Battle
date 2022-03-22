//
// Created by kuukie on 2022/2/28.
//

#ifndef BATTLE_GAME_H
#define BATTLE_GAME_H

#pragma once
#include "../../util/json/CJsonObject.h"
#include "../../cache/server/Channel.h"

class Game {
public:
    static ng::GameFrame game_json(const char* request);
};


#endif //BATTLE_GAME_H
