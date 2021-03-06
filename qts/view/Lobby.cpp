//
// Created by kuukie on 2021/11/22.
//

#include "Lobby.h"

Lobby::Lobby() {
    setUI();
    setQSS();
    setSignal();
}

Lobby::~Lobby() {
    delete quit;
    delete friends;
    delete ladder;
    delete competitive;
    delete task;
    delete knapsack;
    delete gridLayout;
    delete layoutWidget;
}

void Lobby::setShow(QWidget* widget) {
    layoutWidget->setParent(widget);
}

void Lobby::setUI() {
    layoutWidget = new QWidget();
    layoutWidget->setGeometry(100,100,1000,600);

    gridLayout = new QGridLayout();
//    gridLayout->setRowStretch(0,2);
//    gridLayout->setRowStretch(1,2);
//    gridLayout->setRowStretch(2,1);
//    gridLayout->setColumnStretch(0,4);
//    gridLayout->setColumnStretch(1,6);

    columnLayout = new QHBoxLayout();
    columnLayout->setContentsMargins(20,10,20,10);
    knapsack = new QPushButton();
    knapsack->setText("背包");
    task = new QPushButton();
    task->setText("任务");
    friends = new QPushButton();
    friends->setText("好友");
    setting = new QPushButton();
    setting->setText("环境");
    quit = new QPushButton();
    quit->setText("退出");
    columnLayout->addWidget(knapsack);
    columnLayout->addWidget(task);
    columnLayout->addWidget(friends);
    columnLayout->addWidget(setting);
    columnLayout->addWidget(quit);
    gridLayout->addLayout(columnLayout,2,0);

    competitive = new QPushButton();
    competitive->setText("竞技大厅");
    gridLayout->addWidget(competitive,1,1);

    ladder = new QPushButton();
    ladder->setText("名人堂");
    gridLayout->addWidget(ladder,1,0);

    layoutWidget->setLayout(gridLayout);
}

void Lobby::setQSS() {
    knapsack->setObjectName("knapsack");
    task->setObjectName("task");
    friends->setObjectName("friends");
    setting->setObjectName("setting");
    quit->setObjectName("quit");
    competitive->setObjectName("competitive");
    ladder->setObjectName("ladder");
}

void Lobby::setSignal() {
    connect(knapsack,SIGNAL(clicked()),this,SLOT(knapsackEnter()));
    connect(task,SIGNAL(clicked()),this,SLOT(taskEnter()));
    connect(friends,SIGNAL(clicked()),this,SLOT(friendsEnter()));
    connect(setting,SIGNAL(clicked()),this,SLOT(settingEnter()));
    connect(competitive,SIGNAL(clicked()),this,SLOT(competitiveEnter()));
    connect(ladder,SIGNAL(clicked()),this,SLOT(ladderEnter()));
}

void Lobby::knapsackEnter() {

}

void Lobby::taskEnter() {

}

void Lobby::friendsEnter() {

}

void Lobby::settingEnter() {

}

void Lobby::competitiveEnter() {
    Channel::login(this);
    UdpServer::request(User::rooms_json());
    loading();
}

void Lobby::ladderEnter() {

}

void Lobby::loadingEnd() {
    std::string string = Channel::get(this);
    if(User::rooms_json_ret(string) == 0) {
        neb::CJsonObject jsonObject(string);
        //解析业务
        for (int i=0;i<atoi(jsonObject("size").c_str()) && i<9;i++) {
            int room_id = atoi(jsonObject["value"][i]("roomID").c_str());
            std::string room_name = jsonObject["value"][i]("room_name");
            std::string room_user_name = jsonObject["value"][i]("owner_name");
            int players = atoi(jsonObject["value"][i]("players").c_str());
            Data::setRoomMultiple(i,room_id,room_name.c_str(),room_user_name.c_str(),players);
        }

        entrance();
    } else {

    }
}
