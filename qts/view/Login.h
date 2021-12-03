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
#include "../../rpc/view/UserLogin.h"
#include "../../util/view/Calculate.h"
#include "../../cache/view/Data.h"

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
private slots:
    void loginBarEvent();
};


#endif //BATTLE_LOGIN_H
