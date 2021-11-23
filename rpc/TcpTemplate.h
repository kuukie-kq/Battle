//
// Created by kuukie on 2021/11/21.
//

#ifndef BATTLE_TCPTEMPLATE_H
#define BATTLE_TCPTEMPLATE_H

#pragma once
#include "../util/tcp/TcpConnect.h"

namespace rpc {
    static TcpConnect* tcp = new TcpConnect();
}

class TcpTemplate {
public:
    static void ping(char* request);
    static void pong(char*& response);
};

#endif //BATTLE_TCPTEMPLATE_H
