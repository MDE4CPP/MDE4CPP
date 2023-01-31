#include "_GlobalFunctions.hpp"
#include <iostream>

#include "uml/UMLAny.hpp"
#include "uml/UMLContainerAny.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "uml/OpaqueBehavior.hpp"
#include "uml/FunctionBehavior.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/RealFunctions/RealFunctionsPackage.hpp"
#include "types/typesPackage.hpp"
#include <cmath>
#include <algorithm>

double FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::plus(double x,double y)
{
	double result = 0;

	//Implemented as OpaqueBehaviour plus
	result = x + y;
	

	return result;
}
double FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Neg(double x)
{
	double result = 0;

	//Implemented as OpaqueBehaviour Neg
	result = x * (-1);
	

	return result;
}
std::string FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::ToString(double x)
{
	std::string result = "";

	//Implemented as OpaqueBehaviour ToString
	result = std::to_string(x);
	

	return result;
}
double FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Abs(double x)
{
	double result = 0;

	//Implemented as OpaqueBehaviour Abs
	result = std::abs(x);
	

	return result;
}
double FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Min(double x,double y)
{
	double result = 0;

	//Implemented as OpaqueBehaviour Min
	result = std::min(x, y);
	

	return result;
}
double FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Inv(double x)
{
	double result = 0;

	//No source code found for behavior 'Inv'
	//Make sure that 'CPP' is contained in the 'language' property of behavior 'Inv'
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
	

	return result;
}
double FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::ToReal(std::string x)
{
	double result = 0;

	//Implemented as OpaqueBehaviour ToReal
	result = std::stod(x);
	

	return result;
}
double FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Max(double x,double y)
{
	double result = 0;

	//Implemented as OpaqueBehaviour Max
	result = std::max(x, y);
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::greaterOrEqual(double x,double y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour greaterOrEqual
	result = (x >= y);
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::ToInteger(double x)
{
	int result = 0;

	//Implemented as OpaqueBehaviour ToInteger
	result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Floor(x);
	

	return result;
}
double FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::times(double x,double y)
{
	double result = 0;

	//Implemented as OpaqueBehaviour times
	result = x * y;
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Floor(double x)
{
	int result = 0;

	//Implemented as OpaqueBehaviour Floor
	result = std::floor(x);
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::greaterThan(double x,double y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour greaterThan
	result = (x > y);
	

	return result;
}
double FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::divide(double x,double y)
{
	double result = 0;

	//Implemented as OpaqueBehaviour divide
	result = x / y;
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::lessOrEqual(double x,double y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour lessOrEqual
	result = (x <= y);
	

	return result;
}
double FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::minus(double x,double y)
{
	double result = 0;

	//Implemented as OpaqueBehaviour minus
	result = x - y;
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::lessThan(double x,double y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour lessThan
	result = (x < y);
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Round(double x)
{
	int result = 0;

	//Implemented as OpaqueBehaviour Round
	result = std::round(x);
	

	return result;
}


std::shared_ptr<Any> FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(std::shared_ptr<uml::OpaqueBehavior> _opaqueBehavior, std::shared_ptr<Bag<Any>> inputArguments, std::shared_ptr<Bag<Any>> outputArguments)
{
	unsigned long uID = _opaqueBehavior->_getID();

	switch(uID)
	{
		case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_PLUS:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			double x;
			try
			{
				x = anyX->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			double y;
			try
			{
				y = anyY->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			double result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::plus(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::REAL_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_NEG:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			double x;
			try
			{
				x = anyX->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			double result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Neg(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::REAL_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			double x;
			try
			{
				x = anyX->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			std::string result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::ToString(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::STRING_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_ABS:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			double x;
			try
			{
				x = anyX->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			double result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Abs(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::REAL_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_MIN:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			double x;
			try
			{
				x = anyX->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			double y;
			try
			{
				y = anyY->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			double result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Min(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::REAL_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_INV:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			double x;
			try
			{
				x = anyX->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			double result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Inv(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::REAL_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_TOREAL:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			std::string x;
			try
			{
				x = anyX->get<std::string>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			double result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::ToReal(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::REAL_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_MAX:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			double x;
			try
			{
				x = anyX->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			double y;
			try
			{
				y = anyY->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			double result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Max(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::REAL_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_GREATEROREQUAL:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			double x;
			try
			{
				x = anyX->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			double y;
			try
			{
				y = anyY->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::greaterOrEqual(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_TOINTEGER:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			double x;
			try
			{
				x = anyX->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			int result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::ToInteger(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::INTEGER_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_TIMES:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			double x;
			try
			{
				x = anyX->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			double y;
			try
			{
				y = anyY->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			double result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::times(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::REAL_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_FLOOR:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			double x;
			try
			{
				x = anyX->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			int result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Floor(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::INTEGER_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_GREATERTHAN:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			double x;
			try
			{
				x = anyX->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			double y;
			try
			{
				y = anyY->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::greaterThan(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_DIVIDE:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			double x;
			try
			{
				x = anyX->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			double y;
			try
			{
				y = anyY->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			double result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::divide(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::REAL_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_LESSOREQUAL:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			double x;
			try
			{
				x = anyX->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			double y;
			try
			{
				y = anyY->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::lessOrEqual(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_MINUS:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			double x;
			try
			{
				x = anyX->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			double y;
			try
			{
				y = anyY->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			double result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::minus(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::REAL_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_LESSTHAN:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			double x;
			try
			{
				x = anyX->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			double y;
			try
			{
				y = anyY->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::lessThan(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_ROUND:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			double x;
			try
			{
				x = anyX->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			int result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Round(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::INTEGER_CLASS, false);
	
			return returnArgument;
		}
	}
	return nullptr;
}
