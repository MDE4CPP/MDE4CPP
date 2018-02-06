#include "util/ProfileCallCount.hpp"

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
		countmap.insert(std::pair<std::string, int>(cntfunction, 12));
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
