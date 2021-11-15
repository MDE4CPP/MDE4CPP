#include <string>
#include <oclParser/Utilities/Ocl.h>
#include <iostream>

#include <ecore/EFactory.hpp>
#include <ecore/EPackage.hpp>
#include <ecore/ecorePackage.hpp>
#include <ecore/ecoreFactory.hpp>
#include <ecore/EClassifier.hpp>
#include <ecore/EEnum.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EOperation.hpp>
#include <ecore/EAttribute.hpp>
#include <ecore/EParameter.hpp>
#include <ecore/EEnumLiteral.hpp>
#include <ecore/ETypeParameter.hpp>
#include <abstractDataTypes/Bag.hpp>
#include <abstractDataTypes/SubsetUnion.hpp>

#include <uml/umlFactory.hpp>
#include <uml/umlPackage.hpp>
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

#include <types/typesPackage.hpp>
#include <primitivetypesReflection/PrimitiveTypesPackage.hpp>


void query_syntax1();
void query_syntax2();
void query_syntax3();

void constraint_syntax1();
void constraint_syntax2();

void ecore_query1();
void ecore_query2();
void ecore_query3();
void ecore_query4();

void ecore_any_query1();
void ecore_any_query2();
void ecore_any_query3();
void ecore_any_query4();
void ecore_any_query5();

void uml_query1();
void uml_query2();
void uml_query3();
void uml_query4();

void uml_any_query1();
void uml_any_query2();

void ecore_validate1();
void ecore_validate2();

void validate( std::shared_ptr<ecore::EObject> context, const std::string& query);
void query(std::shared_ptr<ecore::EObject> context, const std::string& query);
Any queryValue(std::shared_ptr<ecore::EObject> context, const std::string& query);
void checkSyntaxQuery(const std::string& query);
void checkSyntaxConstraint(const std::string& query);

void printEAttribute(std::shared_ptr<ecore::EAttribute> eattr);
void printEReference(std::shared_ptr<ecore::EReference> eref);
void printETypedElement(std::shared_ptr<ecore::ETypedElement> etyped);
void printENamedElement(std::shared_ptr<ecore::ENamedElement> ename);
void printEOperation(std::shared_ptr<ecore::EOperation> eope);
void printEcore(Any value);
void printEcoreMany(Any value);

void printProperty(std::shared_ptr<uml::Property> prop);
void printTypedElement(std::shared_ptr<uml::TypedElement> utyped);
void printNamedElement(std::shared_ptr<uml::NamedElement> uname);
void printOperation(std::shared_ptr<uml::Operation> uope);
void printUml(Any value);
void printUmlMany(Any value);

void pause();

std::shared_ptr<ecore::ecorePackage> epackage = ecore::ecorePackage::eInstance();
std::shared_ptr<ecore::ecoreFactory> efactory = ecore::ecoreFactory::eInstance();
std::shared_ptr<uml::umlFactory> ufactory = uml::umlFactory::eInstance();
std::shared_ptr<uml::umlPackage> upackage = uml::umlPackage::eInstance();

int main()
{
    query_syntax1();
    query_syntax2();
    query_syntax3();

    constraint_syntax1();
    constraint_syntax2();

    ecore_query1();
    ecore_query2();
    ecore_query3();
    ecore_query4();

    ecore_any_query1();
    ecore_any_query2();
    ecore_any_query3();
    ecore_any_query4();
    ecore_any_query5();

    uml_query1();
    uml_query2();
    uml_query3();
    uml_query4();

    uml_any_query1();
    uml_any_query2();

    pause();

    return 1;
}

void query_syntax1() {
    std::string query = "self.name";
    std::cout << "START Syntax_1 (correct): " << query << std::endl;
    checkSyntaxQuery(query);
    std::cout << "END Syntax_1 -------------------------------------------\n" << std::endl;
}

void query_syntax2() {
    std::string query = "if self.b then self.a = 1 else self.a = 2 endif";
    std::cout << "START Syntax_2 (correct): " << query << std::endl;
    checkSyntaxQuery(query);
    std::cout << "END Syntax_2 -------------------------------------------\n" << std::endl;
}

void query_syntax3() {
    std::string query = "if self.b then self.a = 1 else self.a = 2";
    std::cout << "START Syntax_2 (error): " << query << std::endl;
    checkSyntaxQuery(query);
    std::cout << "END Syntax_2 -------------------------------------------\n" << std::endl;
}

void constraint_syntax1() {
    std::string query = "context Library::nbBooks : Integer init: 5";
    std::cout << "START Syntax_4 (correct): " << query << std::endl;
    checkSyntaxConstraint(query);
    std::cout << "END Syntax_4 -------------------------------------------\n" << std::endl;
}

void constraint_syntax2() {
    std::string query = "context Library:nbBooks : Integer init: 5";
    std::cout << "START Syntax_5 (error): " << query << std::endl;
    checkSyntaxConstraint(query);
    std::cout << "END Syntax_5 -------------------------------------------\n" << std::endl;
}

void ecore_query1() {
    std::string qry = "self.name";
    std::shared_ptr<ecore::EPackage> context = efactory->createEPackage();
    context->setName("ecore_query1");

    std::cout << "START Query_1 (context = EPackage): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_1 -------------------------------------------\n" << std::endl;
}

void ecore_query2() {
    std::string qry = "self.eAttributes";
    std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
    std::shared_ptr<ecore::EClass> context = efactory->createEClass_in_EPackage(ep);
    std::shared_ptr<ecore::EAttribute> a1 = efactory->createEAttribute_in_EContainingClass(context);
    std::shared_ptr<ecore::EAttribute> a2 = efactory->createEAttribute_in_EContainingClass(context);

    context->setName("theContext");
    a1->setName("a1");
    a1->setLowerBound(0);
    a1->setUpperBound(-1);
    a1->setEType(types::typesPackage::eInstance()->getInteger_Class());
    a2->setName("a2");
    a2->setEType(types::typesPackage::eInstance()->getBoolean_Class());

    std::cout << "START Query_2(context = EClass): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_2 -------------------------------------------\n" << std::endl;
}

void ecore_query3() {
    std::string qry = "self.eType";
    std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
    std::shared_ptr<ecore::EClass> c1 = efactory->createEClass_in_EPackage(ep);
    std::shared_ptr<ecore::EAttribute> context = efactory->createEAttribute_in_EContainingClass(c1);

    context->setName("a1");
    context->setLowerBound(0);
    context->setUpperBound(-1);
    context->setEType(types::typesPackage::eInstance()->getInteger_Class());

    std::cout << "START Query_3(context = EAttribute): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_3 -------------------------------------------\n" << std::endl;
}

void ecore_query4() {
    std::string qry = "self";
    std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
    std::shared_ptr<ecore::EClass> c1 = efactory->createEClass_in_EPackage(ep);
    std::shared_ptr<ecore::EOperation> context = efactory->createEOperation_in_EContainingClass(c1);
    std::shared_ptr<ecore::EParameter> p1 = efactory->createEParameter_in_EOperation(context);
    std::shared_ptr<ecore::EParameter> p2 = efactory->createEParameter_in_EOperation(context);

    context->setName("o1");
    context->setEType(types::typesPackage::eInstance()->getBoolean_Class());
    p1->setName("p1");
    p1->setEType(types::typesPackage::eInstance()->getString_Class());
    p2->setName("p2");
    p2->setLowerBound(0);
    p2->setUpperBound(-1);
    p2->setEType(types::typesPackage::eInstance()->getReal_Class());

    std::cout << "START Query_4(context = EOperation): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_4 -------------------------------------------\n" << std::endl;
}

void uml_query1() {
    std::string qry = "self.name";
    std::shared_ptr<uml::Model> context = ufactory->createModel();
    context->setName("uml_query1");

    std::cout << "START Query_6 (context = Model): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_6 -------------------------------------------\n" << std::endl;
}

void uml_query2() {
    std::string qry = "self.ownedElement";
    std::shared_ptr<uml::Model> p = ufactory->createModel();
    std::shared_ptr<uml::Class> context = ufactory->createClass_in_Package(p);
    std::shared_ptr<uml::Property> a1 = ufactory->createProperty_in_Class(context);
    std::shared_ptr<uml::Property> a2 = ufactory->createProperty_in_Class(context);
    std::shared_ptr<uml::Operation> o1 = ufactory->createOperation_in_Class(context);
    std::shared_ptr<uml::Parameter> p1 = ufactory->createParameter_in_Operation(o1);
    std::shared_ptr<uml::Parameter> p2 = ufactory->createParameter_in_Operation(o1);

    context->setName("theContext");
    a1->setName("a1");
    a1->setLower(0);
    a1->setUpper(-1);
    a1->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
    a2->setName("a2");
    a2->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
    o1->setName("o1");
    // throw an instance of char exception
    //o1->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
    p1->setName("p1");
    p1->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
    p2->setName("p2");
    p2->setLower(0);
    p2->setUpper(-1);
    p2->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());

    std::cout << "START Query_7(context = Class): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_7 -------------------------------------------\n" << std::endl;
}

void uml_query3() {
    std::string qry = "self.name";
    std::shared_ptr<uml::Model> p = ufactory->createModel();
    std::shared_ptr<uml::Class> c1 = ufactory->createClass_in_Package(p);
    std::shared_ptr<uml::Property> context = ufactory->createProperty_in_Class(c1);
    c1->setName("c1");
    context->setName("a1");
    context->setLower(0);
    context->setUpper(-1);
    context->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());

    std::cout << "START Query_8(context = Property): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_8 -------------------------------------------\n" << std::endl;
}

void uml_query4() {
    std::string qry = "self";
    std::shared_ptr<uml::Model> p = ufactory->createModel();
    std::shared_ptr<uml::Class> c1 = ufactory->createClass_in_Package(p);
    std::shared_ptr<uml::Operation> context = ufactory->createOperation_in_Class(c1);
    std::shared_ptr<uml::Parameter> p1 = ufactory->createParameter_in_Operation(context);
    std::shared_ptr<uml::Parameter> p2 = ufactory->createParameter_in_Operation(context);

    c1->setName("theContext");
    context->setName("o1");
    // throw an instance of char exception
    //context->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
    p1->setName("p1");
    p1->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
    p2->setName("p2");
    p2->setLower(0);
    p2->setUpper(-1);
    p2->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());

    std::cout << "START Query_9(context = Operation): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Query_9 -------------------------------------------\n" << std::endl;
}

void ecore_any_query1() {
    std::string qry = "self.name";
    std::shared_ptr<ecore::EPackage> context = efactory->createEPackage();
    context->setName("ecore_query1");
    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_1 (context = EPackage): " << qry << std::endl;
    if(value != nullptr) {
        std::cout << value->get<std::string>() << std::endl;
    }
    std::cout << "END Query_Any_1 -------------------------------------------\n" << std::endl;
}

void ecore_any_query2() {
    std::string qry = "self.eAttributes";
    std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
    std::shared_ptr<ecore::EClass> context = efactory->createEClass_in_EPackage(ep);
    std::shared_ptr<ecore::EAttribute> a1 = efactory->createEAttribute_in_EContainingClass(context);
    std::shared_ptr<ecore::EAttribute> a2 = efactory->createEAttribute_in_EContainingClass(context);

    context->setName("theContext");
    a1->setName("a1");
    a1->setLowerBound(0);
    a1->setUpperBound(-1);
    a1->setEType(types::typesPackage::eInstance()->getInteger_Class());
    a2->setName("a2");
    a2->setEType(types::typesPackage::eInstance()->getBoolean_Class());

    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_2(context = EClass): " << qry << std::endl;
    if(value != nullptr) {
        try {
            std::shared_ptr<Bag<AnyObject>> valueItems = value->get<std::shared_ptr<Bag<AnyObject>>>();
            for(size_t i = 0; i < valueItems->size(); i++) {
                std::shared_ptr<ecore::EObject> eobj = valueItems->at(i)->get<std::shared_ptr<ecore::EObject>>();
                std::shared_ptr<ecore::EAttribute> eattr = std::dynamic_pointer_cast<ecore::EAttribute>(eobj);
                printEAttribute(eattr);
            }
        } catch(...) {
            std::cout << "Error : get failed" << std::endl;
        }
    }
    std::cout << "END Query_Any_2 -------------------------------------------\n" << std::endl;
}

void ecore_any_query3() {
    std::string qry = "self.eType";
    std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
    std::shared_ptr<ecore::EClass> c1 = efactory->createEClass_in_EPackage(ep);
    std::shared_ptr<ecore::EAttribute> context = efactory->createEAttribute_in_EContainingClass(c1);

    context->setName("a1");
    context->setLowerBound(0);
    context->setUpperBound(-1);
    context->setEType(types::typesPackage::eInstance()->getInteger_Class());

    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_3(context = EAttribute): " << qry << std::endl;
    printEcore(value);
    std::cout << "END Query_Any_3 -------------------------------------------\n" << std::endl;
}

void ecore_any_query4() {
    std::string qry = "self";
    std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
    std::shared_ptr<ecore::EClass> c1 = efactory->createEClass_in_EPackage(ep);
    std::shared_ptr<ecore::EOperation> context = efactory->createEOperation_in_EContainingClass(c1);
    std::shared_ptr<ecore::EParameter> p1 = efactory->createEParameter_in_EOperation(context);
    std::shared_ptr<ecore::EParameter> p2 = efactory->createEParameter_in_EOperation(context);

    context->setName("o1");
    context->setEType(types::typesPackage::eInstance()->getBoolean_Class());
    p1->setName("p1");
    p1->setEType(types::typesPackage::eInstance()->getString_Class());
    p2->setName("p2");
    p2->setLowerBound(0);
    p2->setUpperBound(-1);
    p2->setEType(types::typesPackage::eInstance()->getReal_Class());

    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_4(context = EOperation): " << qry << std::endl;
    printEcore(value);
    std::cout << "END Query_Any_4 -------------------------------------------\n" << std::endl;
}

void ecore_any_query5() {
    std::string qry = "self.eStructuralFeatures";
    std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
    std::shared_ptr<ecore::EClass> context = efactory->createEClass_in_EPackage(ep);
    std::shared_ptr<ecore::EOperation> o1 = efactory->createEOperation_in_EContainingClass(context);
    std::shared_ptr<ecore::EParameter> p1 = efactory->createEParameter_in_EOperation(o1);
    std::shared_ptr<ecore::EParameter> p2 = efactory->createEParameter_in_EOperation(o1);
    std::shared_ptr<ecore::EAttribute> a1 = efactory->createEAttribute_in_EContainingClass(context);
    std::shared_ptr<ecore::EReference> r1 = efactory->createEReference_in_EContainingClass(context);

    context->setName("theContext");
    a1->setName("a1");
    a1->setLowerBound(0);
    a1->setUpperBound(-1);
    a1->setEType(types::typesPackage::eInstance()->getInteger_Class());
    r1->setName("r1");
    r1->setEType(types::typesPackage::eInstance()->getBoolean_Class());

    o1->setName("o1");
    o1->setEType(types::typesPackage::eInstance()->getBoolean_Class());
    p1->setName("p1");
    p1->setEType(types::typesPackage::eInstance()->getString_Class());
    p2->setName("p2");
    p2->setLowerBound(0);
    p2->setUpperBound(-1);
    p2->setEType(types::typesPackage::eInstance()->getReal_Class());

    Any value = queryValue(context, qry);

    std::cout << "START Query_Any_5(context = EClass): " << qry << std::endl;
    printEcoreMany(value);
    std::cout << "END Query_Any_5 -------------------------------------------\n" << std::endl;
}

void uml_any_query1() {
    std::string qry = "self.name";
    std::shared_ptr<uml::Model> context = ufactory->createModel();
    context->setName("uml_query1");
    Any value = queryValue(context, qry);

    std::cout << "START Query_UML_Any_1 (context = Model): " << qry << std::endl;
    if(value != nullptr) {
        std::cout << value->get<std::string>() << std::endl;
    }
    std::cout << "END Query_UML_Any_1 -------------------------------------------\n" << std::endl;
}

void uml_any_query2() {
    std::string qry = "self.ownedElement";
    std::shared_ptr<uml::Model> p = ufactory->createModel();
    std::shared_ptr<uml::Class> context = ufactory->createClass_in_Package(p);
    std::shared_ptr<uml::Property> a1 = ufactory->createProperty_in_Class(context);
    std::shared_ptr<uml::Property> a2 = ufactory->createProperty_in_Class(context);
    std::shared_ptr<uml::Operation> o1 = ufactory->createOperation_in_Class(context);
    std::shared_ptr<uml::Parameter> p1 = ufactory->createParameter_in_Operation(o1);
    std::shared_ptr<uml::Parameter> p2 = ufactory->createParameter_in_Operation(o1);

    context->setName("theContext");
    a1->setName("a1");
    a1->setLower(0);
    a1->setUpper(-1);
    a1->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
    a2->setName("a2");
    a2->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
    o1->setName("o1");
    // throw an instance of char exception
    //o1->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
    p1->setName("p1");
    p1->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
    p2->setName("p2");
    p2->setLower(0);
    p2->setUpper(-1);
    p2->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());

    Any value = queryValue(context, qry);

    std::cout << "START Query_UML_Any_2(context = Class): " << qry << std::endl;
    printUmlMany(value);
    std::cout << "END Query_UML_Any_2 -------------------------------------------\n" << std::endl;
}

void ecore_validate1() { /* NOT WORKING */
    std::string qry = "context C1 inv: self.a1 > 0 ";

    std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
    std::shared_ptr<ecore::EClass> c1 = efactory->createEClass_in_EPackage(ep);
    std::shared_ptr<ecore::EAttribute> a1 = efactory->createEAttribute_in_EContainingClass(c1);
    std::shared_ptr<ecore::EObject> context = efactory->createEObject(c1->getClassifierID());

    c1->setName("C1");
    a1->setName("a1");
    a1->setEType(types::typesPackage::eInstance()->getInteger_Class());
    context->eSet(a1, eAny(5));

    std::cout << "START Validate_1(context = EObject (a1=5)): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Validate_1 -------------------------------------------\n" << std::endl;
}

void ecore_validate2() { /* NOT WORKING */
    std::string qry = "context C1 inv: self.a1 > 10 ";

    std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
    std::shared_ptr<ecore::EClass> c1 = efactory->createEClass_in_EPackage(ep);
    std::shared_ptr<ecore::EAttribute> a1 = efactory->createEAttribute_in_EContainingClass(c1);
    std::shared_ptr<ecore::EObject> context = efactory->create(c1->getClassifierID());

    c1->setName("C1");
    a1->setName("a1");
    a1->setEType(types::typesPackage::eInstance()->getInteger_Class());
    context->eSet(a1, eAny(5));

    std::cout << "START Validate_2(context = EObject (a1=5)): " << qry << std::endl;
    query(context, qry);
    std::cout << "END Validate_2 -------------------------------------------\n" << std::endl;
}

void validate(std::shared_ptr<ecore::EObject> context,const std::string& query) {
    try {
        Utilities::Ocl ocl;
        ocl.validate(query, context);
        if(ocl.getErrors().size() > 0) {
            std::cout << ocl.getError() << std::endl;
        } else {
            std::cout << ocl.getResult() << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "exception : " << e.what() << std::endl;
    }
}

void query( std::shared_ptr<ecore::EObject> context, const std::string& query) {
    try {
        Utilities::Ocl ocl;
        if(ocl.query(query, context)) {
            std::cout << ocl.getResult() << std::endl;
        } else {
            std::cout << ocl.getError() << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "exception : " << e.what() << std::endl;
    }
}

Any queryValue(std::shared_ptr<ecore::EObject> context, const std::string& query) {
    try {
        Utilities::Ocl ocl;
        if(ocl.query(query, context)) {
            return ocl.getResultValue();
        } else {
            std::cout << ocl.getError() << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "exception : " << e.what() << std::endl;
    }
    return nullptr;
}

void checkSyntaxQuery(const std::string& query) {
    try {
        Utilities::Ocl ocl;
        if(ocl.checkSyntaxQuery(query)) {
            std::cout << "Syntax OK" << std::endl;
        } else {
            std::cout << ocl.getError() << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "exception : " << e.what() << std::endl;
    }
}

void checkSyntaxConstraint(const std::string& query) {
    try {
        Utilities::Ocl ocl;
        if(ocl.checkSyntaxConstraint(query)) {
            std::cout << "Syntax OK" << std::endl;
        } else {
            std::cout << ocl.getError() << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "exception : " << e.what() << std::endl;
    }
}

void printEcoreMany(Any value) {
    if(value != nullptr && !value->isEmpty()) {
        std::shared_ptr<Bag<AnyObject>> valueItems = value->get<std::shared_ptr<Bag<AnyObject>>>();
        for(size_t i = 0; i < valueItems->size(); i++) {
            printEcore(valueItems->at(i));
        }
    }
}

void printUmlMany(Any value) {
    if(value != nullptr && !value->isEmpty()) {
        std::shared_ptr<Bag<AnyObject>> valueItems = value->get<std::shared_ptr<Bag<AnyObject>>>();
        for(size_t i = 0; i < valueItems->size(); i++) {
            printUml(valueItems->at(i));
        }
    }
}

void printEcore(Any value) {
    try {
        std::shared_ptr<ecore::EObject> eobj = value->get<std::shared_ptr<ecore::EObject>>();
        std::shared_ptr<ecore::EOperation> eope = std::dynamic_pointer_cast<ecore::EOperation>(eobj);
        if(eope != nullptr) {
            return printEOperation(eope);
        }
        std::shared_ptr<ecore::EAttribute> eattr = std::dynamic_pointer_cast<ecore::EAttribute>(eobj);
        if(eattr != nullptr) {
            return printEAttribute(eattr);
        }
        std::shared_ptr<ecore::EReference> eref = std::dynamic_pointer_cast<ecore::EReference>(eobj);
        if(eref != nullptr) {
            return printEReference(eref);
        }
        std::shared_ptr<ecore::ETypedElement> etyped = std::dynamic_pointer_cast<ecore::ETypedElement>(eobj);
        if(etyped != nullptr) {
            return printETypedElement(etyped);
        }
        std::shared_ptr<ecore::ENamedElement> ename = std::dynamic_pointer_cast<ecore::ENamedElement>(eobj);
        if(ename != nullptr) {
            return printENamedElement(ename);
        }
    } catch (...) { }
    try {
        std::shared_ptr<ecore::EEnumLiteral> liter = value->get<std::shared_ptr<ecore::EEnumLiteral>>();
        std::cout << liter->getName() << std::endl;
        return;
    } catch (...) { }
    try {
        bool result = value->get<bool>();
        std::cout << result << std::endl;
        return;
    } catch (...) { }
    try {
        std::string result = value->get<std::string>();
        std::cout << result << std::endl;
        return;
    } catch (...) { }
    try {
        int result = value->get<int>();
        std::cout << result << std::endl;
        return;
    } catch (...) { }
    try {
        double result = value->get<double>();
        std::cout << result << std::endl;
        return;
    } catch (...) { }
}

void printUml(Any value) {
    try {
        std::shared_ptr<uml::Object> uobj = value->get<std::shared_ptr<uml::Object>>();
        std::shared_ptr<uml::Operation> uope = std::dynamic_pointer_cast<uml::Operation>(uobj);
        if(uope != nullptr) {
            return printOperation(uope);
        }
        std::shared_ptr<uml::Property> prop = std::dynamic_pointer_cast<uml::Property>(uobj);
        if(prop != nullptr) {
            return printProperty(prop);
        }
        std::shared_ptr<uml::TypedElement> utyped = std::dynamic_pointer_cast<uml::TypedElement>(uobj);
        if(utyped != nullptr) {
            return printTypedElement(utyped);
        }
        std::shared_ptr<uml::NamedElement> uname = std::dynamic_pointer_cast<uml::NamedElement>(uobj);
        if(uname != nullptr) {
            return printNamedElement(uname);
        }
    } catch (...) { }
    try {
        std::shared_ptr<uml::EnumerationLiteral> liter = value->get<std::shared_ptr<uml::EnumerationLiteral>>();
        std::cout << liter->getName() << std::endl;
        return;
    } catch (...) { }
    try {
        bool result = value->get<bool>();
        std::cout << result << std::endl;
        return;
    } catch (...) { }
    try {
        std::string result = value->get<std::string>();
        std::cout << result << std::endl;
        return;
    } catch (...) { }
    try {
        int result = value->get<int>();
        std::cout << result << std::endl;
        return;
    } catch (...) { }
    try {
        double result = value->get<double>();
        std::cout << result << std::endl;
        return;
    } catch (...) { }
}

void printProperty(std::shared_ptr<uml::Property> uprop) {
    if(uprop != nullptr) {
        if(uprop->getUpper() > 1 || uprop->getUpper() < 0)
            std::cout << "<Property> " + uprop->getName() + " : " + uprop->getType()->getName() + " ["
                +  std::to_string(uprop->getLower()) + "..*]" << std::endl;
        else
            std::cout << "<Property> " + uprop->getName() + " : " + uprop->getType()->getName() + " ["
                +  std::to_string(uprop->getLower()) + ".." + std::to_string(uprop->getUpper()) + "]" << std::endl;
    }
}

void printEAttribute(std::shared_ptr<ecore::EAttribute> eattr) {
    if(eattr != nullptr) {
        if(eattr->getUpperBound() > 1 || eattr->getUpperBound() < 0)
            std::cout << "<EAttribute> " + eattr->getName() + " : " + eattr->getEType()->getName()+ " [" +  std::to_string(eattr->getLowerBound()) + "..*]" << std::endl;
        else
            std::cout << "<EAttribute> " + eattr->getName() + " : " + eattr->getEType()->getName()+ " [" +  std::to_string(eattr->getLowerBound()) + ".." + std::to_string(eattr->getUpperBound()) + "]" << std::endl;
    }
}

void printEReference(std::shared_ptr<ecore::EReference> eref) {
    if(eref != nullptr) {
        if(eref->getUpperBound() > 1 || eref->getUpperBound() < 0)
            std::cout << "<EReference> " + eref->getName() + " : " + eref->getEType()->getName()+ " [" +  std::to_string(eref->getLowerBound()) + "..*]" << std::endl;
        else
            std::cout << "<EReference> " + eref->getName() + " : " + eref->getEType()->getName()+ " [" +  std::to_string(eref->getLowerBound()) + ".." + std::to_string(eref->getUpperBound()) + "]" << std::endl;
    }
}

void printETypedElement(std::shared_ptr<ecore::ETypedElement> etyped) {
    if(etyped != nullptr) {
        if(etyped->isMany())
            std::cout << etyped->getName() + " : " + etyped->getEType()->getName()+ " [0..*]" << std::endl;
        else
            std::cout << etyped->getName() + " : " + etyped->getEType()->getName()+ " [0..1]" << std::endl;
    }
}

void printTypedElement(std::shared_ptr<uml::TypedElement> utyped) {
    if(utyped != nullptr) {
        std::cout << utyped->getName() + " : " + utyped->getType()->getName() << std::endl;
    }
}

void printENamedElement(std::shared_ptr<ecore::ENamedElement> ename) {
    if(ename != nullptr) {
        std::cout << ename->getName() << std::endl;
    }
}

void printNamedElement(std::shared_ptr<uml::NamedElement> uname) {
    if(uname != nullptr) {
        std::cout << uname->getName() << std::endl;
    }
}

void printEOperation(std::shared_ptr<ecore::EOperation> eope) {
    if(eope != nullptr) {
        std::string result = "<Operation> " + eope->getName() + "(";
        std::shared_ptr<Bag<ecore::EParameter>> ebag = std::dynamic_pointer_cast<Bag<ecore::EParameter>>(eope->getEParameters());
        for(unsigned int i = 0; i < ebag->size(); i++) {
            if(i > 0) result += ", ";
            result += ebag->at(i)->getName() + " : ";
            if(ebag->at(i)->getEType() != nullptr)
                result += ebag->at(i)->getEType()->getName();
            else
                result += "[Not set in Model]";
        }
        result += ")";
        std::cout << result << std::endl;
    }
}

void printOperation(std::shared_ptr<uml::Operation> uope) {
    if(uope != nullptr) {
        std::string result = "<Operation> " + uope->getName() + "(";
        std::shared_ptr<Bag<uml::Parameter>> ebag = std::dynamic_pointer_cast<Bag<uml::Parameter>>(uope->getOwnedParameter());
        for(unsigned int i = 0; i < ebag->size(); i++) {
            if(i > 0) result += ", ";
            result += ebag->at(i)->getName() + " : ";
            if(ebag->at(i)->getType() != nullptr) {
                if(ebag->at(i)->getUpper() > 1 || ebag->at(i)->getUpper() < 0)
                    result += ebag->at(i)->getType()->getName()+ " ["
                        +  std::to_string(ebag->at(i)->getLower()) + "..*]";
                else
                    result += ebag->at(i)->getType()->getName()+ " ["
                        +  std::to_string(ebag->at(i)->getLower()) + ".." + std::to_string(ebag->at(i)->getUpper()) + "]";
            }
            else
                result += "[Not set in Model]";
        }
        result += ")";
        std::cout << result << std::endl;
    }
}

void pause() {
    std::cout << "Enter to continue...";
    std::cin.get();
}
