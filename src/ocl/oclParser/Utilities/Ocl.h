/*
 * MDE4CPP - Model Driven Engineering for C++
 *
 * Copyright (c) TU Ilmenau, Systems and Software Engineering Group
 * All rights reserved.
 *
 * MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
 * to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED *AS IS*, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef OCL4CPP_H
#define OCL4CPP_H

#include <ecore/EPackage.hpp>
#include <ecore/EFactory.hpp>
#include <uml/Package.hpp>
#include <uml/Classifier.hpp>

#include <istream>
#include <vector>
#include <string>

#include "Ocllog.h"

namespace OclCS {

    class OclAnalyserErrorListener;
    class OclParserErrorListener;
    class OclLexerErrorListener;
    class OclParser;
    class OclLexer;
    class CSTNode;
}

namespace antlr4 {
    class ANTLRInputStream;
    class CommonTokenStream;
}

using namespace std;
using namespace OclCS;
using namespace antlr4;

namespace Utilities {

class Environment;

/*!
 * \brief The OCL Parser/Interpreter provides an implementation of the Object Constraint Language 2.3 specification.
 *	It offers OCL constraint and query parsing and evaluation, model-based validation.
 */
class Ocl
{
    friend OclParserErrorListener;
    friend OclLexerErrorListener;
    friend OclAnalyserErrorListener;

public:
    Ocl(bool throwException = false);
    virtual ~Ocl();
    /*!
     * \brief Check the correctness of the current Ocl query syntax.
     *	\return true if the query is syntacticaly correct, false otherwise
     */
    bool checkSyntaxQuery(const string& oclText);
    /*!
     * \brief Check the correctness of the current Ocl constraint syntax.
     *	\return true if the constraint  is syntacticaly correct, false otherwise
     */
    bool checkSyntaxConstraint(const string& oclText);
    /*!
     * \brief Analyse the Ocl AST with the given Ocl query.
     * \parm context : the context to query
     *	\return true if the query did not fail, false otherwise
     */
    bool query(const string& oclText, std::shared_ptr<ecore::EObject> context);
    /*!
     * \brief Validate the related model according to the given Ocl constraints.
     * \parm oclText : the ocl constraint
     * \parm context : the context object
     *	\return true if the constraint did not fail, false otherwise
     */
    bool validate(const string& oclText, std::shared_ptr<ecore::EObject> context);

    void setThrowException(bool throwExcepssion);

    const vector<OclLog>& getErrors();
    /*!
     * \brief Gets the sum of all existing errors in one string.
     * \return error
     */
    std::string getError();
    /*!
     * \brief Gets the query result as string.
     * \return query result
     */
    std::string getResult();
    /*!
     * \brief Gets the query result as Any.
     * \return query result
     */
    Any getResultValue();

private:
    /*!
     * \brief Parse the current input stream. The possible exceptions are collected in an vector and are not thrown.
     * \parm oclText : Ocl expression
     */
    void parse(const string& oclText);
    /*!
     * \brief Add the given error in the errors vector or throw an exception.
     *	\parm error : current error
     */
    void addError(const string& error);

    bool m_throwException;

    vector<OclLog> m_errors;

    ANTLRInputStream* m_stream = nullptr;
    CommonTokenStream* m_tokens = nullptr;

    std::shared_ptr<OclAnalyserErrorListener> m_analyseErListener;
    OclParserErrorListener* m_parserErListener = nullptr;
    OclLexerErrorListener* m_lexErListener = nullptr;
    OclParser* m_parser = nullptr;
    OclLexer* m_lexer = nullptr;
    CSTNode* m_root = nullptr;

    std::shared_ptr<Environment> m_env;
};
}
#endif // OCL4CPP_H
