//
// Created by kuukie on 2021/11/22.
//

#ifndef BATTLE_LOBBY_H
#define BATTLE_LOBBY_H

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

class Lobby : public QWidget {
    Q_OBJECT
public:
    Lobby();
    ~Lobby();
    void setShow(QWidget* widget);
private:
    QWidget* layoutWidget;
    QGridLayout* gridLayout;
    QPushButton* knapsack;
    QPushButton* task;
    QPushButton* competitive;
    QPushButton* ladder;
    QPushButton* friends;
    void setUI();
    void setQSS();
    void setSignal();
    signals:
    void entrance(const char* name);
private slots:
};


#endif //BATTLE_LOBBY_H
