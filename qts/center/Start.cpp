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

    loginWidget = nullptr;
    login = nullptr;
    hallWidget = nullptr;
    hall = nullptr;
    readyWidget = nullptr;
    ready = nullptr;
    packageWidget = nullptr;
    package = nullptr;
    editWidget = nullptr;
    edit = nullptr;
    lobbyWidget = nullptr;
    lobby = nullptr;
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

    UISET(loginWidget,login,Login,"../qss/view/login.qss");
}

void Start::setSignal() {
    connect(login,SIGNAL(loginFailed(QString)),this,SLOT(statusMessage(QString)));
    connect(login,SIGNAL(loginSuccess(QString)),this,SLOT(loginSuccess(QString)));
    connect(login,SIGNAL(loading()),this,SLOT(loadingEvent()));
    connect(this,SIGNAL(loadingEnd()),login,SLOT(loadingEnd()));
}

void Start::statusMessage(const QString& message) {
    statusBar->showMessage(message,5000);
}

void Start::loginSuccess(const QString& username) {
    delete login;
    delete loginWidget;

    UISET(lobbyWidget,lobby,Lobby,"../qss/view/lobby.qss");

    connect(lobby,SIGNAL(entrance()),this,SLOT(lobbySuccess()));
    connect(lobby,SIGNAL(loading()),this,SLOT(loadingEvent()));
    connect(this,SIGNAL(loadingEnd()),lobby,SLOT(loadingEnd()));

    setWindowTitle("魔法庭-游戏界面");
    this->window()->show();
    statusBar->showMessage(username + "登录成功",10000);
}

void Start::lobbySuccess() {
    delete lobby;
    delete lobbyWidget;
    UISET(hallWidget,hall,Hall,"../qss/view/hall.qss");

    connect(hall,SIGNAL(entrance(QString)),this,SLOT(hallSuccess(QString)));
    connect(hall,SIGNAL(backExit()),this,SLOT(lobbyExit()));
    connect(hall,SIGNAL(loading()),this,SLOT(loadingEvent()));
    connect(this,SIGNAL(loadingEnd()),hall,SLOT(loadingEnd()));

    setWindowTitle("魔法庭-游戏大厅");
    this->window()->show();
    statusBar->showMessage("进入竞技",10000);
}

void Start::lobbyExit() {
    delete hall;
    delete hallWidget;
    UISET(lobbyWidget,lobby,Lobby,"../qss/view/lobby.qss");

    connect(lobby,SIGNAL(entrance()),this,SLOT(lobbySuccess()));
    connect(lobby,SIGNAL(loading()),this,SLOT(loadingEvent()));
    connect(this,SIGNAL(loadingEnd()),lobby,SLOT(loadingEnd()));

    setWindowTitle("魔法庭-游戏大厅");
    this->window()->show();
    statusBar->showMessage("回到大厅",10000);
}

void Start::hallSuccess(const QString& message) {
    delete hall;
    delete hallWidget;
    UISET(readyWidget,ready,Ready,"../qss/view/ready.qss");

    connect(ready,SIGNAL(start(QString)),this,SLOT(readySuccess(QString)));
    connect(ready,SIGNAL(backExit()),this,SLOT(hallExit()));
    connect(ready,SIGNAL(loading()),this,SLOT(loadingEvent()));
    connect(this,SIGNAL(loadingEnd()),ready,SLOT(loadingEnd()));

    setWindowTitle("魔法庭-房间准备");
    this->window()->show();
    statusBar->showMessage(message,10000);
}

void Start::hallExit() {
    delete ready;
    delete readyWidget;
    UISET(hallWidget,hall,Hall,"../qss/view/hall.qss");

    connect(hall,SIGNAL(entrance(QString)),this,SLOT(hallSuccess(QString)));
    connect(hall,SIGNAL(backExit()),this,SLOT(lobbyExit()));
    connect(hall,SIGNAL(loading()),this,SLOT(loadingEvent()));
    connect(this,SIGNAL(loadingEnd()),hall,SLOT(loadingEnd()));

    setWindowTitle("魔法庭-游戏大厅");
    this->window()->show();
    statusBar->showMessage("进入竞技",10000);
}

void Start::readySuccess(const QString& message) {
    delete ready;
    delete readyWidget;
    UISET(packageWidget,package,Package,"../qss/view/package.qss");

    connect(package,SIGNAL(success(QString)),this,SLOT(packageSuccess(QString)));
    connect(package,SIGNAL(loading()),this,SLOT(loadingEvent()));
    connect(this,SIGNAL(loadingEnd()),package,SLOT(loadingEnd()));

    setWindowTitle("魔法庭-整备装备");
    this->window()->show();
    statusBar->showMessage(message,10000);
}

void Start::packageSuccess(const QString& message) {
    delete package;
    delete packageWidget;
    UISET(editWidget,edit,Edit,"../qss/view/edit.qss");

    connect(edit,SIGNAL(finish(QString)),this,SLOT(editSuccess(QString)));

    setWindowTitle("魔法庭-算法秀");
    this->window()->show();
    statusBar->showMessage(message,10000);
}

void Start::editSuccess(const QString& message) {
    delete edit;
    delete editWidget;
    UISET(playWidget,play,Play,"../qss/view/play.qss");

    connect(play,SIGNAL(playSuccess()),this,SLOT(playSuccess()));
    connect(this,SIGNAL(nextTime(ng::GameFrame)),play,SLOT(nextFrame(ng::GameFrame)));
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(timeoutRead()));
    timer->start(25);

    setWindowTitle("魔法庭-游戏对战");
    this->window()->show();
    statusBar->showMessage(message,10000);
}

void Start::playSuccess() {
    timer->stop();
    delete play;
    delete playWidget;
    UISET(readyWidget,ready,Ready,"../qss/view/ready.qss");

    connect(ready,SIGNAL(start(QString)),this,SLOT(readySuccess(QString)));
    connect(ready,SIGNAL(backExit()),this,SLOT(hallExit()));
    connect(ready,SIGNAL(loading()),this,SLOT(loadingEvent()));
    connect(this,SIGNAL(loadingEnd()),ready,SLOT(loadingEnd()));

    setWindowTitle("魔法庭-房间准备");
    this->window()->show();
}

void Start::loadingEvent() {
    auto* load = new QLabel(this);
    load->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    load->setWindowModality(Qt::ApplicationModal);
    auto* movie = new QMovie("../img/12120419410.gif");
    load->setMovie(movie);
    movie->start();
    load->window()->show();
//    auto* load = new Load(this);
//    load->setShow();

    for (;;) {
        if(Channel::loadingEnd()) {
            break;
        } else {
            sleep(2);
        }
    }

    delete load;
    loadingEnd();
}

void Start::timeoutRead() {
    // Game
    nextTime(Game::game_json(Channel::exit_queue()));
}
