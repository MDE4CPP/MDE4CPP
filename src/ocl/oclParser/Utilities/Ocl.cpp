#include "Ocl.h" 

#include <memory>
#include <any>


#include <ocl/Expressions/ExpressionInOcl.hpp>
#include <ecore/EcoreAny.hpp>

#include "../OclCS/OclParser.h"
#include "../OclCS/OclLexer.h"
#include "../OclCS/OclParserCustomVisitor.h"
#include "../Eval/EcoreEval.h"
#include "../Eval/EcoreEnvironment.h"


#include <ANTLRInputStream.h>
#include <CommonTokenStream.h>

using namespace Utilities;
using namespace OclCS;
using namespace antlr4;
using namespace Eval;

Ocl::Ocl()
{
    m_stream = new antlr4::ANTLRInputStream();
    m_lexer = new OclCS::OclLexer(m_stream);
    m_tokens = new antlr4::CommonTokenStream(m_lexer);
    m_parser = new OclCS::OclParser(m_tokens);

    m_lexer->removeErrorListeners();
    m_parser->removeErrorListeners();

    // TODO use error listener
    //m_lexer->addErrorListener(...);
    //m_parser->addErrorListener(...);
}

Ocl::~Ocl()
{
    if (m_parser != nullptr) {
        delete(m_parser);
        m_parser = nullptr;
    }
    if (m_tokens != nullptr) {
        delete(m_tokens);
        m_tokens = nullptr;
    }

    if (m_stream != nullptr) {
        delete(m_stream);
        m_stream = nullptr;
    }
    m_env=nullptr;
}

void Ocl::parse(const std::string& oclStr) {

    m_stream->load(oclStr);
    m_lexer->setInputStream(m_stream);
    m_tokens->setTokenSource(m_lexer);
    m_parser->setTokenStream(m_tokens);

}

//TODO add an SyntaxError Check
// bool checkSyntax(const std::string& oclStr) {

//     parse(oclText);
//     m_parser->expressionInOclCS();
//     return false;

// }


//TODO check if Ecore or UML Model
//currently only Ecore is supported
std::shared_ptr<Any> Ocl::query(const std::string& oclStr, std::shared_ptr<Any> context) {

    // antlr4 parsing of input
    parse(oclStr);

    // environment creation for Ecore
    m_env = std::make_shared<Eval::EcoreEnvironment>(Eval::EcoreEnvironment(nullptr, context));

    
    // get the root node from antlr4 parsing
    OclCS::OclParser::ExpressionInOclCSContext* m_root = m_parser->expressionInOclCS();
    //m_root->setErrorListener(...);

    // create abstract Syntax Tree
    OclCS::OclParserCustomVisitor visitor;
    std::any returnTree = visitor.visit(dynamic_cast<antlr4::ParserRuleContext*>(m_root));
    //TODO check errors

    // create evaluation Environment for Ecore
    Eval::EcoreEval testEval(m_env);

    // try to cast abstract Syntax Tree
    std::shared_ptr<ocl::Expressions::ExpressionInOcl> rootNode = nullptr;
    if (returnTree.type() == typeid(std::shared_ptr<ocl::Expressions::ExpressionInOcl>)) {
        rootNode = std::any_cast<std::shared_ptr<ocl::Expressions::ExpressionInOcl>>(returnTree);
    } else {
        throw("Error: Return of Syntax Check is no ExpressionInOcl.");
        return nullptr;
    }
    
    // do the query on the actual model
    std::shared_ptr<Any> qryInput = eEcoreAny<std::shared_ptr<ocl::Expressions::ExpressionInOcl>>(rootNode, rootNode->getMetaElementID());
    //TODO check errors
    return testEval.visitNode(qryInput);

}

// query an OCL Expression on an given Model
// with extra Debug Info
std::shared_ptr<Any> Ocl::debugQuery(const std::string& oclStr, std::shared_ptr<Any> context) {

    // antlr4 parsing of input
    parse(oclStr);

    // environment creation for Ecore
    m_env = std::make_shared<Eval::EcoreEnvironment>(Eval::EcoreEnvironment(nullptr, context));

    // get the root node from antlr4 parsing
    OclCS::OclParser::ExpressionInOclCSContext* m_root = m_parser->expressionInOclCS();
    //m_root->setErrorListener(...);

    // create abstract Syntax Tree
    OclCS::OclParserCustomVisitor visitor;
    std::any returnTree = visitor.visit(dynamic_cast<antlr4::ParserRuleContext*>(m_root));
    //TODO check errors

    if (m_root != nullptr) {
        // additional info: Parse Tree
        std::cout << "ParseTree: " << m_root->toStringTree() << std::endl;
    } else {
        throw("Error: Root node is nullptr!");
    }

    // create evaluation Environment for Ecore
    Eval::EcoreEval testEval(m_env);

    // try to cast abstract Syntax Tree
    std::shared_ptr<ocl::Expressions::ExpressionInOcl> rootNode = nullptr;
    if (returnTree.type() == typeid(std::shared_ptr<ocl::Expressions::ExpressionInOcl>)) {
        rootNode = std::any_cast<std::shared_ptr<ocl::Expressions::ExpressionInOcl>>(returnTree);
    } else {
        throw("Error: Return of Syntax Check is no ExpressionInOcl.");
        return nullptr;
    }
    
    // do the query on the actual model
    std::shared_ptr<Any> qryInput = eEcoreAny<std::shared_ptr<ocl::Expressions::ExpressionInOcl>>(rootNode, rootNode->getMetaElementID());
    //TODO check errors
    return testEval.visitNode(qryInput);

}
