//
// Created by kuukie on 2021/11/21.
//

#include "TcpListen.h"

TcpListen::TcpListen() {
    //使用socket，生成套接字文件描述符
    if((fd_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error = "网络绑定描述符错误";
    }
    //通过sock_addr_in结构设置连接端口
    memset(&server,0,sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);
    server_addr_length = sizeof(server);
    //使用bind绑定监听端口，将套接字文件描述符和地址类型变量绑定
    if(bind(fd_socket,(struct sockaddr*)&server,server_addr_length) < 0) {
        error = "绑定端口错误";
    }
}

TcpListen::~TcpListen() = default;

int TcpListen::ping() {
    if(listen(fd_socket,10) < 0) {
        error = "监听端口错误";
        return -1;
    }
}

int TcpListen::shake() {
    if((fd_shake = accept(fd_socket,(struct sockaddr*)NULL,NULL)) < 0) {
        error = "服务连接错误";
        return -1;
    }
    return fd_shake;
}

int TcpListen::request(char *&request,int socket_fd) const {
    std::string rs = request;
    return send(socket_fd, rs.c_str(), rs.size(), 0);
}

void TcpListen::response(int socket_fd) {
    recv(socket_fd, responseLine, MAX, 0);
    message = responseLine;
}

void TcpListen::unShake(int socket_fd) const {
    close(socket_fd);
}

void TcpListen::pong() const {
    close(fd_socket);
}
