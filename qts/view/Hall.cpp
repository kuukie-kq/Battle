//
// Created by kuukie on 2021/10/20.
//

#include "Hall.h"

Hall::Hall() {
    // rpc
    //User::get_rooms_information();

    setUI();
    setQSS();
    setSignal();
}

Hall::~Hall() {
    delete roomNineEnter;
    delete roomNineName;
    delete roomNineId;
    delete roomNineLayout;
    delete roomEightEnter;
    delete roomEightName;
    delete roomEightId;
    delete roomEightLayout;
    delete roomSevenEnter;
    delete roomSevenName;
    delete roomSevenId;
    delete roomSevenLayout;
    delete roomSixEnter;
    delete roomSixName;
    delete roomSixId;
    delete roomSixLayout;
    delete roomFiveEnter;
    delete roomFiveName;
    delete roomFiveId;
    delete roomFiveLayout;
    delete roomFourEnter;
    delete roomFourName;
    delete roomFourId;
    delete roomFourLayout;
    delete roomThreeEnter;
    delete roomThreeName;
    delete roomThreeId;
    delete roomThreeLayout;
    delete roomTwoEnter;
    delete roomTwoName;
    delete roomTwoId;
    delete roomTwoLayout;
    delete roomOneEnter;
    delete roomOneName;
    delete roomOneId;
    delete roomOneLayout;
    delete listLayout;
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
    back->setParent(widget);
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

    back = new QPushButton();
    back->setGeometry(50,50,80,30);
    back->setText("返回");

    pushButtonOne = new QPushButton();
    pushButtonOne->setGeometry(300,50,80,30);
    pushButtonOne->setText("新建房间");

    roomEdit = new QLineEdit();
    roomEdit->setGeometry(400,50,100,30);

    pushButtonTwo = new QPushButton();
    pushButtonTwo->setGeometry(550,50,80,30);
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

    listLayout = new QVBoxLayout();
    listLayout->setContentsMargins(10,10,10,10);

    roomOneLayout = new QHBoxLayout();
    roomOneEnter = new QPushButton();
    roomOneId = new QTextEdit(std::to_string(Data::getRoomIdMultiple(0)).c_str());
    roomOneId->setEnabled(false);
    roomOneName = new QTextEdit(Data::getRoomNameMultiple(0));
    roomOneName->setEnabled(false);
    roomOneLayout->addWidget(roomOneId,0);
    roomOneLayout->addWidget(roomOneName,1);
    roomOneLayout->addWidget(roomOneEnter);

    listLayout->addLayout(roomOneLayout);

    roomTwoLayout = new QHBoxLayout();
    roomTwoEnter = new QPushButton();
    roomTwoId = new QTextEdit(std::to_string(Data::getRoomIdMultiple(1)).c_str());
    roomTwoId->setEnabled(false);
    roomTwoName = new QTextEdit(Data::getRoomNameMultiple(1));
    roomTwoName->setEnabled(false);
    roomTwoLayout->addWidget(roomTwoId,0);
    roomTwoLayout->addWidget(roomTwoName,1);
    roomTwoLayout->addWidget(roomTwoEnter);

    listLayout->addLayout(roomTwoLayout);

    roomThreeLayout = new QHBoxLayout();
    roomThreeEnter = new QPushButton();
    roomThreeId = new QTextEdit(std::to_string(Data::getRoomIdMultiple(2)).c_str());
    roomThreeId->setEnabled(false);
    roomThreeName = new QTextEdit(Data::getRoomNameMultiple(2));
    roomThreeName->setEnabled(false);
    roomThreeLayout->addWidget(roomThreeId,0);
    roomThreeLayout->addWidget(roomThreeName,1);
    roomThreeLayout->addWidget(roomThreeEnter);

    listLayout->addLayout(roomThreeLayout);

    roomFourLayout = new QHBoxLayout();
    roomFourEnter = new QPushButton();
    roomFourId = new QTextEdit(std::to_string(Data::getRoomIdMultiple(3)).c_str());
    roomFourId->setEnabled(false);
    roomFourName = new QTextEdit(Data::getRoomNameMultiple(3));
    roomFourName->setEnabled(false);
    roomFourLayout->addWidget(roomFourId,0);
    roomFourLayout->addWidget(roomFourName,1);
    roomFourLayout->addWidget(roomFourEnter);

    listLayout->addLayout(roomFourLayout);

    roomFiveLayout = new QHBoxLayout();
    roomFiveEnter = new QPushButton();
    roomFiveId = new QTextEdit(std::to_string(Data::getRoomIdMultiple(4)).c_str());
    roomFiveId->setEnabled(false);
    roomFiveName = new QTextEdit(Data::getRoomNameMultiple(4));
    roomFiveName->setEnabled(false);
    roomFiveLayout->addWidget(roomFiveId,0);
    roomFiveLayout->addWidget(roomFiveName,1);
    roomFiveLayout->addWidget(roomFiveEnter);

    listLayout->addLayout(roomFiveLayout);

    roomSixLayout = new QHBoxLayout();
    roomSixEnter = new QPushButton();
    roomSixId = new QTextEdit(std::to_string(Data::getRoomIdMultiple(5)).c_str());
    roomSixId->setEnabled(false);
    roomSixName = new QTextEdit(Data::getRoomNameMultiple(5));
    roomSixName->setEnabled(false);
    roomSixLayout->addWidget(roomSixId,0);
    roomSixLayout->addWidget(roomSixName,1);
    roomSixLayout->addWidget(roomSixEnter);

    listLayout->addLayout(roomSixLayout);

    roomSevenLayout = new QHBoxLayout();
    roomSevenEnter = new QPushButton();
    roomSevenId = new QTextEdit(std::to_string(Data::getRoomIdMultiple(6)).c_str());
    roomSevenId->setEnabled(false);
    roomSevenName = new QTextEdit(Data::getRoomNameMultiple(6));
    roomSevenName->setEnabled(false);
    roomSevenLayout->addWidget(roomSevenId,0);
    roomSevenLayout->addWidget(roomSevenName,1);
    roomSevenLayout->addWidget(roomSevenEnter);

    listLayout->addLayout(roomSevenLayout);

    roomEightLayout = new QHBoxLayout();
    roomEightEnter = new QPushButton();
    roomEightId = new QTextEdit(std::to_string(Data::getRoomIdMultiple(7)).c_str());
    roomEightId->setEnabled(false);
    roomEightName = new QTextEdit(Data::getRoomNameMultiple(7));
    roomEightName->setEnabled(false);
    roomEightLayout->addWidget(roomEightId,0);
    roomEightLayout->addWidget(roomEightName,1);
    roomEightLayout->addWidget(roomEightEnter);

    listLayout->addLayout(roomEightLayout);

    roomNineLayout = new QHBoxLayout();
    roomNineEnter = new QPushButton();
    roomNineId = new QTextEdit(std::to_string(Data::getRoomIdMultiple(8)).c_str());
    roomNineId->setEnabled(false);
    roomNineName = new QTextEdit(Data::getRoomNameMultiple(8));
    roomNineName->setEnabled(false);
    roomNineLayout->addWidget(roomNineId,0);
    roomNineLayout->addWidget(roomNineName,1);
    roomNineLayout->addWidget(roomNineEnter);

    listLayout->addLayout(roomNineLayout);

    horizontalLayoutWidget->setLayout(listLayout);
}

void Hall::setQSS() {

}

void Hall::setSignal() {
    connect(push,SIGNAL(clicked()),this,SLOT(entrancePush()));
    connect(back,SIGNAL(clicked()),this,SIGNAL(backExit()));
    connect(roomOneEnter,SIGNAL(clicked()),this,SLOT(enterOne()));
    connect(roomTwoEnter,SIGNAL(clicked()),this,SLOT(enterTwo()));
    connect(roomThreeEnter,SIGNAL(clicked()),this,SLOT(enterThree()));
    connect(roomFourEnter,SIGNAL(clicked()),this,SLOT(enterFour()));
    connect(roomFiveEnter,SIGNAL(clicked()),this,SLOT(enterFive()));
    connect(roomSixEnter,SIGNAL(clicked()),this,SLOT(enterSix()));
    connect(roomSevenEnter,SIGNAL(clicked()),this,SLOT(enterSeven()));
    connect(roomEightEnter,SIGNAL(clicked()),this,SLOT(enterEight()));
    connect(roomNineEnter,SIGNAL(clicked()),this,SLOT(enterNine()));
}

void Hall::entrancePush() {
    entrance("进入房间");
}

void Hall::enterOne() {

}

void Hall::enterTwo() {

}

void Hall::enterThree() {

}

void Hall::enterFour() {

}

void Hall::enterFive() {

}

void Hall::enterSix() {

}

void Hall::enterSeven() {

}

void Hall::enterEight() {

}

void Hall::enterNine() {

}
