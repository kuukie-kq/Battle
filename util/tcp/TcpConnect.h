//
// Created by kuukie on 2021/11/21.
//

#ifndef BATTLE_TCPCONNECT_H
#define BATTLE_TCPCONNECT_H

#pragma once
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <vector>
#include <arpa/inet.h>

#define MAX 1024
#define HOST "127.0.0.1"
#define PORT 9527

class TcpConnect {
private:
    int fd_socket;
    struct sockaddr_in server;
    unsigned int server_addr_length;
    char responseLine[MAX];
    char requestLine[MAX];
public:
    TcpConnect();
    ~TcpConnect();
    int ping();
    int request(char* request) const;
    void response();
    void pong() const;
    std::string error;
    std::string message;
};

#endif //BATTLE_TCPCONNECT_H
