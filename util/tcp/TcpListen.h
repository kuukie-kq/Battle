//
// Created by kuukie on 2021/11/21.
//

#ifndef BATTLE_TCPLISTEN_H
#define BATTLE_TCPLISTEN_H

#pragma once
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <vector>
#include <arpa/inet.h>

#define MAX 1024
#define HOST "192.168.43.87"
#define PORT 9527

class TcpListen {
private:
    int fd_socket;
    struct sockaddr_in server;
    unsigned int server_addr_length;
    char responseLine[MAX];
    char requestLine[MAX];
    int fd_shake;
public:
    TcpListen();
    ~TcpListen();
    int ping();
    int shake();
    int request(char*& request,int socket_fd) const;
    void response(int socket_fd);
    void unShake(int socket_fd) const;
    void pong() const;
    std::string error;
    std::string message;
};


#endif //BATTLE_TCPLISTEN_H
