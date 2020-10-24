#ifndef A_GENERATOR_H
#define A_GENERATOR_H

#include "Simulation/components.h"

#include <QRandomGenerator>

namespace Simulation { namespace Abstract {

/*!
 * \class AbstractGenerator
 * \brief Any generator that generates time for the simulation should inherit
 * this class.
 */
class Generator {
protected:
    QRandomGenerator mGenerator;
    double mLastGenValue;

    virtual double generate() = 0;

public:
    Generator(int seed = 1):
        mGenerator(seed),
        mLastGenValue(0.0)
    {}

    virtual ~Generator(){}
    void setSeed(int s){ mGenerator.seed(s); }

    // Setters
    virtual void setDistrParams(double mean, double std_dev = 0) = 0;

    // Getters
    virtual double mean() const { return 0.0; }
    virtual double stddev() const { return 0.0; }

    double lastGenValue() const { return mLastGenValue; }
    double newValue(){ return mLastGenValue = generate(); }
};

}} // End of Simulation::Abstract namespace

#endif // A_GENERATOR_H
