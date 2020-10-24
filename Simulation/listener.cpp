#include "listener.h"

#include <QDebug>

namespace Simulation { namespace Listener {

Arrival::Arrival(Statistics *stats):
    Abstract::Listener(stats, State::ARRIVAL)
{}
void Arrival::updateStats(const Abstract::Simulator *s){
    mStats->incTotal(State::ARRIVAL);
}


Service::Service(Statistics *stats):
    Abstract::Listener(stats, State::ARRIVAL)
{}
void Service::updateStats(const Abstract::Simulator *s){
    mStats->incTotal(State::SERVICE);
}


Departure::Departure(Statistics *stats):
    Abstract::Listener(stats, State::ARRIVAL)
{}
void Departure::updateStats(const Abstract::Simulator *s){
    mStats->incTotal(State::DEPARTURE);
}


QueuePosDuration::QueuePosDuration(Statistics *stats):
    Abstract::Listener(stats, State::ARRIVAL | State::SERVICE)
{}
void QueuePosDuration::updateStats(const Abstract::Simulator *s){
    if(State::ARRIVAL & s->currState()) qDebug() << "Arrival";
    else qDebug() << "Service";
}


}} // End of namespace
