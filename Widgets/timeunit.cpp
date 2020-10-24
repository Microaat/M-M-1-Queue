#include "timeunit.h"

namespace Widget {


TimeUnit::TimeUnit(bool shortnames, QWidget *parent):
    QComboBox(parent),
    mShortName(shortnames)
{

    createNames();
}

void TimeUnit::shortenNames(bool value){
    mShortName = value;
    createNames();
}

void TimeUnit::addShortNames(){
    addItem("secs", Simulation::TimeUnit::SECONDS);
    addItem("mins", Simulation::TimeUnit::SECONDS);
    addItem("hrs", Simulation::TimeUnit::SECONDS);
}

void TimeUnit::addLongNames(){
    addItem("seconds", Simulation::TimeUnit::SECONDS);
    addItem("minutes", Simulation::TimeUnit::SECONDS);
    addItem("hours", Simulation::TimeUnit::SECONDS);
}

void TimeUnit::createNames(){
    clear();
    if(mShortName) addShortNames();
    else addLongNames();



    setCurrentIndex(1);
}


} // End of namespace
