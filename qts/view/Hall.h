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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include "../../rpc/view/User.h"
#include "../../cache/view/Data.h"

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
    QVBoxLayout* listLayout;
    QHBoxLayout* roomOneLayout;
    QTextEdit* roomOneId;
    QTextEdit* roomOneName;
    QPushButton* roomOneEnter;
    QHBoxLayout* roomTwoLayout;
    QTextEdit* roomTwoId;
    QTextEdit* roomTwoName;
    QPushButton* roomTwoEnter;
    QHBoxLayout* roomThreeLayout;
    QTextEdit* roomThreeId;
    QTextEdit* roomThreeName;
    QPushButton* roomThreeEnter;
    QHBoxLayout* roomFourLayout;
    QTextEdit* roomFourId;
    QTextEdit* roomFourName;
    QPushButton* roomFourEnter;
    QHBoxLayout* roomFiveLayout;
    QTextEdit* roomFiveId;
    QTextEdit* roomFiveName;
    QPushButton* roomFiveEnter;
    QHBoxLayout* roomSixLayout;
    QTextEdit* roomSixId;
    QTextEdit* roomSixName;
    QPushButton* roomSixEnter;
    QHBoxLayout* roomSevenLayout;
    QTextEdit* roomSevenId;
    QTextEdit* roomSevenName;
    QPushButton* roomSevenEnter;
    QHBoxLayout* roomEightLayout;
    QTextEdit* roomEightId;
    QTextEdit* roomEightName;
    QPushButton* roomEightEnter;
    QHBoxLayout* roomNineLayout;
    QTextEdit* roomNineId;
    QTextEdit* roomNineName;
    QPushButton* roomNineEnter;
    void setUI();
    void setQSS();
    void setSignal();
    signals:
    void entrance(QString message);
private slots:
    void entrancePush();
    void enterOne();
    void enterTwo();
    void enterThree();
    void enterFour();
    void enterFive();
    void enterSix();
    void enterSeven();
    void enterEight();
    void enterNine();
};

#endif //BATTLE_HALL_H
