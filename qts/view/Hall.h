//
// Created by kuukie on 2021/10/20.
//

#ifndef BATTLE_HALL_H
#define BATTLE_HALL_H

#include <QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStyleOption>
#include <QtWidgets/QListView>
#include <QtWidgets/QTextEdit>
#include <QtGui/QPainter>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include "../../rpc/view/User.h"

class Hall : public QWidget {
    Q_OBJECT
public:
    Hall();
    ~Hall();
    void setShow(QWidget* widget);
private:
    QWidget* horizontalLayoutWidget;
    QPushButton* pushButtonOne;
    QPushButton* pushButtonTwo;
    QLineEdit* roomEdit;
    QListView* onLines;
    QTextEdit* chat;
    QLineEdit* inputEdit;
    QComboBox* select;
    QPushButton* push;
    QGridLayout* gridLayout;
    QFrame* roomOne;
    QFrame* roomTwo;
    QFrame* roomThree;
    QFrame* roomFour;
    QFrame* roomFive;
    QFrame* roomSix;
    QFrame* roomSeven;
    QFrame* roomEight;
    QFrame* roomNine;
    void setUI();
    void setQSS();
    void setSignal();
    signals:
    void entrance(QString message);
private slots:
    void entrancePush();
};

#endif //BATTLE_HALL_H
