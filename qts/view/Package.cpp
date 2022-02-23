//
// Created by kuukie on 2021/10/23.
//

#include "Package.h"

Package::Package() {
    setUI();
    setQSS();
    setSignal();
}

Package::~Package() {
    delete pushButton;
    delete frameFifteen;
    delete frameFourteen;
    delete frameThirteen;
    delete frameTwelve;
    delete frameEleven;
    delete frameTen;
    delete frameNine;
    delete frameEight;
    delete frameSeven;
    delete frameSix;
    delete frameFive;
    delete frameFour;
    delete frameThree;
    delete frameTwo;
    delete frameOne;
}

void Package::setShow(QWidget *widget) {
    frameOne->setParent(widget);
    frameTwo->setParent(widget);
    frameThree->setParent(widget);
    frameFour->setParent(widget);
    frameFive->setParent(widget);
    frameSix->setParent(widget);
    frameSeven->setParent(widget);
    frameEight->setParent(widget);
    frameNine->setParent(widget);
    frameTen->setParent(widget);
    frameEleven->setParent(widget);
    frameTwelve->setParent(widget);
    frameThirteen->setParent(widget);
    frameFourteen->setParent(widget);
    frameFifteen->setParent(widget);
}

void Package::setUI() {
    frameOne = new QFrame();
    frameOne->setGeometry(500,20,250,500);
    frameOne->setFrameShape(QFrame::Box);
    frameOne->setFrameShadow(QFrame::Sunken);

    frameTwo = new QFrame();
    frameTwo->setGeometry(550,90,80,80);
    frameTwo->setStyleSheet("background-color: rgb(252, 175, 62);");
    frameTwo->setFrameShape(QFrame::StyledPanel);
    frameTwo->setFrameShadow(QFrame::Raised);

    frameThree = new QFrame();
    frameThree->setGeometry(650,90,80,80);
    frameThree->setFrameShape(QFrame::StyledPanel);
    frameThree->setFrameShadow(QFrame::Raised);

    frameFour = new QFrame();
    frameFour->setGeometry(550,200,80,80);
    frameFour->setFrameShape(QFrame::StyledPanel);
    frameFour->setFrameShadow(QFrame::Raised);

    frameFive = new QFrame();
    frameFive->setGeometry(650,200,80,80);
    frameFive->setFrameShape(QFrame::StyledPanel);
    frameFive->setFrameShadow(QFrame::Raised);

    frameSix = new QFrame();
    frameSix->setGeometry(550,300,80,80);
    frameSix->setFrameShape(QFrame::StyledPanel);
    frameSix->setFrameShadow(QFrame::Raised);

    frameSeven = new QFrame();
    frameSeven->setGeometry(650,300,80,80);
    frameSeven->setFrameShape(QFrame::StyledPanel);
    frameSeven->setFrameShadow(QFrame::Raised);

    frameEight = new QFrame();
    frameEight->setGeometry(550,400,80,80);
    frameEight->setFrameShape(QFrame::StyledPanel);
    frameEight->setFrameShadow(QFrame::Raised);

    frameNine = new QFrame();
    frameNine->setGeometry(650,400,80,80);
    frameNine->setFrameShape(QFrame::StyledPanel);
    frameNine->setFrameShadow(QFrame::Raised);

    frameTen = new QFrame();
    frameTen->setGeometry(100,260,280,60);
    frameTen->setFrameShape(QFrame::StyledPanel);
    frameTen->setFrameShadow(QFrame::Raised);

    frameEleven = new QFrame();
    frameEleven->setGeometry(180,250,60,40);
    frameEleven->setFrameShape(QFrame::StyledPanel);
    frameEleven->setFrameShadow(QFrame::Raised);

    frameTwelve = new QFrame();
    frameTwelve->setGeometry(140,230,190,70);
    frameTwelve->setFrameShape(QFrame::StyledPanel);
    frameTwelve->setFrameShadow(QFrame::Raised);

    frameThirteen = new QFrame();
    frameThirteen->setGeometry(100,260,280,60);
    frameThirteen->setFrameShape(QFrame::StyledPanel);
    frameThirteen->setFrameShadow(QFrame::Raised);

    frameFourteen = new QFrame();
    frameFourteen->setGeometry(160,200,140,50);
    frameFourteen->setFrameShape(QFrame::StyledPanel);
    frameFourteen->setFrameShadow(QFrame::Raised);

    frameFifteen = new QFrame();
    frameFifteen->setGeometry(20,20,480,500);
    frameFifteen->setFrameShape(QFrame::StyledPanel);
    frameFifteen->setFrameShadow(QFrame::Raised);

    pushButton = new QPushButton();
    pushButton->setEnabled(true);
    pushButton->setGeometry(320,410,120,60);
    pushButton->setText("完成组装");
    pushButton->setParent(frameFifteen);
}

void Package::setQSS() {

}

void Package::setSignal() {
    connect(pushButton,SIGNAL(clicked()),this,SLOT(pushButtonSuccess()));
}

void Package::pushButtonSuccess() {
    Channel::login(this);
    UdpServer::request(User::package_tank_json("",""));
    loading();
}

void Package::loadingEnd() {
    std::string string = Channel::get(this);
    if(User::package_tank_json_ret(string) == 0) {
        neb::CJsonObject jsonObject(string);
        //解析业务

        success("ajax");
    } else {

    }
}
