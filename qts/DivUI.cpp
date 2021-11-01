//
// Created by kuukie on 2021/10/20.
//

#include "DivUI.h"

int DivUI::run(int argc, char** argv) {
    QApplication application(argc,argv);

    auto start = new Start();
    start->window()->show();

    return QApplication::exec();
}
