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
    delete push;
    delete select;
    delete inputEdit;
    delete chat;
    delete onLines;
    delete pushButtonOne;
    delete pushButtonTwo;
    delete pushButtonThree;
    delete list;
    delete horizontalLayoutWidget;
}

void Hall::setShow(QWidget* widget) {
    horizontalLayoutWidget->setParent(widget);
    onLines->setParent(widget);
    chat->setParent(widget);
    inputEdit->setParent(widget);
    select->setParent(widget);
    push->setParent(widget);
    roomOne->setParent(widget);
    roomTwo->setParent(widget);
    roomThree->setParent(widget);
    roomFour->setParent(widget);
    roomFive->setParent(widget);
    roomSix->setParent(widget);
    roomSeven->setParent(widget);
    roomEight->setParent(widget);
    roomNine->setParent(widget);
}

void Hall::setUI() {
    horizontalLayoutWidget = new QWidget();
    horizontalLayoutWidget->setGeometry(40,20,800,100);
    list = new QHBoxLayout();
    pushButtonThree = new QPushButton();
    pushButtonThree->setText("新建房间");
    pushButtonTwo = new QPushButton();
    pushButtonTwo->setText("刷新");
    pushButtonOne = new QPushButton();
    pushButtonOne->setText("查找房间");
    list->addWidget(pushButtonThree);
    list->addWidget(pushButtonOne);
    list->addWidget(pushButtonTwo);
    horizontalLayoutWidget->setLayout(list);

    onLines = new QListView();
    onLines->setGeometry(850,50,400,400);

    chat = new QTextEdit();
    chat->setGeometry(850, 500, 400, 180);
    chat->setEnabled(false);

    inputEdit = new QLineEdit();
    inputEdit->setGeometry(895,700,300,30);

    select = new QPushButton();
    select->setGeometry(850,700,40,30);
    select->setText("选择");

    push = new QPushButton();
    push->setGeometry(1200,700,50,30);
    push->setText("Enter");

    roomOne = new QFrame();
    roomOne->setGeometry(40,120,120,100);
    roomOne->setFrameShape(QFrame::StyledPanel);
    roomOne->setFrameShadow(QFrame::Raised);

    roomTwo = new QFrame();
    roomTwo->setGeometry(170,120,120,100);
    roomTwo->setFrameShape(QFrame::StyledPanel);
    roomTwo->setFrameShadow(QFrame::Raised);

    roomThree = new QFrame();
    roomThree->setGeometry(300,120,120,100);
    roomThree->setFrameShape(QFrame::StyledPanel);
    roomThree->setFrameShadow(QFrame::Raised);

    roomFour = new QFrame();
    roomFour->setGeometry(40,240,120,100);
    roomFour->setFrameShape(QFrame::StyledPanel);
    roomFour->setFrameShadow(QFrame::Raised);

    roomFive = new QFrame();
    roomFive->setGeometry(170,240,120,100);
    roomFive->setFrameShape(QFrame::StyledPanel);
    roomFive->setFrameShadow(QFrame::Raised);

    roomSix = new QFrame();
    roomSix->setGeometry(300,240,120,100);
    roomSix->setFrameShape(QFrame::StyledPanel);
    roomSix->setFrameShadow(QFrame::Raised);

    roomSeven = new QFrame();
    roomSeven->setGeometry(40,350,120,100);
    roomSeven->setFrameShape(QFrame::StyledPanel);
    roomSeven->setFrameShadow(QFrame::Raised);

    roomEight = new QFrame();
    roomEight->setGeometry(170,350,120,100);
    roomEight->setFrameShape(QFrame::StyledPanel);
    roomEight->setFrameShadow(QFrame::Raised);

    roomNine = new QFrame();
    roomNine->setGeometry(170,350,120,100);
    roomNine->setFrameShape(QFrame::StyledPanel);
    roomNine->setFrameShadow(QFrame::Raised);
}

void Hall::setQSS() {

}

void Hall::setSignal() {
    connect(push,SIGNAL(clicked()),this,SLOT(entrancePush()));
}

void Hall::entrancePush() {
    entrance("进入房间");
}
