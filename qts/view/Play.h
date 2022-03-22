//
// Created by kuukie on 2022/2/4.
//

#ifndef BATTLE_PLAY_H
#define BATTLE_PLAY_H

#pragma once
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridLayout>
#include "../../rpc/view/Game.h"

class Play : public QWidget {
    Q_OBJECT
public:
    Play();
    ~Play();
    void setShow(QWidget* widget);
private:
    QLabel* mine;
    QPushButton* myBullet[10];
    QLabel* hers;
    QPushButton* herBullet[10];
    QWidget* layoutWidget;
    QGridLayout* gridLayout;
    QLabel* me;
    QLabel* her;
    QPushButton* exit;
    void setUI();
    void setQSS();
    void setSignal();
    signals:
    void playSuccess();
public slots:
    void nextFrame(ng::GameFrame frame);
};


#endif //BATTLE_PLAY_H
