//
// Created by kuukie on 2021/10/23.
//

#ifndef BATTLE_PACKAGE_H
#define BATTLE_PACKAGE_H

#include <QWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include "../../util/server/UdpServer.h"

class Package : public QWidget {
    Q_OBJECT
public:
    Package();
    ~Package();
    void setShow(QWidget* widget);
private:
    QFrame* frameOne;
    QFrame* frameTwo;
    QFrame* frameThree;
    QFrame* frameFour;
    QFrame* frameFive;
    QFrame* frameSix;
    QFrame* frameSeven;
    QFrame* frameEight;
    QFrame* frameNine;
    QFrame* frameTen;
    QFrame* frameEleven;
    QFrame* frameTwelve;
    QFrame* frameThirteen;
    QFrame* frameFourteen;
    QFrame* frameFifteen;
    QPushButton* pushButton;
    void setUI();
    void setQSS();
    void setSignal();
    signals:
    void success(QString message);
    void loading();
private slots:
    void pushButtonSuccess();
    void loadingEnd();
};


#endif //BATTLE_PACKAGE_H
