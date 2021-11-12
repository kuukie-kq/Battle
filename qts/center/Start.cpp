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
    setGeometry(400,200,1280,800);
    setMinimumSize(1280,800);
    setMaximumSize(1280,800);
    setWindowTitle("登录界面");
    setWindowIcon(QIcon("../img/1D9A70788D7.png"));

    loginWidget = new QWidget();
    login = new Login();
    login->setShow(loginWidget);
    loadQSS("../qss/view/login.qss");
    setCentralWidget(loginWidget);
}

void Start::setSignal() {
    connect(login,SIGNAL(loginFailed(QString)),this,SLOT(statusMessage(QString)));
    connect(login,SIGNAL(loginSuccess(QString)),this,SLOT(loginSuccess(QString)));
    connect(hall,SIGNAL(entrance(QString)),this,SLOT(hallSuccess(QString)));
    connect(ready,SIGNAL(start(QString)),this,SLOT(readySuccess(QString)));
    connect(package,SIGNAL(success(QString)),this,SLOT(packageSuccess(QString)));
    connect(edit,SIGNAL(finish(QString)),this,SLOT(editSuccess(QString)));

}

void Start::loadQSS(const QString& relative) {
    QFile file(relative);
    if(file.open(QFile::ReadOnly)) {
        QTextStream filetext(&file);
        this->setStyleSheet(filetext.readAll());
        file.close();
    }
}

void Start::statusMessage(const QString& message) {
    statusBar->showMessage(message,5000);
}

void Start::loginSuccess(const QString& username) {
    delete login;
    delete loginWidget;

    hallWidget = new QWidget();
    hall = new Hall();
    hall->setShow(hallWidget);
    loadQSS("../qss/view/hall.qss");
    setCentralWidget(hallWidget);

    setWindowTitle("坦克大战-游戏界面");
    this->window()->show();
    statusBar->showMessage("登录成功",10000);
}

void Start::hallSuccess(const QString& message) {
    delete hall;
    delete hallWidget;

    readyWidget = new QWidget();
    ready = new Ready();
    ready->setShow(readyWidget);
    loadQSS("../qss/view/hall.qss");
    setCentralWidget(readyWidget);

    this->window()->show();
    statusBar->showMessage(message,10000);
}

void Start::readySuccess(const QString& message) {
    delete ready;
    delete readyWidget;

    packageWidget = new QWidget();
    package = new Package();
    package->setShow(packageWidget);
    loadQSS("../qss/view/hall.qss");
    setCentralWidget(packageWidget);

    this->window()->show();
    statusBar->showMessage(message,10000);
}

void Start::packageSuccess(const QString& message) {
    delete package;
    delete packageWidget;

    editWidget = new QWidget();
    edit = new Edit();
    edit->setShow(editWidget);
    loadQSS("../qss/view/hall.qss");
    setCentralWidget(editWidget);

    this->window()->show();
    statusBar->showMessage(message,10000);
}

void Start::editSuccess(const QString& message) {
    delete edit;
    delete editWidget;

    hallWidget = new QWidget();
    hall = new Hall();
    hall->setShow(hallWidget);
    loadQSS("../qss/view/hall.qss");
    setCentralWidget(hallWidget);

    this->window()->show();
    statusBar->showMessage(message,10000);
}
