//
// Created by kuukie on 2021/10/20.
//

#include "Login.h"
#include "Load.h"

Login::Login() {
    setUI();
    setQSS();
    setSignal();
}

Login::~Login() {
    delete labelOne;
    delete lineEditTwo;
    delete horizontalSpacer;
    delete labelTwo;
    delete lineEditOne;
    delete pushButtonTwo;
    delete pushButtonOne;
    delete horizontalLayout;
    delete gridLayout;
}

void Login::setShow(QWidget* widget) {
    layoutWidget->setParent(widget);
}

void Login::setUI() {
    layoutWidget = new QWidget();
    layoutWidget->setGeometry(CENTER(1280,400), CENTER(800,200), 400, 200);

    gridLayout = new QGridLayout();
    gridLayout->setContentsMargins(10,10,10,10);
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setContentsMargins(10,0,10,0);
    pushButtonOne = new QPushButton();
    pushButtonOne->setText("登录");
    pushButtonOne->setShortcut(QKeySequence::InsertParagraphSeparator);
    pushButtonTwo = new QPushButton();
    pushButtonTwo->setText("注册");
    horizontalLayout->addWidget(pushButtonOne);
    horizontalLayout->addWidget(pushButtonTwo);
    gridLayout->addLayout(horizontalLayout,2,1);

    lineEditOne = new QLineEdit();
    gridLayout->addWidget(lineEditOne,0,1);

    labelTwo = new QLabel();
    labelTwo->setText("密码");
    labelTwo->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
    gridLayout->addWidget(labelTwo,1,0);

    horizontalSpacer = new QSpacerItem(40,20);
    horizontalSpacer->expandingDirections();
    horizontalSpacer->sizeHint();
    gridLayout->spacerItem();

    lineEditTwo = new QLineEdit();
    lineEditTwo->setEchoMode(QLineEdit::Password);
    gridLayout->addWidget(lineEditTwo,1,1);

    labelOne = new QLabel();
    labelOne->setText("账号");
    labelOne->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
    gridLayout->addWidget(labelOne, 0, 0);

    layoutWidget->setLayout(gridLayout);
}

void Login::setQSS() {
    lineEditOne->setObjectName("username");
    lineEditTwo->setObjectName("password");
    pushButtonOne->setObjectName("login");
    pushButtonTwo->setObjectName("register");
}

void Login::setSignal() {
    connect(pushButtonOne,SIGNAL(clicked()),this,SLOT(loginBarEvent()));
    connect(pushButtonTwo,SIGNAL(clicked()),this,SLOT(registerBarEvent()));
}

void Login::loginBarEvent() {
    QString username = lineEditOne->text();
    QString password = lineEditTwo->text();
    if (username.count() == 0) {
        loginFailed("账号不能为空");
    } else if (password.count() == 0) {
        loginFailed("密码不能为空");
    } else {
        // rpc ajax
        Channel::login(this);
        UdpServer::request(User::login_json(username.toStdString(),password.toStdString()));
        loading();
    }
}

void Login::registerBarEvent() {
    loginSuccess("test");
}

void Login::loadingEnd() {
    std::string string = Channel::get(this);
    if(User::login_json_ret(string) == 0) {
        neb::CJsonObject jsonObject(string);
        //解析业务
        int user_id = atoi(jsonObject["value"]("userID").c_str());
        std::string user_name = jsonObject["value"]("userName");
        std::string user_gender = jsonObject["value"]("gender");
        int user_level = atoi(jsonObject["value"]("level").c_str());
        Data::setUserId(user_id);
        Data::setUserName(user_name.c_str());
        Data::setUserGender(user_gender.c_str());
        Data::setUserLevel(user_level);

        loginSuccess(QString(user_name.c_str()));
    } else {
        loginFailed("远程调用错误");
    }
}
