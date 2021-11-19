//
// Created by kuukie on 2021/10/25.
//

#ifndef BATTLE_USERLOGIN_H
#define BATTLE_USERLOGIN_H

#pragma once
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <strings.h>
#include <QString>
#include <cstring>
#include <vector>
#include <arpa/inet.h>
#include "../../util/json/CJSonObject.h"
#define MAX 1024
#define PORT 9999

class UserLogin {
private:
    int fdSocket;
    unsigned int server_addr_length;
    struct sockaddr_in server;
    char responseLine[MAX];
    char requestLine[MAX];
    int callBySocket(char*& request);
    QString error;
public:
    int login(const QString& username,const QString& password);
};

class TestUserLogin {
private:
    int serverSockfd;
    unsigned int server_addr_length;
    unsigned int client_addr_length;
    struct sockaddr_in serveraddr;
    struct sockaddr_in clientaddr;
    char recvline[MAX];
    char sendline[MAX];
    int login(const QString& username,const QString& password);
public:
    int server();
};


#endif //BATTLE_USERLOGIN_H
