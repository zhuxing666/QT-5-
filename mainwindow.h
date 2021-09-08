#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    // 添加学生 on_按钮名字_pressed()可以不用写connect函数，直接触发槽函数。
    void on_actionAdd_triggered();

    // 显示学生查找 on_按钮名字_pressed()可以不用写connect函数，直接触发槽函数。
    void on_actionQuersy_triggered();

    // 帮助按钮触发
    void on_actionHelp_triggered();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
