//
// Created by kuukie on 2021/10/20.
//

#ifndef BATTLE_LOGIN_H
#define BATTLE_LOGIN_H

#pragma once
#include <QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStyleOption>
#include <QtGui/QPainter>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include "../../util/view/Calculate.h"
#include "../../util/server/UdpServer.h"

class Login : public QWidget {
    Q_OBJECT
public:
    Login();
    ~Login();
    void setShow(QWidget* widget);
private:
    QWidget* layoutWidget;
    QGridLayout* gridLayout;
    QHBoxLayout* horizontalLayout;
    QPushButton* pushButtonOne;
    QPushButton* pushButtonTwo;
    QLineEdit* lineEditOne;
    QLabel* labelTwo;
    QSpacerItem* horizontalSpacer;
    QLineEdit* lineEditTwo;
    QLabel* labelOne;
    void setUI();
    void setQSS();
    void setSignal();
    signals:
    void loginSuccess(QString username);
    void loginFailed(QString message);
    void loading();
private slots:
    void loginBarEvent();
    void registerBarEvent();
    void loadingEnd();
};

#endif //BATTLE_LOGIN_H
