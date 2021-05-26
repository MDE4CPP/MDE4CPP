/*!
 * \file ParserErrorListener.h
 * \brief Track OclParser errors.
 * \author Ndongmo Silatsa F.
 * \date 16-11-2019
 */

#pragma once


#include <antlr4-runtime.h>
#include "../Utilities/Ocl.h"

using namespace Utilities;
using namespace antlr4;
using namespace std;

namespace OclCS {
/*!
 * \brief Error listener for the OclParser. It throws a ParseCancellationException
 * when an error occurs in parsing.
 */
class OclParserErrorListener : public BaseErrorListener
{
public:
	OclParserErrorListener(Ocl* owner) : m_owner(owner) {}

	virtual void syntaxError(Recognizer* recognizer, Token* offendingSymbol, size_t line,
		size_t charPositionInLine, std::string const& msg, std::exception_ptr ep) override {

        string error = "OclParser [Line : " + to_string(line) + "]" +
            " [Column : " + to_string(charPositionInLine) + "]" +
            " [Message : " + msg + "]";

		if (m_owner->m_throwException)
			throw ParseCancellationException(error);
		else
            m_owner->m_errors.emplace_back(OclSeverity::ERROR, error);
	}

private:
	Ocl* m_owner;
};
}
