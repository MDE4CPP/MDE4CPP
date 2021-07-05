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

#include "Environment.h"
#include "EnvironmentFactory.h"
#include "OclReflection.h"

#include <ocl/Expressions/ExpressionsFactory.hpp>
#include <abstractDataTypes/SubsetUnion.hpp>
#include <pluginFramework/PluginFramework.hpp>
#include <pluginFramework/MDE4CPPPlugin.hpp>
#include <pluginFramework/EcoreModelPlugin.hpp>

#include <uml/umlFactory.hpp>
#include <uml/umlPackage.hpp>
#include <uml/Package.hpp>
#include <uml/PackageableElement.hpp>

#include <ecore/ecoreFactory.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EPackage.hpp>
#include <ecore/ecorePackage.hpp>
#include <ecore/EClassifier.hpp>

using namespace Utilities;

const std::string Environment::SELF_VARIABLE_NAME = "self";

Environment::Environment(std::shared_ptr<Environment> parent) : m_parent(parent)
{
    if(m_parent != nullptr) {
        m_level = m_parent->m_level;
        m_self = m_parent->m_self;
        for(auto&e : m_parent->m_namedElements) {
            m_namedElements[e.first] = e.second;
        }
    }
}
std::shared_ptr<NamedElement> Environment::lookupLocal(const std::string& name)
{
    if(m_namedElements.find(name) != m_namedElements.end()) {
        return m_namedElements.at(name);
    }
    return nullptr;
}
std::shared_ptr<Variable> Environment::lookup(const std::string& name)
{
    std::shared_ptr<NamedElement> result = lookupLocal(name);

    if(result == nullptr && m_parent != nullptr) {
        return m_parent->lookup(name);
    }
    else if(result != nullptr)
        return result->getReferredElement();
    else
        return nullptr;
}

std::shared_ptr<Variable> Environment::lookupPathName(std::shared_ptr<ecore::EPackage> package, std::vector<std::string> &names)
{
    if(names.size() > 0) {
        std::shared_ptr<ecore::EClassifier> eclass = package->getEClassifier(names[0]);
        if(eclass != nullptr) {
            if(names.size() == 1) {
                std::shared_ptr<Variable> var = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();
                var->setName(eclass->getName());
                var->setEType(eclass);
                var->setValue(OclReflection::createValue(eclass));
                return var;
            }
        }
        else {
            std::shared_ptr<ecore::EPackage> epack = OclReflection::lookupPackage(package, names[0]);
            if(epack != nullptr) {
                if(names.size() == 1) {
                    std::shared_ptr<Variable> var = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();
                    var->setName(epack->getName());
                    var->setEType(epack->eClass());
                    var->setValue(OclReflection::createValue(epack));
                    return var;
                }
                else {
                    names.erase(names.begin());
                    lookupPathName(epack, names);
                }
            }
        }
    }
    return nullptr;
}

std::shared_ptr<Variable> Environment::lookupPathName(std::vector<std::string>& names)
{
    if(names.size() > 0) {
        std::shared_ptr<Variable> var = lookupPathName(names[0]);
        if(var != nullptr && var->getEType()->getClassifierID() == ecore::ecorePackage::EPACKAGE_CLASS && names.size() > 1) {
            std::shared_ptr<ocl::Values::ObjectValue> value = std::dynamic_pointer_cast<ocl::Values::ObjectValue>(var->getValue());
            std::shared_ptr<ecore::EPackage> package = std::dynamic_pointer_cast<ecore::EPackage>(value->getValue());
            names.erase(names.begin());
            return lookupPathName(package, names);
        }
        return var;
    }
    return nullptr;
}

std::shared_ptr<Variable> Environment::lookupPathName(const std::string& name)
{
    for(auto&e : m_namedElements) {
        std::shared_ptr<Variable> var = e.second->getReferredElement();
        if(var->getName() == name) {
            return var;
        }
    }
    for(auto&e : m_namedElements) {
        std::shared_ptr<Variable> var = e.second->getReferredElement();

        if(var->getEType()->getClassifierID() == ecore::ecorePackage::EPACKAGE_CLASS) {
            std::shared_ptr<ocl::Values::ObjectValue> value = std::dynamic_pointer_cast<ocl::Values::ObjectValue>(var->getValue());
            std::shared_ptr<ecore::EPackage> package = std::dynamic_pointer_cast<ecore::EPackage>(value->getValue());
            std::shared_ptr<ecore::EClassifier> eclass = package->getEClassifier(name);
            if(eclass != nullptr) {
                std::shared_ptr<Variable> varClass = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();
                varClass->setName(eclass->getName());
                varClass->setEType(eclass);
                varClass->setValue(OclReflection::createValue(eclass));
                return varClass;
            }
            std::shared_ptr<ecore::EPackage> epack = OclReflection::lookupPackage(package, name);
            if(epack != nullptr) {
                std::shared_ptr<Variable> varPack = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();
                varPack->setName(epack->getName());
                varPack->setEType(epack->eClass());
                varPack->setValue(OclReflection::createValue(epack));
                return varPack;
            }
        }
        else if(var->getEType()->getClassifierID() == uml::umlPackage::PACKAGE_CLASS) {
            std::shared_ptr<ocl::Values::ObjectValue> value = std::dynamic_pointer_cast<ocl::Values::ObjectValue>(var->getValue());
            std::shared_ptr<uml::Package> package = std::dynamic_pointer_cast<uml::Package>(value->getValue());
            std::shared_ptr<uml::PackageableElement> eclass = nullptr;

            std::shared_ptr<Bag<uml::PackageableElement>> elements = package->getPackagedElement();
            for(size_t i = 0; i < elements->size(); i++) {
                if(elements->at(i)->getName() == name) {
                    eclass = elements->at(i);
                    break;
                }
            }
            if(eclass != nullptr) {
                std::shared_ptr<Variable> varClass = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();
                varClass->setName(eclass->getName());
                varClass->setEType(eclass->eClass());
                varClass->setValue(OclReflection::createValue(eclass));
                return varClass;
            }
        }
    }

    if(m_parent != nullptr) {
        return m_parent->lookupPathName(name);
    }
    else {
        std::shared_ptr<PluginFramework> pluginframework=PluginFramework::eInstance();
        std::shared_ptr<Bag<MDE4CPPPlugin>> allpluginlist=pluginframework->getAllPlugins();
        std::shared_ptr<MDE4CPPPlugin> meta_model = pluginframework->findPluginByName(name);

        if(meta_model != nullptr) {
            std::shared_ptr<EcoreModelPlugin> room_meta_model = std::dynamic_pointer_cast<EcoreModelPlugin>(meta_model);
            std::shared_ptr<ecore::EPackage> meta_model_package = room_meta_model->getEPackage();
            std::shared_ptr<Variable> var = ocl::Expressions::ExpressionsFactory::eInstance()->createVariable();
            var->setName(meta_model_package->getName());
            var->setEType(meta_model_package->eClass());
            var->setValue(OclReflection::createValue(meta_model_package));
            return var;
        }
    }

    return nullptr;
}
std::shared_ptr<Variable> Environment::lookupImplicit(const std::string& name)
{
    for(auto&e : m_namedElements) {
        if(e.second->isImplicit() && e.first == name) {
            return e.second->getReferredElement();
        }
    }
    return nullptr;
}
std::shared_ptr<Environment> Environment::nestedEnvironment()
{
    return EnvironmentFactory::getInstance().createEnvironment(std::shared_ptr<Environment>(this));
}
bool Environment::addElement(const std::string& name, std::shared_ptr<Variable> elem, bool isImplicit)
{
    std::string elemName = name;
    if(elemName.empty()) {
        elemName = generateName();
        while (lookup(elemName) != nullptr) {
            elemName = generateName();
        }
    }
    else if(lookupLocal(elemName) != nullptr) {
        return false;
    }
    //elem->setName(elemName);
    std::shared_ptr<NamedElement> newElem = std::make_shared<NamedElement>(elemName, elem, isImplicit);
    m_namedElements[elemName] = newElem;

    return true;
}
std::string Environment::generateName()
{
    m_generatorInt++;
    return "temp" + std::to_string(m_generatorInt);
}


std::shared_ptr<ecore::EClass> Environment::getMetaClass(std::shared_ptr<ecore::EClassifier> type)
{
    if(m_level == Level::M2 ||
            type->getClassifierID() == ecore::ecorePackage::EPACKAGE_CLASS ||
            type->getClassifierID() == ecore::ecorePackage::EOPERATION_CLASS ||
            type->getClassifierID() == ecore::ecorePackage::EATTRIBUTE_CLASS ||
            type->getClassifierID() == ecore::ecorePackage::EREFERENCE_CLASS ||
            type->getClassifierID() == ecore::ecorePackage::EENUM_CLASS ||
            type->getClassifierID() == uml::umlPackage::MODEL_CLASS ||
            type->getClassifierID() == uml::umlPackage::PACKAGE_CLASS ||
            type->getClassifierID() == uml::umlPackage::CLASS_CLASS ||
            type->getClassifierID() == uml::umlPackage::OPERATION_CLASS ||
            type->getClassifierID() == uml::umlPackage::PROPERTY_CLASS ||
            type->getClassifierID() == uml::umlPackage::ASSOCIATION_CLASS ||
            type->getClassifierID() == uml::umlPackage::ENUMERATION_CLASS )
    {
        return std::dynamic_pointer_cast<ecore::EClass>(type);
    }
    else {
        return type->eClass();
    }
}

std::shared_ptr<Environment> Environment::getRootEnv()
{
    std::shared_ptr<Environment> env = std::shared_ptr<Environment>(this);

    while (env->m_parent != nullptr) {
        env = env->m_parent;
    }
    return env;
}

std::shared_ptr<ecore::EObject> Environment::createNewObject(std::shared_ptr<ecore::EPackage> meta_package,
                                                            std::shared_ptr<ecore::EClass> e_class)
{
    std::shared_ptr<ecore::EObject> obj = nullptr;

    std::shared_ptr<ObjectValue> value = std::dynamic_pointer_cast<ObjectValue>(m_self->getValue());
    if(value != nullptr && value->getValue() != nullptr) {
        std::shared_ptr<ecore::EObject> eobj = value->getValue();
        std::shared_ptr<uml::Object> uobj = std::dynamic_pointer_cast<uml::Object>(eobj);

        if(uobj == nullptr) {
            std::shared_ptr<PluginFramework> pluginframework = PluginFramework::eInstance();
            std::string meta_model_name = meta_package->getName();
            std::shared_ptr<MDE4CPPPlugin> meta_model = pluginframework->findPluginByName(meta_model_name);
            obj = meta_model->create(e_class->getName());
        }
        else {
            obj = uml::umlFactory::eInstance()->create(e_class->getName());
        }
    }
    return obj;
}
