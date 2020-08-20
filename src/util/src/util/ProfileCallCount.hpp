#ifndef UTIL_PROFILE_CALL_COUNT_HPP
#define UTIL_PROFILE_CALL_COUNT_HPP

#include <map>

namespace callDebugCount
{
	class ProfileCallCount
	{
		public:
			~ProfileCallCount()
			{
			};

			static ProfileCallCount* getInstance();

			void addCount(std::string cntfunction);
			void subCount(std::string cntfunction);
			void printFunc(std::string cntfunction);
			void printMap();

		private:
			ProfileCallCount()
			{
			};

			std::map<std::string, int> countmap;
			static ProfileCallCount* instance;
	};
}

#define ADD_COUNT(cntfunction) callDebugCount::ProfileCallCount::getInstance()->addCount(cntfunction);
#define SUB_COUNT(cntfunction) callDebugCount::ProfileCallCount::getInstance()->subCount(cntfunction);

#endif
