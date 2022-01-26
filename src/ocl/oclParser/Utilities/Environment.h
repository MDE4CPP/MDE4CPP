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

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <vector>
#include <unordered_map>
#include <ecore/EPackage.hpp>
#include <ecore/EOperation.hpp>
#include <ecore/EAttribute.hpp>
#include <ocl/Evaluations/EvalEnvironment.hpp>
#include <ocl/Expressions/Variable.hpp>

#include "NamedElement.h"

using namespace ocl::Evaluations;
using namespace ocl::Expressions;

namespace Utilities {

/*!
 * \brief The Environment type used in the rules for the concrete syntax is
 * defined according to the following invariants and additional operations.
 * Environments can be nested, denoted by the existence of a parent environment.
 * Each environment keeps a list of named elements, that have a name a reference
 * to a ModelElement. (OCL 2.4 specification)
 */
class Environment
{
public:
    Environment(std::shared_ptr<Environment> parent);

    /*!
     * \brief Find a named element in the current environment, not in its parents, based on a single name.
     * \param name
     * \return nullptr if the element is not found.
     */
    std::shared_ptr<NamedElement> lookupLocal(const std::string& name);
    /*!
     * \brief Find a named element in the current environment or recursively in its parent environment, based on a single name.
     * \param name
     * \return nullptr if the element is not found.
     */
    std::shared_ptr<Variable> lookup(const std::string& name);
    /*!
     * \brief Find a named element in the current environment or recursively in its parent environment, based on a path name.
     * \param names
     * \return nullptr if the element is not found.
     */
    std::shared_ptr<Variable> lookupPathName(std::vector<std::string>& names);
    std::shared_ptr<Variable> lookupPathName(const std::string& name);
    std::shared_ptr<Variable> lookupPathName(std::shared_ptr<ecore::EPackage> package, std::vector<std::string>& names);
    /*!
     * \brief Find a named element in the current environment or recursively in its parent environment, based on a single name and the implicity.
     * \param name
     * \return nullptr if the element is not found.
     */
    std::shared_ptr<Variable> lookupImplicit(const std::string& name);
    /*!
     * \brief This operation results in a new environment that has the current one as its parent.
     * \return a new environment.
     */
    std::shared_ptr<Environment> nestedEnvironment();
    /*!
     * \brief Add a new named element to the environment.
     * \return a new environment.
     */
    bool addElement(const std::string& name, std::shared_ptr<Variable> elem, bool isImplicit);
    /*!
     * \brief Generates a new, unique name for an implicit iterator variable.
     * \return the new name.
     */
    std::string generateName();
    /*!
     * \brief Retrieve the meta class of the given type.
     * If it is already a meta class, cast and return it.
     */
    //std::shared_ptr<ecore::EClass> getMetaClass(std::shared_ptr<ecore::EClassifier> type);
    /*!
     * \brief createNewObject creates a new object of given EClass and returns it
     * \param meta_package is the EPackage of the meta model in which e_class is
     * \param e_class is the EClass of which an object should be created
     * \param new_object_name is the name of the new object
     *
     * If the object couldn't be created, a nullptr is returned
     */
    std::shared_ptr<ecore::EObject> createNewObject(std::shared_ptr<ecore::EPackage> meta_package,
                                                                std::shared_ptr<ecore::EClass> e_class);

    /* SETTERS */
    void setSelfVariable(std::shared_ptr<Variable> self) { m_self = self; }
    /* GETTERS */
    std::shared_ptr<Environment> getRootEnv();
    std::shared_ptr<EvalEnvironment> getEvalEnv() { return m_evalEnv; }
    std::shared_ptr<Variable> getSelfVariable() { return m_self; }

    static const std::string SELF_VARIABLE_NAME;
private:
    /*!
     * \brief Parent environment
     */
    std::shared_ptr<Environment> m_parent;
    /*!
     * \brief Evaluation environment
     */
    std::shared_ptr<EvalEnvironment> m_evalEnv;
    /*!
     * \brief self variable
     */
    std::shared_ptr<Variable> m_self;
    /*!
     * \brief List of declared variables and implicit variables, including "self".
     * Implicit variables are generated when there is an iterator without any
     * iteration variable specified.
     */
    std::unordered_map<std::string, std::shared_ptr<NamedElement>> m_namedElements;
    /*!
     * \brief Used to generate implicit iterator variables
     */
    int m_generatorInt = 0;
};
}
#endif // ENVIRONMENT_H
