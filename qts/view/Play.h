//
// Created by kuukie on 2022/2/4.
//

#ifndef BATTLE_PLAY_H
#define BATTLE_PLAY_H

#pragma once
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

class Play : public QWidget {
    Q_OBJECT
public:
    Play();
    ~Play();
    void setShow(QWidget* widget);
private:
    QLabel* mine;
    QLabel* hers;
    QPushButton* exit;
    void setUI();
    void setQSS();
    void setSignal();
    signals:
    void playSuccess();
public slots:
    void nextFrame(int x,int y);
};


#endif //BATTLE_PLAY_H
