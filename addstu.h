#ifndef ADDSTU_H
#define ADDSTU_H
#include<QPushButton>

#include <QDialog>

namespace Ui {
class addStu;
}

class addStu : public QDialog
{
    Q_OBJECT

public:
    explicit addStu(QWidget *parent = 0);

    ~addStu();

    // 初始化用户的界面
    void clearUserInterface();
    // 写到文件中

    void writeToFile(QString cnt);

private slots:
    // 点按钮确定  槽函数触发
    void on_btn_yes_clicked();

    // 点按钮 取消
    void on_btn_cancel_clicked();


private:
    Ui::addStu *ui;


};

#endif // ADDSTU_H
