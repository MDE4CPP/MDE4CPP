//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_BOOLEANFUNCTIONS__GLOBALFUNCTIONS_HPP
#define FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_BOOLEANFUNCTIONS__GLOBALFUNCTIONS_HPP

#include <memory>

class Any;
template<class T> class Bag;

namespace uml
{
	class OpaqueBehavior;
}

namespace FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions
{
	std::shared_ptr<Any> invoke(const std::shared_ptr<uml::OpaqueBehavior>&, const std::shared_ptr<Bag<Any>>&, const std::shared_ptr<Bag<Any>>&);
	std::shared_ptr<Any> invoke(unsigned long, const std::shared_ptr<Bag<Any>>&, const std::shared_ptr<Bag<Any>>&);
}

namespace FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions
{
	bool ToBoolean(const std::string x);
	bool Or(const bool x, const bool y);
	bool Not(const bool x);
	bool And(const bool x, const bool y);
	std::string ToString(const bool x);
	bool Implies(const bool x, const bool y);
	bool Xor(const bool x, const bool y);
}

#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_BOOLEANFUNCTIONS__GLOBALFUNCTIONS_HPP */
