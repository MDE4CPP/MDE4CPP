//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_REALFUNCTIONS__GLOBALFUNCTIONS_HPP
#define FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_REALFUNCTIONS__GLOBALFUNCTIONS_HPP

#include <memory>

class Any;
template<class T> class Bag;

namespace uml
{
	class OpaqueBehavior;
}

namespace FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions
{
	std::shared_ptr<Any> invoke(const std::shared_ptr<uml::OpaqueBehavior>&, const std::shared_ptr<Bag<Any>>&, const std::shared_ptr<Bag<Any>>&);
	std::shared_ptr<Any> invoke(unsigned long, const std::shared_ptr<Bag<Any>>&, const std::shared_ptr<Bag<Any>>&);
}

namespace FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions
{
	int ToInteger(const double x);
	double Abs(const double x);
	std::string ToString(const double x);
	bool greaterOrEqual(const double x, const double y);
	double divide(const double x, const double y);
	double Min(const double x, const double y);
	bool greaterThan(const double x, const double y);
	double ToReal(const std::string x);
	double times(const double x, const double y);
	bool lessThan(const double x, const double y);
	double Max(const double x, const double y);
	double Inv(const double x);
	double minus(const double x, const double y);
	int Round(const double x);
	double Neg(const double x);
	bool lessOrEqual(const double x, const double y);
	int Floor(const double x);
	double plus(const double x, const double y);
}

#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_PRIMITIVEBEHAVIORS_REALFUNCTIONS__GLOBALFUNCTIONS_HPP */
