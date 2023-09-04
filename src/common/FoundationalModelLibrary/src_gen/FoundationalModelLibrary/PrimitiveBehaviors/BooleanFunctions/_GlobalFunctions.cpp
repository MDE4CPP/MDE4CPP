#include "_GlobalFunctions.hpp"
#include <iostream>

#include "uml/UMLAny.hpp"
#include "uml/UMLContainerAny.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "uml/OpaqueBehavior.hpp"
#include "uml/FunctionBehavior.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/BooleanFunctions/BooleanFunctionsPackage.hpp"
#include "types/typesPackage.hpp"
#include <cassert>
#include <cctype>
#include <algorithm>

std::string FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::ToString(bool x)
{
	std::string result = "";

	//Implemented as OpaqueBehaviour ToString
	result = (x) ? "true" : "false";
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Implies(bool x,bool y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour Implies
	result = (not(x)) || (x && y);
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::ToBoolean(std::string x)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour ToBoolean
	std::transform(x.begin(), x.end(), x.begin(),
		[](unsigned char c){ return std::tolower(c); });
	
	assert(((x == "true") || (x == "false")));
	
	result = (x == "true") ? true : false;
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Xor(bool x,bool y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour Xor
	result = (x != y);
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::And(bool x,bool y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour And
	result = (x && y);
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Not(bool x)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour Not
	result = not (x);
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Or(bool x,bool y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour Or
	result = (x || y);
	

	return result;
}


std::shared_ptr<Any> FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = _opaqueBehavior->_getID();

	switch(uID)
	{
		case FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			bool x;
			try
			{
				x = anyX->get<bool>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			std::string result = FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::ToString(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::STRING_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_IMPLIES:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			bool x;
			try
			{
				x = anyX->get<bool>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			bool y;
			try
			{
				y = anyY->get<bool>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Implies(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_TOBOOLEAN:
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
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::ToBoolean(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_XOR:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			bool x;
			try
			{
				x = anyX->get<bool>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			bool y;
			try
			{
				y = anyY->get<bool>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Xor(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_AND:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			bool x;
			try
			{
				x = anyX->get<bool>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			bool y;
			try
			{
				y = anyY->get<bool>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::And(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_NOT:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			bool x;
			try
			{
				x = anyX->get<bool>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Not(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_OR:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'x'
			std::shared_ptr<Any> anyX =  inputArguments->at(0);
			bool x;
			try
			{
				x = anyX->get<bool>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'x'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			bool y;
			try
			{
				y = anyY->get<bool>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			bool result = FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Or(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::BOOLEAN_CLASS, false);
	
			return returnArgument;
		}
	}
	return nullptr;
}
