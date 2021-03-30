#include "EnvironmentFactory.h"
#include "OclReflection.h"

#include <ocl/Expressions/ExpressionsFactory.hpp>
#include <ocl/Expressions/Variable.hpp>
#include <ocl/Values/NameValueBinding.hpp>
#include <ocl/Values/ObjectValue.hpp>
#include <ocl/Values/LocalSnapshot.hpp>
#include <ecore/EOperation.hpp>
#include <ecore/EParameter.hpp>
#include <ecore/EClassifier.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EPackage.hpp>
#include <ecore/ecoreFactory.hpp>

using namespace ocl;
using namespace ocl::Expressions;
using namespace ocl::Values;
using namespace Utilities;

EnvironmentFactory EnvironmentFactory::m_instance;

std::shared_ptr<Environment> EnvironmentFactory::createEnvironment(std::shared_ptr<Environment> parent)
{
    return  std::make_shared<Environment>(parent);
}

std::shared_ptr<Environment> EnvironmentFactory::createEnvironment(std::shared_ptr<Environment> parent, std::shared_ptr<ecore::EObject> context, Level level)
{
    std::shared_ptr<Environment> env = createEnvironment(parent);
    env->setLevel(level);

    if(level == Level::M2) {
        std::shared_ptr<uml::Element> element = std::dynamic_pointer_cast<uml::Element>(context);
        std::shared_ptr<ecore::EPackage> epackage = nullptr;
        std::shared_ptr<ecore::EClassifier> classifier = nullptr;

        if(element != nullptr) {
            epackage = OclReflection::umlPackage2Ecore(element->getMetaClass()->getPackage().lock());
            classifier = epackage->getEClassifier(element->getMetaClass()->getName());
        }
        else {
            classifier = context->eClass();
            epackage = classifier->getEPackage().lock();
        }

        std::shared_ptr<Variable> packageVar = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();
        packageVar->setName(epackage->getName());
        packageVar->setEType(epackage->eClass());
        packageVar->setValue(OclReflection::createValue(epackage));

        std::shared_ptr<Variable> self = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();
        self->setEType(classifier);
        self->setName(classifier->getName());
        self->setValue(OclReflection::createValue(context));

        env->setSelfVariable(self);
        env->addElement(Environment::SELF_VARIABLE_NAME, self, true);
        env->addElement(packageVar->getName(), packageVar, false);
    }
    else {
        std::shared_ptr<Variable> self = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();
        self->setName(Environment::SELF_VARIABLE_NAME);
        self->setEType(context->eClass());
        self->setValue(OclReflection::createValue(context));

        env->addElement(self->getName(), self, true);
        env->setSelfVariable(self);
    }

    return env;
}
