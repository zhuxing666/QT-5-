#ifndef QUERSYSTU_H
#define QUERSYSTU_H

#include <QDialog>
#include<QFile>
#include<QList>
#include<QString>
// 单元格
#include<QStandardItem>
//表格
#include<QStandardItemModel>

namespace Ui {
class quersyStu;
}

class quersyStu : public QDialog
{
    Q_OBJECT

public:
    explicit quersyStu(QWidget *parent = 0);
    ~quersyStu();

    // 读取文件
    int readFromFile();

    void doQuert(int index, QString cnt);

    // 展示
    void  disPlay(int row, QStringList subs);

    // 设置表头
    void tableSet();
private slots:
    //  查找按钮点击  on_按钮名字_pressed()可以不用写connect函数，直接触发槽函数。
    void on_btn_search_clicked();

private:
    Ui::quersyStu *ui;
    QList<QString> stu_lines;
    QStandardItemModel * model;
};

#endif // QUERSYSTU_H
