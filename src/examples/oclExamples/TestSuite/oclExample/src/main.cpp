#include <string>
#include <oclParser/Utilities/Ocl.h>
#include <iostream>
#include <sstream>

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


bool query_syntax1();
bool query_syntax2();
bool query_syntax3();

bool constraint_syntax1();
bool constraint_syntax2();

bool ecore_query1();
bool ecore_query2();
bool ecore_query3();
bool ecore_query4();

bool ecore_any_query1();
bool ecore_any_query2();
bool ecore_any_query3();
bool ecore_any_query4();
bool ecore_any_query5();

bool uml_query1();
bool uml_query2();
bool uml_query3();
bool uml_query4();

bool uml_any_query1();
bool uml_any_query2();

bool ecore_validate1();
bool ecore_validate2();

void validate( std::shared_ptr<ecore::EObject> context, const std::string& query);
bool query(const std::string& query, std::shared_ptr<ecore::EObject> context, const std::string& testStr);
Any queryValue(const std::string& query, std::shared_ptr<ecore::EObject> context);
bool checkSyntaxQuery(const std::string& query);
bool checkSyntaxConstraint(const std::string& query);

std::string printEAttribute(std::shared_ptr<ecore::EAttribute> eattr);
std::string printEReference(std::shared_ptr<ecore::EReference> eref);
std::string printETypedElement(std::shared_ptr<ecore::ETypedElement> etyped);
std::string printENamedElement(std::shared_ptr<ecore::ENamedElement> ename);
std::string printEOperation(std::shared_ptr<ecore::EOperation> eope);
std::string printEcore(Any value);
std::string printEcoreMany(Any value);

std::string printProperty(std::shared_ptr<uml::Property> prop);
std::string printTypedElement(std::shared_ptr<uml::TypedElement> utyped);
std::string printNamedElement(std::shared_ptr<uml::NamedElement> uname);
std::string printOperation(std::shared_ptr<uml::Operation> uope);
std::string printUml(Any value);
std::string printUmlMany(Any value);

void pause();

std::shared_ptr<ecore::ecorePackage> epackage = ecore::ecorePackage::eInstance();
std::shared_ptr<ecore::ecoreFactory> efactory = ecore::ecoreFactory::eInstance();
std::shared_ptr<uml::umlFactory> ufactory = uml::umlFactory::eInstance();
std::shared_ptr<uml::umlPackage> upackage = uml::umlPackage::eInstance();

int main()
{
	int sucCount=0;
	int failCount=0;
	// Simple OCL Syntax checks
    query_syntax1() == true ? sucCount++:failCount++;
    query_syntax2() == true ? sucCount++:failCount++;
    query_syntax3() == true ? sucCount++:failCount++;

    constraint_syntax1() == true ? sucCount++:failCount++;
    constraint_syntax2() == true ? sucCount++:failCount++;

    // simple ecore querys
    ecore_query1() == true ? sucCount++:failCount++;
    ecore_query2() == true ? sucCount++:failCount++;
    ecore_query3() == true ? sucCount++:failCount++;
    ecore_query4() == true ? sucCount++:failCount++;

    ecore_any_query1()== true ? sucCount++:failCount++;
    ecore_any_query2()== true ? sucCount++:failCount++;
    ecore_any_query3()== true ? sucCount++:failCount++;
    ecore_any_query4()== true ? sucCount++:failCount++;
    ecore_any_query5()== true ? sucCount++:failCount++;

//    ecore_validate1()== true ? sucCount++:failCount++; //ToDo
//    ecore_validate2()== true ? sucCount++:failCount++; //ToDo

    uml_query1()== true ? sucCount++:failCount++;
    uml_query2()== true ? sucCount++:failCount++;
    uml_query3()== true ? sucCount++:failCount++;
    uml_query4()== true ? sucCount++:failCount++;

    uml_any_query1()== true ? sucCount++:failCount++;
    uml_any_query2()== true ? sucCount++:failCount++;

    std::cout << sucCount << "/"<< sucCount+failCount << " correct: ";
    (failCount==0) ? std::cout << "success" << std::endl: std::cout << "fail" << std::endl;
    pause();

    return 1;
}

bool query_syntax1() {
    std::string query = "self.name";
    std::cout << "START Syntax_1 (correct): " << query << std::endl;
    bool returnValue = checkSyntaxQuery(query);
    std::cout << "END Syntax_1 -------------------------------------------\n" << std::endl;
    return returnValue;
}

bool query_syntax2() {
    std::string query = "if self.b then self.a = 1 else self.a = 2 endif";
    std::cout << "START Syntax_2 (correct): " << query << std::endl;
    bool returnValue = checkSyntaxQuery(query);
    std::cout << "END Syntax_2 -------------------------------------------\n" << std::endl;
    return returnValue;
}

bool query_syntax3() {
    std::string query = "if self.b then self.a = 1 else self.a = 2";
    std::cout << "START Syntax_2 (sholud be an error): " << query << std::endl;
    bool returnValue = not(checkSyntaxQuery(query));
    std::cout << "END Syntax_2 -------------------------------------------\n" << std::endl;
    return returnValue;
}

bool constraint_syntax1() {
    std::string query = "context Library::nbBooks : Integer init: 5";
    std::cout << "START Syntax_4 (correct): " << query << std::endl;
    bool returnValue = checkSyntaxConstraint(query);
    std::cout << "END Syntax_4 -------------------------------------------\n" << std::endl;
    return returnValue;
}

bool constraint_syntax2() {
    std::string query = "context Library:nbBooks : Integer init: 5";
    std::cout << "START Syntax_5 (error): " << query << std::endl;
    bool returnValue = not(checkSyntaxConstraint(query));
    std::cout << "END Syntax_5 -------------------------------------------\n" << std::endl;
    return returnValue ;
}

bool ecore_query1() {
    std::string qry = "self.name";
    std::shared_ptr<ecore::EPackage> context = efactory->createEPackage();
    context->setName("my_query1_Package");

    std::cout << "START Query_1 (context = EPackage): " << qry << std::endl;
    bool returnValue = query(qry, context, "my_query1_Package");
    std::cout << "END Query_1 -------------------------------------------\n" << std::endl;
    return returnValue;
}

bool ecore_query2() {
    std::string qry = "self.eAttributes";
    std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
    std::shared_ptr<ecore::EClass> context = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
    std::shared_ptr<ecore::EAttribute> a1 = efactory->createEAttribute_as_eAttributes_in_EClass(context);
    std::shared_ptr<ecore::EAttribute> a2 = efactory->createEAttribute_as_eAttributes_in_EClass(context);

    context->setName("theContext");
    a1->setName("a1");
    a1->setLowerBound(0);
    a1->setUpperBound(-1);
    a1->setEType(types::typesPackage::eInstance()->getInteger_Class());
    a2->setName("a2");
    a2->setEType(types::typesPackage::eInstance()->getBoolean_Class());

    std::cout << "START Query_2(context = EClass): " << qry << std::endl;
    bool returnValue = query(qry, context, "<EAttribute>:a1:Integer[0..*]\n<EAttribute>:a2:Boolean[0..1]");
    std::cout << "END Query_2 -------------------------------------------\n" << std::endl;
    return returnValue;
}

bool ecore_query3() {
    std::string qry = "self.eType";
    std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
    std::shared_ptr<ecore::EClass> c1 = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
    std::shared_ptr<ecore::EAttribute> context = efactory->createEAttribute_as_eAttributes_in_EClass(c1);

    context->setName("a1");
    context->setLowerBound(0);
    context->setUpperBound(-1);
    context->setEType(types::typesPackage::eInstance()->getInteger_Class());

    std::cout << "START Query_3(context = EAttribute): " << qry << std::endl;
    bool returnValue=query(qry, context, "Integer");
    std::cout << "END Query_3 -------------------------------------------\n" << std::endl;
    return returnValue;
}

bool ecore_query4() {
    std::string qry = "self";
    std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
    std::shared_ptr<ecore::EClass> c1 = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
    std::shared_ptr<ecore::EOperation> context = efactory->createEOperation_as_eOperations_in_EClass(c1);
    std::shared_ptr<ecore::EParameter> p1 = efactory->createEParameter_as_eParameters_in_EOperation(context);
    std::shared_ptr<ecore::EParameter> p2 = efactory->createEParameter_as_eParameters_in_EOperation(context);

    context->setName("o1");
    context->setEType(types::typesPackage::eInstance()->getBoolean_Class());
    p1->setName("p1");
    p1->setEType(types::typesPackage::eInstance()->getString_Class());
    p2->setName("p2");
    p2->setLowerBound(0);
    p2->setUpperBound(-1);
    p2->setEType(types::typesPackage::eInstance()->getReal_Class());

    std::cout << "START Query_4(context = EOperation): " << qry << std::endl;
    bool returnValue=query(qry, context, "o1(p1:String, p2:Real)");
    std::cout << "END Query_4 -------------------------------------------\n" << std::endl;
    return returnValue;
}

bool ecore_any_query1() {
	bool returnValue =false;
    std::string qry = "self.name";
    std::shared_ptr<ecore::EPackage> context = efactory->createEPackage();
    context->setName("ecore_query1");
    Any value = queryValue(qry,context);

    std::cout << "START Query_Any_1 (context = EPackage): " << qry << std::endl;
    if(value != nullptr) {
    	std::string resultStr=value->get<std::string>() ;
        std::cout << resultStr << std::endl;
        (resultStr.compare("ecore_query1") == 0) ? returnValue =  true : returnValue =  false;
    }
    returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
    std::cout << "END Query_Any_1 -------------------------------------------\n" << std::endl;
    return returnValue ;
}

bool ecore_any_query2() {
	bool returnValue =false;
    std::string qry = "self.eAttributes";
    std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
    std::shared_ptr<ecore::EClass> context = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
    std::shared_ptr<ecore::EAttribute> a1 = efactory->createEAttribute_as_eAttributes_in_EClass(context);
    std::shared_ptr<ecore::EAttribute> a2 = efactory->createEAttribute_as_eAttributes_in_EClass(context);

    context->setName("theContext");
    a1->setName("a1");
    a1->setLowerBound(0);
    a1->setUpperBound(-1);
    a1->setEType(types::typesPackage::eInstance()->getInteger_Class());
    a2->setName("a2");
    a2->setEType(types::typesPackage::eInstance()->getBoolean_Class());

    Any value = queryValue(qry, context);

    std::cout << "START Query_Any_2(context = EClass): " << qry << std::endl;
    std::string resultStr="";
    if(value != nullptr) {
        try {
            std::shared_ptr<Bag<AnyObject>> valueItems = value->get<std::shared_ptr<Bag<AnyObject>>>();
            for(size_t i = 0; i < valueItems->size(); i++) {
                std::shared_ptr<ecore::EObject> eobj = valueItems->at(i)->get<std::shared_ptr<ecore::EObject>>();
                std::shared_ptr<ecore::EAttribute> eattr = std::dynamic_pointer_cast<ecore::EAttribute>(eobj);
                std::string attrStr = printEAttribute(eattr);
                std::cout << attrStr;
                resultStr +=attrStr;
            }
        } catch(...) {
            std::cout << "Error : get failed" << std::endl;
        }
    }
    (resultStr.compare("<EAttribute> a1 : Integer [0..*]\n<EAttribute> a2 : Boolean [0..1]\n") == 0) ? returnValue =  true : returnValue =  false;
    returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
    std::cout << "END Query_Any_2 -------------------------------------------\n" << std::endl;
    return returnValue ;

}

bool ecore_any_query3() {
	bool returnValue =false;
    std::string qry = "self.eType";
    std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
    std::shared_ptr<ecore::EClass> c1 = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
    std::shared_ptr<ecore::EAttribute> context = efactory->createEAttribute_as_eAttributes_in_EClass(c1);

    context->setName("a1");
    context->setLowerBound(0);
    context->setUpperBound(-1);
    context->setEType(types::typesPackage::eInstance()->getInteger_Class());

    std::cout << "START Query_Any_3(context = EAttribute): " << qry << std::endl;
    Any value = queryValue(qry, context);
    std::string resultStr = printEcore(value);
    std::cout << resultStr;
    (resultStr.compare("Integer\n") == 0) ? returnValue = true : returnValue =  false;
    returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
    std::cout << "END Query_Any_3 -------------------------------------------\n" << std::endl;
    return returnValue;
}

bool ecore_any_query4() {
	bool returnValue =false;
    std::string qry = "self";
    std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
    std::shared_ptr<ecore::EClass> c1 = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
    std::shared_ptr<ecore::EOperation> context = efactory->createEOperation_as_eOperations_in_EClass(c1);
    std::shared_ptr<ecore::EParameter> p1 = efactory->createEParameter_as_eParameters_in_EOperation(context);
    std::shared_ptr<ecore::EParameter> p2 = efactory->createEParameter_as_eParameters_in_EOperation(context);

    context->setName("o1");
    context->setEType(types::typesPackage::eInstance()->getBoolean_Class());
    p1->setName("p1");
    p1->setEType(types::typesPackage::eInstance()->getString_Class());
    p2->setName("p2");
    p2->setLowerBound(0);
    p2->setUpperBound(-1);
    p2->setEType(types::typesPackage::eInstance()->getReal_Class());

    Any value = queryValue(qry, context);

    std::cout << "START Query_Any_4(context = EOperation): " << qry << std::endl;
    std::string resultStr = printEcore(value);
    std::cout << resultStr  << std::endl;
    (resultStr.compare("<Operation> o1(p1 : String, p2 : Real)") == 0) ? returnValue = true : returnValue =  false;
    returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
    std::cout << "END Query_Any_4 -------------------------------------------\n" << std::endl;
    return returnValue;
}

bool ecore_any_query5() {
	bool returnValue =false;
    std::string qry = "self.eStructuralFeatures";
    std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
    std::shared_ptr<ecore::EClass> context = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
    std::shared_ptr<ecore::EOperation> o1 = efactory->createEOperation_as_eOperations_in_EClass(context);
    std::shared_ptr<ecore::EParameter> p1 = efactory->createEParameter_as_eParameters_in_EOperation(o1);
    std::shared_ptr<ecore::EParameter> p2 = efactory->createEParameter_as_eParameters_in_EOperation(o1);
    std::shared_ptr<ecore::EAttribute> a1 = efactory->createEAttribute_as_eAttributes_in_EClass(context);
    std::shared_ptr<ecore::EReference> r1 = efactory->createEReference_as_eReferences_in_EClass(context);

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

    Any value = queryValue(qry, context);

    std::cout << "START Query_Any_5(context = EClass): " << qry << std::endl;

    std::string resultStr = printEcoreMany(value);
    std::cout << resultStr;
    (resultStr.compare("<EAttribute> a1 : Integer [0..*]\n<EReference> r1 : Boolean [0..1]\n") == 0) ? returnValue = true : returnValue =  false;
    returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
    std::cout << "END Query_Any_5 -------------------------------------------\n" << std::endl;
    return returnValue;
}


bool ecore_validate1() { /* NOT WORKING */
    std::string qry = "context C1 inv: self.a1 > 0 ";

    std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
    std::shared_ptr<ecore::EClass> c1 = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
    std::shared_ptr<ecore::EAttribute> a1 = efactory->createEAttribute_as_eAttributes_in_EClass(c1);
    std::shared_ptr<ecore::EObject> context = efactory->create(c1->getClassifierID());

    c1->setName("C1");
    a1->setName("a1");
    a1->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
    context->eSet(a1, eAny(5, ecore::ecorePackage::EINT_CLASS, false));

    std::cout << "START Validate_1(context = EObject (a1=5)): " << qry << std::endl;
    bool returnValue=query(qry, context, "");
    std:: cout << returnValue << std::endl;
    returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
    std::cout << "END Validate_1 -------------------------------------------\n" << std::endl;
    return returnValue;
}

bool ecore_validate2() { /* NOT WORKING */
    std::string qry = "context C1 inv: self.a1 > 10 ";

    std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
    std::shared_ptr<ecore::EClass> c1 = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
    std::shared_ptr<ecore::EAttribute> a1 = efactory->createEAttribute_as_eAttributes_in_EClass(c1);
    std::shared_ptr<ecore::EObject> context = efactory->create(c1->getClassifierID());

    c1->setName("C1");
    a1->setName("a1");
    a1->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
    context->eSet(a1, eAny(5, ecore::ecorePackage::EINT_CLASS, false));

    std::cout << "START Validate_2(context = EObject (a1=5)): " << qry << std::endl;
    bool returnValue=query(qry, context, "");
    std::cout << "END Validate_2 -------------------------------------------\n" << std::endl;
    return returnValue;
}

bool uml_query1() {
    std::string qry = "self.name";
    std::shared_ptr<uml::Model> context = ufactory->createModel();
    context->setName("uml_query1");

    std::cout << "START UML Query_1 (context = Model): " << qry << std::endl;
    bool returnValue=query(qry,context, "uml_query1");
    std::cout << "END UML Query_1 -------------------------------------------\n" << std::endl;
    return returnValue;
}

bool uml_query2() {
    std::string qry = "self.ownedElement";
    std::shared_ptr<uml::Model> p = ufactory->createModel();
    std::shared_ptr<uml::Class> context = ufactory->createClass_as_ownedType_in_Package(p);
    std::shared_ptr<uml::Property> a1 = ufactory->createProperty_as_ownedAttribute_in_Class(context);
    std::shared_ptr<uml::Property> a2 = ufactory->createProperty_as_ownedAttribute_in_Class(context);
    std::shared_ptr<uml::Operation> o1 = ufactory->createOperation_as_ownedOperation_in_Class(context);
    std::shared_ptr<uml::Parameter> p1 = ufactory->createParameter_as_ownedParameter_in_Operation(o1);
    std::shared_ptr<uml::Parameter> p2 = ufactory->createParameter_as_ownedParameter_in_Operation(o1);

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

    std::cout << "START UML Query_2(context = Class): " << qry << std::endl;
    bool returnValue=query(qry,context, "<Property>:a1:Integer[0..*]\n<Property>:a2:Boolean[1..1]\n<Operation>:o1(p1:String[1..1], p2:String[0..*])");
    std::cout << "END UML Query_2 -------------------------------------------\n" << std::endl;
    return returnValue;
}

bool uml_query3() {
    std::string qry = "self.name";
    std::shared_ptr<uml::Model> p = ufactory->createModel();
    std::shared_ptr<uml::Class> c1 = ufactory->createClass_as_ownedType_in_Package(p);
    std::shared_ptr<uml::Property> context = ufactory->createProperty_as_ownedAttribute_in_Class(c1);
    c1->setName("c1");
    context->setName("a1");
    context->setLower(0);
    context->setUpper(-1);
    context->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());

    std::cout << "START UML Query_3(context = Property): " << qry << std::endl;
    bool returnValue=query(qry,context,"a1");
    std::cout << "END UML Query_3 -------------------------------------------\n" << std::endl;
    return returnValue;
}

bool  uml_query4() {
    std::string qry = "self";
    std::shared_ptr<uml::Model> p = ufactory->createModel();
    std::shared_ptr<uml::Class> c1 = ufactory->createClass_as_ownedType_in_Package(p);
    std::shared_ptr<uml::Operation> context = ufactory->createOperation_as_ownedOperation_in_Class(c1);
    std::shared_ptr<uml::Parameter> p1 = ufactory->createParameter_as_ownedParameter_in_Operation(context);
    std::shared_ptr<uml::Parameter> p2 = ufactory->createParameter_as_ownedParameter_in_Operation(context);

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

    std::cout << "START UML Query_4(context = Operation): " << qry << std::endl;
    bool returnValue=query(qry, context, "<Operation>:o1(p1:String[1..1], p2:String[0..*])");
    std::cout << "END UML Query_4 -------------------------------------------\n" << std::endl;
    return returnValue;
}

bool uml_any_query1() {
	bool returnValue=false;
    std::string qry = "self.name";
    std::shared_ptr<uml::Model> context = ufactory->createModel();
    context->setName("uml_query1");
    Any value = queryValue(qry, context);

    std::cout << "START Query_UML_Any_1 (context = Model): " << qry << std::endl;
    std::string resultStr ="";
    if(value != nullptr) {
    	resultStr= value->get<std::string>();
        std::cout << resultStr << std::endl;
    }
    (resultStr.compare("uml_query1") == 0) ? returnValue = true : returnValue =  false;
    returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
    std::cout << "END Query_UML_Any_1 -------------------------------------------\n" << std::endl;
    return returnValue ;
}

bool uml_any_query2() {
	bool returnValue=false;

    std::string qry = "self.ownedElement";
    std::shared_ptr<uml::Model> p = ufactory->createModel();
    std::shared_ptr<uml::Class> context = ufactory->createClass_as_ownedType_in_Package(p);
    std::shared_ptr<uml::Property> a1 = ufactory->createProperty_as_ownedAttribute_in_Class(context);
    std::shared_ptr<uml::Property> a2 = ufactory->createProperty_as_ownedAttribute_in_Class(context);
    std::shared_ptr<uml::Operation> o1 = ufactory->createOperation_as_ownedOperation_in_Class(context);
    std::shared_ptr<uml::Parameter> p1 = ufactory->createParameter_as_ownedParameter_in_Operation(o1);
    std::shared_ptr<uml::Parameter> p2 = ufactory->createParameter_as_ownedParameter_in_Operation(o1);

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

    std::cout << "START Query_UML_Any_2(context = Class): " << qry << std::endl;
    Any value = queryValue(qry, context);

    std::string resultStr = printUmlMany(value);
    std::cout << resultStr << std::endl;
    (resultStr.compare("<Property> a1 : Integer [0..*]\n<Property> a2 : Boolean [1..1]\n<Operation> o1(p1 : String [1..1], p2 : String [0..*])") == 0) ? returnValue = true : returnValue =  false;
    returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
    std::cout << "END Query_UML_Any_2 -------------------------------------------\n" << std::endl;
    return returnValue;
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

bool query(const std::string& query, std::shared_ptr<ecore::EObject> context, const std::string& testStr) {
	bool returnValue = false;
    try {
        Utilities::Ocl ocl;
        if(ocl.query(query, context)) {
        	std::string resultStr=ocl.getResult();
            std::cout << resultStr << std::endl;
            (resultStr.compare(testStr) == 0) ? returnValue =  true : returnValue =  false;
        } else {
            std::cout << ocl.getError() << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "exception : " << e.what() << std::endl;
    }
    returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
    return returnValue;
}

Any queryValue(const std::string& query, std::shared_ptr<ecore::EObject> context) {
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

bool checkSyntaxQuery(const std::string& query) {
	bool returnValue=false;
    try {
        Utilities::Ocl ocl;
        if(ocl.checkSyntaxQuery(query)) {
            std::cout << "Syntax OK" << std::endl;
            returnValue = true;
        } else {
            std::cout << ocl.getError() << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "exception : " << e.what() << std::endl;
    }
    return returnValue;
}

bool checkSyntaxConstraint(const std::string& query) {
	bool returnValue=false;
    try {
        Utilities::Ocl ocl;
        if(ocl.checkSyntaxConstraint(query)) {
            std::cout << "Syntax OK" << std::endl;
            returnValue = true;
        } else {
            std::cout << ocl.getError() << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "exception : " << e.what() << std::endl;
    }
    return returnValue;
}

std::string printEcoreMany(Any value) {
	std::ostringstream returnStringStream;
	if(value != nullptr && !value->isEmpty()) {
        std::shared_ptr<Bag<AnyObject>> valueItems = value->get<std::shared_ptr<Bag<AnyObject>>>();
        for(size_t i = 0; i < valueItems->size(); i++) {
        	returnStringStream << printEcore(valueItems->at(i));
        }
    }
	return returnStringStream.str();
}

std::string printUmlMany(Any value) {
	std::ostringstream returnStringStream;
    if(value != nullptr && !value->isEmpty()) {
        std::shared_ptr<Bag<AnyObject>> valueItems = value->get<std::shared_ptr<Bag<AnyObject>>>();
        for(size_t i = 0; i < valueItems->size(); i++) {
        	std::string result= printUml(valueItems->at(i));
        	returnStringStream << printUml(valueItems->at(i));
        }
    }
	return returnStringStream.str();
}

std::string printEcore(Any value) {
	std::ostringstream returnStringStream;
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
        returnStringStream << liter->getName() << std::endl;
    	return returnStringStream.str();
    } catch (...) { }
    try {
        bool result = value->get<bool>();
        returnStringStream << (result ? "true" : "false") << std::endl;
    	return returnStringStream.str();
    } catch (...) { }
    try {
        std::string result = value->get<std::string>();
        returnStringStream << result << std::endl;
    	return returnStringStream.str();
    } catch (...) { }
    try {
        int result = value->get<int>();
        returnStringStream << result << std::endl;
    	return returnStringStream.str();
    } catch (...) { }
    try {
        double result = value->get<double>();
        returnStringStream << result << std::endl;
    	return returnStringStream.str();
    } catch (...) { }
	return returnStringStream.str();
}

std::string printUml(Any value) {
	std::ostringstream returnStringStream;
    try {
        std::shared_ptr<ecore::EObject> uobj = value->get<std::shared_ptr<ecore::EObject>>();
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
        returnStringStream << liter->getName() << std::endl;
    	return returnStringStream.str();
    } catch (...) { }
    try {
        bool result = value->get<bool>();
        returnStringStream << (result ? "true" : "false") << std::endl;
    	return returnStringStream.str();
    } catch (...) { }
    try {
        std::string result = value->get<std::string>();
        returnStringStream << result << std::endl;
        std::cout<< "s" << std::endl;
    	return returnStringStream.str();
    } catch (...) { }
    try {
        int result = value->get<int>();
        returnStringStream << result << std::endl;
        std::cout<< "i" << std::endl;
    	return returnStringStream.str();
    } catch (...) { }
    try {
        double result = value->get<double>();
        returnStringStream << result << std::endl;
    	return returnStringStream.str();
    } catch (...) { }
    std::cout<< "1" << std::endl;
	return returnStringStream.str();
}

std::string printProperty(std::shared_ptr<uml::Property> uprop) {
	std::ostringstream returnStringStream;
	if(uprop != nullptr) {
        if(uprop->getUpper() > 1 || uprop->getUpper() < 0)
        	returnStringStream << "<Property> " + uprop->getName() + " : " + uprop->getType()->getName() + " ["
                +  std::to_string(uprop->getLower()) + "..*]" << std::endl;
        else
        	returnStringStream << "<Property> " + uprop->getName() + " : " + uprop->getType()->getName() + " ["
                +  std::to_string(uprop->getLower()) + ".." + std::to_string(uprop->getUpper()) + "]" << std::endl;
    }
	return returnStringStream.str();
}

std::string printEAttribute(std::shared_ptr<ecore::EAttribute> eattr) {
	std::ostringstream returnStringStream;

    if(eattr != nullptr) {
        if(eattr->getUpperBound() > 1 || eattr->getUpperBound() < 0)
        	returnStringStream << "<EAttribute> " + eattr->getName() + " : " + eattr->getEType()->getName()+ " [" +  std::to_string(eattr->getLowerBound()) + "..*]" << std::endl;
        else
        	returnStringStream << "<EAttribute> " + eattr->getName() + " : " + eattr->getEType()->getName()+ " [" +  std::to_string(eattr->getLowerBound()) + ".." + std::to_string(eattr->getUpperBound()) + "]" << std::endl;
    }
	return returnStringStream.str();
}

std::string printEReference(std::shared_ptr<ecore::EReference> eref) {
	std::ostringstream returnStringStream;
	if(eref != nullptr) {
        if(eref->getUpperBound() > 1 || eref->getUpperBound() < 0)
        	returnStringStream << "<EReference> " + eref->getName() + " : " + eref->getEType()->getName()+ " [" +  std::to_string(eref->getLowerBound()) + "..*]" << std::endl;
        else
        	returnStringStream << "<EReference> " + eref->getName() + " : " + eref->getEType()->getName()+ " [" +  std::to_string(eref->getLowerBound()) + ".." + std::to_string(eref->getUpperBound()) + "]" << std::endl;
    }
	return returnStringStream.str();
}

std::string printETypedElement(std::shared_ptr<ecore::ETypedElement> etyped) {
	std::ostringstream returnStringStream;
    if(etyped != nullptr) {
        if(etyped->isMany())
        	returnStringStream << etyped->getName() + " : " + etyped->getEType()->getName()+ " [0..*]" << std::endl;
        else
        	returnStringStream << etyped->getName() + " : " + etyped->getEType()->getName()+ " [0..1]" << std::endl;
    }
	return returnStringStream.str();
}

std::string printTypedElement(std::shared_ptr<uml::TypedElement> utyped) {
	std::ostringstream returnStringStream;
	if(utyped != nullptr) {
		returnStringStream << utyped->getName() + " : " + utyped->getType()->getName() << std::endl;
    }
	return returnStringStream.str();
}

std::string printENamedElement(std::shared_ptr<ecore::ENamedElement> ename) {
	std::ostringstream returnStringStream;
	if(ename != nullptr) {
		returnStringStream << ename->getName() << std::endl;
    }
	return returnStringStream.str();
}

std::string printNamedElement(std::shared_ptr<uml::NamedElement> uname) {
	std::ostringstream returnStringStream;
	if(uname != nullptr) {
		returnStringStream << uname->getName() << std::endl;
    }
	return returnStringStream.str();
}

std::string printEOperation(std::shared_ptr<ecore::EOperation> eope) {
	std::string result ="";
	if(eope != nullptr) {
		result = "<Operation> " + eope->getName() + "(";
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
    }
	return result;
}

std::string printOperation(std::shared_ptr<uml::Operation> uope) {
	std::string result = "";
	if(uope != nullptr) {
        result = "<Operation> " + uope->getName() + "(";
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
    }
	return result;
}

void pause() {
    std::cout << "Enter to continue...";
    std::cin.get();
}
