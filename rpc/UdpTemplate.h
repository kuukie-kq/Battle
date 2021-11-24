//
// Created by kuukie on 2021/11/22.
//

#ifndef BATTLE_UDPTEMPLATE_H
#define BATTLE_UDPTEMPLATE_H

#pragma once
#include "../util/udp/UdpConnect.h"

namespace rpc {
    static UdpConnect* udp = new UdpConnect();
}

class UdpTemplate {
public:
    static void ping(char* request);
    static void pong(char*& response);
};


#endif //BATTLE_UDPTEMPLATE_H
