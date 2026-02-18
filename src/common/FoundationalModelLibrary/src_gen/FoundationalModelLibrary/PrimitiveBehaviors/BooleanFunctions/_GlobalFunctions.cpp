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

bool FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Not(bool x)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour Not
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	
	result = not (x);
	DEBUG_INFO("[doBody] Boolean Not result = " << std::to_string(result))
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Or(bool x,bool y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour Or
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	DEBUG_INFO("[doBody] argument = " << std::to_string(y))
	
	result = (x || y);
	DEBUG_INFO("[doBody] Boolean Or result = " << std::to_string(result))
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::And(bool x,bool y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour And
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	DEBUG_INFO("[doBody] argument = " << std::to_string(y))
	
	result = (x && y);
	DEBUG_INFO("[doBody] Boolean And result = " << std::to_string(result))
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Implies(bool x,bool y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour Implies
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	DEBUG_INFO("[doBody] argument = " << std::to_string(y))
	
	result = (not(x)) || (x && y);
	DEBUG_INFO("[doBody] Boolean Implies result = " << std::to_string(result))
	

	return result;
}
std::string FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::ToString(bool x)
{
	std::string result = "";

	//Implemented as OpaqueBehaviour ToString
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	
	result = (x) ? "true" : "false";
	DEBUG_INFO("[doBody] Boolean ToString result = '" << result << "'")
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Xor(bool x,bool y)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour Xor
	DEBUG_INFO("[doBody] argument = " << std::to_string(x))
	DEBUG_INFO("[doBody] argument = " << std::to_string(y))
	
	result = (x != y);
	DEBUG_INFO("[doBody] Boolean Xor result = " << std::to_string(result))
	

	return result;
}
bool FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::ToBoolean(std::string x)
{
	bool result = 0;

	//Implemented as OpaqueBehaviour ToBoolean
	DEBUG_INFO("[doBody] argument = '" << x << "'")
	
	std::transform(x.begin(), x.end(), x.begin(),
		[](unsigned char c){ return std::tolower(c); });
	
	assert(((x == "true") || (x == "false")));
	
	result = (x == "true") ? true : false;
	
	DEBUG_INFO("[doBody] Boolean ToBoolean result = " << std::to_string(result))
	

	return result;
}


std::shared_ptr<Any> FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::invoke(_opaqueBehavior->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::invoke(unsigned long uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	switch(uID)
	{
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
	}
	return nullptr;
}
