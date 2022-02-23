//
// Created by kuukie on 2021/12/1.
//

#ifndef BATTLE_USER_H
#define BATTLE_USER_H

#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <netdb.h>
#include <arpa/inet.h>
#include "../../util/json/CJsonObject.h"
#include "../../util/rand/Random.h"
#include "../../cache/server/Channel.h"
#include "../../cache/view/Data.h"
//#define NETCONN 0 // 0为udp，1为tcp
//#if (NETCONN == 0)
//#include "../UdpTemplate.h"
//#elif (NETCONN == 1)
//#include "../TcpTemplate.h"
//#endif

class User {
private:
//    static int login(const QString& username,const QString& password);
//    static int create_user();
//    static int get_rooms_information();
//    static int find_room_information(const QString& room);
//    static int enter_room(const QString& room);
//    static int create_room();
//    static int enter_channel();
public:
    static std::string hand_shake_json();
    static int hand_shake_json_ret(const std::string& response);
    static std::string shake_hand_json();
    static bool response_event(const std::string& response);
    static std::string login_json(const std::string& username,const std::string& password);
    static int login_json_ret(const std::string& response);
    static std::string rooms_json();
    static int rooms_json_ret(const std::string& response);
    static std::string join_room_json(const std::string& room,const std::string& user);
    static int join_room_json_ret(const std::string& response);
    static std::string ready_room_json(const std::string& room);
    static int ready_room_json_ret(const std::string& response);
    static std::string package_tank_json(const std::string& room,const std::string& user);
    static int package_tank_json_ret(const std::string& response);
    static std::string create_tank_json(const std::string& room,const std::string& user,const std::string& code);
    static int create_tank_json_ret(const std::string& response);
};

#endif //BATTLE_USER_H
