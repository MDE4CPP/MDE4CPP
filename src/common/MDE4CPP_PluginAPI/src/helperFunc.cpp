#include "helpersFunc.hpp"
#include <sstream>
#include <string>
#include <tuple>

void helperFunctions::split_string(std::deque<std::string>& buffer, const std::string s, char split_char){
    std::stringstream ss;
    ss << s; //initilize stringstream with sting 
    std::string segment; 
    while(std::getline(ss, segment, split_char)) //reads ss into segment until split_char is reached or ss is empty
    {
        buffer.push_back(segment); 
    }
}

std::tuple<std::string,std::string> helperFunctions::splitObjectClassKey(const std::string s){
    size_t pos = s.find(':'); 
    if(pos == std::string::npos){
        throw std::runtime_error("malformed ObjectClass key:" + s + "; needs to contain atleast the namespace of the plugin and a className!");
    }
    return {s.substr(0,pos), s.substr(pos +1, std::string::npos)};
}