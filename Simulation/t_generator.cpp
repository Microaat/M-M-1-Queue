#include "t_generator.h"

namespace Simulation { namespace Template {

Generator::Generator(Abstract::Generator *g):
    mGenerator(g)
{}

void Generator::setGenerator(Abstract::Generator *g){
    mGenerator.clear();
    mGenerator.reset(g);
}

const Abstract::Generator &Generator::getGenerator() const {
    return *(mGenerator.data());
}
Abstract::Generator &Generator::getGenerator(){
    return *(mGenerator.data());
}

}} // End of namespace
