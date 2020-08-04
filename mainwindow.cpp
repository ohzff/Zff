#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

int gr(int min, int max)
{
    Q_ASSERT(min < max);
    // 加入随机种子。种子是当前时间距离0点0分0秒的秒数。
    // 每次启动程序，只添加一次种子，以做到数字真正随机。
    static bool seedStatus;
    if (!seedStatus)
    {
        qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
        seedStatus = true;
    }
    int nRandom = qrand() % (max - min);
    nRandom = min + nRandom;

    return nRandom;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

const int inf = 105;
//int hx = , hy = 1, fx = ;
int field[inf][inf];
bool init = false, win = false, easy;

int getw ()
{
    return easy?10:18;
}

int geth ()
{
    return 10;
}

int hx = 1, hy = 1, fx = geth(), fy = getw();

void fufumove()
{
    bool stop = false;
    while (!stop)
    {
        int r = gr(1, 4);
        if (r == 1 && fx - 1>= 2)
        {
            fx--;
            stop = true;
        }
        if (r == 2 && fx + 1 <= getw() - 1)
        {
            fx++;
            stop = true;
        }
        if (r == 3 && fy - 1 >= 2)
        {
            fy--;
            stop = true;
        }
        if (r == 4 && fy + 1 <= geth() - 1)
        {
            fy++;
            stop = true;
        }
    }
}


QString printfield ()
{
    int w = getw();
    int h = geth();
    QString f;
    if (fx == hx && fy == hy)
    {
        win = true;
        return "";
    }
    for (int i = 1; i <= h; i ++)
    {
        for (int j = 1; j <= w; j ++)
        {
            f += "  ";
            if (hx == i && hy == j)
            {
                f += "H";
            }
            else if (fx == i && fy == j)
            {
                f += "F";
            }
            else if (field[i][j] == 0)
            {
                f += " ";
            }
            else if (field[i][j] == 1)
            {
                f += ".";
            }
            f += "  ";
        }
        f += "\n";
    }
    return f;
}

void MainWindow::on_start_clicked()
{
    if (this->ui->easy->isChecked())
    {
        easy = true;
    }
    else if (this->ui->hard->isChecked())
    {
        easy = false;
    }
    else
    {
        this->ui->show->setText(" You must choose a option in versions");
        return;
    }
    for (int i = 0; i < inf; i ++)
    {
        for (int j = 0; j < inf; j ++)
        {
            field[i][j] = 0;
        }
    }
    for (int i = 0; i <= getw(); i ++)
    {
        field[1][i] = 1, field[geth()][i] = 1;
    }
    for (int i = 0; i <= geth(); i ++)
    {
        field[i][1] = 1, field[i][getw()] = 1;
    }
    hx = 2, hy = 2, fx = geth() - 1, fy = getw() - 1, init = true, win = false;
    QString f = printfield();
    this->ui->show->setText(f);
}


void MainWindow::on_up_clicked()
{
    if (hx <= 2) return;
    hx --;
    fufumove();
    QString f = printfield();
    this->ui->show->setText(f);
    if (!init)
    {
        this->ui->show->setText(" Press 'Start' to start game.");
    }
    if (win)
    {
        this->ui->show->setText(" You win!");
        init = false;
    }
}

void MainWindow::on_down_clicked()
{
    if (hx >= geth() - 1) return;
    hx ++;
    fufumove();
    QString f = printfield();
    this->ui->show->setText(f);
    if (!init)
    {
        this->ui->show->setText(" Press 'Start' to start game.");
    }
    if (win)
    {
        this->ui->show->setText(" You win!");
        init = false;
    }
}

void MainWindow::on_left_clicked()
{
    if (hy <= 2) return;
    hy --;
    fufumove();
    QString f = printfield();
    this->ui->show->setText(f);
    if (!init)
    {
        this->ui->show->setText(" Press 'Start' to start game.");
    }
    if (win)
    {
        this->ui->show->setText(" You win!");
        init = false;
    }
}

void MainWindow::on_right_clicked()
{
    if (hy >= geth() - 1) return;
    hy ++;
    fufumove();
    QString f = printfield();
    this->ui->show->setText(f);
    if (!init)
    {
        this->ui->show->setText(" Press 'Start' to start game.");
    }
    if (win)
    {
        this->ui->show->setText(" You win!");
        init = false;
    }
}
