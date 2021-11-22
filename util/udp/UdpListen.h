//
// Created by kuukie on 2021/11/21.
//

#ifndef BATTLE_UDPLISTEN_H
#define BATTLE_UDPLISTEN_H

#pragma once
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <strings.h>
#include <cstring>
#include <vector>
#include <arpa/inet.h>

#define MAX 1024
#define HOST "192.168.31.42"
#define PORT 9527

class UdpListen {
private:
    int fd_socket;
    unsigned int server_addr_length;
    unsigned int client_addr_length;
    struct sockaddr_in server;
    struct sockaddr_in client;
    char responseLine[MAX];
    char requestLine[MAX];
public:
    UdpListen();
    ~UdpListen();
    int request(char*& request);
    void response();
    std::string error;
    std::string message;
};


#endif //BATTLE_UDPLISTEN_H
