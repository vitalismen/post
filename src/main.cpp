#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QSplashScreen>
#include "settings.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen splash(QPixmap(":/images/st0.png"));
    settings::getInatance();
    splash.show();
    MainWindow w;
    splash.finish(&w);
    w.show();
    return a.exec();
}
