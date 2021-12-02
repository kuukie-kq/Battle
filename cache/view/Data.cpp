//
// Created by kuukie on 2021/12/1.
//

#include "Data.h"

char* Data::getUserName() {
    return cac::u.user_name;
}

void Data::setUserName(const char *username) {
    strcpy(cac::u.user_name,username);
}
