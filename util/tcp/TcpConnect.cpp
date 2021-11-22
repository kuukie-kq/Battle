//
// Created by kuukie on 2021/11/21.
//

#include "TcpConnect.h"

TcpConnect::TcpConnect() {
    //使用socket，生成套接字文件描述符
    if((fd_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error = "网络绑定描述符错误";
    }
    //通过sock_addr_in结构设置连接端口
    memset(&server,0,sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    //使用inet_pton(ipv4)inet_ntop(ipv6)将IP地址在二进制与十进制之间转换
    if(inet_pton(AF_INET,HOST,&server.sin_addr) <= 0) {
        error = "ip地址绑定错误";
    }
    server_addr_length = sizeof(server);
}

TcpConnect::~TcpConnect() = default;

int TcpConnect::ping() {
    if(connect(fd_socket, (struct sockaddr*)&server, server_addr_length) < 0) {
        error = "建立连接错误";
        return -1;
    }
    return 0;
}

int TcpConnect::request(char* request) const {
    std::string rs = request;
    return send(fd_socket, rs.c_str(), rs.size(), 0);
}

void TcpConnect::response() {
    recv(fd_socket, responseLine, MAX, 0);
    message = responseLine;
}

void TcpConnect::pong() const {
    close(fd_socket);
}
