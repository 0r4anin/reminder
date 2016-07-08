#include "mainwindow.h"
#include <QApplication>
#include <reminder.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Reminder r;
    MainWindow w(&r);
//    w.show();

    return a.exec();
}
