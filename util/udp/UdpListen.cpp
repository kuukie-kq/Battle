//
// Created by kuukie on 2021/11/21.
//

#include "UdpListen.h"

UdpListen::UdpListen() {
    //使用socket，生成套接字文件描述符
    if((fd_socket = socket(AF_INET,SOCK_DGRAM,0)) < 0) {
        error = "网络绑定描述符错误";
    }
    //通过sock_addr_in结构设置服务器地址和监听端口
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);
    server_addr_length = sizeof(server);
    //使用bind绑定监听端口，将套接字文件描述符和地址类型变量绑定
    if(bind(fd_socket,(struct sockaddr*)&server,server_addr_length) < 0) {
        error = "绑定端口监听失败";
    }
    client_addr_length = sizeof(client);
}

UdpListen::UdpListen(int port) {
    //使用socket，生成套接字文件描述符
    if((fd_socket = socket(AF_INET,SOCK_DGRAM,0)) < 0) {
        error = "网络绑定描述符错误";
    }
    //通过sock_addr_in结构设置服务器地址和监听端口
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(port);
    server_addr_length = sizeof(server);
    //使用bind绑定监听端口，将套接字文件描述符和地址类型变量绑定
    if(bind(fd_socket,(struct sockaddr*)&server,server_addr_length) < 0) {
        error = "绑定端口监听失败";
    }
    client_addr_length = sizeof(client);
}

UdpListen::~UdpListen() = default;

int UdpListen::request(char* request) {
    std::string rs = request;
    return sendto(fd_socket,rs.c_str(),rs.size(),0,(struct sockaddr*)&client,client_addr_length);
}

void UdpListen::response() {
    if(recvfrom(fd_socket,responseLine,sizeof(responseLine),0,(struct sockaddr*)&client,&client_addr_length) < 0) {
        error = "接收数据响应错误";
    }
    message = responseLine;
}
