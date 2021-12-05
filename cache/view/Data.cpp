//
// Created by kuukie on 2021/12/1.
//

#include "Data.h"

void Data::setUserId(int id) {
    cac::u.user_id = id;
}

int Data::getUserId() {
    return cac::u.user_id;
}

void Data::setUserName(const char* username) {
    cac::u.user_name = strdup(username);
}

char* Data::getUserName() {
    return cac::u.user_name;
}

void Data::setUserSignature(const char* signature) {
    cac::u.user_signature = strdup(signature);
}

char* Data::getUserSignature() {
    return cac::u.user_signature;
}

void Data::setRoomMultiple(int index, int id, const char *name) {
    if(cac::rs[index] != nullptr) {
        free(cac::rs[index]);
    }
    cac::rs[index] = (struct cac::room *)malloc(sizeof(struct cac::room));
    cac::rs[index]->room_id = id;
    cac::rs[index]->room_name = strdup(name);
}

int Data::getRoomIdMultiple(int index) {
    if(cac::rs[index] == nullptr) {
        return -1;
    } else {
        return cac::rs[index]->room_id;
    }
}

char* Data::getRoomNameMultiple(int index) {
    if(cac::rs[index] == nullptr) {
        return "none";
    } else {
        return cac::rs[index]->room_name;
    }
}
