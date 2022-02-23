//
// Created by kuukie on 2021/10/23.
//

#include "Ready.h"

Ready::Ready() {
    setUI();
    setQSS();
    setSignal();
}

Ready::~Ready() {
    delete readyOrStart;
    delete visitorName;
    delete ownerName;
    delete pushButton;
    delete leaveRoom;
    delete visitorFrame;
    delete tableFrame;
    delete ownerFrame;
}

void Ready::setShow(QWidget *widget) {
    ownerFrame->setParent(widget);
    tableFrame->setParent(widget);
    visitorFrame->setParent(widget);
    leaveRoom->setParent(widget);
    pushButton->setParent(widget);
    ownerName->setParent(widget);
    visitorName->setParent(widget);
    readyOrStart->setParent(widget);
}

void Ready::setUI() {
    ownerFrame = new QFrame();
    ownerFrame->setGeometry(40,100,160,170);
    ownerFrame->setFrameShape(QFrame::NoFrame);
    ownerFrame->setFrameShadow(QFrame::Raised);

    tableFrame = new QFrame();
    tableFrame->setGeometry(250,100,160,170);
    tableFrame->setFrameShape(QFrame::NoFrame);
    tableFrame->setFrameShadow(QFrame::Raised);

    visitorFrame = new QFrame();
    visitorFrame->setGeometry(470,100,160,170);
    visitorFrame->setFrameShape(QFrame::NoFrame);
    visitorFrame->setFrameShadow(QFrame::Raised);

    leaveRoom = new QPushButton();
    leaveRoom->setGeometry(10,20,170,50);
    leaveRoom->setText("离开房间");

    pushButton = new QPushButton();
    pushButton->setGeometry(530,350,140,60);
    pushButton->setText("准备开始");

    ownerName = new QLabel();
    ownerName->setGeometry(60,290,70,20);
    ownerName->setText("owner");

    visitorName = new QLabel();
    visitorName->setGeometry(520,290,70,20);
    visitorName->setText("visitor");

    readyOrStart = new QFrame();
    readyOrStart->setGeometry(560,190,100,100);
    readyOrStart->setFrameShape(QFrame::NoFrame);
    readyOrStart->setFrameShadow(QFrame::Raised);
}

void Ready::setQSS() {

}

void Ready::setSignal() {
    connect(pushButton,SIGNAL(clicked()),this,SLOT(pushButtonClick()));
    connect(leaveRoom,SIGNAL(clicked()),this,SIGNAL(backExit()));
}

void Ready::pushButtonClick() {
    Channel::login(this);
    UdpServer::request(User::ready_room_json("1001"));
    loading();
}

void Ready::loadingEnd() {
    std::string string = Channel::get(this);
    if(User::ready_room_json_ret(string) == 0) {
        neb::CJsonObject jsonObject(string);
        //解析业务

        start("ajax");
    } else {

    }
}
