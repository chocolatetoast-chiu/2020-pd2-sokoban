#include "mainwindow.h"
#include <QApplication>
#include "lv1.h"
#include "lv2.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
