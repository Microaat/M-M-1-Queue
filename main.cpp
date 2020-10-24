#include "mainwindow.h"
#include "multiqueuewindow.h"

#include <QApplication>

#include <QSharedPointer>
#include <QList>
#include <QFile>
#include <QDir>
#include <QDebug>

#include <QSaveFile>

#include "controller.h"
#include "mm1_model.h"
#include "Simulation/all.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Controller c;
    c.init();

    //return 1;
    return a.exec();
}
