#include "util/util.hpp"

using namespace util;

Util::Util()
{
}

long long Util::polynomialRollingHash(std::string qualifiedName)
{
		//generate a hash value from string using polynomial rolling hash
		int n = qualifiedName.size();
		int m = (int) (10e9 + 9);
		int p = 53;
		long long powerOfP = 1;
		long long hash = 0;
		
		for(int i = 0; i < n; i++)
		{
			int c = qualifiedName.at(i);
			hash = (hash + c * powerOfP) % m;
			powerOfP = (powerOfP * p) % m;
		}
		
		return hash;
}
