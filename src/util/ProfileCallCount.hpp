#ifndef __PROFILE_CALL_COUNT__
#define __PROFILE_CALL_COUNT__


#include <map>
#include <iostream>

namespace callDebugCount
{

    class ProfileCallCount
    {

    public:
        ~ProfileCallCount(){};

        static ProfileCallCount* getInstance();

        void addCount(std::string cntfunction);
        void printMap();

    private:
        ProfileCallCount(){};

        std::map<std::string,int> countmap;
        static ProfileCallCount* instance;


    };



}


#define ADD_COUNT(cntfunction) callDebugCount::ProfileCallCount::getInstance()->addCount(cntfunction);




#endif