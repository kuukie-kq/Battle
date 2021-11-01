//
// Created by kuukie on 2021/10/23.
//

#ifndef BATTLE_READY_H
#define BATTLE_READY_H

#include <QWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>

class Ready : public QWidget {
    Q_OBJECT
public:
    Ready();
    ~Ready();
    void setShow(QWidget* widget);
private:
    QFrame* ownerFrame;
    QFrame* tableFrame;
    QFrame* visitorFrame;
    QPushButton* leaveRoom;
    QPushButton* pushButton;
    QLabel* ownerName;
    QLabel* visitorName;
    QFrame* readyOrStart;
    void setUI();
    void setQSS();
    void setSignal();
    signals:
    void start(QString message);
private slots:
    void pushButtonClick();
};


#endif //BATTLE_READY_H
