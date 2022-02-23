//
// Created by kuukie on 2022/1/17.
//

#include "Load.h"

Load::Load(QWidget* parent) {
    setUI(parent);
    setQSS();
    setSignal();
}

Load::~Load() {
    delete movie;
    delete label;
}

void Load::setShow() {
    label->window()->show();
}

void Load::setUI(QWidget* parent = nullptr) {
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::ApplicationModal);
    label = new QLabel(parent);
    movie = new QMovie("../img/12120419410.gif");
    label->setMovie(movie);
    movie->start();
}

void Load::setQSS() {

}

void Load::setSignal() {

}
