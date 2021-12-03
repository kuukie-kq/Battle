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
    strcpy(cac::u.user_name,username);
}

char* Data::getUserName() {
    return cac::u.user_name;
}

void Data::setUserSignature(const char* signature) {
    strcpy(cac::u.user_signature,signature);
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
    strcpy(cac::rs[index]->room_name,name);
}
