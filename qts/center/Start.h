//
// Created by kuukie on 2021/10/20.
//

#ifndef BATTLE_START_H
#define BATTLE_START_H

#pragma once
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtGui/QScreen>
#include <QtCore/QTimer>
#include "../../util/view/Calculate.h"
#include "../view/Login.h"
#include "../view/Hall.h"
#include "../view/Ready.h"
#include "../view/Package.h"
#include "../view/Edit.h"
#include "../view/Lobby.h"
#include "../view/Load.h"
#include "../view/Play.h"

#define WIDTH 1280
#define HEIGHT 800

#define QSSSET(path) ({ \
    QFile file((path)); \
    if(file.open(QFile::ReadOnly)) { \
        QTextStream fileText(&file); \
        this->setStyleSheet(fileText.readAll()); \
        file.close(); \
    } \
})

#define UISET(broker,view,viewClass,path) ({ \
    (broker) = new QWidget(); \
    view = new viewClass(); \
    (view)->setShow((broker)); \
    QSSSET((path)); \
    setCentralWidget((broker)); \
})

class Start : public QMainWindow {
    Q_OBJECT
public:
    Start(QWidget* parent = nullptr);
    ~Start();
private:
    QWidget* centralWidget;
    QMenuBar* menuBar;
    QStatusBar* statusBar;
    void setUI();
    void setQSS();
    void setSignal();
    QWidget* loginWidget;
    Login* login;
    QWidget* hallWidget;
    Hall* hall;
    QWidget* readyWidget;
    Ready* ready;
    QWidget* packageWidget;
    Package* package;
    QWidget* editWidget;
    Edit* edit;
    QWidget* lobbyWidget;
    Lobby* lobby;
    QWidget* playWidget;
    Play* play;
    QTimer* timer;
    signals:
    void loadingEnd();
    void nextTime(ng::GameFrame frame);
private slots:
    void statusMessage(const QString& message);
    void loginSuccess(const QString& username);
    void lobbySuccess();
    void lobbyExit();
    void hallSuccess(const QString& message);
    void hallExit();
    void readySuccess(const QString& message);
    void packageSuccess(const QString& message);
    void editSuccess(const QString& message);
    void playSuccess();
    void loadingEvent();
    void timeoutRead();
};

#endif //BATTLE_START_H
