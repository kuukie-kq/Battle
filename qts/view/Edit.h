//
// Created by kuukie on 2021/10/23.
//

#ifndef BATTLE_EDIT_H
#define BATTLE_EDIT_H

#include <QWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

class Edit : public QWidget {
    Q_OBJECT
public:
    Edit();
    ~Edit();
    void setShow(QWidget* widget);
private:
    QFrame* owner;
    QFrame* visitor;
    QFrame* ownerReady;
    QFrame* visitorReady;
    QPushButton* pushButton;
    QTextEdit* textEdit;
    void setUI();
    void setQSS();
    void setSignal();
    signals:
    void finish(QString message);
private slots:
    void pushButtonFinish();
};


#endif //BATTLE_EDIT_H
