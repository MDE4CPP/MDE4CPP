#include "helpersFunc.hpp"
#include <sstream>
#include <string>
#include <tuple>

std::deque<std::string> helperFunctions::split_string(const std::string s, const char split_char){
    std::stringstream ss;
    std::deque<std::string> buffer = std::deque<std::string>();
    ss << s; //initilize stringstream with sting 
    std::string segment; 
    while(std::getline(ss, segment, split_char)) //reads ss into segment until split_char is reached or ss is empty
    {
        buffer.push_back(segment); 
    }
    return buffer;
}

std::tuple<std::string, bool, unsigned int> helperFunctions::splitStructuralFeaturePathSegment(const std::string PathSegment){
    char indexSymbol = '@';
    std::deque<std::string> d = split_string(PathSegment, indexSymbol);
    switch(d.size()){
        case 1 : 
            return {d[0], false, 0};
            break;
        case 2 : 
            return {d[0], true, std::stoi(d[1])};
            break;
        default : 
            throw std::invalid_argument("splitStructuralFeaturePathSegment : more than one @ found in segment");
    }
}

std::tuple<std::string,std::string> helperFunctions::splitObjectClassKey(const std::string s){
    std::string namespace_delimiter = "::";
    size_t pos = s.find(namespace_delimiter); 
    if(pos == std::string::npos){
        throw std::runtime_error("malformed ObjectClass key:" + s + "; needs to contain atleast the namespace of the plugin and a className!");
    }
    return {s.substr(0,pos), s.substr(pos + namespace_delimiter.size(), std::string::npos)};
}

void helperFunctions::replaceElementInAnyBag(const std::shared_ptr<Any>& any_ptr, unsigned int index, const std::shared_ptr<Any>& new_element){
    unsigned long typeID = any_ptr->getTypeId();
    switch (typeID){
        case ecore::ecorePackage::EBOOLEAN_CLASS:{
            std::shared_ptr<Bag<bool>> bag = any_ptr->get<std::shared_ptr<Bag<bool>>>();
            replaceElementInBag(bag, index, new_element);
            break;
        }
        case ecore::ecorePackage::ECHAR_CLASS:{
            std::shared_ptr<Bag<char>> bag = any_ptr->get<std::shared_ptr<Bag<char>>>();
            replaceElementInBag(bag, index, new_element);
            break;
        }
        case ecore::ecorePackage::EINT_CLASS:{
            std::shared_ptr<Bag<int>> bag = any_ptr->get<std::shared_ptr<Bag<int>>>();
            replaceElementInBag(bag, index, new_element);
            break;
        }
        case ecore::ecorePackage::ELONG_CLASS:{
            std::shared_ptr<Bag<long>> bag = any_ptr->get<std::shared_ptr<Bag<long>>>();
            replaceElementInBag(bag, index, new_element);
            break;
        }
        case ecore::ecorePackage::EFLOAT_CLASS:{
            std::shared_ptr<Bag<float>> bag = any_ptr->get<std::shared_ptr<Bag<float>>>();
            replaceElementInBag(bag, index, new_element);
            break;
        }
        case ecore::ecorePackage::EDOUBLEOBJECT_CLASS:{
            std::shared_ptr<Bag<double>> bag = any_ptr->get<std::shared_ptr<Bag<double>>>();
            replaceElementInBag(bag, index, new_element);
            break;
        }
        case ecore::ecorePackage::ESTRING_CLASS:{
            std::shared_ptr<Bag<std::string>> bag = any_ptr->get<std::shared_ptr<Bag<std::string>>>();
            replaceElementInBag(bag, index, new_element);
            break;
        }
        default: //should not get here -> unsupported DataType
            throw std::runtime_error("unsupported type: " + typeID);
            return; //abort
    }
};

template <typename T>
  void helperFunctions::replaceElementInBag(const std::shared_ptr<Bag<T>>& bag_ptr, unsigned int index, const std::shared_ptr<Any>& new_element){

    T newValue;
    try{
        newValue = new_element->get<T>();
    }catch(const std::runtime_error& e){
      throw std::runtime_error(e.what());
      return;
    }
    
    if(bag_ptr->size() > index ){
      std::shared_ptr<T> elem_ptr = bag_ptr->at(index);
      *elem_ptr = newValue;
    }else if (bag_ptr->size() == index ){
      bag_ptr->push_back(std::make_shared<T>(newValue));
    }else{
      throw std::runtime_error("Bag : out of bounds");
    }
}

void helperFunctions::replaceCompleteAnyBag(const std::shared_ptr<Any>& any_ptr, const std::shared_ptr<Any>& new_anyBag){
    unsigned long typeID = any_ptr->getTypeId();
    switch (typeID){
        case ecore::ecorePackage::EBOOLEAN_CLASS:{
            std::shared_ptr<Bag<bool>> bag = any_ptr->get<std::shared_ptr<Bag<bool>>>();
            std::shared_ptr<Bag<bool>> new_bag = new_anyBag->get<std::shared_ptr<Bag<bool>>>();
            replaceCompleteAnyBag(bag, new_bag);
            break;
        }
        case ecore::ecorePackage::ECHAR_CLASS:{
            std::shared_ptr<Bag<char>> bag = any_ptr->get<std::shared_ptr<Bag<char>>>();
            std::shared_ptr<Bag<char>> new_bag = new_anyBag->get<std::shared_ptr<Bag<char>>>();
            replaceCompleteAnyBag(bag, new_bag);
            break;
        }
        case ecore::ecorePackage::EINT_CLASS:{
            std::shared_ptr<Bag<int>> bag = any_ptr->get<std::shared_ptr<Bag<int>>>();
            std::shared_ptr<Bag<int>> new_bag = new_anyBag->get<std::shared_ptr<Bag<int>>>();
            replaceCompleteAnyBag(bag, new_bag);
            break;
        }
        case ecore::ecorePackage::ELONG_CLASS:{
            std::shared_ptr<Bag<long>> bag = any_ptr->get<std::shared_ptr<Bag<long>>>();
            std::shared_ptr<Bag<long>> new_bag = new_anyBag->get<std::shared_ptr<Bag<long>>>();
            replaceCompleteAnyBag(bag, new_bag);
            break;
        }
        case ecore::ecorePackage::EFLOAT_CLASS:{
            std::shared_ptr<Bag<float>> bag = any_ptr->get<std::shared_ptr<Bag<float>>>();
            std::shared_ptr<Bag<float>> new_bag = new_anyBag->get<std::shared_ptr<Bag<float>>>();
            replaceCompleteAnyBag(bag, new_bag);
            break;
        }
        case ecore::ecorePackage::EDOUBLEOBJECT_CLASS:{
            std::shared_ptr<Bag<double>> bag = any_ptr->get<std::shared_ptr<Bag<double>>>();
            std::shared_ptr<Bag<double>> new_bag = new_anyBag->get<std::shared_ptr<Bag<double>>>();
            replaceCompleteAnyBag(bag, new_bag);
            break;
        }
        case ecore::ecorePackage::ESTRING_CLASS:{
            std::shared_ptr<Bag<std::string>> bag = any_ptr->get<std::shared_ptr<Bag<std::string>>>();
            std::shared_ptr<Bag<std::string>> new_bag = new_anyBag->get<std::shared_ptr<Bag<std::string>>>();
            replaceCompleteAnyBag(bag, new_bag);
            break;
        }
        default: //should not get here -> unsupported DataType
            throw std::runtime_error("unsupported type: " + typeID);
            return; //abort
    }
}

template <typename T>
void helperFunctions::replaceCompleteAnyBag(const std::shared_ptr<Bag<T>>& bag_ptr, const std::shared_ptr<Bag<T>>& new_bag){
    bag_ptr->clear();
    for(std::shared_ptr<T> element : *new_bag){
        bag_ptr->push_back(element);
    }
}