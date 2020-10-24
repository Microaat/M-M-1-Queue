#include "a_server.h"

namespace Simulation { namespace Abstract {

Server::Server(Abstract::Generator *g):
    Template::Generator(g),
    mLastTDepart(0.0),
    mTotalDeparts(0)
{}


bool Server::addToServer(Entity *e, double time){
    if(!isServing() && e != nullptr){
        mTotalDeparts = 0;
        serving(e, time);
        return true;
    }
    return false;
}

int Server::served(double time){
    if(isServing()){
        return removeFromServer(time);
    }

    return 0;
}

}}

