/*!
 * \file NamedElement.h
 * \brief A named element is a modelelement that is referred to by a name. A modelelement itself has a name, but this is not
        always the name that is used to refer to it. (OCL 2.4 specification)
 * \author Ndongmo Silatsa F.
 * \date 21-01-2020
 */

#ifndef NAMEDELEMENT_H
#define NAMEDELEMENT_H

#include <string>
#include <ocl/Expressions/Variable.hpp>

using namespace ocl::Expressions;

namespace Utilities {

class NamedElement
{
public:
    NamedElement(const std::string& name, std::shared_ptr<Variable> elem, bool isImplicit) :
        m_implicit(isImplicit), m_name(name), m_referredElement(elem) {}

    /* SETTERS */
    void setReferredElement(std::shared_ptr<Variable> referredElement) { m_referredElement = referredElement; }
    void setName(const std::string& name) { m_name = name; }
    /* GETTERS */
    bool isImplicit() { return m_implicit; }
    const std::string& getName() { return m_name; }
    std::shared_ptr<ecore::EClassifier> getType() { return m_referredElement->getEType(); }
    std::shared_ptr<Variable> getReferredElement() { return m_referredElement; }
private:
    bool m_implicit;
    std::string m_name;
    std::shared_ptr<Variable> m_referredElement;
};
}
#endif // NAMEDELEMENT_H
