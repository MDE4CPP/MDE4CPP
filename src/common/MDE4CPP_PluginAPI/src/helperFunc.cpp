#include "helpersFunc.hpp"
#include <sstream>
#include <string>
#include <tuple>

std::shared_ptr<std::deque<std::string>> helperFunctions::split_string(const std::string s, const char split_char){
    std::stringstream ss;
    std::shared_ptr<std::deque<std::string>> buffer = std::make_shared<std::deque<std::string>>(std::deque<std::string>());
    ss << s; //initilize stringstream with sting 
    std::string segment; 
    while(std::getline(ss, segment, split_char)) //reads ss into segment until split_char is reached or ss is empty
    {
        buffer->push_back(segment); 
    }
    return buffer;
}

std::tuple<std::string,std::string> helperFunctions::splitObjectClassKey(const std::string s){
    std::string namespace_delimiter = "::";
    size_t pos = s.find(namespace_delimiter); 
    if(pos == std::string::npos){
        throw std::runtime_error("malformed ObjectClass key:" + s + "; needs to contain atleast the namespace of the plugin and a className!");
    }
    return {s.substr(0,pos), s.substr(pos + namespace_delimiter.size(), std::string::npos)};
}