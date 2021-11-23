//
// Created by kuukie on 2021/11/21.
//

#include "TcpTemplate.h"

void TcpTemplate::ping(char* request) {
    if(rpc::tcp->ping() < 0) {
        return;
    }
    rpc::tcp->request(request);
}

void TcpTemplate::pong(char*& response) {
    rpc::tcp->response();
    if(rpc::tcp->error.empty()) {
        char res[MAX];
        strcpy(res,rpc::tcp->message.c_str());
        response = res;
    } else {
        response = "{\"result\":\"-1\"}";
    }
    rpc::tcp->pong();
}
