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
    layoutWidget->setParent(widget);
}

void Play::setUI() {
    mine = new QLabel();
    mine->setText("我方");
    mine->setGeometry(0,0,40,40);
    hers = new QLabel();
    hers->setText("敌方");
    hers->setGeometry(0,25,40,40);

    layoutWidget = new QWidget();
    layoutWidget->setGeometry(900,100,200,300);
    gridLayout = new QGridLayout();

    exit = new QPushButton();
    exit->setGeometry(1080,700,100,80);
    exit->setText("返回房间");
}

void Play::setQSS() {
    mine->setObjectName("mine");
    hers->setObjectName("hers");
}

void Play::setSignal() {

}

void Play::nextFrame(ng::GameFrame frame) {
    mine->setGeometry(frame.mineX,frame.mineY,40,40);
    hers->setGeometry(frame.herX,frame.herY,40,40);
    if (frame.mineHP == 0 || frame.herHP == 0) {
        connect(exit,SIGNAL(clicked()),this,SLOT(playSuccess()));
    }
}
