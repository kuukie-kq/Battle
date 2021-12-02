//
// Created by kuukie on 2021/12/1.
//

#ifndef BATTLE_USER_H
#define BATTLE_USER_H

#pragma once
#include <iostream>
#include <strings.h>
#include <QString>
#include <cstring>
#include <vector>
#include "../../util/json/CJsonObject.h"
#define NETCONN 0 // 0为udp，1位tcp
#if (NETCONN == 0)
#include "../UdpTemplate.h"
#elif (NETCONN == 1)
#include "../TcpTemplate.h"
#endif

class User {
public:
    static int login(const QString& username,const QString& password);
    static int create_user();
    static int get_rooms_information();
    static int find_room_information(const QString& room);
    static int enter_room(const QString& room);
    static int create_room();
};


#endif //BATTLE_USER_H
