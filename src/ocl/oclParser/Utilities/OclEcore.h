#ifndef OCLECORE_H
#define OCLECORE_H

#include <memory>
#include <string>

#include "OCLInterface.h"

#include <abstractDataTypes/Any.hpp>
#include <ecore/EObject.hpp>

namespace antlr4 {
    class ANTLRInputStream;
    class CommonTokenStream;
} // namespace antlr4

namespace OclCS
{
    class OclLexer;
    class OclParser;
    
} // namespace OclCS

namespace Eval {
    class EcoreEval;
    class EcoreEnvironment;
}

using namespace antlr4;
using namespace OclCS;

namespace Utilities
{
    
    class OclEcore: public OCLInterface
    {   
        public:
        OclEcore();
        virtual ~OclEcore();

        //TODO add an SyntaxError Check
        //bool checkSyntax(const std::string& oclStr);

        // query an OCL Expression on an given Model
        std::shared_ptr<Any> query(const std::string& oclStr, std::shared_ptr<Any> context);

        // query an OCL Expression on an given Model
        // with extra Debug Info
        std::shared_ptr<Any> debugQuery(const std::string& oclStr, std::shared_ptr<Any> context);

        private:

        // antlr4 parsing of OCL Input
        void parse(const std::string& oclStr);

        // antlr4 parsing stuff
        antlr4::ANTLRInputStream* m_stream = nullptr;
        antlr4::CommonTokenStream* m_tokens = nullptr;
        OclCS::OclParser* m_parser = nullptr;
        OclCS::OclLexer* m_lexer = nullptr;

        // Ecore Environment
        std::shared_ptr<Eval::EcoreEnvironment> m_env;
        //context element is in OCLInterface
        // std::shared_ptr<Any> context;
    };
    
    

} // namespace Utilities


#endif