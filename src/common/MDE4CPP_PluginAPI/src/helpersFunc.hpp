#ifndef HELPERFUNCTIONS_HPP
#define HELPERFUNCTIONS_HPP

#include <deque>
#include <string>

 namespace helperFunctions{
   /**
    * splits the string s at every occurence of split_char and writes every segment into the buffer
    * does not ever insert an empty string into buffer
    * @param buffer : reference to the vector where the string segments are supposed to be stored (empty segments are not inserted)
    * @param s : string that is supposed to be split
    * @param split_char : char denoting the boundery between to segments 
   */
    void split_string(std::deque<std::string>& buffer, const std::string s, char split_char);

   /**
    * intended to split the ObjectClass key into PluginName and object namespace and class name
    * ObjectClass key is supposed to be the form "PluginName: [ClassNamespace:] ClassName"
    * @param s : string that is supposed to be split
    * @return : tupel in the form [pluginName , ClassNamespaceAndName]
   */
    std::tuple<std::string,std::string> splitObjectClassKey(const std::string s);
 }


#endif /*HELPERFUNCTIONS_HPP*/