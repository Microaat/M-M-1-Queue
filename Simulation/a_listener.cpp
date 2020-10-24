#include "a_listener.h"

namespace Simulation { namespace Abstract {

Listener::Listener(Statistics *stats, StateFlags states):
    mStats(stats),
    mStatesToListen(states)
{}

void Listener::update(const Simulator *s){
    //if(mStatesToListen & s->currState())
    updateStats(s);
}

}} // End of namespace
