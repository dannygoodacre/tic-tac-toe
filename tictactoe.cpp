#include "tictactoe.h"

//TODO: implement a finish (draw or loss). Currently nothing happens
//TODO: if board full after button click, show a reset button

TicTacToe::TicTacToe(QWidget *parent): QMainWindow(parent), ui(new Ui::TicTacToe)
{
    ui->setupUi(this);
    
    this->buttons[0] = ui->posButton_1;
    this->buttons[1] = ui->posButton_2;
    this->buttons[2] = ui->posButton_3;
    this->buttons[3] = ui->posButton_4;
    this->buttons[4] = ui->posButton_5;
    this->buttons[5] = ui->posButton_6;
    this->buttons[6] = ui->posButton_7;
    this->buttons[7] = ui->posButton_8;
    this->buttons[8] = ui->posButton_9;

    this->finished = false;
}

TicTacToe::~TicTacToe()
{
    delete ui;
}

bool TicTacToe::containsIcon(QPushButton *button, QString icon)
{
    return button->text() == icon;
}

bool TicTacToe::isEmpty(QPushButton *button)
{
    return containsIcon(button, "");
}

int TicTacToe::twoInARow(QString icon)
{
    const int rowStarts[] = {0, 3, 6};
    for (int i = 0; i < 3; i++)
    {
        // rows
        if (containsIcon(this->buttons[rowStarts[i]], icon) && containsIcon(this->buttons[rowStarts[i]+1], icon) && isEmpty(this->buttons[rowStarts[i]+2]))
        {
            return rowStarts[i]+2;
        }
        else if (containsIcon(this->buttons[rowStarts[i]], icon) && containsIcon(this->buttons[rowStarts[i]+2], icon) && isEmpty(this->buttons[rowStarts[i]+1]))
        {
            return rowStarts[i]+1;
        }
        else if (containsIcon(this->buttons[rowStarts[i]+1], icon) && containsIcon(this->buttons[rowStarts[i]+2], icon) && isEmpty(this->buttons[rowStarts[i]]))
        {
            return rowStarts[i];
        } 
        
        // columns
        else if (containsIcon(this->buttons[i], icon) && containsIcon(this->buttons[i+3], icon) && isEmpty(this->buttons[i+6]))
        {
            return i+6;
        }
        else if (containsIcon(this->buttons[i], icon) && containsIcon(this->buttons[i+6], icon) && isEmpty(this->buttons[i+3]))
        {
            return i+3;
        }
        else if (containsIcon(this->buttons[i+3], icon) && containsIcon(this->buttons[i+6], icon) && isEmpty(this->buttons[i]))
        {
            return i;
        }
    }

    if (containsIcon(this->buttons[0], icon) && containsIcon(this->buttons[4], icon) && isEmpty(this->buttons[8]))
    {
        return 8;
    }
    else if (containsIcon(this->buttons[0], icon) && containsIcon(this->buttons[8], icon) && isEmpty(this->buttons[4]))
    {
        return 4;
    }
    else if (containsIcon(this->buttons[4], icon) && containsIcon(this->buttons[8], icon) && isEmpty(this->buttons[0]))
    {
        return 0;
    }
    else if (containsIcon(this->buttons[2], icon) && containsIcon(this->buttons[4], icon) && isEmpty(this->buttons[6]))
    { 
        return 6;
    }
    else if (containsIcon(this->buttons[2], icon) && containsIcon(this->buttons[6], icon) && isEmpty(this->buttons[4]))
    {
        return 4;
    }
    else if (containsIcon(this->buttons[4], icon) && containsIcon(this->buttons[6], icon) && isEmpty(this->buttons[2]))
    {
        return 2;
    }

    return -1;
}

int TicTacToe::botPlay()
{
    int positions[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
    for (int i = 0; i < 9; i++)
    {
        if (this->isEmpty(buttons[positions[i]])) return positions[i];
    }

    return -1;
}

bool TicTacToe::boardIsFull()
{
    for (int i = 0; i < 9; i++)
    {
        if (isEmpty(this->buttons[i]))
        {
            return false;
        }
    }

    return true;
}

int TicTacToe::positionToPlay()
{
    int pos = twoInARow("O");
    if (pos == -1) // no bot two in a row
    {
        pos = twoInARow("X");
        if (pos == -1) // no player two in a row
        {
            if (boardIsFull()) // board is full
            {
                return -1;
            }
            return botPlay();
        }
    }
    else // bot wins
    {
        this->buttons[pos]->setText("O");
        this->buttons[pos]->setFlat(true);
        
        return -2;
    }

    return pos;
}


void TicTacToe::buttonClick(int pos)
{
    ui->goSecondButton->setVisible(false);
    QPushButton *button = this->buttons[pos];

    if (this->isEmpty(button) && !this->finished)
    {
        button->setText("X");
        button->setFlat(true);
        
        bool draw = false;
        int botPos = this->positionToPlay();
        if (botPos >= 0)
        {
            this->buttons[botPos]->setText("O");
            this->buttons[botPos]->setFlat(true);

            if (this->boardIsFull())
            {
                QApplication::quit();
            }
        }
        else if (botPos == -1)
        {
            ui->label->setText("DRAW");
            // QApplication::quit();
        }
        else if (botPos == -2)
        {
            ui->label->setText("LOSS");
            this->finished = true;
            // QApplication::quit();
        }
    }
}

void TicTacToe::on_exitButton_clicked()
{
    QApplication::quit();
}

void TicTacToe::on_goSecondButton_clicked()
{
    ui->posButton_5->setText("O");
    ui->posButton_5->setFlat(true);
    ui->goSecondButton->setVisible(false);
}

void TicTacToe::on_posButton_1_clicked()
{
    this->buttonClick(0);
}

void TicTacToe::on_posButton_2_clicked()
{
    this->buttonClick(1);
}

void TicTacToe::on_posButton_3_clicked()
{
    this->buttonClick(2);
}

void TicTacToe::on_posButton_4_clicked()
{
    this->buttonClick(3);
}

void TicTacToe::on_posButton_5_clicked()
{
    this->buttonClick(4);
}

void TicTacToe::on_posButton_6_clicked()
{
    this->buttonClick(5);
}

void TicTacToe::on_posButton_7_clicked()
{
    this->buttonClick(6);
}

void TicTacToe::on_posButton_8_clicked()
{
    this->buttonClick(7);
}

void TicTacToe::on_posButton_9_clicked()
{
    this->buttonClick(8);
}