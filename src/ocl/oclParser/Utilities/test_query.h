#ifndef TEST_QUERY_H
#define TEST_QUERY_H

#include <string>
#include <memory>

#include <ecore/EObject.hpp>

namespace OclCS {

    class OclParser;
    class OclLexer;
}

namespace antlr4 {
    class ANTLRInputStream;
    class CommonTokenStream;
}

using namespace std;
using namespace OclCS;
using namespace antlr4;

namespace Utilities{

    class ts{

        public:

            std::string query(std::string q);

            std::shared_ptr<Any> contextTest(std::string q, std::shared_ptr<Any> context);
 
    };



}

#endif
