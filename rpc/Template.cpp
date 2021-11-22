//
// Created by kuukie on 2021/11/21.
//

#include "Template.h"

void Template::ping(char* request) {
    rpc::tcp->ping();
    rpc::tcp->request(request);
}

void Template::pong(char*& response) {
    rpc::tcp->response();
    if(rpc::tcp->error.empty()) {
        char res[1024];
        strcpy(res,rpc::tcp->message.c_str());
        response = res;
    } else {
        response = "{\"result\":\"-1\"}";
    }
    rpc::tcp->pong();
}
