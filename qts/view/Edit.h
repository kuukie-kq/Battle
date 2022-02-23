//
// Created by kuukie on 2021/10/23.
//

#ifndef BATTLE_EDIT_H
#define BATTLE_EDIT_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QTextEdit>
#include "../../util/server/UdpServer.h"

class Edit : public QWidget {
    Q_OBJECT
public:
    Edit();
    ~Edit();
    void setShow(QWidget* widget);
private:
    QFrame* owner;
    QFrame* visitor;
    QFrame* ownerReady;
    QFrame* visitorReady;
    QPushButton* pushButton;
    QTextEdit* textEdit;
    void setUI();
    void setQSS();
    void setSignal();
    signals:
    void finish(QString message);
    void loading();
private slots:
    void pushButtonFinish();
    void loadingEnd();
};

#endif //BATTLE_EDIT_H
