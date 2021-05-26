#ifndef OCLANALYSERERRORLISTENER_H
#define OCLANALYSERERRORLISTENER_H

#include "../Utilities/Ocl.h"

using namespace Utilities;

namespace OclCS {

class OclAnalyserErrorListener
{
public:
    OclAnalyserErrorListener(Ocl* owner) : m_owner(owner) {}

    void syntaxError(std::string error)
    {
        if (m_owner->m_throwException)
            throw std::runtime_error(error);
        else
            m_owner->m_errors.emplace_back(OclSeverity::ERROR, error);
    }

private:
    Ocl* m_owner;
};
}
#endif // OCLANALYSERERRORLISTENER_H
