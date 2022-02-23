//
// Created by kuukie on 2022/2/4.
//

#include "Play.h"

Play::Play() {
    setUI();
    setQSS();
    setSignal();
}

Play::~Play() {
    delete exit;
    delete hers;
    delete mine;
}

void Play::setShow(QWidget *widget) {
    mine->setParent(widget);
    hers->setParent(widget);
    exit->setParent(widget);
}

void Play::setUI() {
    mine = new QLabel();
    mine->setText("我方");
    mine->setGeometry(0,0,40,40);
    hers = new QLabel();
    hers->setText("敌方");
    hers->setGeometry(0,25,40,40);
    exit = new QPushButton();
    exit->setGeometry(1080,700,100,80);
    exit->setText("完成");
}

void Play::setQSS() {
    mine->setObjectName("mine");
    hers->setObjectName("hers");
}

void Play::setSignal() {

}

void Play::nextFrame(int x,int y) {
    mine->setGeometry(x,y,40,40);
    hers->setGeometry(x,y+240,40,40);
    if(x >= 150 && x < 250) {
        connect(exit,SIGNAL(clicked()),this,SIGNAL(playSuccess()));
    }
}
