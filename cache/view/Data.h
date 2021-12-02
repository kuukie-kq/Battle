//
// Created by kuukie on 2021/12/1.
//

#ifndef BATTLE_DATA_H
#define BATTLE_DATA_H

#pragma once
#include <cstring>

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
}

class Data {
public:
    static void setUserName(const char* username);
    static char* getUserName();
};


#endif //BATTLE_DATA_H
