#ifndef A_LISTENER_H
#define A_LISTENER_H

#include "components.h"
#include "statistics.h"

#include "a_simulator.h"

namespace Simulation { namespace Abstract {

class Listener {
protected:
    Statistics *mStats;
    StateFlags mStatesToListen;

    // This function takes a Abstract::Simulation pointer
    virtual void updateStats(const Simulator *s) = 0;

public:
    Listener(Statistics *stats, StateFlags states);
    virtual ~Listener(){}

    // This function takes a Abstract::Simulation pointer
    void update(const Simulator *s);
};

}} // End of Simulation::Abstract namespace

#endif // A_LISTENER_H
