/********************************************************************************
** Form generated from reading UI file 'tictactoe.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICTACTOE_H
#define UI_TICTACTOE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TicTacToe
{
public:
    QWidget *centralwidget;
    QPushButton *posButton_1;
    QPushButton *posButton_3;
    QPushButton *posButton_2;
    QPushButton *posButton_4;
    QPushButton *posButton_5;
    QPushButton *posButton_6;
    QPushButton *posButton_7;
    QPushButton *posButton_8;
    QPushButton *posButton_9;
    QPushButton *exitButton;
    QPushButton *goSecondButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TicTacToe)
    {
        if (TicTacToe->objectName().isEmpty())
            TicTacToe->setObjectName(QString::fromUtf8("TicTacToe"));
        TicTacToe->resize(673, 457);
        centralwidget = new QWidget(TicTacToe);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        posButton_1 = new QPushButton(centralwidget);
        posButton_1->setObjectName(QString::fromUtf8("posButton_1"));
        posButton_1->setGeometry(QRect(70, 40, 91, 91));
        QFont font;
        font.setPointSize(80);
        posButton_1->setFont(font);
        posButton_3 = new QPushButton(centralwidget);
        posButton_3->setObjectName(QString::fromUtf8("posButton_3"));
        posButton_3->setGeometry(QRect(250, 40, 91, 91));
        posButton_3->setFont(font);
        posButton_2 = new QPushButton(centralwidget);
        posButton_2->setObjectName(QString::fromUtf8("posButton_2"));
        posButton_2->setGeometry(QRect(160, 40, 91, 91));
        posButton_2->setFont(font);
        posButton_4 = new QPushButton(centralwidget);
        posButton_4->setObjectName(QString::fromUtf8("posButton_4"));
        posButton_4->setGeometry(QRect(70, 130, 91, 91));
        posButton_4->setFont(font);
        posButton_5 = new QPushButton(centralwidget);
        posButton_5->setObjectName(QString::fromUtf8("posButton_5"));
        posButton_5->setGeometry(QRect(160, 130, 91, 91));
        posButton_5->setFont(font);
        posButton_6 = new QPushButton(centralwidget);
        posButton_6->setObjectName(QString::fromUtf8("posButton_6"));
        posButton_6->setGeometry(QRect(250, 130, 91, 91));
        posButton_6->setFont(font);
        posButton_7 = new QPushButton(centralwidget);
        posButton_7->setObjectName(QString::fromUtf8("posButton_7"));
        posButton_7->setGeometry(QRect(70, 220, 91, 91));
        posButton_7->setFont(font);
        posButton_8 = new QPushButton(centralwidget);
        posButton_8->setObjectName(QString::fromUtf8("posButton_8"));
        posButton_8->setGeometry(QRect(160, 220, 91, 91));
        posButton_8->setFont(font);
        posButton_9 = new QPushButton(centralwidget);
        posButton_9->setObjectName(QString::fromUtf8("posButton_9"));
        posButton_9->setGeometry(QRect(250, 220, 91, 91));
        posButton_9->setFont(font);
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(400, 40, 91, 91));
        goSecondButton = new QPushButton(centralwidget);
        goSecondButton->setObjectName(QString::fromUtf8("goSecondButton"));
        goSecondButton->setGeometry(QRect(400, 130, 91, 91));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 330, 121, 51));
        QFont font1;
        font1.setPointSize(29);
        label->setFont(font1);
        TicTacToe->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TicTacToe);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 673, 20));
        TicTacToe->setMenuBar(menubar);
        statusbar = new QStatusBar(TicTacToe);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TicTacToe->setStatusBar(statusbar);

        retranslateUi(TicTacToe);

        QMetaObject::connectSlotsByName(TicTacToe);
    } // setupUi

    void retranslateUi(QMainWindow *TicTacToe)
    {
        TicTacToe->setWindowTitle(QCoreApplication::translate("TicTacToe", "TicTacToe", nullptr));
        posButton_1->setText(QString());
        posButton_3->setText(QString());
        posButton_2->setText(QString());
        posButton_4->setText(QString());
        posButton_5->setText(QString());
        posButton_6->setText(QString());
        posButton_7->setText(QString());
        posButton_8->setText(QString());
        posButton_9->setText(QString());
        exitButton->setText(QCoreApplication::translate("TicTacToe", "Exit", nullptr));
        goSecondButton->setText(QCoreApplication::translate("TicTacToe", "Go Second", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TicTacToe: public Ui_TicTacToe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICTACTOE_H
