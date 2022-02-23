//
// Created by kuukie on 2021/12/1.
//

#include "User.h"

//字符串分割函数
std::vector<std::string> split(std::string str,std::string pattern) {
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

//int User::login(const QString& username,const QString& password) {
//    char data[MAX];
//    neb::CJsonObject jsonObject;
//    jsonObject.Add("methodName","login");
//    jsonObject.Add("className","BaseService");
//    jsonObject.AddEmptySubArray("argCls");
//    jsonObject["argCls"].Add("java.lang.String");
//    jsonObject["argCls"].Add("java.lang.String");
//    jsonObject.AddEmptySubArray("args");
//    jsonObject["args"].Add(username.toStdString());
//    jsonObject["args"].Add(password.toStdString());
//    std::cerr << jsonObject.ToString() << std::endl;
//    std::cerr << "json & " << jsonObject.ToString().size() << std::endl;
//    sprintf(data,"%s",jsonObject.ToString().c_str());
//    char* requestAndResponse = data;
//
//    #if (NETCONN == 0)
//    UdpTemplate::ping(requestAndResponse);
//    UdpTemplate::pong(requestAndResponse);
//    #elif (NETCONN == 1)
//    TcpTemplate::ping(requestAndResponse);
//    TcpTemplate::pong(requestAndResponse);
//    #endif
//
//    int result;
//    std::cerr << requestAndResponse << std::endl;
//    neb::CJsonObject test(requestAndResponse);
//    test.Get("result",result);
//
//    Data::setUserId(atoi(test["value"]("id").c_str()));
//    Data::setUserName(test["value"]("username").c_str());
//    Data::setUserSignature(test["value"]("gender").c_str());
//
//    return result;
//}
//
//int User::get_rooms_information() {
//    char data[MAX];
//    neb::CJsonObject jsonObject;
//    jsonObject.Add("methodName","getRooms");
//    jsonObject.Add("className","BaseService");
//    jsonObject.AddEmptySubArray("argCls");
//    jsonObject.AddEmptySubArray("args");
//    std::cerr << jsonObject.ToString() << std::endl;
//    std::cerr << "json & " << jsonObject.ToString().size() << std::endl;
//    sprintf(data,"%s",jsonObject.ToString().c_str());
//    char* requestAndResponse = data;
//
//    #if (NETCONN == 0)
//    UdpTemplate::ping(requestAndResponse);
//    UdpTemplate::pong(requestAndResponse);
//    #elif (NETCONN == 1)
//    TcpTemplate::ping(requestAndResponse);
//    TcpTemplate::pong(requestAndResponse);
//    #endif
//
//    int result;
//    std::cerr << requestAndResponse << std::endl;
//    neb::CJsonObject test(requestAndResponse);
//    test.Get("result",result);
//
//    for(int i = 0;i < atoi(test["value"]("size").c_str()) && i < 9;i++) {
//        Data::setRoomMultiple(i,atoi(test["value"]["value"][i]("roomID").c_str()),test["value"]["value"][i]("roomName").c_str());
//    }
//
//    return result;
//}
//
//int User::find_room_information(const QString& room) {
//    char data[MAX];
//    neb::CJsonObject jsonObject;
//    jsonObject.Add("methodName","findRoom");
//    jsonObject.Add("className","BaseService");
//    jsonObject.AddEmptySubArray("argCls");
//    jsonObject["argCls"].Add("java.lang.String");
//    jsonObject.AddEmptySubArray("args");
//    jsonObject["args"].Add(room.toStdString());
//    std::cerr << jsonObject.ToString() << std::endl;
//    std::cerr << "json & " << jsonObject.ToString().size() << std::endl;
//    sprintf(data,"%s",jsonObject.ToString().c_str());
//    char* requestAndResponse = data;
//
//    #if (NETCONN == 0)
//    UdpTemplate::ping(requestAndResponse);
//    UdpTemplate::pong(requestAndResponse);
//    #elif (NETCONN == 1)
//    TcpTemplate::ping(requestAndResponse);
//    TcpTemplate::pong(requestAndResponse);
//    #endif
//
//    std::string result;
//    std::cerr << requestAndResponse << std::endl;
//    neb::CJsonObject test(requestAndResponse);
//    test.Get("result",result);
//    return atoi(result.c_str());
//}
//
//int User::enter_room(const QString& room) {
//    char data[MAX];
//    neb::CJsonObject jsonObject;
//    jsonObject.Add("methodName","joinRoom");
//    jsonObject.Add("className","BaseService");
//    jsonObject.AddEmptySubArray("argCls");
//    jsonObject["argCls"].Add("java.lang.String");
//    jsonObject["argCls"].Add("java.lang.String");
//    jsonObject.AddEmptySubArray("args");
//    jsonObject["args"].Add(room.toStdString());
//    jsonObject["args"].Add(room.toStdString());
//    std::cerr << jsonObject.ToString() << std::endl;
//    std::cerr << "json & " << jsonObject.ToString().size() << std::endl;
//    sprintf(data,"%s",jsonObject.ToString().c_str());
//    char* requestAndResponse = data;
//
//    #if (NETCONN == 0)
//    UdpTemplate::ping(requestAndResponse);
//    UdpTemplate::pong(requestAndResponse);
//    #elif (NETCONN == 1)
//    TcpTemplate::ping(requestAndResponse);
//    TcpTemplate::pong(requestAndResponse);
//    #endif
//
//    std::string result;
//    std::cerr << requestAndResponse << std::endl;
//    neb::CJsonObject test(requestAndResponse);
//    test.Get("result",result);
//    return atoi(result.c_str());
//}
//
//int User::enter_channel() {
//    char data[MAX];
//    neb::CJsonObject jsonObject;
//    jsonObject.Add("methodName","strategyRoutines");
//    jsonObject.Add("className","GameService");
//    jsonObject.Add("reqId","room808:1");
//    jsonObject.AddEmptySubArray("argCls");
//    jsonObject.AddEmptySubArray("args");
//    std::cerr << jsonObject.ToString() << std::endl;
//    std::cerr << "json & " << jsonObject.ToString().size() << std::endl;
//    sprintf(data,"%s",jsonObject.ToString().c_str());
//    char* requestAndResponse = data;
//
//#if (NETCONN == 0)
//    UdpTemplate::ping(requestAndResponse);
//    UdpTemplate::pong(requestAndResponse);
//#elif (NETCONN == 1)
//    TcpTemplate::ping(requestAndResponse);
//    TcpTemplate::pong(requestAndResponse);
//#endif
//
//    int result;
//    std::cerr << requestAndResponse << std::endl;
//    neb::CJsonObject test(requestAndResponse);
//    test.Get("result",result);
//
//    return result;
//}

std::string User::hand_shake_json() {
    neb::CJsonObject jsonObject;
    jsonObject.Add("number",Random::randInt());
    jsonObject.Add("message","test");
    std::cerr << "json & " << jsonObject.ToString().size() << jsonObject.ToString() << std::endl;
    return jsonObject.ToString();
}

int User::hand_shake_json_ret(const std::string& response) {
    neb::CJsonObject jsonObject(response);
    std::string message;
    jsonObject.Get("shake",message);
    std::vector<std::string> messages = split(message,":");
    if (messages.size() == 3) {
        Channel::hand_shake(atoi(messages[0].c_str()),messages[1],atoi(messages[2].c_str()));
        std::cerr << response << "\treturn:" << messages[0] << std::endl;
        return 0;
    } else {
        std::cerr << "hand shake error, please restart project!" << std::endl;
        return -1;
    }
}

std::string User::shake_hand_json() {
    neb::CJsonObject jsonObject;
    jsonObject.Add("reqID",Channel::get_number());
    jsonObject.Add("message","Hello");
    jsonObject.Add("version","0.1.0");
    jsonObject.AddEmptySubObject("host");
    jsonObject["host"].Add("c","192.168.253.136");
    jsonObject["host"].Add("s",Channel::get_host());
    jsonObject.AddEmptySubObject("port");
    jsonObject["port"].Add("c",65535);
    jsonObject["port"].Add("s",Channel::get_port());
    std::cerr << "json & " << jsonObject.ToString().size()  << jsonObject.ToString() << std::endl;
    return jsonObject.ToString();
}

bool User::response_event(const std::string& response) {
    neb::CJsonObject jsonObject(response);
    return !(jsonObject("result").empty() && jsonObject("flag").empty());
}

std::string User::login_json(const std::string& username,const std::string& password) {
    neb::CJsonObject jsonObject;
    jsonObject.Add("reqID",Channel::get_number());
    jsonObject.Add("methodName","login");
    jsonObject.Add("className","BaseService");
    jsonObject.AddEmptySubArray("argCls");
    jsonObject["argCls"].Add("java.lang.String");
    jsonObject["argCls"].Add("java.lang.String");
    jsonObject.AddEmptySubArray("args");
    jsonObject["args"].Add(username);
    jsonObject["args"].Add(password);
    std::cerr << "json & " << jsonObject.ToString().size()  << jsonObject.ToString() << std::endl;
    return jsonObject.ToString();
}

int User::login_json_ret(const std::string& response) {
    neb::CJsonObject jsonObject(response);
    int result;
    jsonObject.Get("result",result);
    if (jsonObject("flag") == "login") {
        std::cerr << response << "\t" << jsonObject("flag") << " return:" << result << std::endl;
        return result;
    } else {
        std::cerr << response << "\t" << jsonObject("flag") << " return:" << result << " flag error" << std::endl;
        return -1;
    }
}

std::string User::rooms_json() {
    neb::CJsonObject jsonObject;
    jsonObject.Add("reqID",Channel::get_number());
    jsonObject.Add("methodName","getRooms");
    jsonObject.Add("className","BaseService");
    jsonObject.AddEmptySubArray("argCls");
    jsonObject.AddEmptySubArray("args");
    std::cerr << "json & " << jsonObject.ToString().size()  << jsonObject.ToString() << std::endl;
    return jsonObject.ToString();
}

int User::rooms_json_ret(const std::string& response) {
    neb::CJsonObject jsonObject(response);
    int result;
    jsonObject.Get("result",result);
    if (jsonObject("flag") == "rooms") {
        std::cerr << response << "\t" << jsonObject("flag") << " return:" << result << std::endl;
        return result;
    } else {
        std::cerr << response << "\t" << jsonObject("flag") << " return:" << result << " flag error" << std::endl;
        return -1;
    }
}

std::string User::join_room_json(const std::string& room,const std::string& user) {
    neb::CJsonObject jsonObject;
    jsonObject.Add("reqID",Channel::get_number());
    jsonObject.Add("methodName","joinRoom");
    jsonObject.Add("className","GameService");
    jsonObject.AddEmptySubArray("argCls");
    jsonObject["argCls"].Add("java.lang.String");
    jsonObject["argCls"].Add("java.lang.String");
    jsonObject.AddEmptySubArray("args");
    jsonObject["args"].Add(room);
    jsonObject["args"].Add(user);
    std::cerr << "json & " << jsonObject.ToString().size()  << jsonObject.ToString() << std::endl;
    return jsonObject.ToString();
}

int User::join_room_json_ret(const std::string& response) {
    neb::CJsonObject jsonObject(response);
    int result;
    jsonObject.Get("result",result);
    if (jsonObject("flag") == "join") {
        std::cerr << response << "\t" << jsonObject("flag") << " return:" << result << std::endl;
        return result;
    } else {
        std::cerr << response << "\t" << jsonObject("flag") << " return:" << result << " flag error" << std::endl;
        return -1;
    }
}

std::string User::ready_room_json(const std::string& room) {
    neb::CJsonObject jsonObject;
    jsonObject.Add("reqID",Channel::get_number());
    jsonObject.Add("methodName","readyGame");
    jsonObject.Add("className","GameService");
    jsonObject.AddEmptySubArray("argCls");
    jsonObject["argCls"].Add("java.lang.String");
    jsonObject.AddEmptySubArray("args");
    jsonObject["args"].Add(room);
    std::cerr << "json & " << jsonObject.ToString().size()  << jsonObject.ToString() << std::endl;
    return jsonObject.ToString();
}

int User::ready_room_json_ret (const std::string& response) {
    neb::CJsonObject jsonObject(response);
    int result;
    jsonObject.Get("result",result);
    if (jsonObject("flag") == "play") {
        std::cerr << response << "\t" << jsonObject("flag") << " return:" << result << std::endl;
        return result;
    } else {
        std::cerr << response << "\t" << jsonObject("flag") << " return:" << result << " flag error" << std::endl;
        return -1;
    }
}

std::string User::package_tank_json(const std::string& room, const std::string& user) {
    neb::CJsonObject jsonObject;
    jsonObject.Add("reqID",Channel::get_number());
    jsonObject.Add("methodName","packageTank");
    jsonObject.Add("className","GameService");
    jsonObject.AddEmptySubArray("argCls");
    jsonObject["argCls"].Add("java.lang.String");
    jsonObject["argCls"].Add("java.lang.String");
    jsonObject.AddEmptySubArray("args");
    jsonObject["args"].Add(room);
    jsonObject["args"].Add(user);
    std::cerr << "json & " << jsonObject.ToString().size()  << jsonObject.ToString() << std::endl;
    return jsonObject.ToString();
}

int User::package_tank_json_ret (const std::string& response) {
    neb::CJsonObject jsonObject(response);
    int result;
    jsonObject.Get("result",result);
    if (jsonObject("flag") == "tank") {
        std::cerr << response << "\t" << jsonObject("flag") << " return:" << result << std::endl;
        return result;
    } else {
        std::cerr << response << "\t" << jsonObject("flag") << " return:" << result << " flag error" << std::endl;
        return -1;
    }
}

std::string User::create_tank_json(const std::string& room, const std::string& user, const std::string& code) {
    neb::CJsonObject jsonObject;
    jsonObject.Add("reqID",Channel::get_number());
    jsonObject.Add("methodName","createTank");
    jsonObject.Add("className","GameService");
    jsonObject.AddEmptySubArray("argCls");
    jsonObject["argCls"].Add("java.lang.String");
    jsonObject["argCls"].Add("java.lang.String");
    jsonObject["argCls"].Add("java.lang.String");
    jsonObject.AddEmptySubArray("args");
    jsonObject["args"].Add(room);
    jsonObject["args"].Add(user);
    jsonObject["args"].Add(code);
    std::cerr << "json & " << jsonObject.ToString().size()  << jsonObject.ToString() << std::endl;
    return jsonObject.ToString();
}

int User::create_tank_json_ret (const std::string& response) {
    neb::CJsonObject jsonObject(response);
    int result;
    jsonObject.Get("result",result);
    if (jsonObject("flag") == "tanks") {
        std::cerr << response << "\t" << jsonObject("flag") << " return:" << result << std::endl;
        return result;
    } else {
        std::cerr << response << "\t" << jsonObject("flag") << " return:" << result << " flag error" << std::endl;
        return -1;
    }
}
