//
// Created by kuukie on 2021/11/21.
//

#ifndef BATTLE_UDPCONNECT_H
#define BATTLE_UDPCONNECT_H

#pragma once
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <vector>
#include <arpa/inet.h>

#define MAX 1024
#define HOST "192.168.31.42"
#define PORT 9527

class UdpConnect {
private:
    int fd_socket;
    unsigned int server_addr_length;
    struct sockaddr_in server;
    char responseLine[MAX];
    char requestLine[MAX];
public:
    UdpConnect();
    ~UdpConnect();
    int request(char* request);
    void response();
    std::string error;
    std::string message;
};


#endif //BATTLE_UDPCONNECT_H
