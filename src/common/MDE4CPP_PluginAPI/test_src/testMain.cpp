#include <iostream>
#include <gtest/gtest.h>
#include "testHelpers.hpp"

#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "ecore/EClass.hpp"



/**
 * Testing the HelperFunctions
*/



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