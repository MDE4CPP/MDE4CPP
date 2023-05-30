// ####################################################################################### //
// currently this is a dummy for the non existing implementation of Ocl for UML in MDE4CPP //
// ####################################################################################### //

#ifndef OCLUML_H
#define OCLUML_H

#include <memory>
#include <string>

#include "OCLInterface.h"

#include <abstractDataTypes/Any.hpp>

namespace antlr4 {
    class ANTLRInputStream;
    class CommonTokenStream;
} // namespace antlr4

namespace OclCS
{
    class OclLexer;
    class OclParser;
    
} // namespace OclCS

// namespace Eval {
//     class UMLEval;
//     class UMLEnvironment;
// }

using namespace antlr4;
using namespace OclCS;

namespace Utilities
{
    
    class OclUml: public OCLInterface
    {   
        public:
        OclUml();
        virtual ~OclUml();

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

        // Uml Environment
        //std::shared_ptr<Eval::UMLEnvironment> m_env;
        //context element is in OCLInterface
        // std::shared_ptr<Any> context;
    };
    
} // namespace Utilities

#endif