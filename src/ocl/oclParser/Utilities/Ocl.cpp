#include "Ocl.h"

#include "../OclCS/CSTNode.h"
#include "../OclCS/OclParser.h"
#include "../OclCS/OclLexer.h"
#include "../OclCS/OclParserErrorListener.h"
#include "../OclCS/OclLexerErrorListener.h"
#include "../OclCS/OclAnalyserErrorListener.h"
#include "../OclCS/OclParserCustomVisitor.h"
#include "OclReflection.h"

#include "Environment.h"
#include "EnvironmentFactory.h"

#include <ANTLRInputStream.h>
#include <CommonTokenStream.h>

using namespace OclCS;
using namespace ocl::Evaluations;
using namespace Utilities;

Ocl::Ocl(bool throwException) : m_throwException(throwException)
{
    m_stream = new ANTLRInputStream();
    m_lexer = new OclLexer(m_stream);
    m_tokens = new CommonTokenStream(m_lexer);
    m_parser = new OclParser(m_tokens);

    m_lexErListener = new OclLexerErrorListener(this);
    m_parserErListener = new OclParserErrorListener(this);
    m_analyseErListener = std::make_shared<OclAnalyserErrorListener>(this);

    m_lexer->removeErrorListeners();
    m_parser->removeErrorListeners();

    m_lexer->addErrorListener(m_lexErListener);
    m_parser->addErrorListener(m_parserErListener);
}

Ocl::~Ocl()
{
    m_root = nullptr;

    if (m_lexer != nullptr) {
        delete(m_lexer);
        m_lexer = nullptr;
    }
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
    if (m_lexErListener != nullptr) {
        delete(m_lexErListener);
        m_lexErListener = nullptr;
    }
    if (m_parserErListener != nullptr) {
        delete(m_parserErListener);
        m_parserErListener = nullptr;
    }
}

void Ocl::parse(const string& oclText)
{
    m_errors.clear();

    m_stream->load(oclText);
    m_lexer->setInputStream(m_stream);
    m_tokens->setTokenSource(m_lexer);
    m_parser->setTokenStream(m_tokens);
}

bool Ocl::checkSyntaxQuery(const string &oclText)
{
    parse(oclText);
    m_parser->expressionInOclCS();
    return m_errors.size() == 0;
}

bool Ocl::checkSyntaxConstraint(const string &oclText)
{
    parse(oclText);
    m_parser->packageDeclarationCS();
    return m_errors.size() == 0;
}

bool Ocl::query(const string& oclText, std::shared_ptr<ecore::EObject> context)
{
    parse(oclText);

    m_env = EnvironmentFactory::getInstance().createEnvironment(nullptr, context, Level::M1);
    m_root = m_parser->expressionInOclCS();
    m_root->setEnv(m_env);
    m_root->setErrorListener(m_analyseErListener);

    OclCS::OclParserCustomVisitor visitor;
    visitor.visit(dynamic_cast<antlr4::ParserRuleContext*>(m_root));

    return m_errors.size() == 0;
}

bool Ocl::validate(const string& oclText, std::shared_ptr<ecore::EObject> context)
{
    parse(oclText);

    m_env = EnvironmentFactory::getInstance().createEnvironment(nullptr, context, Level::M2);
    m_root = m_parser->packageDeclarationCS();
    m_root->setEnv(m_env);
    m_root->setErrorListener(m_analyseErListener);

    OclCS::OclParserCustomVisitor visitor;
    visitor.visit(dynamic_cast<antlr4::ParserRuleContext*>(m_root));

    return m_errors.empty() && m_root->getAST() != nullptr && OclReflection::getResult(m_root->getAST());
}

void Ocl::setThrowException(bool throwExcepssion)
{
    m_throwException = throwExcepssion;
}

const vector<OclLog>& Ocl::getErrors()
{
    return m_errors;
}

std::string Ocl::getResult()
{
    if(m_root != nullptr && m_root->getAST() != nullptr && m_errors.empty()) {
        return OclReflection::getStringValue(m_root->getAST());
    }
    else
        return "";
}

std::string Ocl::getError()
{
    std::string error = "";
    for(auto& log : m_errors) {
        if(error.empty()) {
            error = log.getMsg();
        }
        else {
            error += "\n" + log.getMsg();
        }
    }
    return error;
}

void Ocl::addError(const string& error)
{
    if (m_throwException)
        throw(error);
    else
        m_errors.emplace_back(OclSeverity::ERROR, error);
}
