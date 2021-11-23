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

#ifndef ENVIRONMENTFACTORY_H
#define ENVIRONMENTFACTORY_H

#include <memory>
#include <ecore/EPackage.hpp>
#include <ocl/Evaluations/EvalEnvironment.hpp>

#include <uml/Package.hpp>
#include <uml/Classifier.hpp>

#include "Environment.h"

using namespace ocl::Evaluations;

namespace Utilities {

class EnvironmentFactory
{
public:
    EnvironmentFactory() {}
    /*!
     * \brief Create an environment with the given context.
     * \param parent
     * \param context : can be a package, a classifier, a EStructuralFeature or an operation
     * \return
     */
    std::shared_ptr<Environment> createRootEnvironment(std::shared_ptr<ecore::EObject> context);
    /*!
     * \brief Create an environment son of the given environment.
     * \param parent
     * \return
     */
    std::shared_ptr<Environment> createEnvironment(std::shared_ptr<Environment> parent);

    /* GETTERS */
    static EnvironmentFactory& getInstance() { return m_instance; }
    /* SETTERS */
private:
    static EnvironmentFactory m_instance;
};
}
#endif // ENVIRONMENTFACTORY_H
