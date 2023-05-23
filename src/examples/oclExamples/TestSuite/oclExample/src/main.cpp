#include <string>
#include <iostream>
#include <sstream>
#include <memory>
#include <typeinfo>

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

//#include <abstractDataTypes/Any.hpp>
#include <ecore/EcoreAny.hpp>

#include <types/typesPackage.hpp>
#include <primitivetypesReflection/PrimitiveTypesPackage.hpp>

//#include <oclParser/Utilities/test_query.h>
#include <oclParser/Utilities/Ocl.h>

// #include "Library_ecoreFactory.hpp"
// #include "Library_ecorePackage.hpp"

// #include "Library.hpp"
// #include "Member.hpp"
// #include "Book.hpp"
// #include "Loan.hpp"
// #include "Writer.hpp"
// #include "BookCategory.hpp"


bool floatCompare(double f1, double f2)
{
    static constexpr auto epsilon = 1.0e-05f;
    if (std::abs(f1 - f2) <= epsilon)
        return true;
    return std::abs(f1 - f2) <= epsilon * std::max(std::abs(f1), std::abs(f2));
}

bool testCasePrintableDouble(std::string testname, std::string qry, std::string corResStr, double targetResult, std::shared_ptr<Any> context, int* counter) {
  
    Utilities::Ocl ocl = Utilities::Ocl();
    
    std::cout << "--------------" << testname << "--------------" << std::endl;
    std::shared_ptr<Any> result = ocl.debugQuery(qry, context);
    double testResult = result->get<double>();
    std::cout << "Input: " << qry << std::endl;
    std::cout << "(should be " << corResStr << "): " << testResult << std::endl;

    *counter = floatCompare(testResult, targetResult) ? *counter : *counter+1;
    return floatCompare(testResult, targetResult);



}

template <class T>
bool testCasePrintable(std::string testname, std::string qry, std::string corResStr, T targetResult, std::shared_ptr<Any> context, int* counter) {
  
    Utilities::Ocl ocl = Utilities::Ocl();
    
    std::cout << "--------------" << testname << "--------------" << std::endl;
    std::shared_ptr<Any> result = ocl.debugQuery(qry, context);
    if (result == nullptr) {
        std::cout << "Error: Result is nullptr. Query: " << qry << std::endl;
        *counter = *counter+1;
        return false;
    }
    T testResult = result->get<T>();
    std::cout << "Input: " << qry << std::endl;
    std::cout << "(should be " << corResStr << "): " << testResult << std::endl;

    *counter = testResult == targetResult ? *counter : *counter+1;
    return testResult == targetResult;

}

bool failCounterFunction(int* counter, bool status) {

    *counter = status ? *counter : *counter+1;
    return status;

}

bool collectionTestCase(std::string testname, std::string qry, Bag<Any> targetResult, std::shared_ptr<Any> context, int* counter) {

    Utilities::Ocl ocl = Utilities::Ocl();
    
    std::cout << "--------------" << testname << "--------------" << std::endl;
    std::shared_ptr<Any> result = ocl.debugQuery(qry, context);
    std::cout << "Input: " << qry << std::endl;
    
    if (!result->isContainer()) {
        std::cout << "Error: result is no Container!" << std::endl; 
        *counter = *counter+1;
        return false;
    }

    std::shared_ptr<Bag<Any>> collection = nullptr;
    try
    {
        collection = result->get<std::shared_ptr<Bag<Any>>>();
    }
    catch(...){
        std::cout << "Error: Result is no " << typeid(collection).name() << std::endl;
        *counter = *counter+1;
        return false;
    }
    
    std::cout << "Begin elementwise check" << std::endl;

    size_t bagSize = collection->size();

    if (bagSize != targetResult.size()) {
        std::cout << "Result collection is not equal sized to target collection" << std::endl;
        std::cout << "Result collection size: " << bagSize << " target collection size: "  << targetResult.size() << std::endl;
        *counter = *counter+1;
        return false;
    }

    std::shared_ptr<Any> resultElem;
    std::shared_ptr<Any> targetElem;

    // check all elements
    for (size_t i = 0; i < bagSize; i++)
    {
        resultElem = collection->at(i);
        targetElem = targetResult.at(i);
        if (resultElem->getTypeId() != targetElem->getTypeId()) {
            std::cout << "Collection element at " << i << " have different type to target element!" << std::endl;
            *counter = *counter+1;
            return false;
        }
        if (resultElem->getTypeId() == ecore::ecorePackage::EINT_CLASS) {

            int resultInt = resultElem->get<int>();
            int targetInt = targetElem->get<int>();

            if (resultInt != targetInt) {
                std::cout << "Collection element at " << i << " is not equal to target result!" << std::endl;
                std::cout << "Result element: " << resultInt << " targetElement: " << targetInt << std::endl;
                *counter = *counter+1;
                return false;
            }
        }
        else if (resultElem->getTypeId() == ecore::ecorePackage::EBOOLEAN_CLASS) {

            bool resultBoolean = resultElem->get<bool>();
            bool targetBoolean = targetElem->get<bool>();

            if (resultBoolean != targetBoolean) {
                std::cout << "Collection element at " << i << " is not equal to target result!" << std::endl;
                std::cout << "Result element: " << resultBoolean << " targetElement: " << targetBoolean << std::endl;
                *counter = *counter+1;
                return false;
            }
        }
        else if (resultElem->getTypeId() == ecore::ecorePackage::EDOUBLE_CLASS) {

            double resultDouble = resultElem->get<double>();
            double targetDouble = targetElem->get<double>();

            if (resultDouble != targetDouble) {
                std::cout << "Collection element at " << i << " is not equal to target result!" << std::endl;
                std::cout << "Result element: " << resultDouble << " targetElement: " << targetDouble << std::endl;
                *counter = *counter+1;
                return false;
            }
        }
        else if (resultElem->getTypeId() == ecore::ecorePackage::ESTRING_CLASS) {

            std::string resultString = resultElem->get<std::string>();
            std::string targetString = targetElem->get<std::string>();

            if (resultString != targetString) {
                std::cout << "Collection element at " << i << " is not equal to target result!" << std::endl;
                std::cout << "Result element: " << resultString << " targetElement: " << targetString << std::endl;
                *counter = *counter+1;
                return false;
            }
        } else {
            std::cout << "Result is no primitive type. Currently unsupported!" << std::endl;
            *counter = *counter+1;
            return false;
        }
    } // END of for (size_t i = 0; i < bagSize; i++)
     
    std::cout << "All element checks succesfull!" << std::endl;
    
    return true;

}

int main() {

    std::cout << "Gestartet:" << std::endl;

    //std::cout << ts.query("Sequence{5, -6, 7 , -8, 4..7, 8}") << std::endl;
    //std::cout << ts.query("Sequence{ 4..7 }") << std::endl;
    //std::cout << ts.query("Sequence{ 4., 7..8, -3..6, -1..-2 }") << std::endl;
    //std::cout << ts.query("Tuple{a = 5, b = -6, c = 7, d = -8, e = 8}") << std::endl;
    //std::cout << ts.query("tuer(1, varName.status, self.gehen{true})") << std::endl;
    //std::cout << ts.query("if true then 3 else 4 endif") << std::endl;
    //std::cout << ts.query("let b: Integer = 5, c = 'neun', e = 4. in theContext") << std::endl;
    //std::cout << ts.query("Bag(Tuple(a: Integer, b: Real, c: Set(Integer), d: String))") << std::endl;
    //std::cout << ts.query("observer^update(? : Integer, ? : Integer)") << std::endl;
    //std::cout << ts.query("observer^^update(12, 14)") << std::endl;
    //std::cout << ts.query("self->select(a, b | a<>b)") << std::endl;
    //std::cout << ts.query("self.setVar[1325, 4., 'robin']") << std::endl;
    //std::cout << ts.query("self.colVar->iterate(a; b | a<>b)") << std::endl;
    //std::cout << ts.query("-2+2*(2-3)+4+1-5") << std::endl;
    //std::cout << ts.query("-42+-2*(2+3)+4+1-5") << std::endl;
    //std::cout << ts.query("package pfad::packagetest context classifierpath::classifiertest inv invname: 1 endpackage") << std::endl;
    //std::cout << ts.query("package pfad::packagetest context classifiertest inv invname: 1 endpackage") << std::endl;
    //std::cout << ts.query("context classifiertest inv invname: 1") << std::endl;
    // sonderfall möglich da varDecExp eine Deklarierung auch möglich ist, sonst nur über defExpressionCS
    // ob error noch unklar
    //std::cout << ts.query("context classifiertest static def defname: varname: Real = 5 = 5") << std::endl;
    //std::cout << ts.query("context operationName(a, b): pre: 1 post: 2 body: 3") << std::endl;

    // std::shared_ptr<ecore::ecoreFactory> efactory = ecore::ecoreFactory::eInstance();
    // std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();

    // std::shared_ptr<ecore::EClass> car = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
    // std::shared_ptr<ecore::EOperation> operContext = efactory->createEOperation_as_eOperations_in_EClass(car);
    // std::shared_ptr<ecore::EParameter> p1 = efactory->createEParameter_as_eParameters_in_EOperation(operContext);
    // std::shared_ptr<ecore::EParameter> p2 = efactory->createEParameter_as_eParameters_in_EOperation(operContext);
    // std::shared_ptr<ecore::EParameter> p3 = efactory->createEParameter_as_eParameters_in_EOperation(operContext);

    // std::shared_ptr<ecore::EAttribute> a1_car = efactory->createEAttribute_as_eAttributes_in_EClass(car);
    // std::shared_ptr<ecore::EAttribute> a2_car = efactory->createEAttribute_as_eAttributes_in_EClass(car);

    // std::shared_ptr<ecore::EClass> tuer = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
    // std::shared_ptr<ecore::EClass> scheibe = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
    // std::shared_ptr<ecore::EAttribute> a1_tuer = efactory->createEAttribute_as_eAttributes_in_EClass(tuer);


    // //std::shared_ptr<ecore::EClass> scheibe = efactory->createEClass_as_eClassifiers_in_EPackage(ep);

    // a1_car->setName("a1");
    // a1_car->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());

    // a2_car->setName("tuer");
    // a2_car->setEType(tuer);
    // a1_tuer->setName("scheibe");
    // a1_tuer->setEType(scheibe);
    
    // operContext->setName("o1");
    // std::shared_ptr<ecore::EDataType> test = types::typesPackage::eInstance()->getBoolean_Class();
    // operContext->setEType(test);
    // p1->setName("p1");
    // p1->setEType(types::typesPackage::eInstance()->getString_Class());
    // p2->setName("p2");
    // p2->setLowerBound(0);
    // p2->setUpperBound(-1);
    // p2->setEType(types::typesPackage::eInstance()->getReal_Class());
    // p3->setName("p3");
    // p3->setEType(types::typesPackage::eInstance()->getBoolean_Class());

    // std::shared_ptr<Any> operationAny = eEcoreAny<std::shared_ptr<ecore::EOperation>>(operContext, operContext->getMetaElementID());
    // std::shared_ptr<Any> classAny = eEcoreAny<std::shared_ptr<ecore::EClass>>(car, car->getMetaElementID());  
    
    //negate Tests
    
    const std::string PASS = "PASSED";
    const std::string FAIL = "FAILED";

    int failCounter = 0;
    int* failCounterPtr = &failCounter;
    
    std::cout << (testCasePrintable<bool>("Negate Test","not false", "1", true , nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Negate Test","not true", "0", false , nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<int>("Negate Test","-10", "-10", -10 , nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<int>("Negate Test","--10", "10", 10 , nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<int>("Negate Test","---10", "-10", -10 , nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Negate Test","-.4", "-0.4", -0.4 , nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Negate Test","--1.2", "1.2", 1.2 , nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;

    std::cout << (testCasePrintable<int>("Addition Test","1+1", "2", 2 , nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Addition Test","0.4+0.6", "1.0", 1.0 , nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Addition Test","0.4+1", "1.4", 1.4 , nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Addition Test","1+0.6", "1.6", 1.6 , nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<std::string>("Addition Test","'He'+'llo'", "Hello", "Hello" , nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    // not working std::cout << (testCasePrintable<std::string>("Addition Test","\"Wo\"+\"rld\"", "Hello", "Hello" , nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;

    std::cout << (testCasePrintableDouble("Subtraction Test","0.4-0.6", "-0.2", -0.2, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Subtraction Test","0.4-1", "-0.6", -0.6, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Subtraction Test","1-0.6", "0.4", 0.4, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<int>("Subtraction Test","1-1", "0", 0, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<int>("Subtraction Test","-1-1", "-2", -2, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Subtraction Test","-1.3-1", "-2.3", -2.3 , nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Subtraction Test","-1.3+1", "-0.3", -0.3, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Subtraction Test","-1.3+2", "0.7", 0.7, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;

    std::cout << (testCasePrintable<int>("Mutiplication Test","9*9", "81", 81, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<int>("Mutiplication Test","-9*9", "-81", -81, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<int>("Mutiplication Test","9*-9", "-81", -81, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<int>("Mutiplication Test","-9*-9", "81", 81, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Multiplication Test","1.3*2", "2.6", 2.6, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Multiplication Test","1.3*-2", "-2.6", -2.6, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Multiplication Test","-1.3*2", "-2.6", -2.6, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Multiplication Test","-1.3*-2", "2.6", 2.6, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Multiplication Test","0.3*2.3", "0.69", 0.69, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Multiplication Test","-0.3*2.3", "-0.69", -0.69, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Multiplication Test","0.3*-2.3", "-0.69", -0.69, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Multiplication Test","-0.3*-2.3", "0.69", 0.69, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;

    std::cout << (testCasePrintableDouble("Division Test","9/9", "1", 1, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Division Test","-9/9", "-1", -1, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Division Test","9/-9", "-1", -1, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Division Test","-9/-9", "1", 1, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Division Test","1.3/2", "0.65", 0.65, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Division Test","1.3/-2", "-0.65", -0.65, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Division Test","-1.3/2", "-0.65", -0.65, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Division Test","-1.3/-2", "0.65", 0.65, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Division Test","0.5/2.5", "0.2", 0.2, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Division Test","-0.5/2.5", "-0.2", -0.2, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Division Test","0.5/-2.5", "-0.2", -0.2, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Division Test","-0.5/-2.5", "0.2", 0.2, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;

    std::cout << (testCasePrintableDouble("Big EquationTest Test","3+9-8*7+3+3+9-8-7/3/3-10+50", "2.22222", 2.22222, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Big EquationTest Test","-3+9-8*7+3+3+9-8-7/3/3-10+50", "-3.77778", -3.77778, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;

    std::cout << (testCasePrintableDouble("Big EquationTest Test with ()","(3+9-8)*(7+3+3+9-8-7)/3/(3-10+50)", "0.217054", 0.217054, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Big EquationTest Test with ()","-(3+9-8)*(7+3+3+9-8-7)/3/(3-10+50)", "-0.217054", -0.217054, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Big EquationTest Test with ()","(((3+(9-8))))*((((((7)))))+((((3+3))))+9-8-7)/3/(3-10+50)", "0.217054", 0.217054, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("Big EquationTest Test with ()","-(((3+(9-8))))*((((((7)))))+((((3+3))))+9-8-7)/3/(3-10+50)", "-0.217054", -0.217054, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("EquationTest Test with ()","(3+3)*(3+(1-((2/((4-1))*4))))", "8", 8, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintableDouble("EquationTest Test with ()","-(3+3)*(3+(1-((2/((4-1))*4))))", "-8", -8, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;

    std::cout << (testCasePrintable<bool>("Equality Test","-3<3", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3<-3", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","-3>3", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3>-3", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3>3", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3>3", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3<3", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3<3", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","-3<=3", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3<=-3", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","-3>=3", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3>=-3", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3>=3", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3>=3", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3<=3", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3<=3", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Big Equality Test","-(3+3)*(3+(1-((2/((4-1))*4)))) < (3+3)*(3+(1-((2/((4-1))*4))))", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Big Equality Test","-(3+3)*(3+(1-((2/((4-1))*4)))) > (3+3)*(3+(1-((2/((4-1))*4))))", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;

    std::cout << (testCasePrintable<bool>("Equality Test","3=3", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3<>3", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3=4", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3<>4", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3.9=3.9", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3.9<>3.9", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3.9=4.9", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Equality Test","3.9<>4.9", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;

    std::cout << (testCasePrintable<int>("If Expression Test","if true then 1 else 2 endif", "1", 1, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<int>("If Expression Test","if false then 1 else 2 endif", "2", 2, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<int>("If Expression Test","if 1<2 then 1+9 else 2*8 endif", "10", 10, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<int>("If Expression Test","if 1>1 then 1+9 else 2*8 endif", "16", 16, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;

    std::cout << (testCasePrintable<bool>("Logic Operator Test","true and true", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Logic Operator Test","true and false", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Logic Operator Test","false and true", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Logic Operator Test","false and false", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;

    std::cout << (testCasePrintable<bool>("Logic Operator Test","true or true", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Logic Operator Test","true or false", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Logic Operator Test","false or true", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Logic Operator Test","false or false", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;

    std::cout << (testCasePrintable<bool>("Logic Operator Test","true xor true", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Logic Operator Test","true xor false", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Logic Operator Test","false xor true", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Logic Operator Test","false xor false", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    
    std::cout << (testCasePrintable<bool>("Logic Operator Test","true implies true", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Logic Operator Test","true implies false", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Logic Operator Test","false implies true", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Logic Operator Test","false implies false", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
////////////////////////////////////////////////////////////////////////////////
    Bag<Any> collectionTest = Bag<Any>();
    std::string testStr = "input";
    std::shared_ptr<Any> anyString = eAny(testStr, ecore::ecorePackage::ESTRING_CLASS, false);
    std::shared_ptr<Any> anyInt = eAny(42, ecore::ecorePackage::EINT_CLASS, false);
    std::shared_ptr<Any> anyDouble = eAny(3.1415, ecore::ecorePackage::EDOUBLE_CLASS, false);
    std::shared_ptr<Any> anyBoolean = eAny(true, ecore::ecorePackage::EBOOLEAN_CLASS, false);
    collectionTest.add(anyString);
    collectionTest.add(anyInt);
    collectionTest.add(anyDouble);
    collectionTest.add(anyBoolean);

    std::cout << (collectionTestCase("Collection Test","Bag{'input', 42, 3.1415, true}", collectionTest, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
////////////////////////////////////////////////////////////////////////////////
    collectionTest = Bag<Any>();
    for (int i = 0; i <= 10; i++)
    {
        collectionTest.add(eAny(i, ecore::ecorePackage::EINT_CLASS, false));
    }   
    std::cout << (collectionTestCase("Collection Test","Sequence{0..10}", collectionTest, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
////////////////////////////////////////////////////////////////////////////////
    collectionTest = Bag<Any>();
    for (int i = 10; i >= 0; i--)
    {
        collectionTest.add(eAny(i, ecore::ecorePackage::EINT_CLASS, false));
    }   
    std::cout << (collectionTestCase("Collection Test","Sequence{10..0}", collectionTest, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
////////////////////////////////////////////////////////////////////////////////
    collectionTest = Bag<Any>();
    for (int i = -100; i <= 0; i++)
    {
        collectionTest.add(eAny(i, ecore::ecorePackage::EINT_CLASS, false));
    }   
    std::cout << (collectionTestCase("Collection Test","Sequence{-100..0}", collectionTest, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
////////////////////////////////////////////////////////////////////////////////
    collectionTest = Bag<Any>();
    for (int i = -100; i <= -10; i++)
    {
        collectionTest.add(eAny(i, ecore::ecorePackage::EINT_CLASS, false));
    }   
    std::cout << (collectionTestCase("Collection Test","Sequence{-100..-10}", collectionTest, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
////////////////////////////////////////////////////////////////////////////////
    collectionTest = Bag<Any>();
    for (int i = -10; i >= -100; i--)
    {
        collectionTest.add(eAny(i, ecore::ecorePackage::EINT_CLASS, false));
    }   
    std::cout << (collectionTestCase("Collection Test","Sequence{-10..-100}", collectionTest, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
////////////////////////////////////////////////////////////////////////////////
    collectionTest = Bag<Any>();
    for (int i = 100; i >= -100; i--)
    {
        collectionTest.add(eAny(i, ecore::ecorePackage::EINT_CLASS, false));
    }   
    std::cout << (collectionTestCase("Collection Test","Sequence{100..-100}", collectionTest, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
////////////////////////////////////////////////////////////////////////////////
    collectionTest = Bag<Any>();
    for (int i = 100; i >= -100; i--)
    {
        collectionTest.add(eAny(i, ecore::ecorePackage::EINT_CLASS, false));
    }
    for (int i = 3; i <= 3; i++)
    {
        collectionTest.add(eAny(i, ecore::ecorePackage::EINT_CLASS, false));
    }
    anyInt = eAny(4, ecore::ecorePackage::EINT_CLASS, false);
    collectionTest.add(anyInt);
    anyBoolean = eAny(true, ecore::ecorePackage::EBOOLEAN_CLASS, false);
    collectionTest.add(anyBoolean);     
    std::cout << (collectionTestCase("Collection Test","Sequence{100..-100, 3..3, 4, true}", collectionTest, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
////////////////////////////////////////////////////////////////////////////////

    std::cout << (testCasePrintable<bool>("Let Expression Test","let test = true in test", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Let Expression Test","let test = true in let z = not test in z", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Let Expression Test","let test = true in let z = test in z", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<std::string>("Let Expression Test","let test = 'A lot of tests' in let z = (test+'!') in z", "A lot of tests!", "A lot of tests!", nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<std::string>("Let Expression Test","let test = 'A lot of tests' in if test = 'A lot of tests' then test+'!' else test+'?'", "A lot of tests!", "A lot of tests!", nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Tuple Expression Test","Tuple{a = true, b = false}.a", "true", true, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<bool>("Tuple Expression Test","Tuple{a = true, b = false}.b", "false", false, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<int>("Tuple Expression Test","Tuple{a = true, b = false, c = 57}.c", "57", 57, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<int>("Tuple and Let Expression Test","let t = Tuple{a = true, b = false, c = 57} in if t.a then t.c else t.b endif", "57", 57, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    std::cout << (testCasePrintable<int>("Tuple and Let Expression Test","let t = Tuple{a = true, b = false, c = 57}.c in t", "57", 57, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
    
// ////////////////////////////////////////////////////////////////////////////////
// NOT IMPLEMENTED YET
//     collectionTest = Bag<Any>();
//     anyInt = eAny(42, ecore::ecorePackage::EINT_CLASS, false);
//     collectionTest.add(anyInt);    
//     std::cout << (collectionTestCase("Tuple and Collection Test","let s = Set{Tuple{a = true, b = false, c = 57}} in s->collect(c)", collectionTest, nullptr, failCounterPtr) ? PASS : FAIL) << std::endl;
// ////////////////////////////////////////////////////////////////////////////////


    std::cout << "\nRESULT:" << std::endl;
    
    if (failCounter==0) {

        std::cout << "#########################" << std::endl;
        std::cout << "### All tests PASSED! ###" << std::endl;
        std::cout << "#########################" << std::endl;

    } else {

        std::cout << "#########################" << std::endl;
        std::cout << "### " << failCounter << " test(s) FAILED! ###" << std::endl;
        std::cout << "#########################" << std::endl;

    }
    

    // *** not working anymore, because query is on metamodel and there is no attribute tuer or scheibe
    // std::shared_ptr<Any> result = ts.contextTest("self.tuer.scheibe", classAny);
    // std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(result);
    // std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
    // std::shared_ptr<ecore::EStructuralFeature> eStructFeat = std::dynamic_pointer_cast<ecore::EStructuralFeature>(eObject);
    // std::cout << "Ergebnis: " << eStructFeat->getName() << std::endl;
    
    // std::shared_ptr<Any> result = ts.contextTest("self", operationAny);
    // std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(result);
    // std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
    // std::shared_ptr<ecore::EOperation> oper = std::dynamic_pointer_cast<ecore::EOperation>(eObject);
    // std::cout << "Ergebnis: " << oper->getName() << std::endl;

    // std::shared_ptr<Any> result = ts.contextTest("false", classAny);
    // bool boolTest = result->get<bool>();
    // std::cout << "Ergebnis: " << boolTest << std::endl;

    // std::shared_ptr<Any> result = ts.contextTest("'DasIstEinString'", classAny);
    // std::string strTest = result->get<std::string>();
    // std::cout << "Ergebnis: " << strTest << std::endl;

    // std::shared_ptr<Any> result = ts.contextTest("*", classAny);
    // int unNatTest = result->get<int>();
    // std::cout << "Ergebnis: " << unNatTest << std::endl;

    // std::shared_ptr<Any> result = ts.contextTest("312", classAny);
    // int intTest = result->get<int>();
    // std::cout << "Ergebnis: " << intTest << std::endl;

    // std::shared_ptr<Any> result1 = ts.contextTest("4.", classAny);
    // double realTest1 = result1->get<double>();
    // std::cout << "Ergebnis: " << realTest1 << std::endl;

    // std::shared_ptr<Any> result2 = ts.contextTest("4.0", classAny);
    // double realTest2 = result2->get<double>();
    // std::cout << "Ergebnis: " << realTest2 << std::endl;

    // std::shared_ptr<Any> result3 = ts.contextTest(".4", classAny);
    // double realTest3 = result3->get<double>();
    // std::cout << "Ergebnis: " << realTest3 << std::endl;

    // std::shared_ptr<Any> result4 = ts.contextTest("1E4", classAny);
    // double realTest4 = result4->get<double>();
    // std::cout << "Ergebnis: " << realTest4 << std::endl;

    // std::shared_ptr<Any> result5 = ts.contextTest("1267.43233E12", classAny);
    // double realTest5 = result5->get<double>();
    // std::cout << "Ergebnis: " << realTest5 << std::endl;

    // std::shared_ptr<Any> result6 = ts.contextTest("12.78e-2", classAny);
    // double realTest6 = result6->get<double>();
    // std::cout << "Ergebnis: " << realTest6 << std::endl;
    

    return 1;

}


// #include <ecore/EFactory.hpp>
// #include <ecore/EPackage.hpp>
// #include <ecore/ecorePackage.hpp>
// #include <ecore/ecoreFactory.hpp>
// #include <ecore/EClassifier.hpp>
// #include <ecore/EEnum.hpp>
// #include <ecore/EClass.hpp>
// #include <ecore/EReference.hpp>
// #include <ecore/EOperation.hpp>
// #include <ecore/EAttribute.hpp>
// #include <ecore/EParameter.hpp>
// #include <ecore/EEnumLiteral.hpp>
// #include <ecore/ETypeParameter.hpp>
// #include <abstractDataTypes/Bag.hpp>
// #include <abstractDataTypes/SubsetUnion.hpp>

// #include <uml/umlFactory.hpp>
// #include <uml/umlPackage.hpp>
// #include <uml/Model.hpp>
// #include <uml/Package.hpp>
// #include <uml/Classifier.hpp>
// #include <uml/Enumeration.hpp>
// #include <uml/Class.hpp>
// #include <uml/Association.hpp>
// #include <uml/Property.hpp>
// #include <uml/Operation.hpp>
// #include <uml/Parameter.hpp>
// #include <uml/EnumerationLiteral.hpp>
// #include <uml/PrimitiveType.hpp>

// #include <types/typesPackage.hpp>
// #include <primitivetypesReflection/PrimitiveTypesPackage.hpp>

// bool query_syntax1();
// bool query_syntax2();
// bool query_syntax3();

// bool constraint_syntax1();
// bool constraint_syntax2();

// bool ecore_query1();
// bool ecore_query2();
// bool ecore_query3();
// bool ecore_query4();

// bool ecore_any_query1();
// bool ecore_any_query2();
// bool ecore_any_query3();
// bool ecore_any_query4();
// bool ecore_any_query5();

// bool uml_query1();
// bool uml_query2();
// bool uml_query3();
// bool uml_query4();

// bool uml_any_query1();
// bool uml_any_query2();

// bool ecore_validate1();
// bool ecore_validate2();

// void validate( std::shared_ptr<ecore::EObject> context, const std::string& query);
// bool query(const std::string& query, std::shared_ptr<ecore::EObject> context, const std::string& testStr);
// Any queryValue(const std::string& query, std::shared_ptr<ecore::EObject> context);
// bool checkSyntaxQuery(const std::string& query);
// bool checkSyntaxConstraint(const std::string& query);

// std::string printEAttribute(std::shared_ptr<ecore::EAttribute> eattr);
// std::string printEReference(std::shared_ptr<ecore::EReference> eref);
// std::string printETypedElement(std::shared_ptr<ecore::ETypedElement> etyped);
// std::string printENamedElement(std::shared_ptr<ecore::ENamedElement> ename);
// std::string printEOperation(std::shared_ptr<ecore::EOperation> eope);
// std::string printEcore(Any value);
// std::string printEcoreMany(Any value);

// std::string printProperty(std::shared_ptr<uml::Property> prop);
// std::string printTypedElement(std::shared_ptr<uml::TypedElement> utyped);
// std::string printNamedElement(std::shared_ptr<uml::NamedElement> uname);
// std::string printOperation(std::shared_ptr<uml::Operation> uope);
// std::string printUml(Any value);
// std::string printUmlMany(Any value);

// void pause();

// std::shared_ptr<ecore::ecorePackage> epackage = ecore::ecorePackage::eInstance();
// std::shared_ptr<ecore::ecoreFactory> efactory = ecore::ecoreFactory::eInstance();
// std::shared_ptr<uml::umlFactory> ufactory = uml::umlFactory::eInstance();
// std::shared_ptr<uml::umlPackage> upackage = uml::umlPackage::eInstance();

// int main()
// {
// 	int sucCount=0;
// 	int failCount=0;
// 	// Simple OCL Syntax checks
//     query_syntax1() == true ? sucCount++:failCount++;
//     query_syntax2() == true ? sucCount++:failCount++;
//     query_syntax3() == true ? sucCount++:failCount++;

//     constraint_syntax1() == true ? sucCount++:failCount++;
//     constraint_syntax2() == true ? sucCount++:failCount++;

//     // simple ecore querys
//     ecore_query1() == true ? sucCount++:failCount++;
//     ecore_query2() == true ? sucCount++:failCount++;
//     ecore_query3() == true ? sucCount++:failCount++;
//     ecore_query4() == true ? sucCount++:failCount++;

//     ecore_any_query1()== true ? sucCount++:failCount++;
//     ecore_any_query2()== true ? sucCount++:failCount++;
//     ecore_any_query3()== true ? sucCount++:failCount++;
//     ecore_any_query4()== true ? sucCount++:failCount++;
//     ecore_any_query5()== true ? sucCount++:failCount++;

// //    ecore_validate1()== true ? sucCount++:failCount++; //ToDo
// //    ecore_validate2()== true ? sucCount++:failCount++; //ToDo

//     uml_query1()== true ? sucCount++:failCount++;
//     uml_query2()== true ? sucCount++:failCount++;
//     uml_query3()== true ? sucCount++:failCount++;
//     uml_query4()== true ? sucCount++:failCount++;

//     uml_any_query1()== true ? sucCount++:failCount++;
//     uml_any_query2()== true ? sucCount++:failCount++;

//     std::cout << sucCount << "/"<< sucCount+failCount << " correct: ";
//     (failCount==0) ? std::cout << "success" << std::endl: std::cout << "fail" << std::endl;
//     pause();

//     return 1;
// }

// bool query_syntax1() {
//     std::string query = "self.name";
//     std::cout << "START Syntax_1 (correct): " << query << std::endl;
//     bool returnValue = checkSyntaxQuery(query);
//     std::cout << "END Syntax_1 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool query_syntax2() {
//     std::string query = "if self.b then self.a = 1 else self.a = 2 endif";
//     std::cout << "START Syntax_2 (correct): " << query << std::endl;
//     bool returnValue = checkSyntaxQuery(query);
//     std::cout << "END Syntax_2 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool query_syntax3() {
//     std::string query = "if self.b then self.a = 1 else self.a = 2";
//     std::cout << "START Syntax_2 (sholud be an error): " << query << std::endl;
//     bool returnValue = not(checkSyntaxQuery(query));
//     std::cout << "END Syntax_2 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool constraint_syntax1() {
//     std::string query = "context Library::nbBooks : Integer init: 5";
//     std::cout << "START Syntax_4 (correct): " << query << std::endl;
//     bool returnValue = checkSyntaxConstraint(query);
//     std::cout << "END Syntax_4 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool constraint_syntax2() {
//     std::string query = "context Library:nbBooks : Integer init: 5";
//     std::cout << "START Syntax_5 (error): " << query << std::endl;
//     bool returnValue = not(checkSyntaxConstraint(query));
//     std::cout << "END Syntax_5 -------------------------------------------\n" << std::endl;
//     return returnValue ;
// }

// bool ecore_query1() {
//     std::string qry = "self.name";
//     std::shared_ptr<ecore::EPackage> context = efactory->createEPackage();
//     context->setName("my_query1_Package");

//     std::cout << "START Query_1 (context = EPackage): " << qry << std::endl;
//     bool returnValue = query(qry, context, "my_query1_Package");
//     std::cout << "END Query_1 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool ecore_query2() {
//     std::string qry = "self.eAttributes";
//     std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
//     std::shared_ptr<ecore::EClass> context = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
//     std::shared_ptr<ecore::EAttribute> a1 = efactory->createEAttribute_as_eAttributes_in_EClass(context);
//     std::shared_ptr<ecore::EAttribute> a2 = efactory->createEAttribute_as_eAttributes_in_EClass(context);

//     context->setName("theContext");
//     a1->setName("a1");
//     a1->setLowerBound(0);
//     a1->setUpperBound(-1);
//     a1->setEType(types::typesPackage::eInstance()->getInteger_Class());
//     a2->setName("a2");
//     a2->setEType(types::typesPackage::eInstance()->getBoolean_Class());

//     std::cout << "START Query_2(context = EClass): " << qry << std::endl;
//     bool returnValue = query(qry, context, "<EAttribute>:a1:Integer[0..*]\n<EAttribute>:a2:Boolean[0..1]");
//     std::cout << "END Query_2 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool ecore_query3() {
//     std::string qry = "self.eType";
//     std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
//     std::shared_ptr<ecore::EClass> c1 = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
//     std::shared_ptr<ecore::EAttribute> context = efactory->createEAttribute_as_eAttributes_in_EClass(c1);

//     context->setName("a1");
//     context->setLowerBound(0);
//     context->setUpperBound(-1);
//     context->setEType(types::typesPackage::eInstance()->getInteger_Class());

//     std::cout << "START Query_3(context = EAttribute): " << qry << std::endl;
//     bool returnValue=query(qry, context, "Integer");
//     std::cout << "END Query_3 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool ecore_query4() {
//     std::string qry = "self";
//     std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
//     std::shared_ptr<ecore::EClass> c1 = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
//     std::shared_ptr<ecore::EOperation> context = efactory->createEOperation_as_eOperations_in_EClass(c1);
//     std::shared_ptr<ecore::EParameter> p1 = efactory->createEParameter_as_eParameters_in_EOperation(context);
//     std::shared_ptr<ecore::EParameter> p2 = efactory->createEParameter_as_eParameters_in_EOperation(context);

//     context->setName("o1");
//     context->setEType(types::typesPackage::eInstance()->getBoolean_Class());
//     p1->setName("p1");
//     p1->setEType(types::typesPackage::eInstance()->getString_Class());
//     p2->setName("p2");
//     p2->setLowerBound(0);
//     p2->setUpperBound(-1);
//     p2->setEType(types::typesPackage::eInstance()->getReal_Class());

//     std::cout << "START Query_4(context = EOperation): " << qry << std::endl;
//     bool returnValue=query(qry, context, "o1(p1:String, p2:Real)");
//     std::cout << "END Query_4 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool ecore_any_query1() {
// 	bool returnValue =false;
//     std::string qry = "self.name";
//     std::shared_ptr<ecore::EPackage> context = efactory->createEPackage();
//     context->setName("ecore_query1");
//     Any value = queryValue(qry,context);

//     std::cout << "START Query_Any_1 (context = EPackage): " << qry << std::endl;
//     if(value != nullptr) {
//     	std::string resultStr=value->get<std::string>() ;
//         std::cout << resultStr << std::endl;
//         (resultStr.compare("ecore_query1") == 0) ? returnValue =  true : returnValue =  false;
//     }
//     returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
//     std::cout << "END Query_Any_1 -------------------------------------------\n" << std::endl;
//     return returnValue ;
// }

// bool ecore_any_query2() {
// 	bool returnValue =false;
//     std::string qry = "self.eAttributes";
//     std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
//     std::shared_ptr<ecore::EClass> context = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
//     std::shared_ptr<ecore::EAttribute> a1 = efactory->createEAttribute_as_eAttributes_in_EClass(context);
//     std::shared_ptr<ecore::EAttribute> a2 = efactory->createEAttribute_as_eAttributes_in_EClass(context);

//     context->setName("theContext");
//     a1->setName("a1");
//     a1->setLowerBound(0);
//     a1->setUpperBound(-1);
//     a1->setEType(types::typesPackage::eInstance()->getInteger_Class());
//     a2->setName("a2");
//     a2->setEType(types::typesPackage::eInstance()->getBoolean_Class());

//     Any value = queryValue(qry, context);

//     std::cout << "START Query_Any_2(context = EClass): " << qry << std::endl;
//     std::string resultStr="";
//     if(value != nullptr) {
//         try {
//             std::shared_ptr<Bag<AnyObject>> valueItems = value->get<std::shared_ptr<Bag<AnyObject>>>();
//             for(size_t i = 0; i < valueItems->size(); i++) {
//                 std::shared_ptr<ecore::EObject> eobj = valueItems->at(i)->get<std::shared_ptr<ecore::EObject>>();
//                 std::shared_ptr<ecore::EAttribute> eattr = std::dynamic_pointer_cast<ecore::EAttribute>(eobj);
//                 std::string attrStr = printEAttribute(eattr);
//                 std::cout << attrStr;
//                 resultStr +=attrStr;
//             }
//         } catch(...) {
//             std::cout << "Error : get failed" << std::endl;
//         }
//     }
//     (resultStr.compare("<EAttribute> a1 : Integer [0..*]\n<EAttribute> a2 : Boolean [0..1]\n") == 0) ? returnValue =  true : returnValue =  false;
//     returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
//     std::cout << "END Query_Any_2 -------------------------------------------\n" << std::endl;
//     return returnValue ;

// }

// bool ecore_any_query3() {
// 	bool returnValue =false;
//     std::string qry = "self.eType";
//     std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
//     std::shared_ptr<ecore::EClass> c1 = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
//     std::shared_ptr<ecore::EAttribute> context = efactory->createEAttribute_as_eAttributes_in_EClass(c1);

//     context->setName("a1");
//     context->setLowerBound(0);
//     context->setUpperBound(-1);
//     context->setEType(types::typesPackage::eInstance()->getInteger_Class());

//     std::cout << "START Query_Any_3(context = EAttribute): " << qry << std::endl;
//     Any value = queryValue(qry, context);
//     std::string resultStr = printEcore(value);
//     std::cout << resultStr;
//     (resultStr.compare("Integer\n") == 0) ? returnValue = true : returnValue =  false;
//     returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
//     std::cout << "END Query_Any_3 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool ecore_any_query4() {
// 	bool returnValue =false;
//     std::string qry = "self";
//     std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
//     std::shared_ptr<ecore::EClass> c1 = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
//     std::shared_ptr<ecore::EOperation> context = efactory->createEOperation_as_eOperations_in_EClass(c1);
//     std::shared_ptr<ecore::EParameter> p1 = efactory->createEParameter_as_eParameters_in_EOperation(context);
//     std::shared_ptr<ecore::EParameter> p2 = efactory->createEParameter_as_eParameters_in_EOperation(context);

//     context->setName("o1");
//     context->setEType(types::typesPackage::eInstance()->getBoolean_Class());
//     p1->setName("p1");
//     p1->setEType(types::typesPackage::eInstance()->getString_Class());
//     p2->setName("p2");
//     p2->setLowerBound(0);
//     p2->setUpperBound(-1);
//     p2->setEType(types::typesPackage::eInstance()->getReal_Class());

//     Any value = queryValue(qry, context);

//     std::cout << "START Query_Any_4(context = EOperation): " << qry << std::endl;
//     std::string resultStr = printEcore(value);
//     std::cout << resultStr  << std::endl;
//     (resultStr.compare("<Operation> o1(p1 : String, p2 : Real)") == 0) ? returnValue = true : returnValue =  false;
//     returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
//     std::cout << "END Query_Any_4 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool ecore_any_query5() {
// 	bool returnValue =false;
//     std::string qry = "self.eStructuralFeatures";
//     std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
//     std::shared_ptr<ecore::EClass> context = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
//     std::shared_ptr<ecore::EOperation> o1 = efactory->createEOperation_as_eOperations_in_EClass(context);
//     std::shared_ptr<ecore::EParameter> p1 = efactory->createEParameter_as_eParameters_in_EOperation(o1);
//     std::shared_ptr<ecore::EParameter> p2 = efactory->createEParameter_as_eParameters_in_EOperation(o1);
//     std::shared_ptr<ecore::EAttribute> a1 = efactory->createEAttribute_as_eAttributes_in_EClass(context);
//     std::shared_ptr<ecore::EReference> r1 = efactory->createEReference_as_eReferences_in_EClass(context);

//     context->setName("theContext");
//     a1->setName("a1");
//     a1->setLowerBound(0);
//     a1->setUpperBound(-1);
//     a1->setEType(types::typesPackage::eInstance()->getInteger_Class());
//     r1->setName("r1");
//     r1->setEType(types::typesPackage::eInstance()->getBoolean_Class());

//     o1->setName("o1");
//     o1->setEType(types::typesPackage::eInstance()->getBoolean_Class());
//     p1->setName("p1");
//     p1->setEType(types::typesPackage::eInstance()->getString_Class());
//     p2->setName("p2");
//     p2->setLowerBound(0);
//     p2->setUpperBound(-1);
//     p2->setEType(types::typesPackage::eInstance()->getReal_Class());

//     Any value = queryValue(qry, context);

//     std::cout << "START Query_Any_5(context = EClass): " << qry << std::endl;

//     std::string resultStr = printEcoreMany(value);
//     std::cout << resultStr;
//     (resultStr.compare("<EAttribute> a1 : Integer [0..*]\n<EReference> r1 : Boolean [0..1]\n") == 0) ? returnValue = true : returnValue =  false;
//     returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
//     std::cout << "END Query_Any_5 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }


// bool ecore_validate1() { /* NOT WORKING */
//     std::string qry = "context C1 inv: self.a1 > 0 ";

//     std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
//     std::shared_ptr<ecore::EClass> c1 = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
//     std::shared_ptr<ecore::EAttribute> a1 = efactory->createEAttribute_as_eAttributes_in_EClass(c1);
//     std::shared_ptr<ecore::EObject> context = efactory->create(c1->getClassifierID());

//     c1->setName("C1");
//     a1->setName("a1");
//     a1->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
//     context->eSet(a1, eAny(5, ecore::ecorePackage::EINT_CLASS, false));

//     std::cout << "START Validate_1(context = EObject (a1=5)): " << qry << std::endl;
//     bool returnValue=query(qry, context, "");
//     std:: cout << returnValue << std::endl;
//     returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
//     std::cout << "END Validate_1 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool ecore_validate2() { /* NOT WORKING */
//     std::string qry = "context C1 inv: self.a1 > 10 ";

//     std::shared_ptr<ecore::EPackage> ep = efactory->createEPackage();
//     std::shared_ptr<ecore::EClass> c1 = efactory->createEClass_as_eClassifiers_in_EPackage(ep);
//     std::shared_ptr<ecore::EAttribute> a1 = efactory->createEAttribute_as_eAttributes_in_EClass(c1);
//     std::shared_ptr<ecore::EObject> context = efactory->create(c1->getClassifierID());

//     c1->setName("C1");
//     a1->setName("a1");
//     a1->setEType(ecore::ecorePackage::eInstance()->getEInt_Class());
//     context->eSet(a1, eAny(5, ecore::ecorePackage::EINT_CLASS, false));

//     std::cout << "START Validate_2(context = EObject (a1=5)): " << qry << std::endl;
//     bool returnValue=query(qry, context, "");
//     std::cout << "END Validate_2 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool uml_query1() {
//     std::string qry = "self.name";
//     std::shared_ptr<uml::Model> context = ufactory->createModel();
//     context->setName("uml_query1");

//     std::cout << "START UML Query_1 (context = Model): " << qry << std::endl;
//     bool returnValue=query(qry,context, "uml_query1");
//     std::cout << "END UML Query_1 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool uml_query2() {
//     std::string qry = "self.ownedElement";
//     std::shared_ptr<uml::Model> p = ufactory->createModel();
//     std::shared_ptr<uml::Class> context = ufactory->createClass_as_ownedType_in_Package(p);
//     std::shared_ptr<uml::Property> a1 = ufactory->createProperty_as_ownedAttribute_in_Class(context);
//     std::shared_ptr<uml::Property> a2 = ufactory->createProperty_as_ownedAttribute_in_Class(context);
//     std::shared_ptr<uml::Operation> o1 = ufactory->createOperation_as_ownedOperation_in_Class(context);
//     std::shared_ptr<uml::Parameter> p1 = ufactory->createParameter_as_ownedParameter_in_Operation(o1);
//     std::shared_ptr<uml::Parameter> p2 = ufactory->createParameter_as_ownedParameter_in_Operation(o1);

//     context->setName("theContext");
//     a1->setName("a1");
//     a1->setLower(0);
//     a1->setUpper(-1);
//     a1->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
//     a2->setName("a2");
//     a2->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
//     o1->setName("o1");
//     // throw an instance of char exception
//     //o1->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
//     p1->setName("p1");
//     p1->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
//     p2->setName("p2");
//     p2->setLower(0);
//     p2->setUpper(-1);
//     p2->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());

//     std::cout << "START UML Query_2(context = Class): " << qry << std::endl;
//     bool returnValue=query(qry,context, "<Property>:a1:Integer[0..*]\n<Property>:a2:Boolean[1..1]\n<Operation>:o1(p1:String[1..1], p2:String[0..*])");
//     std::cout << "END UML Query_2 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool uml_query3() {
//     std::string qry = "self.name";
//     std::shared_ptr<uml::Model> p = ufactory->createModel();
//     std::shared_ptr<uml::Class> c1 = ufactory->createClass_as_ownedType_in_Package(p);
//     std::shared_ptr<uml::Property> context = ufactory->createProperty_as_ownedAttribute_in_Class(c1);
//     c1->setName("c1");
//     context->setName("a1");
//     context->setLower(0);
//     context->setUpper(-1);
//     context->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());

//     std::cout << "START UML Query_3(context = Property): " << qry << std::endl;
//     bool returnValue=query(qry,context,"a1");
//     std::cout << "END UML Query_3 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool  uml_query4() {
//     std::string qry = "self";
//     std::shared_ptr<uml::Model> p = ufactory->createModel();
//     std::shared_ptr<uml::Class> c1 = ufactory->createClass_as_ownedType_in_Package(p);
//     std::shared_ptr<uml::Operation> context = ufactory->createOperation_as_ownedOperation_in_Class(c1);
//     std::shared_ptr<uml::Parameter> p1 = ufactory->createParameter_as_ownedParameter_in_Operation(context);
//     std::shared_ptr<uml::Parameter> p2 = ufactory->createParameter_as_ownedParameter_in_Operation(context);

//     c1->setName("theContext");
//     context->setName("o1");
//     // throw an instance of char exception
//     //context->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
//     p1->setName("p1");
//     p1->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
//     p2->setName("p2");
//     p2->setLower(0);
//     p2->setUpper(-1);
//     p2->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());

//     std::cout << "START UML Query_4(context = Operation): " << qry << std::endl;
//     bool returnValue=query(qry, context, "<Operation>:o1(p1:String[1..1], p2:String[0..*])");
//     std::cout << "END UML Query_4 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// bool uml_any_query1() {
// 	bool returnValue=false;
//     std::string qry = "self.name";
//     std::shared_ptr<uml::Model> context = ufactory->createModel();
//     context->setName("uml_query1");
//     Any value = queryValue(qry, context);

//     std::cout << "START Query_UML_Any_1 (context = Model): " << qry << std::endl;
//     std::string resultStr ="";
//     if(value != nullptr) {
//     	resultStr= value->get<std::string>();
//         std::cout << resultStr << std::endl;
//     }
//     (resultStr.compare("uml_query1") == 0) ? returnValue = true : returnValue =  false;
//     returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
//     std::cout << "END Query_UML_Any_1 -------------------------------------------\n" << std::endl;
//     return returnValue ;
// }

// bool uml_any_query2() {
// 	bool returnValue=false;

//     std::string qry = "self.ownedElement";
//     std::shared_ptr<uml::Model> p = ufactory->createModel();
//     std::shared_ptr<uml::Class> context = ufactory->createClass_as_ownedType_in_Package(p);
//     std::shared_ptr<uml::Property> a1 = ufactory->createProperty_as_ownedAttribute_in_Class(context);
//     std::shared_ptr<uml::Property> a2 = ufactory->createProperty_as_ownedAttribute_in_Class(context);
//     std::shared_ptr<uml::Operation> o1 = ufactory->createOperation_as_ownedOperation_in_Class(context);
//     std::shared_ptr<uml::Parameter> p1 = ufactory->createParameter_as_ownedParameter_in_Operation(o1);
//     std::shared_ptr<uml::Parameter> p2 = ufactory->createParameter_as_ownedParameter_in_Operation(o1);

//     context->setName("theContext");
//     a1->setName("a1");
//     a1->setLower(0);
//     a1->setUpper(-1);
//     a1->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Integer());
//     a2->setName("a2");
//     a2->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
//     o1->setName("o1");
//     // throw an instance of char exception
//     //o1->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_Boolean());
//     p1->setName("p1");
//     p1->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());
//     p2->setName("p2");
//     p2->setLower(0);
//     p2->setUpper(-1);
//     p2->setType(PrimitiveTypes::PrimitiveTypesPackage::eInstance()->get_PrimitiveTypes_String());

//     std::cout << "START Query_UML_Any_2(context = Class): " << qry << std::endl;
//     Any value = queryValue(qry, context);

//     std::string resultStr = printUmlMany(value);
//     std::cout << resultStr << std::endl;
//     (resultStr.compare("<Property> a1 : Integer [0..*]\n<Property> a2 : Boolean [1..1]\n<Operation> o1(p1 : String [1..1], p2 : String [0..*])") == 0) ? returnValue = true : returnValue =  false;
//     returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
//     std::cout << "END Query_UML_Any_2 -------------------------------------------\n" << std::endl;
//     return returnValue;
// }

// void validate(std::shared_ptr<ecore::EObject> context,const std::string& query) {
//     try {
//         Utilities::Ocl ocl;
//         ocl.validate(query, context);
//         if(ocl.getErrors().size() > 0) {
//             std::cout << ocl.getError() << std::endl;
//         } else {
//             std::cout << ocl.getResult() << std::endl;
//         }
//     } catch (std::exception &e) {
//         std::cout << "exception : " << e.what() << std::endl;
//     }
// }

// bool query(const std::string& query, std::shared_ptr<ecore::EObject> context, const std::string& testStr) {
// 	bool returnValue = false;
//     try {
//         Utilities::Ocl ocl;
//         if(ocl.query(query, context)) {
//         	std::string resultStr=ocl.getResult();
//             std::cout << resultStr << std::endl;
//             (resultStr.compare(testStr) == 0) ? returnValue =  true : returnValue =  false;
//         } else {
//             std::cout << ocl.getError() << std::endl;
//         }
//     } catch (std::exception &e) {
//         std::cout << "exception : " << e.what() << std::endl;
//     }
//     returnValue ? std::cout << "success" << std::endl : std::cout << "fail" << std::endl;
//     return returnValue;
// }

// Any queryValue(const std::string& query, std::shared_ptr<ecore::EObject> context) {
//     try {
//         Utilities::Ocl ocl;
//         if(ocl.query(query, context)) {
//             return ocl.getResultValue();
//         } else {
//             std::cout << ocl.getError() << std::endl;
//         }
//     } catch (std::exception &e) {
//         std::cout << "exception : " << e.what() << std::endl;
//     }
//     return nullptr;
// }

// bool checkSyntaxQuery(const std::string& query) {
// 	bool returnValue=false;
//     try {
//         Utilities::Ocl ocl;
//         if(ocl.checkSyntaxQuery(query)) {
//             std::cout << "Syntax OK" << std::endl;
//             returnValue = true;
//         } else {
//             std::cout << ocl.getError() << std::endl;
//         }
//     } catch (std::exception &e) {
//         std::cout << "exception : " << e.what() << std::endl;
//     }
//     return returnValue;
// }

// bool checkSyntaxConstraint(const std::string& query) {
// 	bool returnValue=false;
//     try {
//         Utilities::Ocl ocl;
//         if(ocl.checkSyntaxConstraint(query)) {
//             std::cout << "Syntax OK" << std::endl;
//             returnValue = true;
//         } else {
//             std::cout << ocl.getError() << std::endl;
//         }
//     } catch (std::exception &e) {
//         std::cout << "exception : " << e.what() << std::endl;
//     }
//     return returnValue;
// }

// std::string printEcoreMany(Any value) {
// 	std::ostringstream returnStringStream;
// 	if(value != nullptr && !value->isEmpty()) {
//         std::shared_ptr<Bag<AnyObject>> valueItems = value->get<std::shared_ptr<Bag<AnyObject>>>();
//         for(size_t i = 0; i < valueItems->size(); i++) {
//         	returnStringStream << printEcore(valueItems->at(i));
//         }
//     }
// 	return returnStringStream.str();
// }

// std::string printUmlMany(Any value) {
// 	std::ostringstream returnStringStream;
//     if(value != nullptr && !value->isEmpty()) {
//         std::shared_ptr<Bag<AnyObject>> valueItems = value->get<std::shared_ptr<Bag<AnyObject>>>();
//         for(size_t i = 0; i < valueItems->size(); i++) {
//         	std::string result= printUml(valueItems->at(i));
//         	returnStringStream << printUml(valueItems->at(i));
//         }
//     }
// 	return returnStringStream.str();
// }

// std::string printEcore(Any value) {
// 	std::ostringstream returnStringStream;
//     try {
//         std::shared_ptr<ecore::EObject> eobj = value->get<std::shared_ptr<ecore::EObject>>();
//         std::shared_ptr<ecore::EOperation> eope = std::dynamic_pointer_cast<ecore::EOperation>(eobj);
//         if(eope != nullptr) {
//             return printEOperation(eope);
//         }
//         std::shared_ptr<ecore::EAttribute> eattr = std::dynamic_pointer_cast<ecore::EAttribute>(eobj);
//         if(eattr != nullptr) {
//             return printEAttribute(eattr);
//         }
//         std::shared_ptr<ecore::EReference> eref = std::dynamic_pointer_cast<ecore::EReference>(eobj);
//         if(eref != nullptr) {
//             return printEReference(eref);
//         }
//         std::shared_ptr<ecore::ETypedElement> etyped = std::dynamic_pointer_cast<ecore::ETypedElement>(eobj);
//         if(etyped != nullptr) {
//             return printETypedElement(etyped);
//         }
//         std::shared_ptr<ecore::ENamedElement> ename = std::dynamic_pointer_cast<ecore::ENamedElement>(eobj);
//         if(ename != nullptr) {
//             return printENamedElement(ename);
//         }
//     } catch (...) { }
//     try {
//         std::shared_ptr<ecore::EEnumLiteral> liter = value->get<std::shared_ptr<ecore::EEnumLiteral>>();
//         returnStringStream << liter->getName() << std::endl;
//     	return returnStringStream.str();
//     } catch (...) { }
//     try {
//         bool result = value->get<bool>();
//         returnStringStream << (result ? "true" : "false") << std::endl;
//     	return returnStringStream.str();
//     } catch (...) { }
//     try {
//         std::string result = value->get<std::string>();
//         returnStringStream << result << std::endl;
//     	return returnStringStream.str();
//     } catch (...) { }
//     try {
//         int result = value->get<int>();
//         returnStringStream << result << std::endl;
//     	return returnStringStream.str();
//     } catch (...) { }
//     try {
//         double result = value->get<double>();
//         returnStringStream << result << std::endl;
//     	return returnStringStream.str();
//     } catch (...) { }
// 	return returnStringStream.str();
// }

// std::string printUml(Any value) {
// 	std::ostringstream returnStringStream;
//     try {
//         std::shared_ptr<ecore::EObject> uobj = value->get<std::shared_ptr<ecore::EObject>>();
//         std::shared_ptr<uml::Operation> uope = std::dynamic_pointer_cast<uml::Operation>(uobj);
//         if(uope != nullptr) {
//             return printOperation(uope);
//         }
//         std::shared_ptr<uml::Property> prop = std::dynamic_pointer_cast<uml::Property>(uobj);
//         if(prop != nullptr) {
//             return printProperty(prop);
//         }
//         std::shared_ptr<uml::TypedElement> utyped = std::dynamic_pointer_cast<uml::TypedElement>(uobj);
//         if(utyped != nullptr) {
//             return printTypedElement(utyped);
//         }
//         std::shared_ptr<uml::NamedElement> uname = std::dynamic_pointer_cast<uml::NamedElement>(uobj);
//         if(uname != nullptr) {
//             return printNamedElement(uname);
//         }
//     } catch (...) { }
//     try {
//         std::shared_ptr<uml::EnumerationLiteral> liter = value->get<std::shared_ptr<uml::EnumerationLiteral>>();
//         returnStringStream << liter->getName() << std::endl;
//     	return returnStringStream.str();
//     } catch (...) { }
//     try {
//         bool result = value->get<bool>();
//         returnStringStream << (result ? "true" : "false") << std::endl;
//     	return returnStringStream.str();
//     } catch (...) { }
//     try {
//         std::string result = value->get<std::string>();
//         returnStringStream << result << std::endl;
//         std::cout<< "s" << std::endl;
//     	return returnStringStream.str();
//     } catch (...) { }
//     try {
//         int result = value->get<int>();
//         returnStringStream << result << std::endl;
//         std::cout<< "i" << std::endl;
//     	return returnStringStream.str();
//     } catch (...) { }
//     try {
//         double result = value->get<double>();
//         returnStringStream << result << std::endl;
//     	return returnStringStream.str();
//     } catch (...) { }
//     std::cout<< "1" << std::endl;
// 	return returnStringStream.str();
// }

// std::string printProperty(std::shared_ptr<uml::Property> uprop) {
// 	std::ostringstream returnStringStream;
// 	if(uprop != nullptr) {
//         if(uprop->getUpper() > 1 || uprop->getUpper() < 0)
//         	returnStringStream << "<Property> " + uprop->getName() + " : " + uprop->getType()->getName() + " ["
//                 +  std::to_string(uprop->getLower()) + "..*]" << std::endl;
//         else
//         	returnStringStream << "<Property> " + uprop->getName() + " : " + uprop->getType()->getName() + " ["
//                 +  std::to_string(uprop->getLower()) + ".." + std::to_string(uprop->getUpper()) + "]" << std::endl;
//     }
// 	return returnStringStream.str();
// }

// std::string printEAttribute(std::shared_ptr<ecore::EAttribute> eattr) {
// 	std::ostringstream returnStringStream;

//     if(eattr != nullptr) {
//         if(eattr->getUpperBound() > 1 || eattr->getUpperBound() < 0)
//         	returnStringStream << "<EAttribute> " + eattr->getName() + " : " + eattr->getEType()->getName()+ " [" +  std::to_string(eattr->getLowerBound()) + "..*]" << std::endl;
//         else
//         	returnStringStream << "<EAttribute> " + eattr->getName() + " : " + eattr->getEType()->getName()+ " [" +  std::to_string(eattr->getLowerBound()) + ".." + std::to_string(eattr->getUpperBound()) + "]" << std::endl;
//     }
// 	return returnStringStream.str();
// }

// std::string printEReference(std::shared_ptr<ecore::EReference> eref) {
// 	std::ostringstream returnStringStream;
// 	if(eref != nullptr) {
//         if(eref->getUpperBound() > 1 || eref->getUpperBound() < 0)
//         	returnStringStream << "<EReference> " + eref->getName() + " : " + eref->getEType()->getName()+ " [" +  std::to_string(eref->getLowerBound()) + "..*]" << std::endl;
//         else
//         	returnStringStream << "<EReference> " + eref->getName() + " : " + eref->getEType()->getName()+ " [" +  std::to_string(eref->getLowerBound()) + ".." + std::to_string(eref->getUpperBound()) + "]" << std::endl;
//     }
// 	return returnStringStream.str();
// }

// std::string printETypedElement(std::shared_ptr<ecore::ETypedElement> etyped) {
// 	std::ostringstream returnStringStream;
//     if(etyped != nullptr) {
//         if(etyped->isMany())
//         	returnStringStream << etyped->getName() + " : " + etyped->getEType()->getName()+ " [0..*]" << std::endl;
//         else
//         	returnStringStream << etyped->getName() + " : " + etyped->getEType()->getName()+ " [0..1]" << std::endl;
//     }
// 	return returnStringStream.str();
// }

// std::string printTypedElement(std::shared_ptr<uml::TypedElement> utyped) {
// 	std::ostringstream returnStringStream;
// 	if(utyped != nullptr) {
// 		returnStringStream << utyped->getName() + " : " + utyped->getType()->getName() << std::endl;
//     }
// 	return returnStringStream.str();
// }

// std::string printENamedElement(std::shared_ptr<ecore::ENamedElement> ename) {
// 	std::ostringstream returnStringStream;
// 	if(ename != nullptr) {
// 		returnStringStream << ename->getName() << std::endl;
//     }
// 	return returnStringStream.str();
// }

// std::string printNamedElement(std::shared_ptr<uml::NamedElement> uname) {
// 	std::ostringstream returnStringStream;
// 	if(uname != nullptr) {
// 		returnStringStream << uname->getName() << std::endl;
//     }
// 	return returnStringStream.str();
// }

// std::string printEOperation(std::shared_ptr<ecore::EOperation> eope) {
// 	std::string result ="";
// 	if(eope != nullptr) {
// 		result = "<Operation> " + eope->getName() + "(";
//         std::shared_ptr<Bag<ecore::EParameter>> ebag = std::dynamic_pointer_cast<Bag<ecore::EParameter>>(eope->getEParameters());
//         for(unsigned int i = 0; i < ebag->size(); i++) {
//             if(i > 0) result += ", ";
//             result += ebag->at(i)->getName() + " : ";
//             if(ebag->at(i)->getEType() != nullptr)
//                 result += ebag->at(i)->getEType()->getName();
//             else
//                 result += "[Not set in Model]";
//         }
//         result += ")";
//     }
// 	return result;
// }

// std::string printOperation(std::shared_ptr<uml::Operation> uope) {
// 	std::string result = "";
// 	if(uope != nullptr) {
//         result = "<Operation> " + uope->getName() + "(";
//         std::shared_ptr<Bag<uml::Parameter>> ebag = std::dynamic_pointer_cast<Bag<uml::Parameter>>(uope->getOwnedParameter());
//         for(unsigned int i = 0; i < ebag->size(); i++) {
//             if(i > 0) result += ", ";
//             result += ebag->at(i)->getName() + " : ";
//             if(ebag->at(i)->getType() != nullptr) {
//                 if(ebag->at(i)->getUpper() > 1 || ebag->at(i)->getUpper() < 0)
//                     result += ebag->at(i)->getType()->getName()+ " ["
//                         +  std::to_string(ebag->at(i)->getLower()) + "..*]";
//                 else
//                     result += ebag->at(i)->getType()->getName()+ " ["
//                         +  std::to_string(ebag->at(i)->getLower()) + ".." + std::to_string(ebag->at(i)->getUpper()) + "]";
//             }
//             else
//                 result += "[Not set in Model]";
//         }
//         result += ")";
//     }
// 	return result;
// }

// void pause() {
//     std::cout << "Enter to continue...";
//     std::cin.get();
// }
