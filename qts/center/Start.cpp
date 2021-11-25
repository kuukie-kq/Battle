//
// Created by kuukie on 2021/10/20.
//

#include "Start.h"

Start::Start(QWidget* parent) : QMainWindow(parent) {
    setUI();
    setQSS();
    setSignal();
}

Start::~Start() {
    delete statusBar;
    delete menuBar;
    delete centralWidget;
}

void Start::setUI() {
    centralWidget = new QWidget();
    menuBar = new QMenuBar();
    statusBar = new QStatusBar();
    setCentralWidget(centralWidget);
//    setMenuBar(menuBar);
    setStatusBar(statusBar);
}

void Start::setQSS() {
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect resolution = screen->availableGeometry();

    setGeometry(CENTER(resolution.width(),WIDTH),CENTER(resolution.height(),HEIGHT),WIDTH,HEIGHT);
    setMinimumSize(WIDTH,HEIGHT);
    setMaximumSize(WIDTH,HEIGHT);
    setWindowTitle("登录界面");
    setWindowIcon(QIcon("../img/1D9A70788D7.png"));
    setObjectName("main");

    UISET(loginWidget,login,Login,"../qss/view/login.qss")
}

void Start::setSignal() {
    connect(login,SIGNAL(loginFailed(QString)),this,SLOT(statusMessage(QString)));
    connect(login,SIGNAL(loginSuccess(QString)),this,SLOT(loginSuccess(QString)));
}

void Start::statusMessage(const QString& message) {
    statusBar->showMessage(message,5000);
}

void Start::loginSuccess(const QString& username) {
    delete login;
    delete loginWidget;
    UISET(lobbyWidget,lobby,Lobby,"../qss/view/lobby.qss")

    connect(lobby,SIGNAL(entrance()),this,SLOT(lobbySuccess()));

    setWindowTitle("坦克大战-游戏界面");
    this->window()->show();
    statusBar->showMessage("登录成功",10000);
}

void Start::lobbySuccess() {
    delete lobby;
    delete lobbyWidget;
    UISET(hallWidget,hall,Hall,"../qss/view/hall.qss")

    connect(hall,SIGNAL(entrance(QString)),this,SLOT(hallSuccess(QString)));

    setWindowTitle("魔法庭-游戏大厅");
    this->window()->show();
    statusBar->showMessage("进入竞技",10000);
}

void Start::hallSuccess(const QString& message) {
    delete hall;
    delete hallWidget;
    UISET(readyWidget,ready,Ready,"../qss/view/hall.qss")

    connect(ready,SIGNAL(start(QString)),this,SLOT(readySuccess(QString)));

    this->window()->show();
    statusBar->showMessage(message,10000);
}

void Start::readySuccess(const QString& message) {
    delete ready;
    delete readyWidget;
    UISET(packageWidget,package,Package,"../qss/view/hall.qss")

    connect(package,SIGNAL(success(QString)),this,SLOT(packageSuccess(QString)));

    this->window()->show();
    statusBar->showMessage(message,10000);
}

void Start::packageSuccess(const QString& message) {
    delete package;
    delete packageWidget;
    UISET(editWidget,edit,Edit,"../qss/view/hall.qss")

    connect(edit,SIGNAL(finish(QString)),this,SLOT(editSuccess(QString)));

    this->window()->show();
    statusBar->showMessage(message,10000);
}

void Start::editSuccess(const QString& message) {
    delete edit;
    delete editWidget;
    UISET(readyWidget,ready,Ready,"../qss/view/hall.qss")

    connect(ready,SIGNAL(start(QString)),this,SLOT(readySuccess(QString)));

    this->window()->show();
    statusBar->showMessage(message,10000);
}
