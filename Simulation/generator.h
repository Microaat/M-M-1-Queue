#ifndef GENERATORS_H
#define GENERATORS_H

#include "a_generator.h"

#include <random>

namespace Simulation { namespace Generator {

/*!
 * \class FixedRate
 * \brief The FixedRate generator class generates times based on a Poisson mean.
 * The mean does not change each time generate() is called.
 */
class FixedRate : public Abstract::Generator {
    std::exponential_distribution<double> mDistr;

public:
    FixedRate() = default;
    FixedRate(double mean, int seed = 1);
    ~FixedRate(){}

    double mean() const;
    void setDistrParams(double mean, double std_dev = 0.0);

protected:
    double generate();
};


/*!
 * \brief The VariatingRate class is similar to the SimpleGenerator except
 * that the Poisson mean changes each time generate() is called.
 */
class VariatingRate : public Abstract::Generator {
    FixedRate mFixedRate;
    std::normal_distribution<double> mDistr;

public:
    VariatingRate() = default;
    VariatingRate(double mean, double std_dev, int seed = 1);

    void setDistrParams(double mean, double std_dev);
    double mean() const { return mDistr.mean(); }
    double stddev() const { return mDistr.stddev(); }

protected:
    double generate();
};

}} // End of namespace


#endif // GENERATORS_H
