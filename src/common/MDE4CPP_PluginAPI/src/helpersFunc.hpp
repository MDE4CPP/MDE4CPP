#ifndef HELPERFUNCTIONS_HPP
#define HELPERFUNCTIONS_HPP

#include <deque>
#include <string>
#include <vector>
#include <memory> //for shared_ptr

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Any.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EcoreAny.hpp"

namespace helperFunctions{
  /**
  * splits the string s at every occurence of split_char and writes every segment into the buffer
  * does not ever insert an empty string into buffer
  * @param buffer : reference to the vector where the string segments are supposed to be stored (empty segments are not inserted)
  * @param s : string that is supposed to be split
  * @param split_char : char denoting the boundery between to segments 
  */
  std::deque<std::string> split_string(const std::string s, const char split_char);

  /**
   * splits the PathSegment into the name of the StructuralFeature as a String and an index as an integer if one exists in the Segment
   * @param PathSegment : string that is supposed to be split
   *   - expectet format: NameOfStructFeature [@Index]
   * @return : tuple in the form (featureName, hasIndex, Index)
   */
  std::tuple<std::string, bool, unsigned int> splitStructuralFeaturePathSegment(const std::string PathSegment);


  /**
  * intended to split the ObjectClass key into PluginName and object namespace and class name
  * ObjectClass key 
  * @param ObjectClassKey : string that is supposed to be split
  *   - is supposed to be the form "PluginName: [ClassNamespace:] ClassName"
  * @return : tupel in the form (pluginName , ClassNamespaceAndName)
  */
  std::tuple<std::string,std::string> splitObjectClassKey(const std::string ObjectClassKey);

  /**
   * TODO Docu
   */
  void replaceElementInAnyBag(const std::shared_ptr<Any>& any_ptr, unsigned int index, const std::shared_ptr<Any>& new_element);

  /**
   * TODO : Docu
   */
  template <typename T>
  void replaceElementInBag(const std::shared_ptr<Bag<T>>& bag_ptr, unsigned int index, const std::shared_ptr<Any>& new_element);

  
  void replaceCompleteAnyBag(const std::shared_ptr<Any>& any_ptr, const std::shared_ptr<Any>& new_anyBag);

  template <typename T>
  void replaceCompleteAnyBag(const std::shared_ptr<Bag<T>>& bag_ptr, const std::shared_ptr<Bag<T>>& new_bag);

  /*
  template <>
  void replaceElementInBag<ecore::EObject>(const std::shared_ptr<Bag<ecore::EObject>>& bag_ptr, int index, const std::shared_ptr<Any>& new_element){
    
    unsigned long typeID = new_element->getTypeId();
    std::shared_ptr<ecore::EcoreAny> new_ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(new_element);
    if(new_ecoreAny == nullptr){//cast failed
        throw(std::runtime_error("replaceElementInBag : any with type : \"" + std::to_string(typeID) + "\" could not be cast into a EcoreContainerAny!"));
        return;
    }
    std::shared_ptr<ecore::EObject> new_eObj_ptr = new_ecoreAny->getAsEObject();

    if(bag_ptr->begin() + index <= bag_ptr->end()){
        auto it = bag_ptr->erase(bag_ptr->begin() + index);
        bag_ptr->insert(it, new_eObj_ptr);
    }else if (bag_ptr->begin() + index == bag_ptr->end() + 1)
    {
        bag_ptr->push_back(new_eObj_ptr);
    }else{
        throw std::runtime_error("Bag : out of bounds");
    }
  }*/
}


#endif /*HELPERFUNCTIONS_HPP*/