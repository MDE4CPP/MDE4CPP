#include "_GlobalFunctions.hpp"
#include <iostream>

#include "uml/UMLAny.hpp"
#include "uml/UMLContainerAny.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "uml/OpaqueBehavior.hpp"
#include "uml/FunctionBehavior.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/UnlimitedNaturalFunctions/UnlimitedNaturalFunctionsPackage.hpp"
#include "types/typesPackage.hpp"
#include <cassert>
#include "FoundationalModelLibrary/PrimitiveBehaviors/IntegerFunctions/_GlobalFunctions.hpp"

std::string FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::ToString(int x)
{
	std::string result = "";

	//Implemented as OpaqueBehaviour ToString
	result = (x == -1) ? "*" : std::to_string(x);
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::greaterOrEqual(int x,int y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour greaterOrEqual
	result = (x == y) || (FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::greaterThan(x, y));
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::ToUnlimitedNatural(std::string x)
{
	int result = 0;

	//Implemented as OpaqueBehaviour ToUnlimitedNatural
	result = (x == "*") ? -1 : FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::ToUnlimitedNatural(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::ToInteger(x));
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::lessThan(int x,int y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour lessThan
	result = (x == -1) ? false : ((y == -1) ? true : (x < y));
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::Min(int x,int y)
{
	int result = 0;

	//Implemented as OpaqueBehaviour Min
	result = (FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::lessOrEqual(x, y)) ? x : y;
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::Max(int x,int y)
{
	int result = 0;

	//Implemented as OpaqueBehaviour Max
	result = (FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::greaterOrEqual(x, y)) ? x : y;
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::greaterThan(int x,int y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour greaterThan
	result = not (FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::lessOrEqual(x, y));
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::ToInteger(int x)
{
	int result = 0;

	//Implemented as OpaqueBehaviour ToInteger
	assert((x >= 0));
	
	result = x;
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::lessOrEqual(int x,int y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour lessOrEqual
	result = (x == y) || (FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::lessThan(x, y));
	

	return result;
}


std::shared_ptr<Any> FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = _opaqueBehavior->_getID();

	switch(uID)
	{
		case FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::UNLIMITEDNATURALFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING:
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
			std::string result = FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::ToString(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::STRING_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::UNLIMITEDNATURALFUNCTIONS_FUNCTIONBEHAVIOR_GREATEROREQUAL:
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
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::greaterOrEqual(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::UNLIMITEDNATURALFUNCTIONS_FUNCTIONBEHAVIOR_TOUNLIMITEDNATURAL:
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
			int result = FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::ToUnlimitedNatural(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::UNLIMITEDNATURAL_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::UNLIMITEDNATURALFUNCTIONS_FUNCTIONBEHAVIOR_LESSTHAN:
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
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::lessThan(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::UNLIMITEDNATURALFUNCTIONS_FUNCTIONBEHAVIOR_MIN:
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
			int result = FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::Min(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::UNLIMITEDNATURAL_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::UNLIMITEDNATURALFUNCTIONS_FUNCTIONBEHAVIOR_MAX:
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
			int result = FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::Max(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::UNLIMITEDNATURAL_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::UNLIMITEDNATURALFUNCTIONS_FUNCTIONBEHAVIOR_GREATERTHAN:
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
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::greaterThan(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::UNLIMITEDNATURALFUNCTIONS_FUNCTIONBEHAVIOR_TOINTEGER:
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
			int result = FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::ToInteger(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::INTEGER_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::UNLIMITEDNATURALFUNCTIONS_FUNCTIONBEHAVIOR_LESSOREQUAL:
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
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::lessOrEqual(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
	}
	return nullptr;
}
