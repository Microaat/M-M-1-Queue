#include "generator.h"

#include <QDebug>

namespace Simulation { namespace Generator {

// FixedRate
FixedRate::FixedRate(double mean, int seed):
    Abstract::Generator(seed)
{
    setDistrParams(mean);
}

double FixedRate::mean() const {
    return mDistr.lambda();
}
void FixedRate::setDistrParams(double mean, double std_dev){
    mDistr.param(std::exponential_distribution<double>::param_type(mean));
}

double FixedRate::generate(){
    return mDistr(mGenerator);
}


// VariatingRate
VariatingRate::VariatingRate(double mean, double std_dev, int seed):
    Abstract::Generator(seed)
{
    setDistrParams(mean, std_dev);
}
void VariatingRate::setDistrParams(double mean, double std_dev){
    mDistr.param(std::normal_distribution<double>::param_type(mean, std_dev));
}

double VariatingRate::generate(){
    auto mean = mDistr(mGenerator);
    mean = (mean < 0.0)? 0.0 : mean;

    mFixedRate.setDistrParams(mean);
    return mFixedRate.newValue();
}

}} // End of namespace
