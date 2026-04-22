#include "_GlobalFunctions.hpp"
#include <iostream>

#include "uml/UMLAny.hpp"
#include "uml/UMLContainerAny.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "uml/OpaqueBehavior.hpp"
#include "uml/FunctionBehavior.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/IntegerFunctions/IntegerFunctionsPackage.hpp"
#include "types/typesPackage.hpp"
#include <cmath>  
#include <cassert>
#include <algorithm>

bool FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::greaterOrEqual(int x,int y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour greaterOrEqual
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	DEBUG_INFO("[doBody] argument = " << std::to_string(y))
	
	result = (x >= y);
	DEBUG_INFO("[doBody] Integer Greater Than or Equal result = " << std::to_string(result))
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::lessOrEqual(int x,int y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour lessOrEqual
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	DEBUG_INFO("[doBody] argument = " << std::to_string(y))
	
	result = (x <= y);
	DEBUG_INFO("[doBody] Integer Less Than or Equal result = " << std::to_string(result))
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Mod(int x,int y)
{
	int result = 0;

	//Implemented as OpaqueBehaviour Mod
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	DEBUG_INFO("[doBody] argument = " << std::to_string(y))
	
	result = x % y;
	DEBUG_INFO("[doBody] Integer Modulo result = " << std::to_string(result))
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Abs(int x)
{
	int result = 0;

	//Implemented as OpaqueBehaviour Abs
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	
	result = std::abs(x);
	DEBUG_INFO("[doBody] Integer Abs result = " << std::to_string(result))
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::ToUnlimitedNatural(int x)
{
	int result = 0;

	//Implemented as OpaqueBehaviour ToUnlimitedNatural
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	
	assert((x >= 0));
	
	result = x;
	DEBUG_INFO("[doBody] Integer ToUnlimitedNatural result = " << std::to_string(result))
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::ToInteger(std::string x)
{
	int result = 0;

	//Implemented as OpaqueBehaviour ToInteger
	DEBUG_INFO("[doBody] argument = " << x)
	
	result = std::stoi(x);
	DEBUG_INFO("[doBody] Integer ToInteger result = " << std::to_string(result))
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::lessThan(int x,int y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour lessThan
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	DEBUG_INFO("[doBody] argument = " << std::to_string(y))
	
	result = (x < y);
	DEBUG_INFO("[doBody] Integer Less Than result = " << std::to_string(result))
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Min(int x,int y)
{
	int result = 0;

	//Implemented as OpaqueBehaviour Min
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	DEBUG_INFO("[doBody] argument = " << std::to_string(y))
	
	result = std::min(x,y);
	DEBUG_INFO("[doBody] Integer Min result = " << std::to_string(result))
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::minus(int x,int y)
{
	int result = 0;

	//Implemented as OpaqueBehaviour minus
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	DEBUG_INFO("[doBody] argument = " << std::to_string(y))
	
	result = x - y;
	DEBUG_INFO("[doBody] Integer Minus result = " << std::to_string(result))
	

	return result;
}
std::string FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::ToString(int x)
{
	std::string result = "";

	//Implemented as OpaqueBehaviour ToString
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	
	result = std::to_string(x);
	DEBUG_INFO("[doBody] Integer ToString result = " << result)
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::greaterThan(int x,int y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour greaterThan
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	DEBUG_INFO("[doBody] argument = " << std::to_string(y))
	
	result = (x > y);
	DEBUG_INFO("[doBody] Integer Greater Than result = " << std::to_string(result))
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::plus(int x,int y)
{
	int result = 0;

	//Implemented as OpaqueBehaviour plus
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	DEBUG_INFO("[doBody] argument = " << std::to_string(y))
	
	result = x + y;
	DEBUG_INFO("[doBody] Integer Plus result = " << std::to_string(result))
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::equals(int x,int y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour equals
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	DEBUG_INFO("[doBody] argument = " << std::to_string(y))
	
	result = (x == y);
	DEBUG_INFO("[doBody] Integer Equals result = " << std::to_string(result))
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::times(int x,int y)
{
	int result = 0;

	//Implemented as OpaqueBehaviour times
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	DEBUG_INFO("[doBody] argument = " << std::to_string(y))
	
	result = x * y;
	DEBUG_INFO("[doBody] Integer Multiply result = " << std::to_string(result))
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Neg(int x)
{
	int result = 0;

	//Implemented as OpaqueBehaviour Neg
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	
	result = x * (-1);
	DEBUG_INFO("[doBody] Integer Negate result = " << std::to_string(result))
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Max(int x,int y)
{
	int result = 0;

	//Implemented as OpaqueBehaviour Max
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	DEBUG_INFO("[doBody] argument = " << std::to_string(y))
	
	result = std::max(x,y);
	DEBUG_INFO("[doBody] Integer Max result = " << std::to_string(result))
	

	return result;
}
double FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::divide(int x,int y)
{
	double result = 0;

	//Implemented as OpaqueBehaviour divide
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	DEBUG_INFO("[doBody] argument = " << std::to_string(y))
	
	result = (double)x / (double)y;
	DEBUG_INFO("[doBody] Integer divide result = " << std::to_string(result))
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Div(int x,int y)
{
	int result = 0;

	//Implemented as OpaqueBehaviour Div
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	DEBUG_INFO("[doBody] argument = " << std::to_string(y))
	
	result =x / y;
	
	DEBUG_INFO("[doBody] Integer Div result = " << std::to_string(result))
	

	return result;
}


std::shared_ptr<Any> FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(_opaqueBehavior->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(unsigned long uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	switch(uID)
	{
		case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_GREATEROREQUAL:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			int x;
			try
			{
				x = anyX->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			int y;
			try
			{
				y = anyY->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::greaterOrEqual(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_LESSOREQUAL:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			int x;
			try
			{
				x = anyX->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			int y;
			try
			{
				y = anyY->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::lessOrEqual(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MOD:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			int x;
			try
			{
				x = anyX->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			int y;
			try
			{
				y = anyY->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			int result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Mod(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::INTEGER_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_ABS:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			int x;
			try
			{
				x = anyX->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			int result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Abs(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::INTEGER_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TOUNLIMITEDNATURAL:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			int x;
			try
			{
				x = anyX->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			int result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::ToUnlimitedNatural(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::UNLIMITEDNATURAL_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TOINTEGER:
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
			int result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::ToInteger(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::INTEGER_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_LESSTHAN:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			int x;
			try
			{
				x = anyX->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			int y;
			try
			{
				y = anyY->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::lessThan(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MIN:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			int x;
			try
			{
				x = anyX->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			int y;
			try
			{
				y = anyY->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			int result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Min(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::INTEGER_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MINUS:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			int x;
			try
			{
				x = anyX->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			int y;
			try
			{
				y = anyY->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			int result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::minus(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::INTEGER_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			int x;
			try
			{
				x = anyX->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			std::string result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::ToString(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::STRING_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_GREATERTHAN:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			int x;
			try
			{
				x = anyX->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			int y;
			try
			{
				y = anyY->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::greaterThan(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_PLUS:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			int x;
			try
			{
				x = anyX->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			int y;
			try
			{
				y = anyY->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			int result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::plus(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::INTEGER_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_EQUALS:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			int x;
			try
			{
				x = anyX->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			int y;
			try
			{
				y = anyY->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::equals(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TIMES:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			int x;
			try
			{
				x = anyX->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			int y;
			try
			{
				y = anyY->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			int result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::times(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::INTEGER_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_NEG:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			int x;
			try
			{
				x = anyX->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			int result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Neg(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::INTEGER_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MAX:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			int x;
			try
			{
				x = anyX->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			int y;
			try
			{
				y = anyY->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			int result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Max(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::INTEGER_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_DIVIDE:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			int x;
			try
			{
				x = anyX->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			int y;
			try
			{
				y = anyY->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			double result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::divide(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::REAL_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_DIV:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			int x;
			try
			{
				x = anyX->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			int y;
			try
			{
				y = anyY->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			int result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Div(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::INTEGER_CLASS, false);
	
			return returnArgument;
		}
	}
	return nullptr;
}
