#include "a_simulator.h"

#include <QDebug>

namespace Simulation { namespace Abstract {

Simulator::Simulator()
{
    reset();

    connect(&mSource, &Source::arrival,     [=](){ updateState(State::ARRIVAL); });
    connect(&mQueue, &Queue::queueAccept,   [=](){ updateState(State::QUEUE_ACCEPT); });
    connect(&mQueue, &Queue::queueReject,   [=](){ updateState(State::QUEUE_REJECT); });
    connect(&mQueue, &Queue::empty,         [=](){ updateState(State::QUEUE_EMPTY); });
    connect(&mServer, &Server::service,     [=](){ updateState(State::SERVICE); });
    connect(&mServer, &Server::depart,      [=](){ updateState(State::DEPARTURE); });
}

Simulator::~Simulator(){}

void Simulator::run(int max_iterations){
    reset();
    //for(int i = 0; i < max_iterations; i++){

    mEntities.append(mSource.newArrival());
    mQueue.put(&(mEntities.last()));
    mServer.addToServer(mQueue.pop(), mSource.lastTArrival());

    while(mClock.getDblTime() <= static_cast<double>(max_iterations)){
        mCurrState = State::NONE;
        runSim();
        mStats.addQueueSize(mQueue.size());
    }
    mStats.setClock(mClock);
}

void Simulator::reset(){
    Entity::resetId();

    mClock.reset();
    mCurrState = State::NONE;
    mEntities.clear();
    mQueue.clear();
    mSource.reset();
    mServer.reset();
    mStats.reset();
}

void Simulator::setSourceGenerator(Abstract::Generator *g){
    mSource.setGenerator(g);
}
void Simulator::setServiceGenerator(Abstract::Generator *g){
    mServer.setGenerator(g);
}

void Simulator::updateState(State new_state){
    mStats.incTotal(new_state);

    if(State::SERVICE == new_state){
        mStats.addEntityTimeInQueue(mServer.servingEntity());
    }

    if(State::DEPARTURE == new_state){
        mStats.addEntityServingDuration(mServer.lastEntityServed());
        mStats.addEntityTimeInSystem(mServer.lastEntityServed());
    }

    /*QString state_name;
    switch(new_state){
    case State::ARRIVAL:
        state_name = "arrival";
        break;

    case State::QUEUE_ACCEPT:
        state_name = "queue accept";
        break;

    case State::QUEUE_REJECT:
        state_name = "queue reject";
        break;

    case State::SERVICE:
        state_name = "service";
        break;
    case State::DEPARTURE:
        state_name = "departure";
        break;
    }
    qDebug() << "* event: " << state_name;*/
}

}} // End of namespace
