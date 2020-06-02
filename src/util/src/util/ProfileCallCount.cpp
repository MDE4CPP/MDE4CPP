#include "util/ProfileCallCount.hpp"

#include <iostream>

using namespace callDebugCount;

ProfileCallCount* ProfileCallCount::instance = nullptr;

ProfileCallCount* ProfileCallCount::getInstance()
{
	if (!instance)
	{
		instance = new ProfileCallCount();
	}
	return instance;
}

void ProfileCallCount::addCount(std::string cntfunction)
{
	auto search = countmap.find(cntfunction);
	if (search != countmap.end())
	{
		search->second++;
	}
	else
	{
		countmap.insert(std::pair<std::string, int>(cntfunction, 1));
	}
}

void ProfileCallCount::subCount(std::string cntfunction)
{
	auto search = countmap.find(cntfunction);
	if (search != countmap.end())
	{
		search->second--;
	}
}

void ProfileCallCount::printFunc(std::string cntfunction)
{
	auto search = countmap.find(cntfunction);
	if (search != countmap.end())
	{
		std::cout<<"Function '"<<cntfunction<<"' counter: "<<search->second<<std::endl;
	}
	else 
	{
		std::cout<<"Function '"<<cntfunction<<"' not present in map"<<std::endl;
	}
}

void ProfileCallCount::printMap()
{
	std::map<std::string, int>::iterator it;

	std::cout << "Count Functions: " << countmap.size() << std::endl;

	for (it = countmap.begin(); it != countmap.end(); it++)
	{
		std::cout << it->second << ';' << it->first << std::endl;
	}
}
