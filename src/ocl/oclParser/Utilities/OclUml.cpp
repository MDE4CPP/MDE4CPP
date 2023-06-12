// ####################################################################################### //
// currently this is a dummy for the non existing implementation of Ocl for UML in MDE4CPP //
// ####################################################################################### //

#include "OclUml.h" 

#include <memory>
#include <any>


#include <ocl/Expressions/ExpressionInOcl.hpp>
// #include <uml/UmlAny.hpp>

#include "../OclCS/OclParser.h"
#include "../OclCS/OclLexer.h"
#include "../OclCS/OclParserCustomVisitor.h"
// #include "../Eval/UmlEval.h"
// #include "../Eval/UmlEnvironment.h"


#include <ANTLRInputStream.h>
#include <CommonTokenStream.h>

using namespace Utilities;
using namespace OclCS;
using namespace antlr4;
// using namespace Eval;

OclUml::OclUml()
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

OclUml::~OclUml()
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
    // m_env=nullptr;
}

void OclUml::parse(const std::string& oclStr) {

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


std::shared_ptr<Any> OclUml::query(const std::string& oclStr, std::shared_ptr<Any> context) {

    // setContext(context);
    
    // // antlr4 parsing of input
    // parse(oclStr);

    // // get the root node from antlr4 parsing
    // OclCS::OclParser::ExpressionInOclCSContext* m_root = m_parser->expressionInOclCS();
    // //m_root->setErrorListener(...);

    // // create abstract Syntax Tree
    // OclCS::OclParserCustomVisitor visitor;
    // std::any returnTree = visitor.visit(dynamic_cast<antlr4::ParserRuleContext*>(m_root));
    // //TODO check errors

    // // environment creation for Uml
    // // m_env = std::make_shared<Eval::UmlEnvironment>(Eval::UmlEnvironment(nullptr, context));

    // // create evaluation Environment for Uml
    // // Eval::UmlEval eval(m_env);

    // // try to cast abstract Syntax Tree
    // std::shared_ptr<ocl::Expressions::ExpressionInOcl> rootNode = nullptr;
    // if (returnTree.type() == typeid(std::shared_ptr<ocl::Expressions::ExpressionInOcl>)) {
    //     rootNode = std::any_cast<std::shared_ptr<ocl::Expressions::ExpressionInOcl>>(returnTree);
    // } else {
    //     throw("Error: Return of Syntax Check is no ExpressionInOcl.");
    //     return nullptr;
    // }
    
    // // do the query on the actual model
    // // std::shared_ptr<Any> qryInput = umlAny<std::shared_ptr<ocl::Expressions::ExpressionInOcl>>(rootNode, rootNode->getMetaElementID());
    // //TODO check errors
    // return eval.visitNode(qryInput);

}

// query an OCL Expression on an given Model
// with extra Debug Info
std::shared_ptr<Any> OclUml::debugQuery(const std::string& oclStr, std::shared_ptr<Any> context) {

    // setContext(context);
    
    // // antlr4 parsing of input
    // parse(oclStr);

    // // get the root node from antlr4 parsing
    // OclCS::OclParser::ExpressionInOclCSContext* m_root = m_parser->expressionInOclCS();
    // //m_root->setErrorListener(...);

    // // create abstract Syntax Tree
    // OclCS::OclParserCustomVisitor visitor;
    // std::any returnTree = visitor.visit(dynamic_cast<antlr4::ParserRuleContext*>(m_root));
    // //TODO check errors

    // if (m_root != nullptr) {
    //     // additional info: Parse Tree
    //     std::cout << "ParseTree: " << m_root->toStringTree() << std::endl;
    // } else {
    //     throw("Error: Root node is nullptr!");
    // }

    // // environment creation for Uml
    // // m_env = std::make_shared<Eval::UmlEnvironment>(Eval::UmlEnvironment(nullptr, context));

    // // create evaluation Environment for Uml
    // // Eval::UmlEval eval(m_env);

    // // try to cast abstract Syntax Tree
    // std::shared_ptr<ocl::Expressions::ExpressionInOcl> rootNode = nullptr;
    // if (returnTree.type() == typeid(std::shared_ptr<ocl::Expressions::ExpressionInOcl>)) {
    //     rootNode = std::any_cast<std::shared_ptr<ocl::Expressions::ExpressionInOcl>>(returnTree);
    // } else {
    //     throw("Error: Return of Syntax Check is no ExpressionInOcl.");
    //     return nullptr;
    // }
    
    // // do the query on the actual model
    // // std::shared_ptr<Any> qryInput = umlAny<std::shared_ptr<ocl::Expressions::ExpressionInOcl>>(rootNode, rootNode->getMetaElementID());
    // //TODO check errors
    // return eval.visitNode(qryInput);

}
