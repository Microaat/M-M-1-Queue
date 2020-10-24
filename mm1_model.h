#ifndef MM1_MODEL_H
#define MM1_MODEL_H

#include "Simulation/simulator.h"

#include <QSharedPointer>

class QStringList;

class MM1_model {
    QSharedPointer<Simulation::Abstract::Simulator> mSimulator;

    double mLambda;
    double mLambda_Stddev;
    int mLambda_Pop;
    double mMu;
    double mMu_StdDev;
    int mMu_Pop;

public:
    MM1_model();
    ~MM1_model();

    // Setters
    void setLambda(double lambda){ mLambda = lambda; }
    void setLambdaStdDev(double std_dev){ mLambda_Stddev = std_dev; }
    void setLambdaPop(int pop){ mLambda_Pop = pop; }

    void setMu(double mu){ mMu = mu; }
    void setMuStdDev(double std_dev){ mMu_StdDev = std_dev; }
    void setMuPop(int pop){ mMu_Pop = pop; }

    // Getters
    double getLambda() const { return mLambda; }
    double getMu() const { return mMu; }

    // Runs the simulation and returns the results as a QStringList.
    const Simulation::Abstract::Simulator* runSimFixedRates(int max_iterations, int queue_size = -1, int seed = 1);
    const Simulation::Abstract::Simulator* runSimVarRates(int max_iterations, int queue_size = -1, int seed = 1);

    // Returns the average utilization of the service system (commonly denoted as rho).
    double meanUtilization() const { return mLambda / mMu; }

    // Returns the average amount of items in the system being handled by the queue.
    double meanAmountInSystem() const { return meanUtilization() / (1 - meanUtilization()); }

    // Returns the average time spent in the system.
    double meanTimeInSystem() const { return 1.0 / (mMu - mLambda); }

    // Returns the average size of the queue.
    double meanQueueSize() const { return mLambda * meanWaitingTime(); }

    // Returns the average waiting time which is the time spent in the queue.
    double meanWaitingTime() const { return mLambda / (mMu*(mMu - mLambda)); }
};

#endif // MM1_MODEL_H
