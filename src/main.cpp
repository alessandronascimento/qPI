#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication qPI(argc, argv);
    MainWindow* main = new MainWindow;

    qPI.setApplicationName("qPI");

    main->show();
    return qPI.exec();
}
