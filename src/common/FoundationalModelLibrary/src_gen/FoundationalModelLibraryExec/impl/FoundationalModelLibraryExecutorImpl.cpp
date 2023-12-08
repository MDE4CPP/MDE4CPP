#include "FoundationalModelLibraryExecutorImpl.hpp"
#include <iostream>

#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
#endif

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "uml/umlPackage.hpp"
#include "uml/Activity.hpp"
#include "uml/Enumeration.hpp"
#include "uml/EnumerationLiteral.hpp"
#include "uml/FunctionBehavior.hpp"
#include "uml/InstanceValue.hpp"
#include "uml/OpaqueBehavior.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterDirectionKind.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "FoundationalModelLibrary/BasicInputOutput/BasicInputOutputPackage.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/BooleanFunctions/BooleanFunctionsPackage.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/IntegerFunctions/IntegerFunctionsPackage.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/RealFunctions/RealFunctionsPackage.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/StringFunctions/StringFunctionsPackage.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/UnlimitedNaturalFunctions/UnlimitedNaturalFunctionsPackage.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/StringFunctions/_GlobalFunctions.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/RealFunctions/_GlobalFunctions.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/BooleanFunctions/_GlobalFunctions.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/UnlimitedNaturalFunctions/_GlobalFunctions.hpp"
#include "FoundationalModelLibrary/PrimitiveBehaviors/IntegerFunctions/_GlobalFunctions.hpp"

using namespace FoundationalModelLibrary;

//*********************************
// Constructor / Destructor
//*********************************
FoundationalModelLibraryExecutorImpl::FoundationalModelLibraryExecutorImpl()
{
}

FoundationalModelLibraryExecutorImpl::~FoundationalModelLibraryExecutorImpl()
{
}

std::shared_ptr<Any> FoundationalModelLibraryExecutorImpl::evaluate(const std::shared_ptr<uml::ValueSpecification>& specification)
{
	return fUML::Semantics::Loci::ExecutorImpl::evaluate(specification);
	//return PSCS::Semantics::Loci::CS_ExecutorImpl::evaluate(specification);
}

std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> FoundationalModelLibraryExecutorImpl::execute(const std::shared_ptr<uml::Behavior>& behavior, const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& context, const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& inputs)
{
	int behaviorMetaElementID = behavior->getMetaElementID();
    if((behaviorMetaElementID == uml::umlPackage::OPAQUEBEHAVIOR_CLASS) || (behaviorMetaElementID == uml::umlPackage::FUNCTIONBEHAVIOR_CLASS))
    {
		const std::shared_ptr<uml::OpaqueBehavior>& opaqueBehavior = std::dynamic_pointer_cast<uml::OpaqueBehavior>(behavior);
		return this->invokeOpaqueBehavior(opaqueBehavior, context, inputs);
    }
	else if(behaviorMetaElementID == uml::umlPackage::ACTIVITY_CLASS)
	{
		const std::shared_ptr<fUML::Semantics::Activities::ActivityExecution>& activityExecution = 
			std::dynamic_pointer_cast<fUML::Semantics::Activities::ActivityExecution>(this->getLocus().lock()->getFactory()->createExecution(behavior, context));

		//Model-internal activities
		if(activityExecution)
		{
			activityExecution->getParameterValues()->clear();
			activityExecution->setContext(context);
	
			for(const std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue>& inputParameterValue : *inputs)
		    {
		        activityExecution->setParameterValue(inputParameterValue);
		    }
	
			activityExecution->execute();

			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> outputParameterValues = activityExecution->getOutputParameterValues();
			activityExecution->getParameterValues()->clear();
			activityExecution->getActivationGroup()->terminateAll();
			
			return outputParameterValues;
		}
		//Model-external activities
		else
		{
			//No external activities called in Activities of this model
		}
	}
	else
	{
		std::cerr<<__PRETTY_FUNCTION__<<" : Unsupported type of Behavior! Currently only Activities, OpaqueBehaviors and FunctionBehaviors are supported!"<<std::endl;
	}

	return fUML::Semantics::Loci::ExecutorImpl::execute(behavior, context, inputs);
}

std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> FoundationalModelLibraryExecutorImpl::invokeOpaqueBehavior(const std::shared_ptr<uml::OpaqueBehavior>& opaqueBehavior, const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& context, const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& inputs)
{
	std::string pluginName;

	//No external opaque behaviors called in Activities of this model

	//I know, this is a very ugly way to determine if we are handling an internal or external behavior...
	//Model-internal OpaqueBehavior
	if(pluginName.empty())
	{

		std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> outputParameterValues(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
		std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> returnParameterValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();

		std::shared_ptr<Bag<Any>> inputArguments(new Bag<Any>());
		std::shared_ptr<Bag<Any>> outputArguments(new Bag<Any>());
		std::shared_ptr<Any> result;

		for(const std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue>& parameterValue : *inputs)
		{
			inputArguments->add(parameterValue->getValues()->at(0));
		}

		switch(opaqueBehavior->_getID())
		{
			case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_PLUS:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::plus has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_plus_result());
				break;
			}
			case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_READLINE:
			{	
				// OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextInputChannel::fb_readLine specifies Operation FoundationalModelLibrary::BasicInputOutput::TextInputChannel::readLine
				if(!context)
				{
					DEBUG_ERROR("Context for execution OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextInputChannel::fb_readLine is null!");
					return outputParameterValues;
				}
				result = context->invoke(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readLine_Status_Status(), inputArguments, outputArguments);

				//Create output ParameterValue for out parameter errorStatus
				std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> errorStatusParameterValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();
				errorStatusParameterValue->setParameter(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readLine_errorStatus());
				errorStatusParameterValue->getValues()->add(outputArguments->at(0));
				outputParameterValues->add(errorStatusParameterValue);
				returnParameterValue->setParameter(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readLine_ReturnResult());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MAX:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Max has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Max_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_TOREAL:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::ToReal has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToReal_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_MAX:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Max has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Max_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::StringFunctionsPackage::STRINGFUNCTIONS_FUNCTIONBEHAVIOR_CONCAT:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::Concat has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::StringFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Concat_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_LESSTHAN:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::lessThan has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_lessThan_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::StringFunctionsPackage::STRINGFUNCTIONS_FUNCTIONBEHAVIOR_SUBSTRING:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::Substring has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::StringFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Substring_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_DIVIDE:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::divide has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_divide_result());
				break;
			}
			case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITELINE:
			{	
				// OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::fb_writeLine specifies Operation FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::writeLine
				if(!context)
				{
					DEBUG_ERROR("Context for execution OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::fb_writeLine is null!");
					return outputParameterValues;
				}
				result = context->invoke(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeLine_String_Status_String_Status(), inputArguments, outputArguments);

				//Create output ParameterValue for out parameter errorStatus
				std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> errorStatusParameterValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();
				errorStatusParameterValue->setParameter(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeLine_errorStatus());
				errorStatusParameterValue->getValues()->add(outputArguments->at(0));
				outputParameterValues->add(errorStatusParameterValue);
				break;
			}
			case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITEINTEGER:
			{	
				// OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::fb_writeInteger specifies Operation FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::writeInteger
				if(!context)
				{
					DEBUG_ERROR("Context for execution OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::fb_writeInteger is null!");
					return outputParameterValues;
				}
				result = context->invoke(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeInteger_Integer_Status_Integer_Status(), inputArguments, outputArguments);

				//Create output ParameterValue for out parameter errorStatus
				std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> errorStatusParameterValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();
				errorStatusParameterValue->setParameter(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeInteger_errorStatus());
				errorStatusParameterValue->getValues()->add(outputArguments->at(0));
				outputParameterValues->add(errorStatusParameterValue);
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_PLUS:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::plus has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_plus_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_GREATEROREQUAL:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::greaterOrEqual has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_greaterOrEqual_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::UNLIMITEDNATURALFUNCTIONS_FUNCTIONBEHAVIOR_MAX:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::Max has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_Max_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_LESSTHAN:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::lessThan has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessThan_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::UNLIMITEDNATURALFUNCTIONS_FUNCTIONBEHAVIOR_LESSOREQUAL:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::lessOrEqual has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_lessOrEqual_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_ROUND:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Round has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Round_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_NEG:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Neg has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Neg_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::ToString has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToString_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_EQUALS:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::equals has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_equals_result());
				break;
			}
			case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_READINTEGER:
			{	
				// OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextInputChannel::fb_readInteger specifies Operation FoundationalModelLibrary::BasicInputOutput::TextInputChannel::readInteger
				if(!context)
				{
					DEBUG_ERROR("Context for execution OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextInputChannel::fb_readInteger is null!");
					return outputParameterValues;
				}
				result = context->invoke(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readInteger_Status_Status(), inputArguments, outputArguments);

				//Create output ParameterValue for out parameter errorStatus
				std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> errorStatusParameterValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();
				errorStatusParameterValue->setParameter(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readInteger_errorStatus());
				errorStatusParameterValue->getValues()->add(outputArguments->at(0));
				outputParameterValues->add(errorStatusParameterValue);
				returnParameterValue->setParameter(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readInteger_ReturnResult());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_GREATEROREQUAL:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::greaterOrEqual has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterOrEqual_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_TIMES:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::times has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_times_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MINUS:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::minus has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_minus_result());
				break;
			}
			case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_READBOOLEAN:
			{	
				// OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextInputChannel::fb_readBoolean specifies Operation FoundationalModelLibrary::BasicInputOutput::TextInputChannel::readBoolean
				if(!context)
				{
					DEBUG_ERROR("Context for execution OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextInputChannel::fb_readBoolean is null!");
					return outputParameterValues;
				}
				result = context->invoke(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readBoolean_Status_Status(), inputArguments, outputArguments);

				//Create output ParameterValue for out parameter errorStatus
				std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> errorStatusParameterValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();
				errorStatusParameterValue->setParameter(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readBoolean_errorStatus());
				errorStatusParameterValue->getValues()->add(outputArguments->at(0));
				outputParameterValues->add(errorStatusParameterValue);
				returnParameterValue->setParameter(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readBoolean_ReturnResult());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MIN:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Min has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Min_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_GREATERTHAN:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::greaterThan has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_greaterThan_result());
				break;
			}
			case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITEBOOLEAN:
			{	
				// OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::fb_writeBoolean specifies Operation FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::writeBoolean
				if(!context)
				{
					DEBUG_ERROR("Context for execution OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::fb_writeBoolean is null!");
					return outputParameterValues;
				}
				result = context->invoke(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeBoolean_Boolean_Status_Boolean_Status(), inputArguments, outputArguments);

				//Create output ParameterValue for out parameter errorStatus
				std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> errorStatusParameterValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();
				errorStatusParameterValue->setParameter(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeBoolean_errorStatus());
				errorStatusParameterValue->getValues()->add(outputArguments->at(0));
				outputParameterValues->add(errorStatusParameterValue);
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_AND:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::And has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_And_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TOUNLIMITEDNATURAL:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::ToUnlimitedNatural has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_ToUnlimitedNatural_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_MINUS:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::minus has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_minus_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::UNLIMITEDNATURALFUNCTIONS_FUNCTIONBEHAVIOR_LESSTHAN:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::lessThan has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_lessThan_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_TOBOOLEAN:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::ToBoolean has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToBoolean_result());
				break;
			}
			case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITENEWLINE:
			{	
				// OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::fb_writeNewLine specifies Operation FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::writeNewLine
				if(!context)
				{
					DEBUG_ERROR("Context for execution OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::fb_writeNewLine is null!");
					return outputParameterValues;
				}
				result = context->invoke(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeNewLine_Status_Status(), inputArguments, outputArguments);

				//Create output ParameterValue for out parameter errorStatus
				std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> errorStatusParameterValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();
				errorStatusParameterValue->setParameter(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeNewLine_errorStatus());
				errorStatusParameterValue->getValues()->add(outputArguments->at(0));
				outputParameterValues->add(errorStatusParameterValue);
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_ABS:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Abs has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Abs_result());
				break;
			}
			case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_READCHARACTER:
			{	
				// OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextInputChannel::fb_readCharacter specifies Operation FoundationalModelLibrary::BasicInputOutput::TextInputChannel::readCharacter
				if(!context)
				{
					DEBUG_ERROR("Context for execution OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextInputChannel::fb_readCharacter is null!");
					return outputParameterValues;
				}
				result = context->invoke(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readCharacter_Status_Status(), inputArguments, outputArguments);

				//Create output ParameterValue for out parameter errorStatus
				std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> errorStatusParameterValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();
				errorStatusParameterValue->setParameter(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readCharacter_errorStatus());
				errorStatusParameterValue->getValues()->add(outputArguments->at(0));
				outputParameterValues->add(errorStatusParameterValue);
				returnParameterValue->setParameter(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readCharacter_ReturnResult());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_INV:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Inv has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Inv_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::UNLIMITEDNATURALFUNCTIONS_FUNCTIONBEHAVIOR_GREATEROREQUAL:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::greaterOrEqual has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_greaterOrEqual_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::ToString has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_ToString_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::StringFunctionsPackage::STRINGFUNCTIONS_FUNCTIONBEHAVIOR_SIZE:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::Size has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::StringFunctions::StringFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_StringFunctions_Size_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_FLOOR:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Floor has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Floor_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TIMES:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::times has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_times_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_IMPLIES:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Implies has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Implies_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_NEG:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Neg has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Neg_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::ToString has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_ToString_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_LESSOREQUAL:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::lessOrEqual has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_lessOrEqual_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_DIVIDE:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::divide has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_divide_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_MOD:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Mod has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Mod_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::UNLIMITEDNATURALFUNCTIONS_FUNCTIONBEHAVIOR_TOINTEGER:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::ToInteger has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToInteger_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_DIV:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Div has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Div_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_GREATERTHAN:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::greaterThan has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_greaterThan_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_NOT:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Not has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Not_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_MIN:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::Min has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_Min_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::UNLIMITEDNATURALFUNCTIONS_FUNCTIONBEHAVIOR_TOUNLIMITEDNATURAL:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::ToUnlimitedNatural has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToUnlimitedNatural_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_OR:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Or has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Or_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_LESSOREQUAL:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::lessOrEqual has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_lessOrEqual_result());
				break;
			}
			case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_PEEKCHARACTER:
			{	
				// OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextInputChannel::fb_peekCharacter specifies Operation FoundationalModelLibrary::BasicInputOutput::TextInputChannel::peekCharacter
				if(!context)
				{
					DEBUG_ERROR("Context for execution OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextInputChannel::fb_peekCharacter is null!");
					return outputParameterValues;
				}
				result = context->invoke(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_peekCharacter_Status_Status(), inputArguments, outputArguments);

				//Create output ParameterValue for out parameter errorStatus
				std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> errorStatusParameterValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();
				errorStatusParameterValue->setParameter(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_peekCharacter_errorStatus());
				errorStatusParameterValue->getValues()->add(outputArguments->at(0));
				outputParameterValues->add(errorStatusParameterValue);
				returnParameterValue->setParameter(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_peekCharacter_ReturnResult());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::REALFUNCTIONS_FUNCTIONBEHAVIOR_TOINTEGER:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::ToInteger has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::RealFunctions::RealFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_RealFunctions_ToInteger_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::UNLIMITEDNATURALFUNCTIONS_FUNCTIONBEHAVIOR_GREATERTHAN:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::greaterThan has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_greaterThan_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_TOINTEGER:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::ToInteger has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_ToInteger_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::UNLIMITEDNATURALFUNCTIONS_FUNCTIONBEHAVIOR_TOSTRING:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::ToString has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_ToString_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::BOOLEANFUNCTIONS_FUNCTIONBEHAVIOR_XOR:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::Xor has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::BooleanFunctions::BooleanFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_BooleanFunctions_Xor_result());
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::UNLIMITEDNATURALFUNCTIONS_FUNCTIONBEHAVIOR_MIN:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::Min has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::UnlimitedNaturalFunctions::UnlimitedNaturalFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_UnlimitedNaturalFunctions_Min_result());
				break;
			}
			case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITESTRING:
			{	
				// OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::fb_writeString specifies Operation FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::writeString
				if(!context)
				{
					DEBUG_ERROR("Context for execution OpaqueBehavior FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::fb_writeString is null!");
					return outputParameterValues;
				}
				result = context->invoke(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeString_String_Status_String_Status(), inputArguments, outputArguments);

				//Create output ParameterValue for out parameter errorStatus
				std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> errorStatusParameterValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();
				errorStatusParameterValue->setParameter(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeString_errorStatus());
				errorStatusParameterValue->getValues()->add(outputArguments->at(0));
				outputParameterValues->add(errorStatusParameterValue);
				break;
			}
			case FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::INTEGERFUNCTIONS_FUNCTIONBEHAVIOR_ABS:
			{	
				// OpaqueBehavior FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::Abs has no context
				// and is therefore realized as a global function
				result = FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::invoke(opaqueBehavior, inputArguments, outputArguments);
				returnParameterValue->setParameter(FoundationalModelLibrary::PrimitiveBehaviors::IntegerFunctions::IntegerFunctionsPackage::eInstance()->get_FoundationalModelLibrary_PrimitiveBehaviors_IntegerFunctions_Abs_result());
				break;
			}

		}
		if(result)
		{
			returnParameterValue->getValues()->add(result);
			outputParameterValues->add(returnParameterValue);
		}

		return outputParameterValues;
	}
	//Model-external OpaqueBehavior
	else
	{
		//No external opaque behaviors called in Activities of this model
	}

	return nullptr;
}

void FoundationalModelLibraryExecutorImpl::setThisExecutorPtr(std::weak_ptr</*PSCS::Semantics::Loci::CS_Executor*/fUML::Semantics::Loci::Executor> thisExecutorPtr)
{
	/*PSCS::Semantics::Loci::CS_ExecutorImpl::setThisExecutorPtr(thisExecutorPtr)*/ fUML::Semantics::Loci::ExecutorImpl::setThisExecutorPtr(thisExecutorPtr);
}
