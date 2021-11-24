//
// Created by kuukie on 2021/11/22.
//

#include "UdpTemplate.h"

void UdpTemplate::ping(char* request) {
    rpc::udp->request(request);
}

void UdpTemplate::pong(char*& response) {
    rpc::udp->response();
    if(rpc::udp->error.empty()) {
        char res[MAX];
        strcpy(res,rpc::udp->message.c_str());
        response = res;
    } else {
        response = "{\"result\":\"-1\"}";
    }
}
