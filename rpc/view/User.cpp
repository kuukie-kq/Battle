//
// Created by kuukie on 2021/12/1.
//

#include "User.h"

int User::login(const QString& username,const QString& password) {
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
    std::cerr << "json & " << jsonObject.ToString().size() << std::endl;
    sprintf(data,"%s",jsonObject.ToString().c_str());
    char* requestAndResponse = data;

    #if (NETCONN == 0)
    UdpTemplate::ping(requestAndResponse);
    UdpTemplate::pong(requestAndResponse);
    #elif (NETCONN == 1)
    TcpTemplate::ping(requestAndResponse);
    TcpTemplate::pong(requestAndResponse);
    #endif

    int result;
    std::cerr << requestAndResponse << std::endl;
    neb::CJsonObject test(requestAndResponse);
    test.Get("result",result);

    Data::setUserId(atoi(test["value"]("id").c_str()));
    Data::setUserName(test["value"]("username").c_str());
    Data::setUserSignature(test["value"]("gender").c_str());

    return result;
}

int User::get_rooms_information() {
    char data[MAX];
    neb::CJsonObject jsonObject;
    jsonObject.Add("methodName","getRooms");
    jsonObject.Add("className","BaseService");
    jsonObject.AddEmptySubArray("argCls");
    jsonObject.AddEmptySubArray("args");
    std::cerr << jsonObject.ToString() << std::endl;
    std::cerr << "json & " << jsonObject.ToString().size() << std::endl;
    sprintf(data,"%s",jsonObject.ToString().c_str());
    char* requestAndResponse = data;

    #if (NETCONN == 0)
    UdpTemplate::ping(requestAndResponse);
    UdpTemplate::pong(requestAndResponse);
    #elif (NETCONN == 1)
    TcpTemplate::ping(requestAndResponse);
    TcpTemplate::pong(requestAndResponse);
    #endif

    int result;
    std::cerr << requestAndResponse << std::endl;
    neb::CJsonObject test(requestAndResponse);
    test.Get("result",result);

    for(int i = 0;i < atoi(test["value"]("size").c_str()) && i < 9;i++) {
        Data::setRoomMultiple(i,atoi(test["value"]["value"][i]("roomID").c_str()),test["value"]["value"][i]("roomName").c_str());
    }

    return result;
}

int User::find_room_information(const QString& room) {
    char data[MAX];
    neb::CJsonObject jsonObject;
    jsonObject.Add("methodName","findRoom");
    jsonObject.Add("className","BaseService");
    jsonObject.AddEmptySubArray("argCls");
    jsonObject["argCls"].Add("java.lang.String");
    jsonObject.AddEmptySubArray("args");
    jsonObject["args"].Add(room.toStdString());
    std::cerr << jsonObject.ToString() << std::endl;
    std::cerr << "json & " << jsonObject.ToString().size() << std::endl;
    sprintf(data,"%s",jsonObject.ToString().c_str());
    char* requestAndResponse = data;

    #if (NETCONN == 0)
    UdpTemplate::ping(requestAndResponse);
    UdpTemplate::pong(requestAndResponse);
    #elif (NETCONN == 1)
    TcpTemplate::ping(requestAndResponse);
    TcpTemplate::pong(requestAndResponse);
    #endif

    std::string result;
    std::cerr << requestAndResponse << std::endl;
    neb::CJsonObject test(requestAndResponse);
    test.Get("result",result);
    return atoi(result.c_str());
}

int User::enter_room(const QString& room) {
    char data[MAX];
    neb::CJsonObject jsonObject;
    jsonObject.Add("methodName","joinRoom");
    jsonObject.Add("className","BaseService");
    jsonObject.AddEmptySubArray("argCls");
    jsonObject["argCls"].Add("java.lang.String");
    jsonObject["argCls"].Add("java.lang.String");
    jsonObject.AddEmptySubArray("args");
    jsonObject["args"].Add(room.toStdString());
    jsonObject["args"].Add(room.toStdString());
    std::cerr << jsonObject.ToString() << std::endl;
    std::cerr << "json & " << jsonObject.ToString().size() << std::endl;
    sprintf(data,"%s",jsonObject.ToString().c_str());
    char* requestAndResponse = data;

    #if (NETCONN == 0)
    UdpTemplate::ping(requestAndResponse);
    UdpTemplate::pong(requestAndResponse);
    #elif (NETCONN == 1)
    TcpTemplate::ping(requestAndResponse);
    TcpTemplate::pong(requestAndResponse);
    #endif

    std::string result;
    std::cerr << requestAndResponse << std::endl;
    neb::CJsonObject test(requestAndResponse);
    test.Get("result",result);
    return atoi(result.c_str());
}

int User::enter_channel() {
    char data[MAX];
    neb::CJsonObject jsonObject;
    jsonObject.Add("methodName","strategyRoutines");
    jsonObject.Add("className","GameService");
    jsonObject.Add("reqId","room808:1");
    jsonObject.AddEmptySubArray("argCls");
    jsonObject.AddEmptySubArray("args");
    std::cerr << jsonObject.ToString() << std::endl;
    std::cerr << "json & " << jsonObject.ToString().size() << std::endl;
    sprintf(data,"%s",jsonObject.ToString().c_str());
    char* requestAndResponse = data;

#if (NETCONN == 0)
    UdpTemplate::ping(requestAndResponse);
    UdpTemplate::pong(requestAndResponse);
#elif (NETCONN == 1)
    TcpTemplate::ping(requestAndResponse);
    TcpTemplate::pong(requestAndResponse);
#endif

    int result;
    std::cerr << requestAndResponse << std::endl;
    neb::CJsonObject test(requestAndResponse);
    test.Get("result",result);

    return result;
}
