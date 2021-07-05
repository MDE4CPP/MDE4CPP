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

#ifndef NAMEDELEMENT_H
#define NAMEDELEMENT_H

#include <string>
#include <ocl/Expressions/Variable.hpp>

using namespace ocl::Expressions;

namespace Utilities {

/*!
 * \brief A named element is a modelelement that is referred to by a name.
 * A modelelement itself has a name, but this is not always the name that is
 * used to refer to it. (OCL 2.4 specification)
 */
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
