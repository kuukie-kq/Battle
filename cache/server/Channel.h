//
// Created by kuukie on 2022/1/24.
//

#ifndef BATTLE_CHANNEL_H
#define BATTLE_CHANNEL_H

#pragma once
#include <cstring>
#include <string>
#include <atomic>
#include "../view/Data.h"

#define MAX 1024

#define LOCK_PREFIX "lock;"
#define __sync_bool_compare_and_swap(mem,oldval,newval) ({ \
    __typeof (*mem) ret; \
    __asm __volatile (LOCK_PREFIX "cmpxchgl %2, %1;sete %%al;movzbl %%al,%%eax" \
    : "=a" (ret), "=m" (*mem) \
    : "r" (newval), "m" (*mem), "a" (oldval) \
    :"memory"); \
    ret; \
})

namespace cac {
    class CyclicQueue {
    private:
        static const int size = 12;
        char* data[size];
        int read;
        int write;
    public:
        CyclicQueue() {
            for (int i=0;i<size;i++) {
                data[i] = nullptr;
            }
            read = 0;
            write = 0;
        }

        bool push(const char* request) {
            if (write + 1 == read) {
                printf("%s","queue full, try again");
                return false;
            } else {
                data[write] = strdup(request);
                if (write + 1 == size) {
                    write = 0;
                } else {
                    write = write + 1;
                }
                return true;
            }
        }

        char* pull() {
            if (read == write) {
                printf("%s","queue null, wait a moment");
                return nullptr;
            } else {
                char* response = strdup(data[read]);
                if (read + 1 == size) {
                    read = 0;
                } else {
                    read = read + 1;
                }
                return response;
            }
        }
    };
    // ajax event
    static int flag = 0;
    static void* view = nullptr;
    static char response[MAX];
    // hand shake
    static int number;
    static std::string host;
    static int port;
    // room game start data
    static CyclicQueue* cyclic = new CyclicQueue();
}

class Channel {
public:
    static void hand_shake(const int number,const std::string host,const int port);
    static int get_number();
    static std::string get_host();
    static int get_port();
    static void login(void* view);
    static void event_ret(const std::string& data);
    static std::string get(void* view);
    static bool loadingEnd();
    static void event_req(const std::string& data);
    static bool join_queue(const char* request);
    static char* exit_queue();
};

#endif //BATTLE_CHANNEL_H
