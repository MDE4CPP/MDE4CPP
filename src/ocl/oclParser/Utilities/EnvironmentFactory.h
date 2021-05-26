/*!
 * \file EnvironmentFactory.h
 * \brief The Environment Factory class.
 * \author Ndongmo Silatsa F.
 * \date 22-01-2020
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
    std::shared_ptr<Environment> createEnvironment(std::shared_ptr<Environment> parent, std::shared_ptr<ecore::EObject> context, Level level);
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
