/*!
 * \file CSTNode.h
 * \brief  An Concrete syntax Tree node.
 * \author Ndongmo Silatsa F.
 * \date 29-01-2020
 */

#ifndef CSTNODE_H
#define CSTNODE_H

#include "../Utilities/Environment.h"
#include "OclAnalyserErrorListener.h"

#include <memory>
#include <ocl/Expressions/OclExpression.hpp>

using namespace Utilities;

namespace OclCS {

class CSTNode
{
public:
    CSTNode() : m_ast(nullptr), m_env(nullptr), m_errorListener(nullptr) {}
    virtual std::string toString() { return ""; }


    /* SETTERS */
    void setAST(std::shared_ptr<ocl::Expressions::OclExpression> ast) { m_ast = ast; }
    void setEnv(std::shared_ptr<Environment> env) { m_env = env; }
    void setErrorListener(std::shared_ptr<OclAnalyserErrorListener> listener) { m_errorListener = listener; }
    /* GETTERS */
    std::shared_ptr<ocl::Expressions::OclExpression> getAST() {return m_ast; }
    std::shared_ptr<Environment> getEnv() { return m_env; }
    std::shared_ptr<OclAnalyserErrorListener> getErrorListener() { return m_errorListener; }
protected:
    std::shared_ptr<ocl::Expressions::OclExpression> m_ast; // corresponding AST node
    std::shared_ptr<Environment> m_env;   // current environment
    std::shared_ptr<OclAnalyserErrorListener> m_errorListener; // error listener
};
}
#endif // CSTNODE_H
