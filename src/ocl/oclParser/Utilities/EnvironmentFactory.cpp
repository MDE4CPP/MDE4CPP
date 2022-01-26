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

std::shared_ptr<Environment> EnvironmentFactory::createRootEnvironment(std::shared_ptr<ecore::EObject> context)
{
    std::shared_ptr<Environment> env = createEnvironment(nullptr);

	std::shared_ptr<uml::Element> element = std::dynamic_pointer_cast<uml::Element>(context);
	std::shared_ptr<ecore::EPackage> epackage = nullptr;
	std::shared_ptr<ecore::EClassifier> classifier = nullptr;

	if(element != nullptr)
	{ 
		std::shared_ptr<ecore::EClass> eClass=element->eClass();

		// TODO alternative UML-Modellunterscheidung: 	if(nullptr!=uobj->getMetaClass())
		std::shared_ptr<uml::NamedElement> namedElement = std::dynamic_pointer_cast<uml::NamedElement>(context);
		if(nullptr!=namedElement)
		{
			std::shared_ptr<ecore::EPackage> package=eClass->getEPackage().lock();
			if(nullptr!=namedElement)
			{
				epackage = uml::umlPackage::eInstance(); //OclReflection::umlPackage2Ecore(element->getMetaClass()->getPackage().lock());
				classifier = element->eClass(); //epackage->getEClassifier(element->getMetaClass()->getName());
			}
		}
		if(nullptr==epackage) // UML-Modell UMLReflection (ecore-)Model necessary! --> TODO!!! über Plugin-Manager gehen!!!
		{
			if(nullptr!=element->getMetaClass() && nullptr != element->getMetaClass()->getPackage().lock())
			{
				//Bad Workaround ToDo: Support UML-Based OCL-Reflection use uml::get instead of eGet...
				//Use Pluginframework for unknown / uml Packages to find classifier
				epackage = OclReflection::umlPackage2Ecore(element->getMetaClass()->getPackage().lock());
				classifier = epackage->getEClassifier(element->getMetaClass()->getName());
			}
		}
	}
	else {
		classifier = context->eClass();
		epackage = classifier->getEPackage().lock();
	}

	std::shared_ptr<Variable> self = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();
	self->setEType(classifier);
	self->setName(classifier->getName());
	self->setValue(OclReflection::createValue(context));
	env->setSelfVariable(self);
	env->addElement(Environment::SELF_VARIABLE_NAME, self, true);

	if(epackage)
	{
		std::shared_ptr<Variable> packageVar = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();

		packageVar->setName(epackage->getName());
		packageVar->setEType(epackage->eClass());
		packageVar->setValue(OclReflection::createValue(epackage));

		env->addElement(packageVar->getName(), packageVar, false);
	 }
/*    }
    else {

        std::shared_ptr<Variable> self = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();
        self->setName(Environment::SELF_VARIABLE_NAME);
        self->setEType(context->eClass());
        self->setValue(OclReflection::createValue(context));

        env->addElement(self->getName(), self, true);
        env->setSelfVariable(self);

    }
*/
    return env;
}
