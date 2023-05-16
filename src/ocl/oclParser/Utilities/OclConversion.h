#ifndef OCLCONVERSION_H
#define OCLCONVERSION_H

#include <any>
#include <ocl/Expressions/OclExpression.hpp>
#include <abstractDataTypes/Bag.hpp>

namespace OclCS {

    class OclParser;
    class OclLexer;
}

namespace ocl {

    class Expression;

}

using namespace std;
using namespace ocl;

namespace Utilities {

    class oclCV {

        public:

            // this method casts any oclExp packed into an std::any into an oclExpression typed variable
            // if there is no oclExp derivate, nullptr will be returned, also for abstract Exp-Classes (except oclExpression)
            static std::shared_ptr<ocl::Expressions::OclExpression> exp2oclExp(std::any exp);

            // extracts all path parts from a given string
            static std::shared_ptr<std::list<std::string>> extractPath(const std::string& pathWithName);

    };

}

#endif