#include "resultschart.h"

#include <QDebug>
#include <QList>
#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QCategoryAxis>


ResultsChart::ResultsChart():
    mChart(new QChart)
{
    mChart->setTitle("Simulation Result Totals");
    mChart->legend()->hide();
    mChart->setAnimationOptions(QChart::SeriesAnimations);
    mChart->legend()->setVisible(true);
    mChart->legend()->setAlignment(Qt::AlignBottom);
}

void ResultsChart::setSet(Simulation::State setname, int value){
    mSets[setname] = value;
}

void ResultsChart::createChart(){
    mChart->removeAllSeries();

    if(mChart->axisX() != nullptr){
        mChart->removeAxis(mChart->axisX());
    }

    QList<QBarSet *> sets;
    sets << (new QBarSet("Arrivals"))
         << (new QBarSet("Departures"))
         //<< (new QBarSet("Serviced"))
         << (new QBarSet("Arrivals Accepted"))
         << (new QBarSet("Arrivals Rejected"))
         << (new QBarSet("Queue Empty"));

    *(sets[0]) << mSets[Simulation::State::ARRIVAL];
    *(sets[1]) << mSets[Simulation::State::DEPARTURE];
    //*(sets[2]) << mSets[Simulation::State::SERVICE];
    *(sets[2]) << mSets[Simulation::State::QUEUE_ACCEPT];
    *(sets[3]) << mSets[Simulation::State::QUEUE_REJECT];
    *(sets[4]) << mSets[Simulation::State::QUEUE_EMPTY];

    QBarSeries *series = new QBarSeries();
    for(auto iter = sets.begin(); iter != sets.end(); ++iter){
        series->append(*iter);
    }

    mChart->addSeries(series);
    mChart->createDefaultAxes();

    QBarCategoryAxis *xaxis = new QBarCategoryAxis();
    xaxis->append(" ");
    mChart->setAxisX(xaxis);
}

QChart *ResultsChart::getChart(){ return mChart.data(); }

/*ResultsChart::ResultsChart():
    mChart(new QChart)
{
    mSets[ARRIVALS] = new QBarSet("Total Arrivals");
    mSets[DEPARTURES] = new QBarSet("Total Departures");
    mSets[SERVICES] = new QBarSet("Total Serviced");

    QBarSeries *series = new QBarSeries();
    for(auto iter = mSets.begin(); iter != mSets.end(); ++iter){
        series->append(iter.value());
    }

    mChart->setTitle("Simulation Results");
    mChart->legend()->hide();
    mChart->addSeries(series);
    mChart->createDefaultAxes();
    mChart->setAnimationOptions(QChart::SeriesAnimations);
    mChart->legend()->setVisible(true);
    mChart->legend()->setAlignment(Qt::AlignBottom);

    QBarCategoryAxis *xaxis = new QBarCategoryAxis();
    xaxis->append(" ");
    mChart->setAxisX(xaxis);

    QAbstractAxis *yaxis = mChart->axisY();
    yaxis->setRange(0, 10);
    yaxis->setTitleText("Totals");


}

QChart *ResultsChart::getChart(){
    return mChart;
}

void ResultsChart::setSet(ResultsChart::BarSets setname, int value){
    mSets[setname]->remove(0);
    *(mSets[setname]) << value;
}

void ResultsChart::createChart(){
    QBarCategoryAxis *axisx = new QBarCategoryAxis();
    if(mChart->axisX() != nullptr) delete mChart->axisX();
    axisx->append(" ");
    mChart->setAxisX(axisx);
}*/
