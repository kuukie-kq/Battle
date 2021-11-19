//
// Created by kuukie on 2021/10/20.
//

#include "Hall.h"

Hall::Hall() {
    setUI();
    setQSS();
    setSignal();
}

Hall::~Hall() {
    delete roomNine;
    delete roomEight;
    delete roomSeven;
    delete roomSix;
    delete roomFive;
    delete roomFour;
    delete roomThree;
    delete roomTwo;
    delete roomOne;
    delete gridLayout;
    delete push;
    delete select;
    delete inputEdit;
    delete chat;
    delete onLines;
    delete pushButtonOne;
    delete pushButtonTwo;
    delete horizontalLayoutWidget;
}

void Hall::setShow(QWidget* widget) {
    horizontalLayoutWidget->setParent(widget);
    pushButtonOne->setParent(widget);
    roomEdit->setParent(widget);
    pushButtonTwo->setParent(widget);
    onLines->setParent(widget);
    chat->setParent(widget);
    inputEdit->setParent(widget);
    select->setParent(widget);
    push->setParent(widget);
}

void Hall::setUI() {
    horizontalLayoutWidget = new QWidget();
    horizontalLayoutWidget->setGeometry(50,100,750,500);

    pushButtonOne = new QPushButton();
    pushButtonOne->setGeometry(50,50,80,30);
    pushButtonOne->setText("新建房间");

    roomEdit = new QLineEdit();
    roomEdit->setGeometry(400,50,100,30);

    pushButtonTwo = new QPushButton();
    pushButtonTwo->setGeometry(300,50,80,30);
    pushButtonTwo->setText("查找房间");

    onLines = new QListView();
    onLines->setGeometry(850,50,400,400);

    chat = new QTextEdit();
    chat->setGeometry(850, 500, 400, 180);
    chat->setEnabled(false);

    inputEdit = new QLineEdit();
    inputEdit->setGeometry(940,700,250,30);

    select = new QComboBox();
    select->setGeometry(850,700,80,30);
    select->addItem("当前");
    select->addItem("公屏");
    select->addItem("小队");
    select->addItem("协会");

    push = new QPushButton();
    push->setGeometry(1200,700,50,30);
    push->setText("Enter");

    gridLayout = new QGridLayout();
    gridLayout->setContentsMargins(10,10,10,10);

    roomOne = new QFrame();
    roomOne->setFrameShape(QFrame::StyledPanel);
    roomOne->setFrameShadow(QFrame::Raised);
    gridLayout->addWidget(roomOne,0,0);

    roomTwo = new QFrame();
    roomTwo->setFrameShape(QFrame::StyledPanel);
    roomTwo->setFrameShadow(QFrame::Raised);
    gridLayout->addWidget(roomTwo,0,1);

    roomThree = new QFrame();
    roomThree->setFrameShape(QFrame::StyledPanel);
    roomThree->setFrameShadow(QFrame::Raised);
    gridLayout->addWidget(roomThree,0,2);

    roomFour = new QFrame();
    roomFour->setFrameShape(QFrame::StyledPanel);
    roomFour->setFrameShadow(QFrame::Raised);
    gridLayout->addWidget(roomFour,1,0);

    roomFive = new QFrame();
    roomFive->setFrameShape(QFrame::StyledPanel);
    roomFive->setFrameShadow(QFrame::Raised);
    gridLayout->addWidget(roomFive,1,1);

    roomSix = new QFrame();
    roomSix->setFrameShape(QFrame::StyledPanel);
    roomSix->setFrameShadow(QFrame::Raised);
    gridLayout->addWidget(roomSix,1,2);

    roomSeven = new QFrame();
    roomSeven->setFrameShape(QFrame::StyledPanel);
    roomSeven->setFrameShadow(QFrame::Raised);
    gridLayout->addWidget(roomSix,2,0);

    roomEight = new QFrame();
    roomEight->setFrameShape(QFrame::StyledPanel);
    roomEight->setFrameShadow(QFrame::Raised);
    gridLayout->addWidget(roomSix,2,1);

    roomNine = new QFrame();
    roomNine->setFrameShape(QFrame::StyledPanel);
    roomNine->setFrameShadow(QFrame::Raised);
    gridLayout->addWidget(roomSix,2,2);

    horizontalLayoutWidget->setLayout(gridLayout);
}

void Hall::setQSS() {

}

void Hall::setSignal() {
    connect(push,SIGNAL(clicked()),this,SLOT(entrancePush()));
}

void Hall::entrancePush() {
    entrance("进入房间");
}
