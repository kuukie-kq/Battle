//
// Created by kuukie on 2021/10/23.
//

#include "Edit.h"

Edit::Edit() {
    setUI();
    setQSS();
    setSignal();
}

Edit::~Edit() {
    delete textEdit;
    delete pushButton;
    delete visitorReady;
    delete ownerReady;
    delete visitor;
    delete owner;
}

void Edit::setShow(QWidget *widget) {
    owner->setParent(widget);
    visitor->setParent(widget);
    ownerReady->setParent(widget);
    visitorReady->setParent(widget);
    pushButton->setParent(widget);
    textEdit->setParent(widget);
}

void Edit::setUI() {
    owner = new QFrame();
    owner->setGeometry(540,20,150,150);
    owner->setFrameShape(QFrame::NoFrame);
    owner->setFrameShadow(QFrame::Raised);

    visitor = new QFrame();
    visitor->setGeometry(540,200,150,150);
    visitor->setFrameShape(QFrame::NoFrame);
    visitor->setFrameShadow(QFrame::Raised);

    ownerReady = new QFrame();
    ownerReady->setGeometry(620,110,50,50);
    ownerReady->setFrameShape(QFrame::NoFrame);
    ownerReady->setFrameShadow(QFrame::Raised);

    visitorReady = new QFrame();
    visitorReady->setGeometry(620,290,50,50);
    visitorReady->setFrameShape(QFrame::NoFrame);
    visitorReady->setFrameShadow(QFrame::Raised);

    pushButton = new QPushButton();
    pushButton->setGeometry(550,360,120,60);
    pushButton->setText("编写完成");

    textEdit = new QTextEdit();
    textEdit->setGeometry(50,60,450,350);
}

void Edit::setQSS() {

}

void Edit::setSignal() {
    connect(pushButton,SIGNAL(clicked()),this,SLOT(pushButtonFinish()));
}

void Edit::pushButtonFinish() {
    finish("编写完成，模拟演练，结果为");
}
