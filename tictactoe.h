#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "ui_tictactoe.h"
#include <QMainWindow>
#include <chrono>
#include <thread>

QT_BEGIN_NAMESPACE
namespace Ui { class TicTacToe; }
QT_END_NAMESPACE

class TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    TicTacToe(QWidget *parent = nullptr);
    ~TicTacToe();

    QPushButton *buttons[9];

    bool finished;

    bool containsIcon(QPushButton *button, QString icon);

    bool isEmpty(QPushButton *button);

    int twoInARow(QString icon);

    int botPlay();

    bool boardIsFull();

    int positionToPlay();

    void buttonClick(int buttonPos);

private slots:
    void on_exitButton_clicked();
    void on_goSecondButton_clicked();
    void on_posButton_1_clicked();
    void on_posButton_2_clicked();
    void on_posButton_3_clicked();
    void on_posButton_4_clicked();
    void on_posButton_5_clicked();
    void on_posButton_6_clicked();
    void on_posButton_7_clicked();
    void on_posButton_8_clicked();
    void on_posButton_9_clicked();

private:
    Ui::TicTacToe *ui;
};
#endif // TICTACTOE_H