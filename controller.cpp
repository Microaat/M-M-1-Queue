#include "controller.h"

#include "Widgets/resultschart.h"

#include <QList>
#include <QStringList>
#include <QDebug>
#include <cmath>

Controller::Controller(QObject *parent) :
    QObject(parent)
{
    connect(&mMainWindow, SIGNAL(run()), this, SLOT(runSimulation()));
    //connect(&mMainWindow, SIGNAL())
}

void Controller::init(){
    mMainWindow.show();
}

void Controller::runSimulation(){
    const Simulation::Abstract::Simulator *sim;
    int seed = mMainWindow.getRandSeed();
    int max_iter = mMainWindow.getMaxIterations();
    int queue_size = mMainWindow.getQueueSize();

    Simulation::TimeUnit tunit = intToTimeUnit(mMainWindow.getTimeUnit());
    MainWindow::Tab currTab = mMainWindow.getTab();

    if(currTab == MainWindow::Tab::FIXED_RATE){
        mModel.setLambda(mMainWindow.getLambda());
        mModel.setMu(mMainWindow.getMu());
        sim = mModel.runSimFixedRates(max_iter, queue_size, seed);
    }
    else {
        mModel.setLambda(mMainWindow.getLambdaMean());
        mModel.setLambdaStdDev(mMainWindow.getLambdaStdDev());
        mModel.setLambdaPop(mMainWindow.getLambdaPop());

        mModel.setMu(mMainWindow.getMuMean());
        mModel.setMuStdDev(mMainWindow.getMuStdDev());
        mModel.setMuPop(mMainWindow.getMuPop());

        sim = mModel.runSimVarRates(max_iter, queue_size, seed);
    }

    const Simulation::Entities entities = sim->entities();
    const Simulation::Statistics stats = sim->stats();


    mMainWindow.clearResults();
    mMainWindow.setChartData(stats.getTotals());

    mMainWindow.setSimTotals(
                stats.getTotal(Simulation::State::ARRIVAL),
                stats.getTotal(Simulation::State::QUEUE_ACCEPT),
                stats.getTotal(Simulation::State::QUEUE_REJECT),
                stats.getTotal(Simulation::State::SERVICE),
                stats.getTotal(Simulation::State::DEPARTURE),
                stats.getTotalQueueSize(),
                stats.getTotal(Simulation::State::QUEUE_EMPTY)
    );
    mMainWindow.setSimTimeTotals(
                stats.getTotalTimeInSystem(),
                stats.getTotalTimeInQueue(),
                stats.getTotalServingDuration()
    );
    mMainWindow.setSimAvg(
                stats.getMeanQueueSize(),
                stats.getMeanTimeInQueue(),
                stats.getMeanServingDuration(),
                stats.getMeanTimeInSystem()
    );

    QStringList str_entities;
    for(auto iter = entities.cbegin(); iter != entities.cend(); ++iter){
        str_entities.clear();
        str_entities << QString::number(iter->getId())
                     << (iter->getQueueAccepted()? "True" : "False")
                     << QString::number(iter->getTArrival())
                     << QString::number(iter->getTService())
                     << QString::number(iter->getTDepart())
                     << QString::number(iter->totalWaitTime());

        mMainWindow.addRowResultTable(str_entities);
    }

    emit simulationDone();
}
void Controller::calStats(){

}

Simulation::TimeUnit Controller::intToTimeUnit(int value) const {
    switch(value){
    case 0: return Simulation::SECONDS;
    case 1: return Simulation::MINUTES;
    case 2: return Simulation::HOURS;
    }

    return Simulation::SECONDS;
}
