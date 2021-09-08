#include "quersystu.h"
#include "ui_quersystu.h"
#include<QIODevice>
#include<QTextStream>
#include<QDebug>
#include<QStringList>
#include<QMessageBox>
#include<QSound>

quersyStu::quersyStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::quersyStu)
{
    ui->setupUi(this);
    //窗口一调用就读取数据
    if(readFromFile() == -1){
        QMessageBox::critical(this,"错误","文件打开失败，请重试","确认");
        this->close();
    }
    //new出表格
    this->model = new QStandardItemModel;
    //设置表头，并调整单元格宽度
    tableSet();


}

quersyStu::~quersyStu()
{
    delete ui;
}
  //  查找按钮点击  on_按钮名字_pressed()可以不用写connect函数，直接触发槽函数。
void quersyStu::on_btn_search_clicked()
{

    //每次查询完会清空model，但是会把表头也会清空
    this->model->clear();
    //每次清空完后要设置一下表头
    //设置表头
    tableSet();
    //index下拉框的下标
    int index = this->ui->cbb_method->currentIndex();
    //要搜索的数据
    QString cnt = this->ui->le_cnt->text();
    // 调用查询显示函数
    doQuert(index,cnt);
}

// 读取文件
int quersyStu::readFromFile()
{
   QFile file("student.txt");
   if(!file.open(QIODevice::ReadOnly | QIODevice ::Text))
       return -1;
   QTextStream in(&file);
   while(!in.atEnd())
   {
       QString line = in.readLine();
       //每一行的信息分别存入QList<QString>类型的stu_lines变量中。每一行信息作为单独的选项。
       stu_lines.append(line);
   }
   file.close();

   //确信文件已经保存到stu_lines里区了,将数据打印到应用程序输出终端
   int i = 0;
   for(i = 0;i < stu_lines.length();i++){
       qDebug() << stu_lines.at(i);
   }

   return 0;

}

//遍历容器中的每一条字符串，对每条字符串进行分隔，让其对比
void quersyStu::doQuert(int index, QString cnt)
{

    int i = 0;
    int row = 0;
    for(i = 0; i < stu_lines.length(); i++)
    {
        QString line = stu_lines.at(i);
        //trimmed()函数如果一个字符串开头或结尾有空白，那么会将空白去掉
        line = line.trimmed();
        QStringList subs = line.split(" ");
        switch (index) {
        case 1:
            if(cnt == subs.at(0))
            {
                disPlay(row++,subs);
            }
        case 2:
            if(cnt == subs.at(1)){
                disPlay(row++,subs);
            }
            break;
        case 3:
            if(cnt == subs.at(4)){
                disPlay(row++,subs);
            }

            break;
        default:
            break;
        }
    }

}

// 展示
void  quersyStu::disPlay(int row, QStringList subs)
{

    int i = 0;
    for(i = 0;i < 5;i++){
        //设置普通的单元格setItem(),row表示行，i表示列
        this->model->setItem(row,i,new QStandardItem(subs.at(i)));
    }
    QString ins;
    for(i = 5;i < subs.length();i++){
        ins += subs.at(i) + ",";
    }
    this->model->setItem(row,5,new QStandardItem(ins));
}

// 设置表头
void quersyStu::tableSet()
{

    //设置表头第0列
    this->model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    //设置表头第1列
    this->model->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("性别"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("年龄"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("院系"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("基础技能"));
    //将当前表格模型绑定到view
    this->ui->tableView->setModel(model);
    //调整各列单元格宽度
    this->ui->tableView->setColumnWidth(0,100);
    this->ui->tableView->setColumnWidth(1,150);
    this->ui->tableView->setColumnWidth(2,50);
    this->ui->tableView->setColumnWidth(3,50);
    this->ui->tableView->setColumnWidth(4,100);
    this->ui->tableView->setColumnWidth(5,150);
}
