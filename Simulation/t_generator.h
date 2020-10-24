#ifndef T_GENERATOR_H
#define T_GENERATOR_H

#include "a_generator.h"

#include <QSharedPointer>

namespace Simulation { namespace Template {

class Generator {
protected:
    QSharedPointer<Abstract::Generator> mGenerator;

public:
    Generator(Abstract::Generator *g = nullptr);
    virtual ~Generator(){}

    void setGenerator(Abstract::Generator *g);
    const Abstract::Generator& getGenerator() const;
    Abstract::Generator& getGenerator();
};

}} // End of Simulation namespace

#endif // T_GENERATOR_H
