//
// Created by kuukie on 2022/2/28.
//

#include "Game.h"

ng::GameFrame Game::game_json(const char *request) {
    struct ng::GameFrame gameFrame;
    neb::CJsonObject jsonObject(request);

    if (Channel::room_master()) {
        gameFrame.mineX = atoi(jsonObject["info"][0]["Player1"]("x").c_str());
        gameFrame.mineY = atoi(jsonObject["info"][0]["Player1"]("y").c_str());
        gameFrame.mineHP = atoi(jsonObject["info"][0]["Player1"]("hp").c_str());
        gameFrame.mineST = atoi(jsonObject["info"][0]["Player1"]("dir").c_str()) + atoi(jsonObject["info"][0]["Player1"]("dir").c_str()) * 4;

        gameFrame.herX = atoi(jsonObject["info"][1]["Player2"]("x").c_str());
        gameFrame.herY = atoi(jsonObject["info"][1]["Player2"]("y").c_str());
        gameFrame.herHP = atoi(jsonObject["info"][1]["Player2"]("hp").c_str());
        gameFrame.herST = atoi(jsonObject["info"][1]["Player2"]("dir").c_str()) + atoi(jsonObject["info"][1]["Player2"]("dir").c_str()) * 4;
    } else {
        gameFrame.herX = atoi(jsonObject["info"][0]["Player1"]("x").c_str());
        gameFrame.herY = atoi(jsonObject["info"][0]["Player1"]("y").c_str());
        gameFrame.herHP = atoi(jsonObject["info"][0]["Player1"]("hp").c_str());
        gameFrame.herST = atoi(jsonObject["info"][0]["Player1"]("dir").c_str()) + atoi(jsonObject["info"][0]["Player1"]("dir").c_str()) * 4;

        gameFrame.mineX = atoi(jsonObject["info"][1]["Player2"]("x").c_str());
        gameFrame.mineY = atoi(jsonObject["info"][1]["Player2"]("y").c_str());
        gameFrame.mineHP = atoi(jsonObject["info"][1]["Player2"]("hp").c_str());
        gameFrame.mineST = atoi(jsonObject["info"][1]["Player2"]("dir").c_str()) + atoi(jsonObject["info"][1]["Player2"]("dir").c_str()) * 4;
    }

    return gameFrame;
}
