//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_UNLIMITEDNATURALFUNCTIONS__GLOBALFUNCTIONS_HPP
#define FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_UNLIMITEDNATURALFUNCTIONS__GLOBALFUNCTIONS_HPP

#include <memory>

class Any;
template<class T> class Bag;

namespace uml
{
	class OpaqueBehavior;
}

namespace FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions
{
	std::shared_ptr<Any> invoke(const std::shared_ptr<uml::OpaqueBehavior>&, const std::shared_ptr<Bag<Any>>&, const std::shared_ptr<Bag<Any>>&);
	std::shared_ptr<Any> invoke(unsigned long, const std::shared_ptr<Bag<Any>>&, const std::shared_ptr<Bag<Any>>&);
}

namespace FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions
{
	int Min(const int x, const int y);
	int Max(const int x, const int y);
	bool lessThan(const int x, const int y);
	int ToInteger(const int x);
	bool greaterOrEqual(const int x, const int y);
	int ToUnlimitedNatural(const std::string x);
	bool lessOrEqual(const int x, const int y);
	bool greaterThan(const int x, const int y);
	std::string ToString(const int x);
}

#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_UNLIMITEDNATURALFUNCTIONS__GLOBALFUNCTIONS_HPP */
