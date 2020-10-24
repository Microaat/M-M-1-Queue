#include "server.h"

#include <QtGlobal>

namespace Simulation {

Server::Server(Abstract::Generator *g, QObject *parent):
    QObject(parent),
    Template::Generator(g),
    mEntity(nullptr),
    mLastEntity(nullptr)
{
    setObjectName("server");
}

bool Server::addToServer(Entity *e, double time){
    if(!isServing() && e != nullptr){
        mEntity = e;
        mEntity->setTService(time);
        mEntity->setTDepart(time + mGenerator->newValue());

        emit service();
        return true;
    }

    return false;
}

bool Server::served(double time){
    if(isServing() && mEntity->getTDepart() <= time){
        mLastEntity = mEntity;
        mEntity = nullptr;

        emit depart();
        return true;
    }

    return false;
}

bool Server::isServing() const {
    if(mEntity == nullptr) return false;
    return true;
}

const Entity &Server::servingEntity() const {
    return (*mEntity);
}

const Entity &Server::lastEntityServed() const {
    return (*mLastEntity);
}

double Server::lastTDepart() const {
    if(mLastEntity == nullptr) return 0.0;
    return mLastEntity->getTDepart();
}
double Server::nextTDepart() const {
    return (mEntity == nullptr)?
        qInf() : mEntity->getTDepart();
}

void Server::reset(){
    mLastEntity = nullptr;
    mEntity = nullptr;
}



/*namespace Server {

Single::Single(Abstract::Generator *g):
    Abstract::Server(g),
    mEntity(nullptr)
{}

void Single::serving(Entity *e, double time){
    mEntity = e;
    mEntity->setTService(time);
    mEntity->setTDepart(time + mGenerator->newValue());
}

int Single::removeFromServer(double time){
    if(mEntity->getTDepart() <= time){
        mEntity = nullptr;
        mLastTDepart = time;
        return mTotalDeparts = 1;
    }
}

bool Single::isServing() const {
    if(mEntity == nullptr) return false;
    return true;
}

void Single::reset(){
    mEntity = nullptr;
    mLastTDepart = 0.0;
    mTotalDeparts = 0;
}

}*/} // End of namespace
