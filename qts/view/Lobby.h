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
    QHBoxLayout* columnLayout;
    QPushButton* knapsack;
    QPushButton* task;
    QPushButton* competitive;
    QPushButton* ladder;
    QPushButton* friends;
    QPushButton* setting;
    QPushButton* quit;
    void setUI();
    void setQSS();
    void setSignal();
    signals:
    void entrance();
private slots:
    void knapsackEnter();
    void taskEnter();
    void friendsEnter();
    void settingEnter();
    void competitiveEnter();
    void ladderEnter();
};


#endif //BATTLE_LOBBY_H
