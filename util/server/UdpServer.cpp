//
// Created by kuukie on 2022/1/11.
//

#include "UdpServer.h"

void thread_battle() {
    //hand shake
    char datas[MAX];
    char* data;
    sprintf(datas,"%s",User::hand_shake_json().c_str());
    UdpTemplate::ping(datas);
    UdpTemplate::pong(data);
    std::string string = data;
    if (User::hand_shake_json_ret(string) == 0) {
        UdpServer* connectServer = new UdpServer(
                Channel::get_host().c_str(),
                Channel::get_port());
        UdpServer::request(User::shake_hand_json());
        for(;;) {
            connectServer->connect()->response();
            if(!connectServer->connect()->error.empty()) {
                break;
            } else {
                // 缓存机制
                if (User::response_event(connectServer->connect()->message)) {
                    Channel::event_ret(connectServer->connect()->message);
                } else {
                    Channel::event_req(connectServer->connect()->message);
                }
            }
        }
    } else {
        std::cerr << "hand shake field!" << std::endl;
    }
}

void UdpServer::server() {
    std::thread td(thread_battle);
    td.detach();
}

UdpServer::UdpServer(const char* host, int port) {
    server::udp = new UdpConnect(host,port);
}

UdpServer::~UdpServer() = default;

UdpConnect* UdpServer::connect() {
    return server::udp;
}

void UdpServer::request(std::string data) {
    if(server::udp == nullptr) {
        std::cerr << "server not found, please call producer" << std::endl;
    } else {
        server::udp->request(data.data());
        std::cerr << "send " << server::udp <<":" << data.data() << std::endl;
    }
}
