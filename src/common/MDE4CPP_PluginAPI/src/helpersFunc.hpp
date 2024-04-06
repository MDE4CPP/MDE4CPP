#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <deque>
#include <string>

 namespace helperFunctions{
    /**
     * splits the string s at every occurence of split_char and writes every segment into the buffer
     * does not ever insert an empty string into buffer
     * @param buffer : pointer to the vector where the string segments are supposed to be stored (empty segments are not inserted)
     * @param s : string that is supposed to be split
     * @param split_char : char denoting the boundery between to segments 
    */
    void split_string(std::deque<std::string>& buffer, const std::string s, char split_char);
 }

#endif /*HELPERFUNCTIONS_H*/