#include <iostream>
#include <gtest/gtest.h>
#include "testHelpers.hpp"

#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "ecore/EClass.hpp"

#include "helpersFunc.hpp"
#include <tuple>

#include "util/crow_all.h"
#define TEST_FRIENDS \
    friend class Json2EcoreTest_Json2Ecore_createModel_without_crossRef_Test;
#include "json2ecore.hpp"


/**
 * Testing the HelperFunctions
*/

//tests splitObjectClassKey function
TEST(helperFunctions_Tests, splitObjectClassKey){
    auto [pluginName, className] = helperFunctions::splitObjectClassKey( "PluginName::ClassName");
    EXPECT_EQ(pluginName , "PluginName");
    EXPECT_EQ(className , "ClassName");

    auto [ _ , classNamespaceAndName] = helperFunctions::splitObjectClassKey( "PluginName::ClassNamespace::ClassName");
    EXPECT_EQ(classNamespaceAndName , "ClassNamespace::ClassName");
};

//tests splitString function
TEST(helperFunctions_Tests, splitString){
    std::string test_string_1 = "segment_0:segment_1:segment_2";
    auto segmented_string = helperFunctions::split_string(test_string_1, ':');
    EXPECT_EQ(segmented_string->at(0), "segment_0");
    EXPECT_EQ(segmented_string->at(1), "segment_1");
    EXPECT_EQ(segmented_string->at(2), "segment_2");
    EXPECT_THROW(segmented_string->at(4), std::out_of_range);
}


#include "libraryModel_ecore/libraryModel_ecorePackage.hpp" //for Test printModel

#include "ModelInstance.hpp"


/**
 * Testing of the Class ModelInstance and its functions
*/

class ModelInstanceTest : public testing::Test { //helper class for testing ModelInstance
    protected:
        void SetUp() override {
            m1_ = std::make_shared<ModelInstance>(ModelInstance(testHelpers::getExampleModelInstance_1()));
        };
    std::shared_ptr<ModelInstance> m0_;
    std::shared_ptr<ModelInstance> m1_;
};

//tests if SetUp was successfull
TEST_F(ModelInstanceTest, printModel) { 
    auto printLibOp = m1_->getRootObject()->eClass()->getEOperation(libraryModel_ecore::libraryModel_ecorePackage::LIBRARYMODEL_OPERATION_PRINTLIBRARY);
    m1_->getRootObject()->eInvoke(printLibOp, std::make_shared<Bag<Any>>(Bag<Any>()));
}

//tests getObjectAtPath with empty path
TEST_F(ModelInstanceTest, getObjectAtPath_EmptyPath) {
    auto p1 = m1_->getRootObject();
    auto dq_path = std::make_shared<std::deque<std::string>>(std::deque<std::string>({}));
    EXPECT_TRUE(dq_path->empty());
    std::shared_ptr<EObject> p2;
    try
    {
        p2 = m1_->getObjectAtPath(dq_path);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    EXPECT_EQ(p1.get(), p2.get());
}

//tests getObjectAtPath with path to first first auhor
TEST_F(ModelInstanceTest, getObjectAtPath_Author) {
    auto dq_path = std::make_shared<std::deque<std::string>>(std::deque<std::string>({"authors@0"}));
    std::shared_ptr<EObject> p1;
    try
    {
        p1 = m1_->getObjectAtPath(dq_path);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    auto p1_name = p1->eClass()->getName();
    EXPECT_EQ(p1_name, "Author");
}

//tests getObjectAtPath with a longer path path 
TEST_F(ModelInstanceTest, getObjectAtPath_Picure) {
    auto dq_path = std::make_shared<std::deque<std::string>>(std::deque<std::string>({"book@0","pictures@0"}));
    std::shared_ptr<EObject> p1;
    try
    {
        p1 = m1_->getObjectAtPath(dq_path);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    auto p1_name = p1->eClass()->getName();
    EXPECT_EQ(p1_name, "Picture");
}

//tests getObjectAtPath with a path that tries to access a container out of bound 
TEST_F(ModelInstanceTest, getObjectAtPath_OutOfBounds) {
    auto dq_path = std::make_shared<std::deque<std::string>>(std::deque<std::string>({"book@1","pictures@0"}));
    std::shared_ptr<EObject> p1;
    std::string error;
    try
    {
        p1 = m1_->getObjectAtPath(dq_path);
    }
    catch(const std::exception& e)
    {
        error=  e.what();
    }

    EXPECT_EQ(error, "Bag.hpp: index out of range");
}

//tests getObjectAtPath with a path that tries to access a container StructFeature of pimitive types
TEST_F(ModelInstanceTest, getObjectAtPath_BookGenre) {
    auto dq_path = std::make_shared<std::deque<std::string>>(std::deque<std::string>({"book@0","genres@1"}));
    std::shared_ptr<Any> p1;
    try
    {
        p1 = m1_->getAnyAtPath(dq_path);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    auto p1_name = p1->get<std::shared_ptr<std::string>>();
    EXPECT_EQ(*p1_name, "Architecture");
}

//tests getObjectAtPath with a path that tries to access a non-container StructFeature of pimitive type
TEST_F(ModelInstanceTest, getObjectAtPath_PicurePage) {
    auto dq_path = std::make_shared<std::deque<std::string>>(std::deque<std::string>({"book@0","pictures@0","pageNumber"}));
    std::shared_ptr<Any> p1;
    try
    {
        p1 = m1_->getAnyAtPath(dq_path);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    auto p1_name = p1->get<int>();
    EXPECT_EQ(p1_name, 212);
}

TEST_F(ModelInstanceTest, getObjectAtPath_UnknownStrucFeature) {//tests getObjectAtPath with a path that tries to access a StrcuturalFeature that does not exist at that path 
    auto dq_path = std::make_shared<std::deque<std::string>>(std::deque<std::string>({"pictures"}));
    std::shared_ptr<EObject> p1;
    std::string error;
    try
    {
        p1 = m1_->getObjectAtPath(dq_path);
    }
    catch(const std::exception& e)
    {
        error=  e.what();
    }
    EXPECT_EQ(error, "structuralFeature: pictures not found in LibraryModel!");
}

/*
TEST_F(ModelInstanceTest, test_ecore_eContainer) {//tests the ecore eContainerFunction
    auto p0 = m1_->getRootObject();
    EXPECT_TRUE(p0->eContainer() == nullptr); //root_obj should return nullptr

    std::deque<std::string> dq_path = {"book@1","pictures@0"};//get picture 
    std::shared_ptr<EObject> p1;
    std::string error;
    try
    {
        p1 = m1_->getObjectAtPath(dq_path);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    EXPECT_FALSE(p1 == nullptr); //eContainer of picture should be set
}*/

/**
 * testing Json2Ecore 
*/


class Json2EcoreTest : public testing::Test {
    protected:
        void SetUp() override {
           rval = crow::json::load(testHelpers::getTestJSON_Large());
           Json2Ecore_Inst = Json2Ecore();
        };
    crow::json::rvalue rval;
    std::shared_ptr<ModelInstance> m;
    Json2Ecore Json2Ecore_Inst;
};

TEST_F(Json2EcoreTest, jsonPrint){
    crow::json::wvalue wval(rval);
    std::cout<<wval.dump()<<std::endl;
}

TEST_F(Json2EcoreTest, Json2Ecore_createModel_without_crossRef){
    std::vector<std::tuple<std::shared_ptr<EObject>, std::shared_ptr<ecore::EReference>, crow::json::rvalue>> crossReferenceBuffer;
    auto rootObj = Json2Ecore_Inst.createModelWithoutCrossRef(rval,crossReferenceBuffer);
    for(const auto [eObj, eRef, rval] : crossReferenceBuffer){
        crow::json::wvalue wval(rval);
        std::cout<<"reference " << eRef->getName() << " links to : " << wval.dump() << "; isContainer : " << eRef->isContainer() <<std::endl;
    }
}

TEST_F(Json2EcoreTest, Json2Ecore_createModel){
    m = Json2Ecore_Inst.createEcoreModelFromJson(rval);
    auto printLibOp = m->getRootObject()->eClass()->getEOperation(libraryModel_ecore::libraryModel_ecorePackage::LIBRARYMODEL_OPERATION_PRINTLIBRARY);
    m->getRootObject()->eInvoke(printLibOp, std::make_shared<Bag<Any>>(Bag<Any>()));

    auto dq_path = std::make_shared<std::deque<std::string>>(std::deque<std::string>({"book@0"}));
    auto obj = m->getObjectAtPath(dq_path);

    std::shared_ptr<EStructuralFeature> sFeature = obj->eClass()->getEStructuralFeature("Name");
    auto obj_name_any = obj->eGet(sFeature);
    std::cout << "type of any is " << obj_name_any->getTypeId() << std::endl;
    auto s = obj_name_any->get<std::string>();
    //auto obj_name = obj->get<std::shared_ptr<std::string>>();
    //EXPECT_EQ(*obj_name, "Der letzte Wunsch");
}