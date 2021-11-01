//
// Created by kuukie on 2021/10/20.
//

#ifndef BATTLE_HALL_H
#define BATTLE_HALL_H

#include <QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStyleOption>
#include <QtWidgets/QListView>
#include <QtWidgets/QTextEdit>
#include <QtGui/QPainter>
#include <QtCore/QFile>
#include <QtCore/QTextStream>

class Hall : public QWidget {
    Q_OBJECT
public:
    Hall();
    ~Hall();
    void setShow(QWidget* widget);
private:
    QWidget* horizontalLayoutWidget;
    QHBoxLayout* list;
    QPushButton* pushButtonThree;
    QPushButton* pushButtonOne;
    QPushButton* pushButtonTwo;
    QListView* onLines;
    QTextEdit* lowQQ;
    QLineEdit* inputEdit;
    QPushButton* push;
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
