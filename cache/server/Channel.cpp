//
// Created by kuukie on 2022/1/24.
//

#include "Channel.h"

void Channel::hand_shake(const int number, const std::string host, const int port) {
    cac::number = number;
    cac::host = host;
    cac::port = port;
}

int Channel::get_number() {
    return cac::number;
}

std::string Channel::get_host() {
    return cac::host;
}

int Channel::get_port() {
    return cac::port;
}

void Channel::login(void* view) {
    if(__sync_bool_compare_and_swap(&cac::flag,0,1)) {
        cac::view = view;
        memset(cac::response,0,sizeof(cac::response));
    }
}

void Channel::event_ret(const std::string& data) {
    strcpy(cac::response,data.c_str());
    cac::flag = 10;
}

std::string Channel::get(void *view) {
    if (cac::view == view) {
        return cac::response;
    } else {
        return "";
    }
}

bool Channel::loadingEnd() {
    return __sync_bool_compare_and_swap(&cac::flag,10,0);
}

void Channel::event_req(const std::string& data) {
    bool success = join_queue(data.c_str());
    for (;!success;success = join_queue(data.c_str())) {
        continue;
    }
}

bool Channel::join_queue(const char *request) {
    return cac::cyclic->push(request);
}

char* Channel::exit_queue() {
    return cac::cyclic->pull();
}
