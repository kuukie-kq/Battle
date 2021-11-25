//
// Created by kuukie on 2021/10/25.
//

#include "UserLogin.h"

//字符串分割函数
std::vector<std::string> split(std::string str,const std::string& pattern) {
    std::string::size_type pos;
    std::vector<std::string> result;
    str+=pattern;  //扩展字符串以方便操作
    int size=str.size();
    for(int i=0;i<size;i++) {
        pos=str.find(pattern,i);
        if(pos<size) {
            std::string s=str.substr(i,pos-i);
            result.push_back(s);
            i=pos+pattern.size()-1;
        }
    }
    return result;
}

int UserLogin::callBySocket(char*& request) {
    //使用socket，生成套接字文件描述符
    if((fdSocket = socket(AF_INET,SOCK_DGRAM,0)) < 0) {
        error = "网络绑定描述符";
        return 1;
    }
    //通过sockaddr_in结构设置服务器地址和监听端口
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(HOST);
    server.sin_port = htons(PORT);
    server_addr_length = sizeof(server);
    //数据请求
    int send_length = 0;
    std::string rs = request;
    sprintf(requestLine, "%s", request);
    std::cerr << rs.size() << std::endl;
    send_length = sendto(fdSocket, rs.c_str(), rs.size(), 0, (struct sockaddr*)&server, server_addr_length);
    if(send_length < 0) {
        error = "发送数据请求";
        return 1;
    }
    //数据响应
    int recv_length = 0;
    recv_length = recvfrom(fdSocket, responseLine, sizeof(responseLine), 0, (struct sockaddr*)&server, &server_addr_length);
    if(recv_length < 0) {
        error = "接受数据响应";
        return 1;
    }
    QString response = responseLine;
    request = (char *)response.toStdString().c_str();
    request = responseLine;
    close(fdSocket);
    return 0;
}

int UserLogin::login(const QString& username, const QString& password) {
    char data[MAX];
//    sprintf(data,"login<:>%s<->%s",username.toStdString().c_str(),password.toStdString().c_str());
//    char* requestAndResponse = data;
//    int call = callBySocket(requestAndResponse);
//    if (call != 0) {
//        return -1;
//    }
    /**
     * json request start
     */
    neb::CJsonObject jsonObject;
    jsonObject.Add("methodName","login");
    jsonObject.Add("className","BaseService");
    jsonObject.AddEmptySubArray("argCls");
    jsonObject["argCls"].Add("java.lang.String");
    jsonObject["argCls"].Add("java.lang.String");
    jsonObject.AddEmptySubArray("args");
    jsonObject["args"].Add(username.toStdString());
    jsonObject["args"].Add(password.toStdString());
    std::cerr << jsonObject.ToString() << std::endl;
    sprintf(data,"%s",jsonObject.ToString().c_str());
    char* requestAndResponse = data;
    int call = callBySocket(requestAndResponse);
    if (call != 0) {
        return -1;
    }
    std::string result;
    std::cerr << requestAndResponse << std::endl;
    neb::CJsonObject test(requestAndResponse);
    test.Get("result",result);
    std::cerr << test.ToString() << std::endl;
    std::cerr << result << std::endl;
    return atoi(result.c_str());
    /**
     * json response end
     */
    return atoi(requestAndResponse);
}

int TestUserLogin::server() {
    //使用socket，生成套接字文件描述符
    if((serverSockfd = socket(AF_INET,SOCK_DGRAM,0)) < 0) {
        std::cerr << "server first socket error\n";
        exit(1);
    }
    //通过sockaddr_in结构设置服务器地址和监听端口
    bzero(&serveraddr,sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(PORT);
    server_addr_length = sizeof(serveraddr);
    //使用bind绑定监听端口，将套接字文件描述符和地址类型变量绑定
    if(bind(serverSockfd,(struct sockaddr*)&serveraddr,server_addr_length) < 0) {
        std::cerr << "server first bind error\n";
        exit(1);
    }

    //请求数据
    client_addr_length = sizeof(sockaddr_in);
    int recv_length = 0;
    recv_length = recvfrom(serverSockfd,recvline,sizeof(recvline),0,(struct sockaddr*)&clientaddr,&client_addr_length);
    if(recv_length < 0) {
        std::cerr << "server recvfrom error\n";
    }

    std::string request = recvline;
    std::vector<std::string> words = split(request,"<:>");
    for(int i=0;i<words.size();i++) {
        if(words[i] == "login" && i == 0 && words.size() == 2) {
            std::vector<std::string> params = split(words[1],"<->");
            sprintf(sendline,"%d",login(params[0].c_str(),params[1].c_str()));
        }
    }

    //响应数据
    int send_length = 0;
    send_length = sendto(serverSockfd,sendline,sizeof(sendline),0,(struct sockaddr*)&clientaddr,client_addr_length);
    if(send_length < 0) {
        std::cerr << "server sendto error\n";
    }

    close(serverSockfd);//析构
    return 0;
}

int TestUserLogin::login(const QString& username, const QString& password) {
    if(username == password) {
        return 1;
    } else {
        return 0;
    }
}

int UserLogin::loginTest(const QString &username, const QString &password) {
    char data[MAX];
    neb::CJsonObject jsonObject;
    jsonObject.Add("methodName","login");
    jsonObject.Add("className","BaseService");
    jsonObject.AddEmptySubArray("argCls");
    jsonObject["argCls"].Add("java.lang.String");
    jsonObject["argCls"].Add("java.lang.String");
    jsonObject.AddEmptySubArray("args");
    jsonObject["args"].Add(username.toStdString());
    jsonObject["args"].Add(password.toStdString());
    std::cerr << jsonObject.ToString() << std::endl;
    sprintf(data,"%s",jsonObject.ToString().c_str());
    char* requestAndResponse = data;

    TcpTemplate::ping(requestAndResponse);
    TcpTemplate::pong(requestAndResponse);

    std::string result;
    std::cerr << requestAndResponse << std::endl;
    neb::CJsonObject test(requestAndResponse);
    test.Get("result",result);
    return atoi(result.c_str());
}
