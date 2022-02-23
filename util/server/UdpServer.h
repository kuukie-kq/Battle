//
// Created by kuukie on 2022/1/11.
//

#ifndef BATTLE_UDPSERVER_H
#define BATTLE_UDPSERVER_H

#pragma once

#include <thread>
#include <cstring>
#include "../../cache/server/Channel.h"
#include "../../cache/view/Data.h"
#include "../../rpc/UdpTemplate.h"
#include "../../rpc/view/User.h"

namespace server {
    static UdpConnect* udp;
}

class UdpServer {
public:
    UdpServer(const char* host,int port);
    ~UdpServer();
    static void server();
    UdpConnect* connect();
    static void request(std::string data);
};

#endif //BATTLE_UDPSERVER_H
