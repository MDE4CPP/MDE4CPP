#ifndef UTIL_UTIL_HPP
#define UTIL_UTIL_HPP

#include <string>

namespace util
{
	class Util
	{
		public:
			Util();
			
			static long long polynomialRollingHash(std::string);
				
	};
}
#endif
