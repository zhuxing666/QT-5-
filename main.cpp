#include "mainwindow.h"
#include <QApplication>
#include"addstu.h"
#include"quersystu.h"
#include"about.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    addStu s;
//    s.show();

//    quersyStu q;
//    q.show();

//    about  ab;
//    ab.show();



    return a.exec();
}
