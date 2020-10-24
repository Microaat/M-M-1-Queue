#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QSharedPointer>

#include "mainwindow.h"
#include "mm1_model.h"
#include "Simulation/components.h"

class Controller : public QObject {
    Q_OBJECT

    MainWindow mMainWindow;
    MM1_model mModel;
    Simulation::TimeUnit intToTimeUnit(int value) const;

public:
    explicit Controller(QObject *parent = nullptr);
    void init();

signals:
    // This signals the GUI that the simulation is done.
    void simulationDone();

public slots:
    void runSimulation();
    void calStats();

};

#endif // CONTROLLER_H
