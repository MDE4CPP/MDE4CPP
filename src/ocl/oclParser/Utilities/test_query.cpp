#include <istream>
#include <vector>
#include <string>
#include <typeinfo>

#include "test_query.h" 

#include <ocl/Expressions/ExpressionInOcl.hpp>
#include <ecore/EcoreAny.hpp>

#include "../OclCS/OclParser.h"
#include "../OclCS/OclLexer.h"
#include "../OclCS/OclParserCustomVisitor.h"
#include "../Eval/EcoreEval.h"
#include "../Eval/EcoreEnvironment.h"

//#include "Environment.h"
//#include "EnvironmentFactory.h"

#include <ANTLRInputStream.h>
#include <CommonTokenStream.h>

using namespace Utilities;
using namespace OclCS;

std::string ts::query(std::string q) {


    //creating

    antlr4::ANTLRInputStream* m_stream = nullptr;
    antlr4::CommonTokenStream* m_tokens = nullptr;

    OclCS::OclParser* m_parser = nullptr;
    OclCS::OclLexer* m_lexer = nullptr;

    //initial setting
    m_stream = new antlr4::ANTLRInputStream();
    m_lexer = new OclCS::OclLexer(m_stream);
    m_tokens = new antlr4::CommonTokenStream(m_lexer);
    m_parser = new OclCS::OclParser(m_tokens);

    m_lexer->removeErrorListeners();
    m_parser->removeErrorListeners();

    //parsing

    m_stream->load(q);
    m_lexer->setInputStream(m_stream);
    m_tokens->setTokenSource(m_lexer);
    m_parser->setTokenStream(m_tokens);

    //going through the visitors

    OclCS::OclParser::ExpressionInOclCSContext* m_root = m_parser->expressionInOclCS();

    OclCS::OclParserCustomVisitor visitor;
    visitor.visit(dynamic_cast<antlr4::ParserRuleContext*>(m_root));

    std::cout << "ParseTree: " << m_root->toStringTree() << std::endl;

    return "Test query is done!";


}

std::shared_ptr<Any> ts::contextTest(std::string q, std::shared_ptr<Any> context) {

    //creating

    antlr4::ANTLRInputStream* m_stream = nullptr;
    antlr4::CommonTokenStream* m_tokens = nullptr;

    OclCS::OclParser* m_parser = nullptr;
    OclCS::OclLexer* m_lexer = nullptr;

    //initial setting
    m_stream = new antlr4::ANTLRInputStream();
    m_lexer = new OclCS::OclLexer(m_stream);
    m_tokens = new antlr4::CommonTokenStream(m_lexer);
    m_parser = new OclCS::OclParser(m_tokens);

    m_lexer->removeErrorListeners();
    m_parser->removeErrorListeners();

    //parsing

    m_stream->load(q);
    m_lexer->setInputStream(m_stream);
    m_tokens->setTokenSource(m_lexer);
    m_parser->setTokenStream(m_tokens);

    //going through the visitors

    OclCS::OclParser::ExpressionInOclCSContext* m_root = m_parser->expressionInOclCS();

    OclCS::OclParserCustomVisitor visitor;
    std::any resultSyntax = visitor.visit(dynamic_cast<antlr4::ParserRuleContext*>(m_root));

    std::cout << "ParseTree: " << m_root->toStringTree() << std::endl;

    std::shared_ptr<std::any> anyTest = std::make_shared<std::any>(resultSyntax);

    // ### EvalTest ###

    // Create EvalEnv and set Context

    std::shared_ptr<Eval::EcoreEnvironment> sharedEnv = std::make_shared<Eval::EcoreEnvironment>(Eval::EcoreEnvironment(nullptr, context));

    Eval::EcoreEval testEval(sharedEnv);

    std::shared_ptr<ocl::Expressions::ExpressionInOcl> rootNode;

    // std::cout << "RootNode: " << typeid(rootNode).name() << std::endl;
    // std::cout << resultSyntax.type().name() << std::endl;
    // std::cout << typeid(std::shared_ptr<ocl::Expressions::ExpressionInOcl>).name() << std::endl;

    if (resultSyntax.type() == typeid(std::shared_ptr<ocl::Expressions::ExpressionInOcl>)) {
        try
        {
            rootNode = std::any_cast<std::shared_ptr<ocl::Expressions::ExpressionInOcl>>(resultSyntax);
            // auto e = std::any_cast<std::shared_ptr<ocl::Expressions::ExpressionInOcl>>(resultSyntax);
            // std::cout << typeid(rootNode).name() << std::endl;
            // std::cout << resultSyntax.type().name() << std::endl;
            // std::cout << typeid(std::shared_ptr<ocl::Expressions::ExpressionInOcl>).name() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

    } else {
        throw("Error: Return of Syntax Check is no ExpressionInOcl.");

    }
    
    std::shared_ptr<Any> sharedTestNode = eEcoreAny<std::shared_ptr<ocl::Expressions::ExpressionInOcl>>(rootNode, rootNode->getMetaElementID());
    //std::shared_ptr<ocl::Expressions::ExpressionInOcl> recastTest = sharedTestNode->get<std::shared_ptr<ocl::Expressions::ExpressionInOcl>>();
    //std::shared_ptr<Any> sharedTestNode = std::make_shared<Any>(testNode);

    
    
    return testEval.visitNode(sharedTestNode);

}