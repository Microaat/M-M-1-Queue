#ifndef RESULTSCHART_H
#define RESULTSCHART_H

#include <QHash>
#include <QSharedPointer>

#include "Simulation/components.h"
#include "Simulation/statistics.h"

#include <QtCharts/QChart>

QT_CHARTS_USE_NAMESPACE

class ResultsChart {
public:
    typedef Simulation::Statistics::HashTotals SetData;

    ResultsChart();
    ResultsChart(const ResultsChart& rc);
    ~ResultsChart(){}
    QChart* getChart();

    void setSet(Simulation::State setname, int value);
    void setSetData(const ResultsChart::SetData& data){ mSets = data; }
    void createChart();

private:
    QSharedPointer<QChart> mChart;
    SetData mSets;

};

/*class ResultsChart {
public:
    enum BarSets {
        ARRIVALS,
        SERVICES,
        DEPARTURES
    };

    ResultsChart();
    QChart* getChart();

    void setSet(BarSets setname, int value);
    void createChart();

private:
    QChart *mChart;
    QHash<BarSets, QBarSet *> mSets;

};*/

#endif // RESULTSCHART_H
