#include "addstu.h"
#include "ui_addstu.h"
#include<QString>
#include<QList>
#include<QAbstractButton>
#include<QMessageBox>
#include<QIODevice>
#include<QFile>
#include<QTextStream>
#include<QPushButton>
#include<QDebug>
#include<QSound>


addStu::addStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addStu)
{
    ui->setupUi(this);
}

addStu::~addStu()
{
    delete ui;
}

// 初始化用户的界面
void addStu::clearUserInterface()
{
  this->ui->line_name->clear();
    this->ui->line_id->clear();
    this->ui->rbtn_male->setChecked(true);
    this->ui->agecm->setCurrentIndex(0);
    this->ui->xycomboBox_2->setCurrentIndex(0);
    QList<QAbstractButton *> ins_list = this->ui->insbuttonGroup->buttons();

    int i = 0;
    for(i = 0;i < ins_list.length();i++){
        QAbstractButton * box = ins_list.at(i);
        box->setChecked(false);
    }
    this->ui->line_name->setFocus();



}

// 写到文件中

void addStu::writeToFile(QString cnt)
{

    QFile file("student.txt");
    if(!file.open(QIODevice::Append | QIODevice ::Text))
    {
        //如果文件没打开会弹出这个框
        QMessageBox::critical(this,"错误","文件打开失败，信息没有保持！","确认");
        return;
    }

    QTextStream out(&file);
    out<< cnt;
    file.close();

}

// 点按钮确定
void addStu::on_btn_yes_clicked()
{
    //确定音效

    QSound * yesSound = new QSound(":/qT image/BackButtonSound.wav",this);
    yesSound->play();
    // 名字  和学号
    QString name = this->ui->line_name->text();
    QString id = this->ui->line_id->text();
    //checkedButtton()代表已选按钮，按钮组默认为单选，Exclusive属性默认为true
    QString sex = this->ui->sexbuttonGroup->checkedButton()->text();

    //创建一个抽象按钮指针链表接收按钮组
    //因为返回的是QList<QAbstractButton *>类型所以要加以<QList><QAbstractButton>
    QList<QAbstractButton *>ins_list = this->ui->insbuttonGroup->buttons();
    //访问所有复选框
    QString ins;
    int i = 0;
    for(i = 0; i < ins_list.length(); i++)
    {
        QAbstractButton * che = ins_list.at(i);
        if(che->isChecked())
        {
            ins += che->text() + " ";
        }
    }

    // 获取年龄下拉框

    QString age = this->ui->agecm->currentText();

    // 获取学院下拉框当前值
    QString dev = this->ui->xycomboBox_2->currentText();


    QString content = name + '\n' + id + '\n' + sex + '\n' + age  + '\n'+dev+ '\n' + ins;

    //为了把数据传入文件，需要重新建一个QString字符串
    QString cnt = name + " " + id + " " + sex + " " + age + " " + dev + " " + ins + "\n";

    if(name.length() < 1 || id.length() < 1 || ins.length() < 1)
    {
        QMessageBox::critical(this,"错误","信息填写不完整，请重新检查","确认");
    }
    else
    {
         int ret = QMessageBox::information(this,"请确认信息",content,"确认","取消");
         if(ret == 0)
         {
             //当点击确认后还原所有选项
             clearUserInterface();
             //把数据传入文件
             writeToFile(cnt);
         }
    }

}

// 点按钮 取消
void addStu::on_btn_cancel_clicked()
{

    this->close();
}
