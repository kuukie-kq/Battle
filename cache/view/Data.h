//
// Created by kuukie on 2021/12/1.
//

#ifndef BATTLE_DATA_H
#define BATTLE_DATA_H

#pragma once
#include <cstring>
#include <cstdlib>

namespace cac {
    typedef struct user {
        int user_id;
        char* user_name;
        char* user_signature;
    };
    typedef struct room {
        int room_id;
        char* room_name;
    };

    static struct user u;
    static struct room r;
    static struct room* rs[9];
}

class Data {
public:
    static void setUserId(int id);
    static int getUserId();
    static void setUserName(const char* username);
    static char* getUserName();
    static void setUserSignature(const char* signature);
    static char* getUserSignature();
    static void setRoomMultiple(int index,int id,const char* name);
    static int getRoomIdMultiple(int index);
    static char* getRoomNameMultiple(int index);
};


#endif //BATTLE_DATA_H
