#include <iostream>
#include <gtest/gtest.h>
#include "testHelpers.hpp"

#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "ecore/EClass.hpp"

#include "helpersFunc.hpp"
#include <tuple>

#include "util/crow_all.h"

#include "libraryModel_ecore/LibraryModel.hpp"

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
    EXPECT_EQ(segmented_string.at(0), "segment_0");
    EXPECT_EQ(segmented_string.at(1), "segment_1");
    EXPECT_EQ(segmented_string.at(2), "segment_2");
    EXPECT_THROW(segmented_string.at(4), std::out_of_range);
}

TEST(helperFunctions_Tests, replaceElementInBag){
    std::shared_ptr<Bag<std::string>> bag_ptr = std::make_shared<Bag<std::string>>();
    bag_ptr->push_back(std::make_shared<std::string>("first_string"));
    bag_ptr->push_back(std::make_shared<std::string>("second_string"));
    bag_ptr->push_back(std::make_shared<std::string>("third_string"));
    bag_ptr->push_back(std::make_shared<std::string>("fourth_string"));
    bag_ptr->push_back(std::make_shared<std::string>("fifths_string"));

    unsigned int i = 0;
    EXPECT_EQ(*(bag_ptr->at(i)), "first_string");
    EXPECT_EQ(bag_ptr->size(), 5);
    std::shared_ptr<Any> any_ptr_1 =  eAny<std::string>("new_first_string", ecore::ecorePackage::ESTRING_CLASS, false);
    helperFunctions::replaceElementInBag(bag_ptr, i, any_ptr_1);
    EXPECT_EQ(bag_ptr->size(), 5);
    EXPECT_EQ(*(bag_ptr->at(i)), "new_first_string");

    i = 5;
    EXPECT_THROW(bag_ptr->at(i), std::invalid_argument);
    EXPECT_EQ(bag_ptr->size(), 5);
    std::shared_ptr<Any> any_ptr_2 =  eAny<std::string>("new_sixth_string", ecore::ecorePackage::ESTRING_CLASS, false);
    helperFunctions::replaceElementInBag(bag_ptr, i, any_ptr_2);
    EXPECT_EQ(bag_ptr->size(), 6);
    EXPECT_EQ(*(bag_ptr->at(i)), "new_sixth_string");

    i = 9;
    EXPECT_THROW(bag_ptr->at(i), std::invalid_argument);
    EXPECT_EQ(bag_ptr->size(), 6);
    std::shared_ptr<Any> any_ptr_3 =  eAny<std::string>("new_tenth_string", ecore::ecorePackage::ESTRING_CLASS, false);
    EXPECT_THROW(helperFunctions::replaceElementInBag(bag_ptr, i, any_ptr_3), std::runtime_error);
    EXPECT_EQ(bag_ptr->size(), 6);
}

/**
 * Testing of the Class ModelInstance and its functions
*/

#include "libraryModel_ecore/libraryModel_ecorePackage.hpp" //for Test printModel

#define TEST_FRIENDS_MODELINSTANCE \
    friend class ModelInstanceTest_setAttributeAtPath_String_Test;\
    friend class ModelInstanceTest_setAttributeAtPath_Number_Test;\
    friend class ModelInstanceTest_setAttributeAtPath_StringBag_ReplaceBag_Test;\
    friend class ModelInstanceTest_setAttributeAtPath_StringBag_UpdateElement_Test;\
    friend class ModelInstanceTest_setAttributeAtPath_StringBag_NewElement_Test;
#include "ModelInstance.hpp"

class ModelInstanceTest : public testing::Test { //helper class for testing ModelInstance
    protected:
        void SetUp() override {
            m1_ = std::make_shared<ModelInstance>(ModelInstance(testHelpers::getExampleModelInstance_1()));
        };
    std::shared_ptr<ModelInstance> m1_;
};

//tests if SetUp was successfull
TEST_F(ModelInstanceTest, printModel) { 
    auto printLibOp = m1_->getRootObject()->eClass()->getEOperation(libraryModel_ecore::libraryModel_ecorePackage::LIBRARYMODEL_OPERATION_PRINTLIBRARY);
    m1_->getRootObject()->eInvoke(printLibOp, std::make_shared<Bag<Any>>(Bag<Any>()));
}

//tests getObjectAtPath with empty path
TEST_F(ModelInstanceTest, getObjectAtPath_EmptyPath) {
    std::shared_ptr<EObject> obj_1 = m1_->getRootObject();
    auto dq_path = std::deque<std::string>({});
    EXPECT_TRUE(dq_path.empty());
    std::shared_ptr<EObject> obj_2;
    try
    {
        obj_2 = m1_->getObjectAtPath(dq_path);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        FAIL();
    }
    EXPECT_EQ(obj_1.get(), obj_2.get());
}

//tests getObjectAtPath with path to first first auhor
TEST_F(ModelInstanceTest, getObjectAtPath_Author) {
    auto dq_path = std::deque<std::string>({"authors@0"});
    std::shared_ptr<EObject> author_eObj;
    try{
        author_eObj = m1_->getObjectAtPath(dq_path);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        FAIL();
    }
    std::string author_eObj_eClass_Name = author_eObj->eClass()->getName();
    EXPECT_EQ(author_eObj_eClass_Name, "Author");
}

//tests getObjectAtPath with a longer path path 
TEST_F(ModelInstanceTest, getObjectAtPath_Picure) {
    auto dq_path = std::deque<std::string>({"books@0","pictures@0"});
    std::shared_ptr<EObject> pitcure_eObj;
    try
    {
        pitcure_eObj = m1_->getObjectAtPath(dq_path);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::string pitcure_eObj_eClass_Name = pitcure_eObj->eClass()->getName();
    EXPECT_EQ(pitcure_eObj_eClass_Name, "Picture");
}

//tests getObjectAtPath with a path that tries to access a container out of bound 
TEST_F(ModelInstanceTest, getObjectAtPath_OutOfBounds) {
    auto dq_path = std::deque<std::string>({"books@1","pictures@0"});
    std::shared_ptr<EObject> pitcure_any;
    std::string error;
    try{
        pitcure_any = m1_->getObjectAtPath(dq_path);
    }
    catch(const std::exception& e){
        error=  e.what();
    }

    EXPECT_EQ(error, "Bag.hpp: index out of range");
}

//tests getObjectAtPath with a path that tries to access a container StructFeature of pimitive types
TEST_F(ModelInstanceTest, getObjectAtPath_BookGenre) {
    auto dq_path = std::deque<std::string>({"books@0","genres@1"});
    std::shared_ptr<Any> genre_any;
    try{
        genre_any = m1_->getAnyAtPath(dq_path);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        FAIL();
    }
    std::string genre = genre_any->get<std::string>();
    EXPECT_EQ(genre, "Architecture");
}

//tests getObjectAtPath with a path that tries to access a non-container StructFeature of pimitive type
TEST_F(ModelInstanceTest, getObjectAtPath_PicurePage) {
    auto dq_path = std::deque<std::string>({"books@0","pictures@0","pageNumber"});
    std::shared_ptr<Any> page_number_any;
    try{
        page_number_any = m1_->getAnyAtPath(dq_path);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        FAIL();
    }
    int page_number = page_number_any->get<int>();
    EXPECT_EQ(page_number, 212);
}

TEST_F(ModelInstanceTest, getObjectAtPath_UnknownStrucFeature) {//tests getObjectAtPath with a path that tries to access a StrcuturalFeature that does not exist at that path 
    auto dq_path = std::deque<std::string>({"pictures"});
    std::shared_ptr<EObject> obj_1;
    std::string error;
    try{
        obj_1 = m1_->getObjectAtPath(dq_path);
    }
    catch(const std::exception& e){
        error=  e.what();
    }
    EXPECT_EQ(error, "structuralFeature: pictures not found in LibraryModel!");
}

TEST_F(ModelInstanceTest, setAttributeAtPath_StringBag_ReplaceBag){
    auto dq_path_genres = std::deque<std::string>({"books@0","genres"});
    std::shared_ptr<Any> bookObj_genres_any;
    std::shared_ptr<Bag<std::string>> bookObj_genres;

    try{
        bookObj_genres_any = m1_->getAnyAtPath(dq_path_genres);
        bookObj_genres = bookObj_genres_any->get<std::shared_ptr<Bag<std::string>>>();
        EXPECT_EQ(*(bookObj_genres->at(0)),"Art");
        EXPECT_EQ(*(bookObj_genres->at(1)),"Architecture");
        EXPECT_THROW(bookObj_genres->at(2), std::invalid_argument);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        FAIL();
    }

    Bag<std::string> new_genres_bag = Bag<std::string>();
    std::string first_element = "first_new_genre";
    new_genres_bag.push_back(std::make_shared<std::string>(first_element));
    std::string second_element = "second_new_genre";
    new_genres_bag.push_back(std::make_shared<std::string>(second_element));
    std::string third_element = "third_new_genre";
    new_genres_bag.push_back(std::make_shared<std::string>(third_element));


    EXPECT_EQ(*(new_genres_bag.at(0)), first_element);
    EXPECT_EQ(*(new_genres_bag.at(1)), second_element);
    EXPECT_EQ(*(new_genres_bag.at(2)), third_element);
    EXPECT_THROW(new_genres_bag.at(3), std::invalid_argument);

    std::shared_ptr<Bag<std::string>> new_genres_bag_ptr = std::make_shared<Bag<std::string>>(new_genres_bag);
    std::shared_ptr<Any> new_genres_bag_any_ptr = eAny(new_genres_bag_ptr, ecorePackage::ESTRING_CLASS, true); 
    m1_->updateAttributeAtPath(dq_path_genres, new_genres_bag_any_ptr);
    try{
        bookObj_genres_any = m1_->getAnyAtPath(dq_path_genres);
        bookObj_genres = bookObj_genres_any->get<std::shared_ptr<Bag<std::string>>>();
        EXPECT_EQ(*(bookObj_genres->at(0)), first_element);
        EXPECT_EQ(*(bookObj_genres->at(1)), second_element);
        EXPECT_EQ(*(bookObj_genres->at(2)), third_element);
        EXPECT_THROW(bookObj_genres->at(3), std::invalid_argument);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        FAIL();
    }
}

TEST_F(ModelInstanceTest, setAttributeAtPath_StringBag_UpdateElement){
    auto dq_path_genres = std::deque<std::string>({"books@0","genres"});
    std::shared_ptr<Any> bookObj_genres_any;
    std::shared_ptr<Bag<std::string>> bookObj_genres;

    try{
        bookObj_genres_any = m1_->getAnyAtPath(dq_path_genres);
        bookObj_genres = bookObj_genres_any->get<std::shared_ptr<Bag<std::string>>>();
        EXPECT_EQ(*(bookObj_genres->at(0)),"Art");
        EXPECT_EQ(*(bookObj_genres->at(1)),"Architecture");
        EXPECT_THROW(bookObj_genres->at(2), std::invalid_argument);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        FAIL();
    }

    auto dq_path_genres_update = std::deque<std::string>({"books@0","genres@1"});
    std::string updated_genre = "an_updated_genre";
    std::shared_ptr<Any> updated_genre_any_ptr = eAny(updated_genre, ecorePackage::ESTRING_CLASS, false);
    m1_->updateAttributeAtPath(dq_path_genres_update, updated_genre_any_ptr);
    try{
        bookObj_genres_any = m1_->getAnyAtPath(dq_path_genres);
        bookObj_genres = bookObj_genres_any->get<std::shared_ptr<Bag<std::string>>>();
        EXPECT_EQ(*(bookObj_genres->at(0)),"Art");
        EXPECT_EQ(*(bookObj_genres->at(1)), updated_genre);
        EXPECT_THROW(bookObj_genres->at(2), std::invalid_argument);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        FAIL();
    }
}

TEST_F(ModelInstanceTest, setAttributeAtPath_StringBag_NewElement){
    auto dq_path_genres = std::deque<std::string>({"books@0","genres"});
    std::shared_ptr<Any> bookObj_genres_any;
    std::shared_ptr<Bag<std::string>> bookObj_genres;

    try{
        bookObj_genres_any = m1_->getAnyAtPath(dq_path_genres);
        bookObj_genres = bookObj_genres_any->get<std::shared_ptr<Bag<std::string>>>();
        EXPECT_EQ(*(bookObj_genres->at(0)),"Art");
        EXPECT_EQ(*(bookObj_genres->at(1)),"Architecture");
        EXPECT_THROW(bookObj_genres->at(2), std::invalid_argument);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        FAIL();
    }

    auto dq_path_genres_new_genre = std::deque<std::string>({"books@0","genres@2"});
    auto dq_path_genres_invalide_new_genre = std::deque<std::string>({"books@0","genres@3"});
    std::string new_genre = "a_new_genre";
    std::shared_ptr<Any> new_genre_any_ptr = eAny(new_genre, ecorePackage::ESTRING_CLASS, false); 

    EXPECT_THROW(m1_->updateAttributeAtPath(dq_path_genres_invalide_new_genre, new_genre_any_ptr), std::runtime_error);
    try{
        bookObj_genres_any = m1_->getAnyAtPath(dq_path_genres);
        bookObj_genres = bookObj_genres_any->get<std::shared_ptr<Bag<std::string>>>();
        EXPECT_EQ(*(bookObj_genres->at(0)),"Art");
        EXPECT_EQ(*(bookObj_genres->at(1)),"Architecture");
        EXPECT_THROW(bookObj_genres->at(2), std::invalid_argument);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        FAIL();
    }

    m1_->updateAttributeAtPath(dq_path_genres_new_genre, new_genre_any_ptr);
    try{
        bookObj_genres_any = m1_->getAnyAtPath(dq_path_genres);
        bookObj_genres = bookObj_genres_any->get<std::shared_ptr<Bag<std::string>>>();
        EXPECT_EQ(*(bookObj_genres->at(0)),"Art");
        EXPECT_EQ(*(bookObj_genres->at(1)),"Architecture");
        EXPECT_EQ(*(bookObj_genres->at(2)), new_genre);
        EXPECT_THROW(bookObj_genres->at(3), std::invalid_argument);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        FAIL();
    }
}

TEST_F(ModelInstanceTest, setAttributeAtPath_Number){
    auto dq_path_pages = std::deque<std::string>({"books@0","pages"});
    std::shared_ptr<Any> bookObj_pages_any;
    int bookObj_pages;

    try{
        bookObj_pages_any = m1_->getAnyAtPath(dq_path_pages);
        bookObj_pages = bookObj_pages_any->get<int>();
        EXPECT_EQ(bookObj_pages, 448);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        FAIL();
    }

    int new_pages = 7872;
    std::shared_ptr<Any> new_pages_any_ptr = eAny(new_pages, ecorePackage::EINT_CLASS, false);
    m1_->updateAttributeAtPath(dq_path_pages, new_pages_any_ptr);
    try{
        bookObj_pages_any = m1_->getAnyAtPath(dq_path_pages);
        bookObj_pages = bookObj_pages_any->get<int>();
        EXPECT_EQ(bookObj_pages, new_pages);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        FAIL();
    }
}

TEST_F(ModelInstanceTest, setAttributeAtPath_String){
    auto dq_path_name = std::deque<std::string>({"books@0","Name"});
    std::shared_ptr<Any> bookObj_name_any;
    std::string bookObj_name;

    try{
        bookObj_name_any = m1_->getAnyAtPath(dq_path_name);
        bookObj_name = bookObj_name_any->get<std::string>();
        EXPECT_EQ(bookObj_name, "Magritte");
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        FAIL();
    }
    
    std::string new_name = "a_random_new_name";
    std::shared_ptr<Any> new_name_any_ptr = eAny(new_name, ecorePackage::ESTRING_CLASS, false);
    m1_->updateAttributeAtPath(dq_path_name, new_name_any_ptr);
    try{
        bookObj_name_any = m1_->getAnyAtPath(dq_path_name);
        bookObj_name = bookObj_name_any->get<std::string>();
        EXPECT_EQ(bookObj_name, new_name);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        FAIL();
    }
}

/*
TEST_F(ModelInstanceTest, test_ecore_eContainer) {//tests the ecore eContainerFunction
    auto p0 = m1_->getRootObject();
    EXPECT_TRUE(p0->eContainer() == nullptr); //root_obj should return nullptr

    std::deque<std::string> dq_path = {"books@1","pictures@0"};//get picture 
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

#define TEST_FRIENDS_JSON2ECORE \
    friend class Json2EcoreTest_Json2Ecore_createModel_without_crossRef_Test;
#include "json2ecore.hpp"


class Json2EcoreTest : public testing::Test {
    protected:
        void SetUp() override {
           rval = crow::json::load(testHelpers::getTestJSON_Medium());
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
    auto rootObj = Json2Ecore_Inst.createObjectWithoutCrossRef(rval);
    for(const auto & [eObj, eRef, rval] : Json2Ecore_Inst.m_crossReferenceBuffer){
        crow::json::wvalue wval(rval);
        std::cout<<"reference " << eRef->getName() << " links to : " << wval.dump() << "; isContainer : " << eRef->isContainer() <<std::endl;
    }
}

TEST_F(Json2EcoreTest, Json2Ecore_createModel){
    m = Json2Ecore_Inst.createEcoreModelFromJson(rval);
    auto printLibOp = m->getRootObject()->eClass()->getEOperation(libraryModel_ecore::libraryModel_ecorePackage::LIBRARYMODEL_OPERATION_PRINTLIBRARY);
    m->getRootObject()->eInvoke(printLibOp, std::make_shared<Bag<Any>>(Bag<Any>()));

    auto dq_path = std::deque<std::string>({"books@0", "Name"});
    auto obj = m->getAnyAtPath(dq_path);
    std::cout << "type of any is " << obj->getTypeId() << std::endl;
    auto obj_name = obj->get<std::string>();
    EXPECT_EQ(obj_name, "Magritte");

    auto dq_path2 = std::deque<std::string>({"authors@0", "Name"});
    auto obj2 = m->getAnyAtPath(dq_path2);
    std::cout << "type of any is " << obj->getTypeId() << std::endl;
    auto obj_name2 = obj2->get<std::string>();
    EXPECT_EQ(obj_name2, "David Sylvester");

    auto dq_path3 = std::deque<std::string>({"authors@0"});
    auto obj3 = m->getObjectAtPath(dq_path3);
    auto dq_path4 =std::deque<std::string>({"books@0", "authors@0"});
    auto obj4 = m->getObjectAtPath(dq_path4);
    std::cout << "type of any is " << obj->getTypeId() << std::endl;
    EXPECT_EQ(obj3.get(), obj4.get());

    std::shared_ptr<ecore::EObject> r_obj = m->getRootObject();
    std::shared_ptr<libraryModel_ecore::LibraryModel> debugModel = std::dynamic_pointer_cast<libraryModel_ecore::LibraryModel>(r_obj);
}

#include "ecore2json.hpp"

class Ecore2JsonTest : public testing::Test{
    protected:
        void SetUp() override {
            m_ = testHelpers::getExampleModelInstance_1();
            e2j_ = Ecore2Json();
        }
    ModelInstance m_;
    Ecore2Json e2j_;
};

TEST_F (Ecore2JsonTest , modelParsing){
    auto root_obj = m_.getRootObject();
    auto result = crow::json::wvalue();
    e2j_.createJsonOfEObject(root_obj, result);
    EXPECT_EQ(result["books"][0]["authors"][0].dump(), result["authors"][0]["ObjectID"].dump());
    std::cout << result.dump() << std::endl;
}