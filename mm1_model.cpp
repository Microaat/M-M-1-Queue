#include "mm1_model.h"

#include "Simulation/generator.h"

MM1_model::MM1_model():
    mSimulator(new Simulation::Simulator::Simple),
    mLambda(0.0),
    mLambda_Stddev(0.0),
    mLambda_Pop(1),
    mMu(0.0),
    mMu_StdDev(0.0),
    mMu_Pop(1)
{}

MM1_model::~MM1_model(){

}

const Simulation::Abstract::Simulator *MM1_model::runSimFixedRates(int max_iterations, int queue_size, int seed){
    mSimulator->setSourceGenerator(new Simulation::Generator::FixedRate(mLambda, seed));
    mSimulator->setServiceGenerator(new Simulation::Generator::FixedRate(mMu, seed));

    //mSimulator->sourceGenerator().setSeed(seed);
    //mSimulator->serverGenerator().setSeed(seed);
    mSimulator->setQueueMaxSize(queue_size);
    mSimulator->run(max_iterations);

    return mSimulator.data();
}

const Simulation::Abstract::Simulator *MM1_model::runSimVarRates(int max_iterations, int queue_size, int seed){
    mSimulator->setSourceGenerator(
        new Simulation::Generator::VariatingRate(mLambda, mLambda_Stddev/std::sqrt(mLambda_Pop))
    );
    mSimulator->setServiceGenerator(
        new Simulation::Generator::VariatingRate(mMu, mMu_StdDev/std::sqrt(mMu_Pop))
    );

    mSimulator->sourceGenerator().setSeed(seed);
    mSimulator->serverGenerator().setSeed(seed);
    mSimulator->setQueueMaxSize(queue_size);
    mSimulator->run(max_iterations);

    return mSimulator.data();
}
