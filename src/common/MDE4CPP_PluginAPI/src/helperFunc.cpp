#include "helpersFunc.hpp"
#include <sstream>

void helperFunctions::split_string(std::deque<std::string>& buffer, const std::string s, char split_char){
    std::stringstream ss;
    ss << s; //initilize stringstream with sting 
    std::string segment; 
    while(std::getline(ss, segment, split_char)) //reads ss into segment until split_char is reached or ss is empty
    {
        buffer.push_back(segment); 
    }
}