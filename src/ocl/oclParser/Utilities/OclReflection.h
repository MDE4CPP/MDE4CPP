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

#ifndef OCLREFLECTION_H
#define OCLREFLECTION_H

#include <ecore/EObject.hpp>
#include <ecore/EOperation.hpp>
#include <ecore/EAttribute.hpp>
#include <ecore/EPackage.hpp>
#include <ecore/EReference.hpp>
#include <abstractDataTypes/Bag.hpp>
#include <types/typesPackage.hpp>

#include <uml/umlFactory.hpp>
#include <uml/umlPackage.hpp>
#include <uml/Property.hpp>
#include <uml/Model.hpp>
#include <uml/Package.hpp>
#include <uml/Classifier.hpp>
#include <uml/Enumeration.hpp>
#include <uml/Class.hpp>
#include <uml/Association.hpp>
#include <uml/Property.hpp>
#include <uml/Operation.hpp>
#include <uml/Parameter.hpp>
#include <uml/EnumerationLiteral.hpp>
#include <uml/PrimitiveType.hpp>

#include <fUML/Semantics/Values/Value.hpp>
#include <ocl/Values/ObjectValue.hpp>
#include <ocl/Values/LocalSnapshot.hpp>
#include <ocl/Expressions/OclExpression.hpp>
#include <ocl/Evaluations/EvalEnvironment.hpp>

#include <memory>

#include "EnvironmentFactory.h"

using namespace ocl;
using namespace ocl::Values;
using namespace ocl::Evaluations;
using namespace ocl::Expressions;

namespace Utilities {

class OclReflection
{
public:
    /**
     * @brief lookup a Class properties and find the property with the given name.
     * @param eclass : Class of the searched property
     * @param name  : name of the searched property
     * @return the found property if it exists within the given class, nullptr otherwise.
     */
    static std::shared_ptr<uml::Property> lookupProperty(std::shared_ptr<uml::Class> eclass, const std::string& name);
    /**
     * @brief lookup a given package and find a subpackage corresponding to the given name.
     * @param package : parent pakage
     * @param name : name of the searched package
     * @return  the found package if it exists within the given package, nullptr otherwise.
     */
    static std::shared_ptr<ecore::EPackage> lookupPackage(std::shared_ptr<ecore::EPackage> package, const std::string& name);
    /**
     * @brief lookup a EClass attributes and find the attribute with the given name.
     * @param eclass EClass of the searched attribute
     * @param name : name of the searched attribute
     * @return the found attribute if it exists within the given class, nullptr otherwise.
     */
    static std::shared_ptr<ecore::EAttribute> lookupProperty(std::shared_ptr<ecore::EClass> eclass, const std::string& name);
    /**
     * @brief lookup a EClass associations and find the reference with the given name.
     * @param eclass EClass of the searched reference
     * @param name : name of the searched reference
     * @return the found reference if it exists within the given class, nullptr otherwise.
     */
    static std::shared_ptr<ecore::EReference> lookupAssociationClass(std::shared_ptr<ecore::EClass> eclass, const std::string& name);
    /**
     * @brief lookup a EClass operations and find the operation with the given name.
     * @param eclass : EClass of the searched operation
     * @param name : name of the searched operation
     * @param arguments : arguments of the searched operation
     * @return the found operation if it exists within the given class, nullptr otherwise.
     */
    static std::shared_ptr<ecore::EOperation> lookupOperation(std::shared_ptr<ecore::EClass> eclass,
                                                              const std::string& name, std::shared_ptr<Bag<OclExpression>> arguments);

    /**
     * @brief Check if the given typed element is a Bag type.
     * @param etyped : the typed element
     * @return true if the element type is a Bag of, false otherwise.
     */
    static bool isMany(std::shared_ptr<ecore::ETypedElement> etyped);
    /**
     * @brief Check if the given first type is the same type or a subtype of the second given type.
     * @param type : first type to check
     * @param ofType : type to compare the first type with
     * @return true if the first type is a kind of the second type, false otherwise.
     */
    static bool kindOf(std::shared_ptr<ecore::EClassifier> type, std::shared_ptr<ecore::EClassifier> ofType);
    /**
     * @brief Check if the given object is an instance of the given template type.
     * @param obj
     * @return
     */
    template <class T>
    static bool instanceOf(std::shared_ptr<ecore::EObject> obj) {
        return std::dynamic_pointer_cast<T>(obj) != nullptr;
    }
    /**
     * @brief Retrieve the embedded value from the given fUML value.
     * @param fromValue : fUML value
     * @return the embedded value
     */
    static Any retrieveRawValue(std::shared_ptr<fUML::Semantics::Values::Value> fromValue);
    /**
     * @brief Retrieve the embedded not many value from the given fUML value.
     * @param fromValue : fUML value
     * @return the embedded value
     */
    static Any retrieveNotManyRawValue(std::shared_ptr<fUML::Semantics::Values::Value> fromValue);
    /**
     * @brief Create a fUML value with the given object as value.
     * @param obj : object to embed
     * @return return the created fUML value
     */
    static std::shared_ptr<fUML::Semantics::Values::Value> createValue(std::shared_ptr<ecore::EObject> obj);
    /**
     * @brief Create the right fUML value with the given parameters.
     * @param type : the type of the value
     * @param value : the value
     * @return return the created fUML value
     */
    static std::shared_ptr<fUML::Semantics::Values::Value> createValue(std::shared_ptr<ecore::ETypedElement> type, Any value);
    /**
     * @brief Find the given structural feature  within the given fUML value and create a new fUML value with the found value.
     * @param type : structural feature of the searched value
     * @param fromValue : source fUML value
     * @param level : the level of the current environment
     * @return return the created fUML value
     */
    static std::shared_ptr<fUML::Semantics::Values::Value> createValue(std::shared_ptr<ecore::EStructuralFeature> type, std::shared_ptr<fUML::Semantics::Values::Value> fromValue, Level level);
    /**
     * @brief Find the given operation within the given fUML value and create a new fUML value with the result of the execution of the operation.
     * @param operation : searched operation
     * @param arguments : operation arguments
     * @param fromValue : source fUML value
     * @return return the created fUML value
     */
    static std::shared_ptr<fUML::Semantics::Values::Value> createValue(std::shared_ptr<ecore::EOperation> operation, std::shared_ptr<Bag<OclExpression>> arguments,
                                                    std::shared_ptr<fUML::Semantics::Values::Value> fromValue);
    /**
     * @brief Retrieve the string value of the given oclExpression.
     * @param source : OclExpression
     * @return the string value
     */
    static std::string getStringValue(std::shared_ptr<OclExpression> source);
    /**
     * @brief Retrieve the value of the given oclExpression as Any.
     * @param source : OclExpression
     * @return the Any value
     */
    static Any getAnyValue(std::shared_ptr<OclExpression> source);
    /**
     * @brief Retrieve the boolean value of the given oclExpression. One must first check if the given expression has a boolean value.
     * @param source : OclExpression
     * @return the boolean value
     */
    static bool getResult(std::shared_ptr<OclExpression> source);
    /**
     * @brief Create an ecore package from the given uml package.
     * @param upackage : source uml package
     * @return an ecore package corresponding (attributes, operations) to the uml package
     */
    //static std::shared_ptr<ecore::EPackage> umlPackage2Ecore(std::shared_ptr<uml::Package> upackage);
    /**
     * @brief Retrieve the default value of the given property
     * @param prop
     * @return the retrieved default value if it exists, nullptr otherwise.
     */
    static Any getDefaultValue(std::shared_ptr<uml::Property> prop);
    /**
     * @brief Find the EClassifier corresponding to the given uml type within the given ecore package.
     * @param package : ecore package
     * @param type :
     * @return the found Eclassifier if it exists, nullptr otherwise.
     */
    static std::shared_ptr<ecore::EClassifier> createClassifier(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<uml::Type> type);
};
}
#endif // OCLREFLECTION_H
