#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"addstu.h"
#include"quersystu.h"
#include"about.h"
#include<QSound>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

// 添加学生
void MainWindow::on_actionAdd_triggered()
{

    addStu * a = new addStu;
    a->show();
    //添加学生音效
    QSound * addSound = new QSound(":/qT image/ConFlipSound.wav",this);
    addSound->play();

}

// 显示学生查找
   void  MainWindow::on_actionQuersy_triggered()
{
    //查找学生音效触发
      QSound * quersySound = new QSound(":/qT image/LevelWinSound.wav",this);
      quersySound->play();
    quersyStu * q = new quersyStu;
    q->show();
}

   // 帮助触发
     void MainWindow::on_actionHelp_triggered()
    {


        about * ab = new about;
        ab->show();
    }
