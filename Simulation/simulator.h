#ifndef SIMULATION_H
#define SIMULATION_H

#include "mm1queue.h"
#include "Simulation/a_simulator.h"
#include "Simulation/server.h"

#include <QSharedPointer>

namespace Simulation { namespace Simulator {

class Simple : public Abstract::Simulator {
protected:
    /*void notifyListeners();
    void addListener(AbstractListener* l);
    void addListeners();*/
    void runSim();

public:
    Simple(): Abstract::Simulator(){}
};


}} // End of Simulation Namespace

#endif // SIMULATION_H
