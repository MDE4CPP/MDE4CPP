#include <iostream>
#include <gtest/gtest.h>
#include "testHelpers.hpp"

#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "ecore/EClass.hpp"



#include "helpersFunc.hpp"
#include <tuple>

/**
 * Testing the HelperFunctions
*/


TEST(helperFunctions_Tests, splitObjectClassKey){
    auto [pluginName, className] = helperFunctions::splitObjectClassKey( "PluginName:ClassName");
    EXPECT_EQ(pluginName , "PluginName");
    EXPECT_EQ(className , "ClassName");

    auto [ _ , classNamespaceAndName] = helperFunctions::splitObjectClassKey( "PluginName:ClassNamespace:ClassName");
    EXPECT_EQ(classNamespaceAndName , "ClassNamespace:ClassName");
};



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


TEST_F(ModelInstanceTest, printModel) { //tests if SetUp was successfull
    auto printLibOp = m1_->getRootObject()->eClass()->getEOperation(libraryModel_ecore::libraryModel_ecorePackage::LIBRARYMODEL_OPERATION_PRINTLIBRARY);
    m1_->getRootObject()->eInvoke(printLibOp, std::make_shared<Bag<Any>>(Bag<Any>()));
}

TEST_F(ModelInstanceTest, getObjectAtPath_EmptyPath) {//tests getObjectAtPath with empty path
    auto p1 = m1_->getRootObject();
    std::deque<std::string> dq_path = {};
    EXPECT_TRUE(dq_path.empty());
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

TEST_F(ModelInstanceTest, getObjectAtPath_Author) {//tests getObjectAtPath with path to first first auhor
    std::deque<std::string> dq_path = {"authors@0"};
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

TEST_F(ModelInstanceTest, getObjectAtPath_Picure) {//tests getObjectAtPath with a longer path path 
    std::deque<std::string> dq_path = {"book@0","pictures@0"};
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

TEST_F(ModelInstanceTest, getObjectAtPath_OutOfBounds) {//tests getObjectAtPath with a path that tries to access a container out of bound 
    std::deque<std::string> dq_path = {"book@1","pictures@0"};
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

TEST_F(ModelInstanceTest, getObjectAtPath_BookGenre) {//tests getObjectAtPath with a path that tries to access a container StructFeature of pimitive types
    std::deque<std::string> dq_path = {"book@0","genres@1"};
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

TEST_F(ModelInstanceTest, getObjectAtPath_PicurePage) {//tests getObjectAtPath with a path that tries to access a non-container StructFeature of pimitive type
    std::deque<std::string> dq_path = {"book@0","pictures@0","pageNumber"};
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
    std::deque<std::string> dq_path = {"pictures"};
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
}