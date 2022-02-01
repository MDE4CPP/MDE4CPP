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

#include "OclReflection.h"

#include <ecore/EEnum.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EParameter.hpp>
#include <ecore/ecorePackage.hpp>
#include <ecore/ETypeParameter.hpp>
#include <abstractDataTypes/Bag.hpp>
#include <abstractDataTypes/Subset.hpp>
#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include <ecore/EFactory.hpp>

#include <uml/Object.hpp>
#include <uml/ValueSpecification.hpp>

#include <ecore/ecoreFactory.hpp>
#include <ecore/EPackage.hpp>
#include <ecore/EEnum.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EOperation.hpp>
#include <ecore/EAttribute.hpp>
#include <ecore/EParameter.hpp>
#include <ecore/EEnumLiteral.hpp>
#include <ecore/ETypeParameter.hpp>
#include "ecore/EObjectContainer.hpp"

#include <primitivetypesReflection/PrimitiveTypesPackage.hpp>
#include <pluginFramework/PluginFramework.hpp>
#include <pluginFramework/MDE4CPPPlugin.hpp>
#include <pluginFramework/EcoreModelPlugin.hpp>

#include <ocl/Values/ValuesFactory.hpp>
#include <ocl/Types/TypesFactory.hpp>
#include <ocl/Types/BagType.hpp>
#include <ocl/Evaluations/EvaluationsFactory.hpp>
#include <ocl/Evaluations/OclExpEval.hpp>
#include <ocl/Values/NameValueBinding.hpp>
#include <ocl/Values/BagTypeValue.hpp>
#include <ocl/Values/Element.hpp>
#include <ocl/Values/UndefinedValue.hpp>
#include <ocl/Values/AnyValue.hpp>

#include <uml/EnumerationLiteral.hpp>
#include <uml/LiteralBoolean.hpp>
#include <uml/LiteralInteger.hpp>
#include <uml/LiteralReal.hpp>
#include <uml/LiteralString.hpp>
#include <uml/LiteralUnlimitedNatural.hpp>

#include <fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp>
#include <fUML/Semantics/SimpleClassifiers/EnumerationValue.hpp>
#include <fUML/Semantics/SimpleClassifiers/BooleanValue.hpp>
#include <fUML/Semantics/SimpleClassifiers/IntegerValue.hpp>
#include <fUML/Semantics/SimpleClassifiers/RealValue.hpp>
#include <fUML/Semantics/SimpleClassifiers/StringValue.hpp>

using namespace ocl::Types;
using namespace Utilities;

std::shared_ptr<uml::Property> OclReflection::lookupProperty(std::shared_ptr<uml::Class> eclass, const std::string &name)
{
    std::shared_ptr<Bag<uml::Property>> uml_attribute = eclass->getAllAttributes();
    Bag<uml::Property>::const_iterator endIt_attribute = uml_attribute->end();
    for (Bag<uml::Property>::const_iterator it_attribute = uml_attribute->begin();
         it_attribute != endIt_attribute; ++it_attribute)
    {
        //std::cout << (*it_attribute)->getName() << ":"<<std::endl;
        if ((*it_attribute)->getName() == name) {
            return (*it_attribute);
        }
    }
    return nullptr;
}

std::shared_ptr<ecore::EPackage> OclReflection::lookupPackage(std::shared_ptr<ecore::EPackage> package, const std::string &name)
{
    std::shared_ptr<Bag<ecore::EPackage>> ecore_packages = package->getESubpackages();
    Bag<ecore::EPackage>::const_iterator endIt_package = ecore_packages->end();
    for (Bag<ecore::EPackage>::const_iterator it_package = ecore_packages->begin();
         it_package != endIt_package; ++it_package)
    {
        if ((*it_package)->getName() == name) {
            return (*it_package);
        }
    }
    return nullptr;
}

bool OclReflection::isMany(std::shared_ptr<ecore::ETypedElement> etyped)
{
    return etyped->getUpperBound() > 1 || etyped->getUpperBound() < 0;
}

bool OclReflection::kindOf(std::shared_ptr<ecore::EClassifier> type, std::shared_ptr<ecore::EClassifier> ofType)
{
	if(type->getClassifierID() == ofType->getClassifierID() && type->getClassifierID() != -1 && ofType->getClassifierID() != -1)
	{
		return true;
	}
	else
	{
		std::shared_ptr<ecore::EClass> eclass = std::dynamic_pointer_cast<ecore::EClass>(type->eClass());
		std::shared_ptr<ecore::EClass> eclassOf = std::dynamic_pointer_cast<ecore::EClass>(ofType->eClass());
		if(eclass != nullptr && eclassOf != nullptr) {
			if(eclassOf->isSuperTypeOf(eclass))
			{
				std::shared_ptr<CollectionType> coll = std::dynamic_pointer_cast<CollectionType>(type);
				std::shared_ptr<CollectionType> collOf = std::dynamic_pointer_cast<CollectionType>(ofType);

				if((nullptr !=  coll)  && (nullptr != collOf) )
				{
					if(coll->getElementType() == nullptr || collOf->getElementType() == nullptr)
						return true;
					else
						return kindOf(coll->getElementType(), collOf->getElementType());
				}
				else {
					return true;
				}
			}
		}
	}
    return false;
}

std::shared_ptr<ecore::EOperation> OclReflection::lookupOperation(std::shared_ptr<ecore::EClass> eclass, const std::string& name, std::shared_ptr<Bag<OclExpression>> arguments)
{
    std::shared_ptr<Bag<ecore::EOperation>> ecore_operations = eclass->getEAllOperations();
    Bag<ecore::EOperation>::const_iterator endIt_operation = ecore_operations->end();
    for (Bag<ecore::EOperation>::const_iterator it_operation = ecore_operations->begin();
         it_operation != endIt_operation; ++it_operation)
    {
        //std::cout << (*it_operation)->getName() << std::endl;
        if ((*it_operation)->getName() == name && (*it_operation)->getEParameters()->size() == arguments->size()) {
            for(size_t i = 0; i < (*it_operation)->getEParameters()->size(); i++) {
                std::shared_ptr<ecore::EParameter> p = (*it_operation)->getEParameters()->at(i);
                std::shared_ptr<OclExpression> e = arguments->at(i);
                if(p->getEType()->getClassifierID() != e->getEType()->getClassifierID()) {
                    return nullptr; // different parameter
                }
            }
            return (*it_operation);
        }
    }
    return nullptr;
}

std::shared_ptr<ecore::EAttribute> OclReflection::lookupProperty(std::shared_ptr<ecore::EClass> eclass, const std::string& name)
{
    std::shared_ptr<Bag<ecore::EAttribute>> ecore_attribute = eclass->getEAllAttributes();
    Bag<ecore::EAttribute>::const_iterator endIt_attribute = ecore_attribute->end();
    for (Bag<ecore::EAttribute>::const_iterator it_attribute = ecore_attribute->begin();
         it_attribute != endIt_attribute; ++it_attribute)
    {
        //std::cout << (*it_attribute)->getName() << std::endl;
        if ((*it_attribute)->getName() == name) {
            return (*it_attribute);
        }
    }
    return nullptr;
}

std::shared_ptr<ecore::EReference> OclReflection::lookupAssociationClass(std::shared_ptr<ecore::EClass> eclass, const std::string& name)
{
    std::shared_ptr<Bag<ecore::EReference>> ecore_reference = eclass->getEAllReferences();
    Bag<ecore::EReference>::const_iterator endIt_reference = ecore_reference->end();
    for (Bag<ecore::EReference>::const_iterator it_reference = ecore_reference->begin();
         it_reference != endIt_reference; ++it_reference)
    {
        //std::cout << (*it_reference)->getName() << std::endl;
        if ((*it_reference)->getName() == name) {
            return (*it_reference);
        }
    }
    return nullptr;
}

Any OclReflection::retrieveRawValue(std::shared_ptr<fUML::Semantics::Values::Value> fromValue)
{
	std::shared_ptr<CollectionValue> colValue = std::dynamic_pointer_cast<CollectionValue>(fromValue);
    if(nullptr != colValue)
    {
        std::shared_ptr<Bag<ocl::Values::Element>> values=colValue->getElements();

        std::shared_ptr<Bag<AnyObject>> bagValue = std::make_shared<Bag<AnyObject>>();
        size_t size=colValue->getElements()->size();
        for(size_t i = 0; i < size; i++) {
            std::shared_ptr<fUML::Semantics::Values::Value> src = colValue->getElements()->at(i)->getValue();
            Any objValue = retrieveRawValue(src);
            if(objValue != nullptr) {
                bagValue->add(objValue);
            }
        }
        return eAny(bagValue,0,true);
    }
    else {
        return retrieveNotManyRawValue(fromValue);
    }
}

Any OclReflection::retrieveNotManyRawValue(std::shared_ptr<fUML::Semantics::Values::Value> fromValue)
{
	std::shared_ptr<ObjectValue> value = std::dynamic_pointer_cast<ObjectValue>(fromValue);
    if(nullptr!= value)
    {
    	std::shared_ptr<ecore::EObject> objectValue= value->getValue();
        return eAny(objectValue,objectValue->getMetaElementID(),false);
    }
   	std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> enumValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::EnumerationValue>(fromValue);
   	if(nullptr!=enumValue)
   	{
   		std::shared_ptr<uml::EnumerationLiteral> enumLiteral=enumValue->getLiteral();
       	return eAny(enumLiteral,enumLiteral->getMetaElementID(),false);
   	}
   	std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> stringValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(fromValue);
   	if(nullptr!=stringValue)
   	{
   		return eAny(stringValue->getValue(),types::typesPackage::STRING_CLASS,false);
   	}
    std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> booleanValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(fromValue);
   	if(nullptr!=booleanValue )
   	{
        return eAny(booleanValue->isValue(),types::typesPackage::BOOLEAN_CLASS,false);
    }
    std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> integerValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::IntegerValue>(fromValue);
   	if(nullptr!=integerValue)
    {
        return eAny(integerValue->getValue(),types::typesPackage::INTEGER_CLASS,false);
    }
    std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> realValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::RealValue>(fromValue);
    if(nullptr!=realValue)
    {
        return eAny(realValue->getValue(),types::typesPackage::REAL_CLASS,false);
    }
    std::shared_ptr<ocl::Values::AnyValue> anyValue = std::dynamic_pointer_cast<ocl::Values::AnyValue>(fromValue);
    if(nullptr != anyValue)
    {
        return anyValue->getValue();
    }
    return nullptr; // unknown Value
}

std::shared_ptr<fUML::Semantics::Values::Value> OclReflection::createValue(std::shared_ptr<ecore::EObject> obj)
{
    std::shared_ptr<ObjectValue> objValue = ocl::Values::ValuesFactory::eInstance()->createObjectValue();
    objValue->setValue(obj);
    return objValue;
}


std::shared_ptr<fUML::Semantics::Values::Value> OclReflection::createValue(std::shared_ptr<ecore::ETypedElement> typedElement, Any value)
{
	if((value)&&(!value->isEmpty()))
	{
		if(value->isContainer())
		{
			try
			{
				std::shared_ptr<BagTypeValue> bagValue = ocl::Values::ValuesFactory::eInstance()->createBagTypeValue();
				switch (value->getTypeId())
				{
					case ecore::ecorePackage::EOBJECT_CLASS:
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectBag;
						std::shared_ptr<AnyEObjectBag> anyObjectBag = std::dynamic_pointer_cast<AnyEObjectBag>(value);
						if(nullptr!=anyObjectBag)// AnyEobjectBag?
						{
							eObjectBag=anyObjectBag->getBag();
						}
						else
						{
							eObjectBag= value->get<std::shared_ptr<Bag<ecore::EObject>>>(); //throws exception

						}
						for(const std::shared_ptr<ecore::EObject> object: *eObjectBag)
						{	// recursive Call of convertToString via new Any EObject Value
							std::shared_ptr<fUML::Semantics::Values::Value> val = createValue(object);
							bagValue->addValue(val);
						}
						break;
					}
					case ecore::ecorePackage::EOBJECTCONTAINER_CLASS:
					{
						std::shared_ptr<ecore::EObjectContainer> eObjectContainer = value->get<std::shared_ptr<ecore::EObjectContainer>>();
						std::shared_ptr<Bag<ecore::EObject>> eObjectBag =  eObjectContainer->getContainer();
						for(const std::shared_ptr<ecore::EObject> object: *eObjectBag)
						{	// recursive Call of convertToString via new Any EObject Value
							std::shared_ptr<fUML::Semantics::Values::Value> val = createValue(object);
							bagValue->addValue(val);
						}
						break;
					}
					case ecore::ecorePackage::ANY_CLASS:
					{
						try
						{
							std::shared_ptr<Bag<AnyObject>> anyBag= value->get<std::shared_ptr<Bag<AnyObject>>>(); //throws exception
							for(const std::shared_ptr<AnyObject> anyObject: *anyBag)
							{
								std::shared_ptr<fUML::Semantics::Values::Value> val = createValue(typedElement, anyObject);
								bagValue->addValue(val);
							}
						}
						catch(...) // it is possible too, but getBag() cant cast from Any to EObject
						{
							/*
							std::shared_ptr<AnyEObjectBag> anyObjectBag = std::dynamic_pointer_cast<AnyEObjectBag>(value);
							if(nullptr!=anyObjectBag)// AnyEObjectBag?
							{
								std::shared_ptr<Bag<ecore::EObject>> eObjectBag=anyObjectBag->getBag();
								for(const std::shared_ptr<ecore::EObject> object: *eObjectBag)
								{	// recursive Call of convertToString via new Any EObject Value
									std::shared_ptr<fUML::Semantics::Values::Value> val = createValue(object);
									bagValue->addValue(val);
								}
							}
							else
							{
								try // last try
								{
//									eObjectBag= value->get<std::shared_ptr<Bag<ecore::EObject>>>(); //throws exception
								}
								catch(...){}
							}*/
						}
						break;
					}
					default:
					{
						try
						{
							std::shared_ptr<Bag<AnyObject>> anyBag = value->get<std::shared_ptr<Bag<AnyObject>>>();
							for(std::shared_ptr<AnyObject> object: *anyBag)
							{
								std::shared_ptr<ocl::Values::AnyValue> anyValue = ocl::Values::ValuesFactory::eInstance()->createAnyValue();
								anyValue->setValue(object); // A Bag in AnyValue, can be AnyValue...
								bagValue->addValue(anyValue);
							}
							break;
						}
						catch(...)
						{
							std::shared_ptr<AnyEObjectBag> anyObjectBag = std::dynamic_pointer_cast<AnyEObjectBag>(value);
							if(nullptr!=anyObjectBag)// AnyEObjectBag?
							{
								std::shared_ptr<Bag<ecore::EObject>> eObjectBag=anyObjectBag->getBag();
								for(const std::shared_ptr<ecore::EObject> object: *eObjectBag)
								{	// recursive Call of convertToString via new Any EObject Value
									std::shared_ptr<fUML::Semantics::Values::Value> val = createValue(object);
									bagValue->addValue(val);
								}
								break;
							}
							else // last supported type bag<Any>
							{
								DEBUG_MESSAGE(std::cerr << " OclReflection: Bag unknown type for:" << typedElement->getName() << std::endl;)
							}
						}
					}
				}
				return bagValue;
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cerr << " OclReflection: unknown type for:" << typedElement->getName() << std::endl;)
			}
		}
		else
		{
			try
			{
				switch(value->getTypeId())
				{
					case ecore::ecorePackage::EOBJECT_CLASS: // unknown or primitive type
					{
						std::shared_ptr<ecore::EObject> obj = value->get<std::shared_ptr<ecore::EObject>>();
						return createValue(obj);
						break;
					}
					case ecore::ecorePackage::EATTRIBUTE_CLASS:
					{
						std::shared_ptr<ecore::EAttribute> aValue = value->get<std::shared_ptr<ecore::EAttribute>>();
						return createValue(aValue);
						break;
					}
					case ecore::ecorePackage::EREFERENCE_CLASS:
					{
						std::shared_ptr<ecore::EReference> aValue = value->get<std::shared_ptr<ecore::EReference>>();
						return createValue(aValue);
						break;
					}
					case ecore::ecorePackage::EOPERATION_CLASS:
					{
						std::shared_ptr<ecore::EOperation> aValue = value->get<std::shared_ptr<ecore::EOperation>>();
						return createValue(aValue);
						break;
					}
					case ecore::ecorePackage::EOBJECTCONTAINER_CLASS:
					{
						std::shared_ptr<ecore::EObjectContainer> eObjectContainer = value->get<std::shared_ptr<ecore::EObjectContainer>>();
						std::shared_ptr<BagTypeValue> bagValue = ocl::Values::ValuesFactory::eInstance()->createBagTypeValue();
						for(const std::shared_ptr<ecore::EObject> object: *(eObjectContainer->getContainer()))
						{	// recursive Call of createValue
							std::shared_ptr<fUML::Semantics::Values::Value> val = createValue(object);
							bagValue->addValue(val);
						}
						return bagValue;
						break;
					}
					case ecore::ecorePackage::EDATATYPE_CLASS:
					{
						std::shared_ptr<ecore::EDataType> obj = value->get<std::shared_ptr<ecore::EDataType>>();
						return createValue(obj);
						break;
					}
					case ecore::ecorePackage::ECLASSIFIER_CLASS:
					{
						std::shared_ptr<ecore::EClassifier> obj = value->get<std::shared_ptr<ecore::EClassifier>>();
						return createValue(obj);
						break;
					}
					case ecore::ecorePackage::ECLASS_CLASS:
					{
						std::shared_ptr<ecore::EClass> obj = value->get<std::shared_ptr<ecore::EClass>>();
						return createValue(obj);
						break;
					}
					case ecore::ecorePackage::ESTRUCTURALFEATURE_CLASS:
					{
						std::shared_ptr<ecore::EStructuralFeature> obj = value->get<std::shared_ptr<ecore::EStructuralFeature>>();
						return createValue(obj);
						break;
					}
					//bool
					case ecore::ecorePackage::EBOOLEANOBJECT_CLASS:
					case ecore::ecorePackage::EBOOLEAN_CLASS:
					{
						bool result = value->get<bool>();
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> boolValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
						boolValue->setValue(result);
						return boolValue;
						break;
					}
					//char
					case ecore::ecorePackage::EBYTE_CLASS:
					case ecore::ecorePackage::EBYTEARRAY_CLASS:
					case ecore::ecorePackage::EBYTEOBJECT_CLASS:
					case ecore::ecorePackage::ECHARACTEROBJECT_CLASS:
					case ecore::ecorePackage::ECHAR_CLASS:
					{
						int result = value->get<char>();
						// interprete char as int value
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> intValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createIntegerValue();
						intValue->setValue(result);
						return intValue;
						break;
					}
					//int
					case ecore::ecorePackage::EDATE_CLASS:
					case ecore::ecorePackage::ERESOURCE_CLASS:
					case ecore::ecorePackage::EINTEGEROBJECT_CLASS:
					case ecore::ecorePackage::EBIGINTEGER_CLASS:
					case ecore::ecorePackage::EINT_CLASS:
					{
						int result = value->get<int>();
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> intValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createIntegerValue();
						intValue->setValue(result);
						return intValue;
						break;
					}
					//long
					case ecore::ecorePackage::ELONGOBJECT_CLASS:
					case ecore::ecorePackage::ELONG_CLASS:
					{
						int result = value->get<long>();
						// only in Values right now --> interprete long as int value
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> intValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createIntegerValue();
						intValue->setValue(result);
						return intValue;
						break;
					}
					//float
					case ecore::ecorePackage::EFLOATOBJECT_CLASS:
					case ecore::ecorePackage::EFLOAT_CLASS:
					{
						int result = value->get<float>();
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> realValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createRealValue();
						realValue->setValue(result);
						break;
					}
					//double
					case ecore::ecorePackage::EBIGDECIMAL_CLASS:
					case ecore::ecorePackage::EDOUBLE_CLASS:
					{
						int result = value->get<double>();
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> realValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createRealValue();
						realValue->setValue(result);
						break;
					}
					//std::string
					case ecore::ecorePackage::ESTRING_CLASS:
					{
						std::string result = value->get<std::string>();
						std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> stringValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
						stringValue->setValue(result);
						return stringValue;
						break;
					}
					/*
					//Any
					case ecore::ecorePackage::EJAVAOBJECT_CLASS:
					case ecore::ecorePackage::EENUMERATOR_CLASS:
					case ecore::ecorePackage::EDIAGNOSTICCHAIN_CLASS:
					case ecore::ecorePackage::ANY_CLASS:
					{
						std::shared_ptr<AnyObject> any = value->get<std::shared_ptr<AnyObject>>();
						returnStringStream << "<AnyObject>:" << std::endl;
						returnStringStream << convertToString(eDataType, any) << std::endl;
						break;
					}
					*/
					default: // unknown or primitive type / or 0--> Try & Error
					{
						try {
							bool result = value->get<bool>();
							std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> boolValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
							boolValue->setValue(result);
							return boolValue;
							break;
						} catch (...) { }
						try {
							int result = value->get<int>();
							std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> intValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createIntegerValue();
							intValue->setValue(result);
							return intValue;
							break;
						} catch (...) { }
						try {
							std::string result = value->get<std::string>();
							std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> stringValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
							stringValue->setValue(result);
							return stringValue;
							break;
						} catch (...) { }
						try {
							double result = value->get<double>();
							std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> realValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createRealValue();
							realValue->setValue(result);
							break;
						} catch (...){}
						try {
							std::shared_ptr<AnyObject> any = value->get<std::shared_ptr<AnyObject>>();
							std::shared_ptr<ocl::Values::AnyValue> anyValue = ocl::Values::ValuesFactory::eInstance()->createAnyValue();
							anyValue->setValue(value); // A Bag in AnyValue, can be AnyValue...
					        return anyValue;
							break;
						} catch (...) { }
						{
							DEBUG_MESSAGE(std::cerr << " OclReflection: Unknown value for:" << typedElement->getName() std::endl;)
							std::shared_ptr<ocl::Values::AnyValue> anyValue = ocl::Values::ValuesFactory::eInstance()->createAnyValue();
							anyValue->setValue(value); // A Bag in AnyValue, can be AnyValue...
							return anyValue;
						}
					}
				}
			}
			catch (...) { }
			{
				DEBUG_MESSAGE(std::cerr << " OclReflection: Invalid value for:" << typedElement->getName() std::endl;)
			}
		}
    }
	//else create an anyValue
	std::shared_ptr<ocl::Values::AnyValue> anyValue = ocl::Values::ValuesFactory::eInstance()->createAnyValue();
	anyValue->setValue(value);
	return anyValue;
    // else create emptyValue with given type
//    return createValue(typedElement->getEType());
}

std::shared_ptr<fUML::Semantics::Values::Value> OclReflection::createValueOfStructuralFeatureFromEObject(std::shared_ptr<ecore::EStructuralFeature> type, const std::shared_ptr<ecore::EObject> obj)
{
	if(nullptr!=obj)
	{
		std::shared_ptr<uml::Element> uobj = std::dynamic_pointer_cast<uml::Element>(obj); // check UML or ecore Model Element
		std::shared_ptr<AnyObject> value = nullptr;

		if(nullptr!=uobj && nullptr!=uobj->eClass())
		{
			std::shared_ptr<uml::Class> umlMetaClass=uobj->getMetaClass();
			if(nullptr!=umlMetaClass)
			{
				std::shared_ptr<uml::Property> prop = lookupProperty(umlMetaClass, type->getName());
				if(prop != nullptr)
				{
					value = uobj->get(prop);
				}
			}
			else // 2. try is an uml generated uml-model
			{
				/* replaced by eGet
				std::shared_ptr<ecore::EAttribute> prop = lookupProperty(uobj->eClass(), type->getName());
				std::shared_ptr<ecore::EReference>  ref = lookupAssociationClass(uobj->eClass(), type->getName());

				if(prop != nullptr)
				{...
				}*/
				value = obj->eGet(type);
			}
		}
		else
		{
			value = obj->eGet(type);
		}
		return OclReflection::createValue(type, value);
	}
    return ocl::Values::ValuesFactory::eInstance()->createUndefinedValue();
}

std::shared_ptr<fUML::Semantics::Values::Value> OclReflection::createValue(std::shared_ptr<ecore::EStructuralFeature> type, std::shared_ptr<fUML::Semantics::Values::Value> fromValue)
{
    std::shared_ptr<CollectionValue> colValue = std::dynamic_pointer_cast<CollectionValue>(fromValue);
	if(nullptr!= colValue )
    {
        std::shared_ptr<BagTypeValue> bagValue = ocl::Values::ValuesFactory::eInstance()->createBagTypeValue();
//        std::shared_ptr<BagType> bagType = ocl::Types::TypesFactory::eInstance()->createBagType();
//        bagType->setElementType(type->getEType());
//        bagValue->setModel(bagType);
        for(size_t i = 0; i < colValue->getElements()->size(); i++) {
            std::shared_ptr<fUML::Semantics::Values::Value> src = colValue->getElements()->at(i)->getValue();
            std::shared_ptr<fUML::Semantics::Values::Value> dst = createValue(type, src);
            bagValue->addValue(dst);
        }
        return bagValue;
    }
    else
    {
		std::shared_ptr<ObjectValue> objValue = std::dynamic_pointer_cast<ObjectValue>(fromValue);

    	if(nullptr!=objValue)
		{
			std::shared_ptr<ecore::EObject> obj = objValue->getValue();
			return createValueOfStructuralFeatureFromEObject(type, obj);
		}
		else
		{// primitive value not managed yet
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> stringValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(fromValue);
			if(nullptr != stringValue)
			{
				std::string value = stringValue->getValue();
				return stringValue;
			}
			else
			{
				std::shared_ptr<AnyValue> anyValue = std::dynamic_pointer_cast<AnyValue>(fromValue);
				if(nullptr!=anyValue)
				{
					Any anAny= anyValue->getValue();
					try
					{
						std::shared_ptr<AnyEObjectBag> eObjectAnyBag = std::dynamic_pointer_cast<AnyEObjectBag>(anAny);
						if(nullptr!=eObjectAnyBag)
						{
					        std::shared_ptr<BagTypeValue> bagValue = ocl::Values::ValuesFactory::eInstance()->createBagTypeValue();

							std::shared_ptr<Bag<ecore::EObject>> eObjectBag=eObjectAnyBag->getBag();
							for(const std::shared_ptr<ecore::EObject> object: *eObjectBag)
							{	// recursive Call of convertToString via new Any EObject Value
								std::shared_ptr<fUML::Semantics::Values::Value> value= createValueOfStructuralFeatureFromEObject(type,object);
								if(nullptr!=value)
								{
									bagValue->addValue(value);
								}
							}
							return bagValue;
						}
						else
						{
							std::shared_ptr<ecore::EObject> obj =nullptr;

							std::shared_ptr<AnyEObject> eObjectAny = std::dynamic_pointer_cast<AnyEObject>(anAny);
							if(nullptr!=eObjectAny)
							{
								obj=eObjectAny->getObject();
							}
							else
							{
								obj = anAny->get<std::shared_ptr<ecore::EObject>>();
							}
							return createValueOfStructuralFeatureFromEObject(type,obj);
						}
					}
					catch(...){
/*						try
						{
							std::shared_ptr<ecore::EObject> obj = anAny->get<std::shared_ptr<ecore::EObject>>();
						}
						catch(...){

						}*/
					}
				}
			}
			return ocl::Values::ValuesFactory::eInstance()->createUndefinedValue();
		}
    }
    return ocl::Values::ValuesFactory::eInstance()->createUndefinedValue();
}

std::shared_ptr<fUML::Semantics::Values::Value> OclReflection::createValue(std::shared_ptr<ecore::EOperation> operation, std::shared_ptr<Bag<OclExpression>> arguments, std::shared_ptr<fUML::Semantics::Values::Value> fromValue)
{
    std::shared_ptr<CollectionValue> colValue = std::dynamic_pointer_cast<CollectionValue>(fromValue);
    if(nullptr != colValue) {

        std::shared_ptr<BagTypeValue> bagValue = ocl::Values::ValuesFactory::eInstance()->createBagTypeValue();
//        std::shared_ptr<BagType> bagType = ocl::Types::TypesFactory::eInstance()->createBagType();
//        bagType->setElementType(operation->getEType());
//        bagValue->setModel(bagType);

        for(size_t i = 0; i < colValue->getElements()->size(); i++) {
            std::shared_ptr<fUML::Semantics::Values::Value> src = colValue->getElements()->at(i)->getValue();
            std::shared_ptr<fUML::Semantics::Values::Value> dst = createValue(operation, arguments, src);
            bagValue->addValue(dst);
        }
        return bagValue;
    }
    else
    {
        std::shared_ptr<ObjectValue> objValue = std::dynamic_pointer_cast<ObjectValue>(fromValue);
    	if(nullptr!= objValue )
    	{
			std::shared_ptr<ecore::EObject> obj = objValue->getValue();
			std::shared_ptr<std::list<Any>> convertArgs = std::make_shared<std::list<Any>>();

			// create the pre value snapshot
			// copy object to avoid modifying the given context
			//ToDo Don't Copy! use const
			std::shared_ptr<ecore::EObject> preObj = obj;//->copy(); // ToDo: avoid set Values not using a copy!!
			std::shared_ptr<ObjectValue> preValue = std::dynamic_pointer_cast<ObjectValue>(createValue(preObj));
			std::shared_ptr<NameValueBinding> nvbPre = ocl::Values::ValuesFactory::eInstance()->createNameValueBinding();
			std::shared_ptr<LocalSnapshot> localSnapshotPre = ocl::Values::ValuesFactory::eInstance()->createLocalSnapshot();
			nvbPre->setName("pre");
			nvbPre->setValue(preValue);
			localSnapshotPre->setIsPre(true);
			localSnapshotPre->getBindings()->add(nvbPre);

			// create the post value snapshot
			//ToDo Don't Copy! use const
			std::shared_ptr<ecore::EObject> postObj = obj;//->copy();// ToDo: avoid set Values not using a copy!!
			std::shared_ptr<ObjectValue> postValue = std::dynamic_pointer_cast<ObjectValue>(createValue(postObj));
			std::shared_ptr<NameValueBinding> nvbPost = ocl::Values::ValuesFactory::eInstance()->createNameValueBinding();
			std::shared_ptr<LocalSnapshot> localSnapshotPost = ocl::Values::ValuesFactory::eInstance()->createLocalSnapshot();
			nvbPost->setName("post");
			nvbPost->setValue(postValue);
			localSnapshotPost->setIsPost(true);
			localSnapshotPost->getBindings()->add(nvbPost);

			localSnapshotPre->setSucc(localSnapshotPost);
			localSnapshotPost->setPred(localSnapshotPre);
			objValue->getHistory()->add(localSnapshotPre);
			objValue->getHistory()->add(localSnapshotPost);
			postValue->getHistory()->add(localSnapshotPre);
			postValue->getHistory()->add(localSnapshotPost);
			preValue->getHistory()->add(localSnapshotPre);
			preValue->getHistory()->add(localSnapshotPost);

			for(size_t i = 0; i < arguments->size(); i++) {
				Any item = retrieveRawValue(arguments->at(i)->getInstance()->getResultValue());
				convertArgs->push_back(item );
			}
			std::shared_ptr<AnyObject> value = postObj->eInvoke(operation, convertArgs);

			return OclReflection::createValue(operation, value);
		}
		else
		{ // primitive value not managed yet
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> stringValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(fromValue);
			if(nullptr!= stringValue )
			{
				std::string value = stringValue->getValue();
				return stringValue;
			}
			return ocl::Values::ValuesFactory::eInstance()->createUndefinedValue();
		}
    }
}

std::string OclReflection::getStringValue(std::shared_ptr<OclExpression> source)
{
    return source->getInstance()->getResultValue()->toString();
}

Any OclReflection::getAnyValue(std::shared_ptr<OclExpression> source)
{
    return retrieveRawValue(source->getInstance()->getResultValue());
}

bool OclReflection::getResult(std::shared_ptr<OclExpression> source)
{
    std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value =
            std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(source->getInstance()->getResultValue());
    if(value != nullptr) {
        return value->isValue();
    }
    return true;
}

std::shared_ptr<ecore::EPackage> OclReflection::umlPackage2Ecore(std::shared_ptr<uml::Package> upackage)
{
	static std::shared_ptr<uml::Package> lastPackage=nullptr;
	static std::shared_ptr<ecore::EPackage> epackage=nullptr;

	if(nullptr!=lastPackage && nullptr!= epackage && lastPackage==upackage)
	{
		return epackage;
	}
	else
	{
		lastPackage=upackage;
		std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		epackage = factory->createEPackage(upackage->getMetaElementID());
		epackage->setName(upackage->getName());

		for(size_t i = 0; i < upackage->getOwnedElement()->size(); i++) {
			std::shared_ptr<uml::Element> type = upackage->getOwnedElement()->at(i);
			std::shared_ptr<uml::Class> uclass = std::dynamic_pointer_cast<uml::Class>(type);
			if(uclass != nullptr) {
				std::shared_ptr<ecore::EClass> c = factory->createEClass_as_eClassifiers_in_EPackage(epackage, uclass->getMetaElementID());
				c->setName(uclass->getName());
				//std::cout << "class : " << c->getName() << std::endl;
			}
			else {
				std::shared_ptr<uml::Enumeration> uenum = std::dynamic_pointer_cast<uml::Enumeration>(type);
				if(uenum != nullptr) {
					std::shared_ptr<ecore::EEnum> eenum =factory->createEEnum_as_eClassifiers_in_EPackage(epackage, uenum->getMetaElementID());
					eenum->setName(uenum->getName());
					//std::cout << "enum : " << uenum->getName() << std::endl;
				}
			}
		}
		for(size_t i = 0; i < upackage->getOwnedElement()->size(); i++) {
			std::shared_ptr<uml::Element> type = upackage->getOwnedElement()->at(i);
			std::shared_ptr<uml::Classifier> utype = std::dynamic_pointer_cast<uml::Classifier>(type);
			if(utype == nullptr) {
				continue;
			}
			std::shared_ptr<uml::Class> uclass = std::dynamic_pointer_cast<uml::Class>(utype);
			std::shared_ptr<ecore::EClassifier> eclassifier = epackage->getEClassifier(utype->getName());
			std::shared_ptr<ecore::EClass> eclass = std::dynamic_pointer_cast<ecore::EClass>(eclassifier);

			if(uclass != nullptr) {
				std::shared_ptr<Bag<uml::Property>> uml_attribute = uclass->getAllAttributes();
				Bag<uml::Property>::const_iterator endIt_attribute = uml_attribute->end();
				for (Bag<uml::Property>::const_iterator it_attribute = uml_attribute->begin();
					 it_attribute != endIt_attribute; ++it_attribute)
				{
					std::shared_ptr<ecore::EStructuralFeature> prop = nullptr;
					if((*it_attribute)->getAssociation() == nullptr) {
						prop = ecore::ecoreFactory::eInstance()->createEAttribute_as_eAttributes_in_EClass(eclass, (*it_attribute)->getMetaElementID());
					}
					else {
						prop = ecore::ecoreFactory::eInstance()->createEReference_as_eReferences_in_EClass(eclass, (*it_attribute)->getMetaElementID());
					}
					std::string name = (*it_attribute)->getName();
					std::shared_ptr<ecore::EClassifier> propType = createClassifier(epackage, (*it_attribute)->getType());

					prop->setEType(propType);
					prop->setName(name);
					prop->setDefaultValue(getDefaultValue((*it_attribute)));
					prop->setUpperBound((*it_attribute)->getUpper());
					prop->setLowerBound((*it_attribute)->getLower());
				}
				std::shared_ptr<Bag<uml::Operation>> uml_operations = uclass->getOwnedOperation();
				Bag<uml::Operation>::const_iterator endIt_operation = uml_operations->end();
				for (Bag<uml::Operation>::const_iterator it_operation = uml_operations->begin();
					 it_operation != endIt_operation; ++it_operation)
				{
					std::shared_ptr<uml::Operation> currentOp = *it_operation;
					std::shared_ptr<ecore::EOperation> op = ecore::ecoreFactory::eInstance()->createEOperation_as_eOperations_in_EClass(eclass, currentOp->getMetaElementID());
					std::string name = currentOp->getName();
					std::shared_ptr<ecore::EClassifier> propType = createClassifier(epackage, currentOp->getType());
					op->setName(name);
					if(propType != nullptr) {
						op->setEType(propType);
					}
					//std::cout << name << std::endl;
					std::shared_ptr<Bag<uml::Parameter>> currentParams = std::dynamic_pointer_cast<Bag<uml::Parameter>>(currentOp->getOwnedParameter());
					for(size_t j = 0; j < currentParams->size(); j++) {
						std::shared_ptr<uml::Parameter> p = currentParams->at(j);
						if(p->getDirection() != uml::ParameterDirectionKind::RETURN) {
							std::shared_ptr<ecore::EParameter> param = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(op, p->getMetaElementID());
							std::shared_ptr<ecore::EClassifier> currentPropType = createClassifier(epackage, p->getType());
							param->setEType(currentPropType);
							param->setName(p->getName());
							param->setUpperBound(p->getUpper());
							param->setLowerBound(p->getLower());
						}
					}
				}
			}
			else {
				std::shared_ptr<ecore::EEnum> eenum = std::dynamic_pointer_cast<ecore::EEnum>(eclassifier);
				std::shared_ptr<uml::Enumeration> uenum = std::dynamic_pointer_cast<uml::Enumeration>(utype);
				if(eenum != nullptr && uenum != nullptr) {
					std::shared_ptr<Bag<uml::EnumerationLiteral>> uliteral = uenum->getOwnedLiteral();
					Bag<uml::EnumerationLiteral>::const_iterator endIt_literal = uliteral->end();
					for (Bag<uml::EnumerationLiteral>::const_iterator it_literal = uliteral->begin();
						 it_literal != endIt_literal; ++it_literal)
					{
						std::shared_ptr<ecore::EEnumLiteral> literal = ecore::ecoreFactory::eInstance()->createEEnumLiteral_as_eLiterals_in_EEnum(eenum, (*it_literal)->getMetaElementID());
						literal->setName((*it_literal)->getName());
						//std::cout << (*it_literal)->getName() << std::endl;
					}
				}
			}
		}
	}
    return epackage;
}

Any OclReflection::getDefaultValue(std::shared_ptr<uml::Property> prop)
{
    if(prop == nullptr) return nullptr;
    std::string name = prop->getType()->getName();
    std::shared_ptr<uml::ValueSpecification> value = prop->getDefaultValue();
    Any any = nullptr;
    if(prop->getDefaultValue() != nullptr) { // association
        if(name == PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean()->getName()){
            std::shared_ptr<uml::LiteralBoolean> lit = std::dynamic_pointer_cast<uml::LiteralBoolean>(value);
            any = eAny(lit->getValue(),types::typesPackage::BOOLEAN_CLASS,false);
        }
        else if(name == PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer()->getName()){
            std::shared_ptr<uml::LiteralInteger> lit = std::dynamic_pointer_cast<uml::LiteralInteger>(value);
            any = eAny(lit->getValue(),types::typesPackage::INTEGER_CLASS,false);
        }
        else if(name == PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real()->getName()){
            std::shared_ptr<uml::LiteralReal> lit = std::dynamic_pointer_cast<uml::LiteralReal>(value);
            any = eAny(lit->getValue(),types::typesPackage::REAL_CLASS,false);
        }
        else if(name == PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String()->getName()){
            std::shared_ptr<uml::LiteralString> lit = std::dynamic_pointer_cast<uml::LiteralString>(value);
            any = eAny(lit->getValue(),types::typesPackage::STRING_CLASS,false);
        }
        else if(name == PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_UnlimitedNatural()->getName()){
            std::shared_ptr<uml::LiteralUnlimitedNatural> lit = std::dynamic_pointer_cast<uml::LiteralUnlimitedNatural>(value);
            any = eAny(lit->getValue(),types::typesPackage::UNLIMITEDNATURAL_CLASS,false);
        }
    }

    return any;
}

std::shared_ptr<ecore::EClassifier> OclReflection::createClassifier(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<uml::Type> type)
{
    if(type == nullptr) return nullptr;

    std::string name = type->getName();
    std::shared_ptr<ecore::EClassifier> propType = package->getEClassifier(name);
    if(propType != nullptr) { // association
        return propType;
    }
    else if(name == PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean()->getName()){
        propType = ::types::typesPackage::eInstance()->getBoolean_Class();
    }
    else if(name == PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer()->getName()){
        propType = ::types::typesPackage::eInstance()->getInteger_Class();
    }
    else if(name == PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real()->getName()){
        propType = ::types::typesPackage::eInstance()->getReal_Class();
    }
    else if(name == PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String()->getName()){
        propType = ::types::typesPackage::eInstance()->getString_Class();
    }
    else if(name == PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_UnlimitedNatural()->getName()){
        propType = ::types::typesPackage::eInstance()->getUnlimitedNatural_Class();
    }
    return propType;
}

