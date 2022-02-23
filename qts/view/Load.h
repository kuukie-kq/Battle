//
// Created by kuukie on 2022/1/17.
//

#ifndef BATTLE_LOAD_H
#define BATTLE_LOAD_H

#pragma once
#include <QWidget>
#include <QPoint>
#include <QMovie>
#include <QFrame>
#include <QLabel>
#include "../../util/view/Calculate.h"

class Load : public QWidget {
    Q_OBJECT
public:
    Load(QWidget* parent);
    ~Load();
    void setShow();
private:
    QLabel* label;
    QMovie* movie;
    void setUI(QWidget* parent);
    void setQSS();
    void setSignal();
    signals:
    void loading();
};

#endif //BATTLE_LOAD_H
