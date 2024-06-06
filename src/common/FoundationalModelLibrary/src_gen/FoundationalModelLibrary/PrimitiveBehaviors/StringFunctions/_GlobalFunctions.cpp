#include "_GlobalFunctions.hpp"
#include <iostream>

#include "uml/UMLAny.hpp"
#include "uml/UMLContainerAny.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "uml/OpaqueBehavior.hpp"
#include "uml/FunctionBehavior.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/StringFunctions/StringFunctionsPackage.hpp"
#include "types/typesPackage.hpp"

std::string FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::Concat(std::string x,std::string y)
{
	std::string result = "";

	//Implemented as OpaqueBehaviour Concat
	result = x + y;
	

	return result;
}
int FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::Size(std::string x)
{
	int result = 0;

	//Implemented as OpaqueBehaviour Size
	result = x.size();
	

	return result;
}
std::string FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::Substring(std::string x,int lower,int upper)
{
	std::string result = "";

	//Implemented as OpaqueBehaviour Substring
	lower -= 1; //C++ starts at 0, fUML starts at 1
	upper -= 1; //C++ starts at 0, fUML starts at 1
	
	unsigned int length = (upper - lower) + 1;
	
	result = x.substr(lower, length);
	

	return result;
}


std::shared_ptr<Any> FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::invoke(_opaqueBehavior->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::invoke(unsigned long uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	switch(uID)
	{
		case FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::StringFunctionsPackage::STRINGFUNCTIONS_FUNCTIONBEHAVIOR_CONCAT:
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
			//Retrieve in parameter 'y'
			std::shared_ptr<Any> anyY =  inputArguments->at(1);
			std::string y;
			try
			{
				y = anyY->get<std::string>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'y'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			std::string result = FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::Concat(x, y);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::STRING_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::StringFunctionsPackage::STRINGFUNCTIONS_FUNCTIONBEHAVIOR_SIZE:
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
			int result = FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::Size(x);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::INTEGER_CLASS, false);
	
			return returnArgument;
		}
		case FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::StringFunctionsPackage::STRINGFUNCTIONS_FUNCTIONBEHAVIOR_SUBSTRING:
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
			//Retrieve in parameter 'lower'
			std::shared_ptr<Any> anyLower =  inputArguments->at(1);
			int lower;
			try
			{
				lower = anyLower->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'lower'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}
			//Retrieve in parameter 'upper'
			std::shared_ptr<Any> anyUpper =  inputArguments->at(2);
			int upper;
			try
			{
				upper = anyUpper->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'upper'. Failed to invoke operation 'invalid'!")
				return nullptr;
			}

			//Invoke method
			std::string result = FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::Substring(x, lower, upper);
			std::shared_ptr<Any> returnArgument = eAny(result, types::typesPackage::STRING_CLASS, false);
	
			return returnArgument;
		}
	}
	return nullptr;
}
