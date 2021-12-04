//
// Created by kuukie on 2021/11/21.
//

#include "UdpConnect.h"

UdpConnect::UdpConnect() {
    //使用socket，生成套接字文件描述符
    if((fd_socket = socket(AF_INET,SOCK_DGRAM,0)) < 0) {
        error = "网络绑定描述符错误";
    }
    //通过sock_addr_in结构设置服务器地址和监听端口
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(HOST);
    server.sin_port = htons(PORT);
    server_addr_length = sizeof(server);
}

UdpConnect::~UdpConnect() = default;

int UdpConnect::request(char* request) {
    std::string rs = request;
    return sendto(fd_socket,rs.c_str(),rs.size(),0,(struct sockaddr*)&server,server_addr_length);
}

void UdpConnect::response() {
    memset(responseLine,0,sizeof(responseLine));
    if(recvfrom(fd_socket,responseLine,sizeof(responseLine),0,(struct sockaddr*)&server,&server_addr_length) < 0) {
        error = "接收数据响应错误";
    }
    message = responseLine;
}
