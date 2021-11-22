//
// Created by kuukie on 2021/11/21.
//

#ifndef BATTLE_TEMPLATE_H
#define BATTLE_TEMPLATE_H

#pragma once
#include "../util/tcp/TcpConnect.h"
#include "../util/udp/UdpConnect.h"

namespace rpc {
    static TcpConnect* tcp = new TcpConnect();
    static UdpConnect* udp = new UdpConnect();
}

class Template {
public:
    static void ping(char* request);
    static void pong(char*& response);
};

#endif //BATTLE_TEMPLATE_H
