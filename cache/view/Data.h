//
// Created by kuukie on 2021/12/1.
//

#ifndef BATTLE_DATA_H
#define BATTLE_DATA_H

#pragma once
#include <cstring>
#include <cstdlib>

namespace cac {
    struct user {
        int user_id;
        char* user_name;
        //char* user_signature;
        char* user_gender;
        int user_level;
    };
    struct room {
        int room_id;
        char* room_name;
        char* room_user_name;
        int players;
    };
    // user message login/register
    static struct user u;
    // room message competitive
    static struct room* rs[9];
}

class Data {
public:
    static void setUserId(int id);
    static int getUserId();
    static void setUserName(const char* username);
    static char* getUserName();
//    static void setUserSignature(const char* signature);
//    static char* getUserSignature();
    static void setUserGender(const char* gender);
    static char* getUserGender();
    static void setUserLevel(int level);
    static int getUserLevel();
    static void setRoomMultiple(int index,int id,const char* name,const char* uname,int players);
    static int getRoomIdMultiple(int index);
    static char* getRoomNameMultiple(int index);
    static char* getUserNameMultiple(int index);
    static int getPlayersMultiple(int index);
};


#endif //BATTLE_DATA_H
