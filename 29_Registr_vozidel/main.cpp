#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    class Pepa{
    public:
        Pepa(){};
    };

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
