#include "OclReflection.h"

#include <ecore/EEnum.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EParameter.hpp>
#include <ecore/ecorePackage.hpp>
#include <ecore/ETypeParameter.hpp>
#include <abstractDataTypes/Bag.hpp>
#include <abstractDataTypes/Subset.hpp>
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
        //std::cout << (*it_attribute)->getName() << std::endl;
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
    std::shared_ptr<ecore::EClass> eclass = std::dynamic_pointer_cast<ecore::EClass>(type->eClass());
    std::shared_ptr<ecore::EClass> eclassOf = std::dynamic_pointer_cast<ecore::EClass>(ofType->eClass());
    if(eclass != nullptr && eclassOf != nullptr) {
        if(eclassOf->isSuperTypeOf(eclass)) {
            if(instanceOf<CollectionType>(type) && instanceOf<CollectionType>(ofType)) {
                std::shared_ptr<CollectionType> coll = std::dynamic_pointer_cast<CollectionType>(type);
                std::shared_ptr<CollectionType> collOf = std::dynamic_pointer_cast<CollectionType>(ofType);

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
    return type->getClassifierID() == ofType->getClassifierID() && type->getClassifierID() != -1 && ofType->getClassifierID() != -1;
}

std::shared_ptr<ecore::EOperation> OclReflection::lookupOperation(std::shared_ptr<ecore::EClass> eclass,
                                                                  const std::string& name, std::shared_ptr<Bag<OclExpression>> arguments)
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
    if(instanceOf<CollectionValue>(fromValue)) {
        std::shared_ptr<CollectionValue> colValue = std::dynamic_pointer_cast<CollectionValue>(fromValue);
        std::shared_ptr<Bag<AnyObject>> bagValue = std::make_shared<Bag<AnyObject>>();

        for(size_t i = 0; i < colValue->getElements()->size(); i++) {
            std::shared_ptr<fUML::Semantics::Values::Value> src = colValue->getElements()->at(i)->getValue();
            Any objValue = retrieveNotManyRawValue(src);
            if(objValue != nullptr) {
                bagValue->add(objValue);
            }
        }
        return eAny(bagValue);
    }
    else {
        return retrieveNotManyRawValue(fromValue);
    }
}

Any OclReflection::retrieveNotManyRawValue(std::shared_ptr<fUML::Semantics::Values::Value> fromValue)
{
    if(instanceOf<ObjectValue>(fromValue)) {
        std::shared_ptr<ObjectValue> value = std::dynamic_pointer_cast<ObjectValue>(fromValue);
        return eAny(value->getValue());
    }
    else if(instanceOf<fUML::Semantics::SimpleClassifiers::EnumerationValue>(fromValue)) {
        std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> value = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::EnumerationValue>(fromValue);
        return eAny(value->getLiteral());
    }
    else if(instanceOf<fUML::Semantics::SimpleClassifiers::StringValue>(fromValue)) {
        std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> value = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(fromValue);
        return eAny(value->getValue());
    }
    else if(instanceOf<fUML::Semantics::SimpleClassifiers::BooleanValue>(fromValue)) {
        std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> value = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::BooleanValue>(fromValue);
        return eAny(value->isValue());
    }
    else if(instanceOf<fUML::Semantics::SimpleClassifiers::IntegerValue>(fromValue)) {
        std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> value = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::IntegerValue>(fromValue);
        return eAny(value->getValue());
    }
    else if(instanceOf<fUML::Semantics::SimpleClassifiers::RealValue>(fromValue)) {
        std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> value = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::RealValue>(fromValue);
        return eAny(value->getValue());
    }
    else {
        return eAny(nullptr);
    }
}

std::shared_ptr<fUML::Semantics::Values::Value> OclReflection::createValue(std::shared_ptr<ecore::EObject> obj)
{
    std::shared_ptr<ObjectValue> objValue = ocl::Values::ValuesFactory::eInstance()->createObjectValue();
    objValue->setValue(obj);
    return objValue;
}


std::shared_ptr<fUML::Semantics::Values::Value> OclReflection::createValue(std::shared_ptr<ecore::ETypedElement> type, Any value)
{
    if(value != nullptr && !value->isEmpty()) {
        if(type != nullptr && isMany(type)) {
            std::shared_ptr<Bag<ecore::EObject>> valueItems = value->get<std::shared_ptr<Bag<ecore::EObject>>>();
            std::shared_ptr<BagTypeValue> bagValue = ocl::Values::ValuesFactory::eInstance()->createBagTypeValue();
            std::shared_ptr<BagType> bagType = ocl::Types::TypesFactory::eInstance()->createBagType();
            bagType->setElementType(type->getEType());
            bagValue->setModel(bagType);

            for(size_t i = 0; i < valueItems->size(); i++) {
                std::shared_ptr<fUML::Semantics::Values::Value> val = createValue(valueItems->at(i));
                bagValue->addValue(val);
            }
            return bagValue;
        }
        else {
            try {
                std::shared_ptr<ecore::EObject> obj = value->get<std::shared_ptr<ecore::EObject>>();
                return createValue(obj);
            } catch (...) { }

            try {
                std::shared_ptr<uml::EnumerationLiteral> liter = value->get<std::shared_ptr<uml::EnumerationLiteral>>();
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> value = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createEnumerationValue();
                value->setLiteral(liter);
            } catch (...) { }

            try {
                bool result = value->get<bool>();
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> boolValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createBooleanValue();
                boolValue->setValue(result);
                return boolValue;
            } catch (...) { }
            try {
                std::string result = value->get<std::string>();
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> stringValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createStringValue();
                stringValue->setValue(result);
                return stringValue;
            } catch (...) { }
            try {
                int result = value->get<int>();
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> intValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createIntegerValue();
                intValue->setValue(result);
                return intValue;
            } catch (...) { }
            try {
                double result = value->get<double>();
                std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> realValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createRealValue();
                realValue->setValue(result);
                return realValue;
            } catch (...) { }
        }
    }
    return createValue(type);
}

std::shared_ptr<fUML::Semantics::Values::Value> OclReflection::createValue(std::shared_ptr<ecore::EStructuralFeature> type, std::shared_ptr<fUML::Semantics::Values::Value> fromValue, Level level)
{
    if(instanceOf<CollectionValue>(fromValue)) {
        std::shared_ptr<CollectionValue> colValue = std::dynamic_pointer_cast<CollectionValue>(fromValue);
        std::shared_ptr<BagTypeValue> bagValue = ocl::Values::ValuesFactory::eInstance()->createBagTypeValue();
        std::shared_ptr<BagType> bagType = ocl::Types::TypesFactory::eInstance()->createBagType();
        bagType->setElementType(type->getEType());
        bagValue->setModel(bagType);

        for(size_t i = 0; i < colValue->getElements()->size(); i++) {
            std::shared_ptr<fUML::Semantics::Values::Value> src = colValue->getElements()->at(i)->getValue();
            std::shared_ptr<fUML::Semantics::Values::Value> dst = createValue(type, src, level);
            bagValue->addValue(dst);
        }
        return bagValue;
    }
    else if(instanceOf<ObjectValue>(fromValue)) {
        std::shared_ptr<ObjectValue> objValue = std::dynamic_pointer_cast<ObjectValue>(fromValue);
        std::shared_ptr<ecore::EObject> obj = objValue->getValue();
        std::shared_ptr<uml::Element> uobj = std::dynamic_pointer_cast<uml::Element>(obj);
        std::shared_ptr<AnyObject> value = nullptr;

        if(level == Level::M2 && uobj != nullptr && uobj->getMetaClass() != nullptr) {
            std::shared_ptr<uml::Property> prop = lookupProperty(uobj->getMetaClass(), type->getName());
            if(prop != nullptr) {
                value = uobj->get(prop);
            }
        }
        else {
            value = obj->eGet(type);
        }

        return OclReflection::createValue(type, value);
    }
    else
    {// primary value not managed yet
        if(instanceOf<fUML::Semantics::SimpleClassifiers::StringValue>(fromValue)) {
            std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> stringValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(fromValue);
            std::string value = stringValue->getValue();

        }
        return ocl::Values::ValuesFactory::eInstance()->createUndefinedValue();
    }
}

std::shared_ptr<fUML::Semantics::Values::Value> OclReflection::createValue(std::shared_ptr<ecore::EOperation> operation,
                                                                           std::shared_ptr<Bag<OclExpression>> arguments, std::shared_ptr<fUML::Semantics::Values::Value> fromValue)
{
    if(instanceOf<CollectionValue>(fromValue)) {
        std::shared_ptr<CollectionValue> colValue = std::dynamic_pointer_cast<CollectionValue>(fromValue);
        std::shared_ptr<BagTypeValue> bagValue = ocl::Values::ValuesFactory::eInstance()->createBagTypeValue();
        std::shared_ptr<BagType> bagType = ocl::Types::TypesFactory::eInstance()->createBagType();
        bagType->setElementType(operation->getEType());
        bagValue->setModel(bagType);

        for(size_t i = 0; i < colValue->getElements()->size(); i++) {
            std::shared_ptr<fUML::Semantics::Values::Value> src = colValue->getElements()->at(i)->getValue();
            std::shared_ptr<fUML::Semantics::Values::Value> dst = createValue(operation, arguments, src);
            bagValue->addValue(dst);
        }
        return bagValue;
    }
    else if(instanceOf<ObjectValue>(fromValue)) {
        std::shared_ptr<ObjectValue> objValue = std::dynamic_pointer_cast<ObjectValue>(fromValue);
        std::shared_ptr<ecore::EObject> obj = objValue->getValue();
        std::shared_ptr<std::list<std::shared_ptr<Any>>> convertArgs = std::make_shared<std::list<std::shared_ptr<Any>>>();

        // create the pre value snapshot
        // copy object to avoid modifying the given context
        std::shared_ptr<ecore::EObject> preObj = obj->copy();
        std::shared_ptr<ObjectValue> preValue = std::dynamic_pointer_cast<ObjectValue>(createValue(preObj));
        std::shared_ptr<NameValueBinding> nvbPre = ocl::Values::ValuesFactory::eInstance()->createNameValueBinding();
        std::shared_ptr<LocalSnapshot> localSnapshotPre = ocl::Values::ValuesFactory::eInstance()->createLocalSnapshot();
        nvbPre->setName("pre");
        nvbPre->setValue(preValue);
        localSnapshotPre->setIsPre(true);
        localSnapshotPre->getBindings()->add(nvbPre);

        // create the post value snapshot
        std::shared_ptr<ecore::EObject> postObj = obj->copy();
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
            std::shared_ptr<Any> item_ptr = std::make_shared<Any>(item);
            convertArgs->push_back(item_ptr);
        }
        std::shared_ptr<AnyObject> value = postObj->eInvoke(operation, convertArgs);

        return OclReflection::createValue(operation, value);
    }
    else
    { // primary value not managed yet

        return ocl::Values::ValuesFactory::eInstance()->createUndefinedValue();
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
    std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
    std::shared_ptr<ecore::EPackage> epackage = factory->createEPackage(upackage->getMetaElementID());
    epackage->setName(upackage->getName());

    for(size_t i = 0; i < upackage->getOwnedElement()->size(); i++) {
        std::shared_ptr<uml::Element> type = upackage->getOwnedElement()->at(i);
        std::shared_ptr<uml::Class> uclass = std::dynamic_pointer_cast<uml::Class>(type);
        if(uclass != nullptr) {
            std::shared_ptr<ecore::EClass> c = factory->createEClass_in_EPackage(epackage, uclass->getMetaElementID());
            c->setName(uclass->getName());
            //std::cout << "class : " << c->getName() << std::endl;
        }
        else {
            std::shared_ptr<uml::Enumeration> uenum = std::dynamic_pointer_cast<uml::Enumeration>(type);
            if(uenum != nullptr) {
                std::shared_ptr<ecore::EEnum> eenum =factory->createEEnum_in_EPackage(epackage, uenum->getMetaElementID());
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
                    prop = ecore::ecoreFactory::eInstance()->createEAttribute_in_EContainingClass(eclass, (*it_attribute)->getMetaElementID());
                }
                else {
                    prop = ecore::ecoreFactory::eInstance()->createEReference_in_EContainingClass(eclass, (*it_attribute)->getMetaElementID());
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
                std::shared_ptr<ecore::EOperation> op = ecore::ecoreFactory::eInstance()->createEOperation_in_EContainingClass(eclass, currentOp->getMetaElementID());
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
                        std::shared_ptr<ecore::EParameter> param = ecore::ecoreFactory::eInstance()->createEParameter_in_EOperation(op, p->getMetaElementID());
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
                    std::shared_ptr<ecore::EEnumLiteral> literal = ecore::ecoreFactory::eInstance()->createEEnumLiteral_in_EEnum(eenum, (*it_literal)->getMetaElementID());
                    literal->setName((*it_literal)->getName());
                    //std::cout << (*it_literal)->getName() << std::endl;
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
            any = eAny(lit->getValue());
        }
        else if(name == PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer()->getName()){
            std::shared_ptr<uml::LiteralInteger> lit = std::dynamic_pointer_cast<uml::LiteralInteger>(value);
            any = eAny(lit->getValue());
        }
        else if(name == PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Real()->getName()){
            std::shared_ptr<uml::LiteralReal> lit = std::dynamic_pointer_cast<uml::LiteralReal>(value);
            any = eAny(lit->getValue());
        }
        else if(name == PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String()->getName()){
            std::shared_ptr<uml::LiteralString> lit = std::dynamic_pointer_cast<uml::LiteralString>(value);
            any = eAny(lit->getValue());
        }
        else if(name == PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_UnlimitedNatural()->getName()){
            std::shared_ptr<uml::LiteralUnlimitedNatural> lit = std::dynamic_pointer_cast<uml::LiteralUnlimitedNatural>(value);
            any = eAny(lit->getValue());
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

