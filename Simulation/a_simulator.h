#ifndef A_SIMULATOR_H
#define A_SIMULATOR_H

#include "Simulation/a_generator.h"
#include "Simulation/a_listener.h"

#include "Simulation/components.h"
#include "Simulation/clock.h"
#include "Simulation/entity.h"
#include "Simulation/source.h"
#include "Simulation/server.h"
#include "Simulation/queue.h"
#include "Simulation/statistics.h"

#include <QObject>

namespace Simulation { namespace Abstract {

class Simulator : public QObject {
    Q_OBJECT

protected:
    Clock mClock;
    Statistics mStats;
    StateFlags mCurrState;

    Entities mEntities;
    Source mSource;
    Queue mQueue;
    Server mServer;

    virtual void runSim() = 0;
    /*void notifyListeners();
    void addListener(AbstractListener* l);
    void addListeners();*/

public:
    Simulator();
    virtual ~Simulator();

    void run(int max_iterations = 1);
    void run(double duration = 1.0);
    void reset();

    void resetState(){ mCurrState = State::NONE; }
    int currState() const { return mCurrState; }

    void setSourceGenerator(Abstract::Generator *g);
    void setServiceGenerator(Abstract::Generator *g);
    void setQueueMaxSize(int value){ mQueue.setMaxSize(value); }
    void setTimeUnit(TimeUnit tunit){ mClock.setTimeUnit(tunit); }

    // Get Components
    const Entities& entities() const { return mEntities; }
    const Source& source() const { return mSource; }
    const Queue& queue() const { return mQueue; }
    const Statistics& stats() const { return mStats; }

    const Abstract::Generator& sourceGenerator() const { return mSource.getGenerator(); }
    const Abstract::Generator& serverGenerator() const { return mServer.getGenerator(); }
    Abstract::Generator& sourceGenerator(){ return mSource.getGenerator(); }
    Abstract::Generator& serverGenerator(){ return mServer.getGenerator(); }

    //const Abstract::Server& server() const { return dynamic_cast<Abstract::Server>(mServer.data()); }

private slots:
    void updateState(State new_state);
};

}} // End of namespace

#endif // A_SIMULATOR_H
