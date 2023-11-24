//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_BASICINPUTOUTPUT_METAMODELPACKAGE_HPP
#define FOUNDATIONALMODELLIBRARY_BASICINPUTOUTPUT_METAMODELPACKAGE_HPP
#include "uml/Package.hpp"

namespace uml 
{
	class Activity;
	class ActivityParameterNode;
	class CallOperationAction;
	class Class;
	class CreateObjectAction;
	class FunctionBehavior;
	class InputPin;
	class ObjectFlow;
	class Operation;
	class OutputPin;
	class Parameter;
	class ConnectorEnd;
}


namespace FoundationalModelLibrary::BasicInputOutput 
{
	/*!
	The Metamodel Package for the BasicInputOutput metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	class BasicInputOutputPackage : virtual public uml::Package
	{
		//protected default construcotr
		protected:
			BasicInputOutputPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			//getter for the ownedMember
			virtual const std::shared_ptr<uml::Class>& get_FoundationalModelLibrary_BasicInputOutput_ActiveChannel() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_FoundationalModelLibrary_BasicInputOutput_Channel() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_FoundationalModelLibrary_BasicInputOutput_InputChannel() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_FoundationalModelLibrary_BasicInputOutput_OutputChannel() = 0;  
			virtual const std::shared_ptr<uml::Activity>& get_FoundationalModelLibrary_BasicInputOutput_ReadLine() = 0;  
			virtual const std::shared_ptr<uml::ActivityParameterNode>& get_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::ActivityParameterNode>& get_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_result() = 0;  
			virtual const std::shared_ptr<uml::CallOperationAction>& get_FoundationalModelLibrary_BasicInputOutput_ReadLine_CallOperationAction_Call_readLine() = 0;  
			virtual const std::shared_ptr<uml::CreateObjectAction>& get_FoundationalModelLibrary_BasicInputOutput_ReadLine_CreateObjectAction_Create_StandardInputChannel() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_ReadLine_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_ReadLine_result() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_FoundationalModelLibrary_BasicInputOutput_StandardInputChannel() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_FoundationalModelLibrary_BasicInputOutput_StandardOutputChannel() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_peekCharacter() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_peekCharacter_ReturnResult() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_peekCharacter_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readBoolean() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readBoolean_ReturnResult() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readBoolean_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readCharacter() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readCharacter_ReturnResult() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readCharacter_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readInteger() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readInteger_ReturnResult() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readInteger_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readLine() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readLine_ReturnResult() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_fb_readLine_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_peekCharacter_ReturnResult() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_peekCharacter_Status_Status() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_peekCharacter_Status_Status_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readBoolean_ReturnResult() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readBoolean_Status_Status() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readBoolean_Status_Status_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readCharacter_ReturnResult() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readCharacter_Status_Status() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readCharacter_Status_Status_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readInteger_ReturnResult() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readInteger_Status_Status() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readInteger_Status_Status_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readLine_ReturnResult() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readLine_Status_Status() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readLine_Status_Status_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readReal_ReturnResult() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readReal_Status_Status() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readReal_Status_Status_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readUnlimitedNatural_ReturnResult() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readUnlimitedNatural_Status_Status() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel_readUnlimitedNatural_Status_Status_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Class>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeBoolean() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeBoolean_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeBoolean_value() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeInteger() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeInteger_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeInteger_value() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeLine() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeLine_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeLine_value() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeNewLine() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeNewLine_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::FunctionBehavior>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeString() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeString_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_fb_writeString_value() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeBoolean_Boolean_Status_Boolean_Status() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeBoolean_Boolean_Status_Boolean_Status_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeBoolean_Boolean_Status_Boolean_Status_value() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeInteger_Integer_Status_Integer_Status() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeInteger_Integer_Status_Integer_Status_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeInteger_Integer_Status_Integer_Status_value() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeLine_String_Status_String_Status() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeLine_String_Status_String_Status_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeLine_String_Status_String_Status_value() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeNewLine_Status_Status() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeNewLine_Status_Status_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeReal_Real_Status_Real_Status() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeReal_Real_Status_Real_Status_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeReal_Real_Status_Real_Status_value() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeString_String_Status_String_Status() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeString_String_Status_String_Status_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeString_String_Status_String_Status_value() = 0;  
			virtual const std::shared_ptr<uml::Operation>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeUnlimitedNatural_UnlimitedNatural_Status_UnlimitedNatural_Status() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeUnlimitedNatural_UnlimitedNatural_Status_UnlimitedNatural_Status_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel_writeUnlimitedNatural_UnlimitedNatural_Status_UnlimitedNatural_Status_value() = 0;  
			virtual const std::shared_ptr<uml::Activity>& get_FoundationalModelLibrary_BasicInputOutput_WriteLine() = 0;  
			virtual const std::shared_ptr<uml::ActivityParameterNode>& get_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::ActivityParameterNode>& get_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_value() = 0;  
			virtual const std::shared_ptr<uml::CallOperationAction>& get_FoundationalModelLibrary_BasicInputOutput_WriteLine_CallOperationAction_Call_writeLine() = 0;  
			virtual const std::shared_ptr<uml::CreateObjectAction>& get_FoundationalModelLibrary_BasicInputOutput_WriteLine_CreateObjectAction_Create_StandardOutputChannel() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_WriteLine_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::Parameter>& get_FoundationalModelLibrary_BasicInputOutput_WriteLine_value() = 0;  
			virtual const std::shared_ptr<uml::InputPin>& get_InputPin_ReadLine_ReadLine_Call_readLine_target() = 0;  
			virtual const std::shared_ptr<uml::InputPin>& get_InputPin_WriteLine_WriteLine_Call_writeLine_target() = 0;  
			virtual const std::shared_ptr<uml::InputPin>& get_InputPin_WriteLine_WriteLine_Call_writeLine_value() = 0;  
			virtual const std::shared_ptr<uml::ObjectFlow>& get_OF_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_value_InputPin_WriteLine_WriteLine_Call_writeLine_value() = 0;  
			virtual const std::shared_ptr<uml::ObjectFlow>& get_OF_OutputPin_ReadLine_ReadLine_Call_readLine_ReturnResult_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_result() = 0;  
			virtual const std::shared_ptr<uml::ObjectFlow>& get_OF_OutputPin_ReadLine_ReadLine_Call_readLine_errorStatus_FoundationalModelLibrary_BasicInputOutput_ReadLine_ActivityParameterNode_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::ObjectFlow>& get_OF_OutputPin_ReadLine_ReadLine_Create_StandardInputChannel_result_InputPin_ReadLine_ReadLine_Call_readLine_target() = 0;  
			virtual const std::shared_ptr<uml::ObjectFlow>& get_OF_OutputPin_WriteLine_WriteLine_Call_writeLine_errorStatus_FoundationalModelLibrary_BasicInputOutput_WriteLine_ActivityParameterNode_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::ObjectFlow>& get_OF_OutputPin_WriteLine_WriteLine_Create_StandardOutputChannel_result_InputPin_WriteLine_WriteLine_Call_writeLine_target() = 0;  
			virtual const std::shared_ptr<uml::OutputPin>& get_OutputPin_ReadLine_ReadLine_Call_readLine_ReturnResult() = 0;  
			virtual const std::shared_ptr<uml::OutputPin>& get_OutputPin_ReadLine_ReadLine_Call_readLine_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::OutputPin>& get_OutputPin_ReadLine_ReadLine_Create_StandardInputChannel_result() = 0;  
			virtual const std::shared_ptr<uml::OutputPin>& get_OutputPin_WriteLine_WriteLine_Call_writeLine_errorStatus() = 0;  
			virtual const std::shared_ptr<uml::OutputPin>& get_OutputPin_WriteLine_WriteLine_Create_StandardOutputChannel_result() = 0;  
			
			

			//getter for subPackages

			//Singleton Getter
			public:
				static std::shared_ptr<BasicInputOutputPackage> eInstance();

			//Static IDs
			//Class FoundationalModelLibrary::BasicInputOutput::ActiveChannel
			static const unsigned long ACTIVECHANNEL_CLASS = 1621752002;
			static const unsigned int ACTIVECHANNEL_CLASS_FEATURE_COUNT = 0;
			static const unsigned int ACTIVECHANNEL_CLASS_OPERATION_COUNT = 0;
			
			//Class FoundationalModelLibrary::BasicInputOutput::Channel
			static const unsigned long CHANNEL_CLASS = 1684916723;
			static const unsigned int CHANNEL_CLASS_FEATURE_COUNT = 0;
			static const unsigned int CHANNEL_CLASS_OPERATION_COUNT = 0;
			
			//Class FoundationalModelLibrary::BasicInputOutput::InputChannel
			static const unsigned long INPUTCHANNEL_CLASS = 168647615;
			static const unsigned int INPUTCHANNEL_CLASS_FEATURE_COUNT = 0;
			static const unsigned int INPUTCHANNEL_CLASS_OPERATION_COUNT = 0;
			
			//Class FoundationalModelLibrary::BasicInputOutput::OutputChannel
			static const unsigned long OUTPUTCHANNEL_CLASS = 1279071845;
			static const unsigned int OUTPUTCHANNEL_CLASS_FEATURE_COUNT = 0;
			static const unsigned int OUTPUTCHANNEL_CLASS_OPERATION_COUNT = 0;
			
			//Activity FoundationalModelLibrary::BasicInputOutput::ReadLine
			static const unsigned long BASICINPUTOUTPUT_ACTIVITY_READLINE = 1724471588;
			static const unsigned int BASICINPUTOUTPUT_ACTIVITY_READLINE_FEATURE_COUNT = 0;
			static const unsigned int BASICINPUTOUTPUT_ACTIVITY_READLINE_OPERATION_COUNT = 0;
			
			//Class FoundationalModelLibrary::BasicInputOutput::StandardInputChannel
			static const unsigned long STANDARDINPUTCHANNEL_CLASS = 2142636726;
			static const unsigned int STANDARDINPUTCHANNEL_CLASS_FEATURE_COUNT = 7;
			static const unsigned int STANDARDINPUTCHANNEL_CLASS_OPERATION_COUNT = 0;
			
			//Class FoundationalModelLibrary::BasicInputOutput::StandardOutputChannel
			static const unsigned long STANDARDOUTPUTCHANNEL_CLASS = 1910803935;
			static const unsigned int STANDARDOUTPUTCHANNEL_CLASS_FEATURE_COUNT = 7;
			static const unsigned int STANDARDOUTPUTCHANNEL_CLASS_OPERATION_COUNT = 0;
			
			//Class FoundationalModelLibrary::BasicInputOutput::TextInputChannel
			static const unsigned long TEXTINPUTCHANNEL_CLASS = 1717586034;
			static const unsigned int TEXTINPUTCHANNEL_CLASS_FEATURE_COUNT = 7;
			static const unsigned int TEXTINPUTCHANNEL_CLASS_OPERATION_COUNT = 7;
			//Operations
			//FoundationalModelLibrary::BasicInputOutput::TextInputChannel::readCharacter(FoundationalModelLibrary::Common::Status) : std::string
			static const unsigned long TEXTINPUTCHANNEL_OPERATION_READCHARACTER_STATUS = 1099812462;
			//FoundationalModelLibrary::BasicInputOutput::TextInputChannel::peekCharacter(FoundationalModelLibrary::Common::Status) : std::string
			static const unsigned long TEXTINPUTCHANNEL_OPERATION_PEEKCHARACTER_STATUS = 1550449558;
			//FoundationalModelLibrary::BasicInputOutput::TextInputChannel::readLine(FoundationalModelLibrary::Common::Status) : std::string
			static const unsigned long TEXTINPUTCHANNEL_OPERATION_READLINE_STATUS = 1985262614;
			//FoundationalModelLibrary::BasicInputOutput::TextInputChannel::readInteger(FoundationalModelLibrary::Common::Status) : int
			static const unsigned long TEXTINPUTCHANNEL_OPERATION_READINTEGER_STATUS = 1439866649;
			//FoundationalModelLibrary::BasicInputOutput::TextInputChannel::readReal(FoundationalModelLibrary::Common::Status) : double
			static const unsigned long TEXTINPUTCHANNEL_OPERATION_READREAL_STATUS = 1711745831;
			//FoundationalModelLibrary::BasicInputOutput::TextInputChannel::readBoolean(FoundationalModelLibrary::Common::Status) : bool
			static const unsigned long TEXTINPUTCHANNEL_OPERATION_READBOOLEAN_STATUS = 193879233;
			//FoundationalModelLibrary::BasicInputOutput::TextInputChannel::readUnlimitedNatural(FoundationalModelLibrary::Common::Status) : int
			static const unsigned long TEXTINPUTCHANNEL_OPERATION_READUNLIMITEDNATURAL_STATUS = 604257804;
			//Behaviors
				//FunctionBehavior FoundationalModelLibrary::BasicInputOutput::TextInputChannel::fb_peekCharacter
			static const unsigned long TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_PEEKCHARACTER = 548795195;
			static const unsigned int TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_PEEKCHARACTER_FEATURE_COUNT = 0;
			static const unsigned int TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_PEEKCHARACTER_OPERATION_COUNT = 0;
			
				//FunctionBehavior FoundationalModelLibrary::BasicInputOutput::TextInputChannel::fb_readInteger
				static const unsigned long TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_READINTEGER = 446400749;
				static const unsigned int TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_READINTEGER_FEATURE_COUNT = 0;
				static const unsigned int TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_READINTEGER_OPERATION_COUNT = 0;
				
				//FunctionBehavior FoundationalModelLibrary::BasicInputOutput::TextInputChannel::fb_readBoolean
				static const unsigned long TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_READBOOLEAN = 818339417;
				static const unsigned int TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_READBOOLEAN_FEATURE_COUNT = 0;
				static const unsigned int TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_READBOOLEAN_OPERATION_COUNT = 0;
				
				//FunctionBehavior FoundationalModelLibrary::BasicInputOutput::TextInputChannel::fb_readCharacter
				static const unsigned long TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_READCHARACTER = 586469930;
				static const unsigned int TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_READCHARACTER_FEATURE_COUNT = 0;
				static const unsigned int TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_READCHARACTER_OPERATION_COUNT = 0;
				
				//FunctionBehavior FoundationalModelLibrary::BasicInputOutput::TextInputChannel::fb_readLine
				static const unsigned long TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_READLINE = 1471477029;
				static const unsigned int TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_READLINE_FEATURE_COUNT = 0;
				static const unsigned int TEXTINPUTCHANNEL_FUNCTIONBEHAVIOR_FB_READLINE_OPERATION_COUNT = 0;
				
			
			//Class FoundationalModelLibrary::BasicInputOutput::TextOutputChannel
			static const unsigned long TEXTOUTPUTCHANNEL_CLASS = 334456783;
			static const unsigned int TEXTOUTPUTCHANNEL_CLASS_FEATURE_COUNT = 7;
			static const unsigned int TEXTOUTPUTCHANNEL_CLASS_OPERATION_COUNT = 7;
			//Operations
			//FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::writeString(std::string, FoundationalModelLibrary::Common::Status)
			static const unsigned long TEXTOUTPUTCHANNEL_OPERATION_WRITESTRING_STRING_STATUS = 1155891658;
			//FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::writeNewLine(FoundationalModelLibrary::Common::Status)
			static const unsigned long TEXTOUTPUTCHANNEL_OPERATION_WRITENEWLINE_STATUS = 1131443760;
			//FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::writeLine(std::string, FoundationalModelLibrary::Common::Status)
			static const unsigned long TEXTOUTPUTCHANNEL_OPERATION_WRITELINE_STRING_STATUS = 343706050;
			//FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::writeInteger(int, FoundationalModelLibrary::Common::Status)
			static const unsigned long TEXTOUTPUTCHANNEL_OPERATION_WRITEINTEGER_INTEGER_STATUS = 1994749676;
			//FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::writeReal(double, FoundationalModelLibrary::Common::Status)
			static const unsigned long TEXTOUTPUTCHANNEL_OPERATION_WRITEREAL_REAL_STATUS = 1016349165;
			//FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::writeBoolean(bool, FoundationalModelLibrary::Common::Status)
			static const unsigned long TEXTOUTPUTCHANNEL_OPERATION_WRITEBOOLEAN_BOOLEAN_STATUS = 1253248740;
			//FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::writeUnlimitedNatural(int, FoundationalModelLibrary::Common::Status)
			static const unsigned long TEXTOUTPUTCHANNEL_OPERATION_WRITEUNLIMITEDNATURAL_UNLIMITEDNATURAL_STATUS = 1732555673;
			//Behaviors
				//FunctionBehavior FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::fb_writeNewLine
			static const unsigned long TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITENEWLINE = 1078171085;
			static const unsigned int TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITENEWLINE_FEATURE_COUNT = 0;
			static const unsigned int TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITENEWLINE_OPERATION_COUNT = 0;
			
				//FunctionBehavior FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::fb_writeInteger
				static const unsigned long TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITEINTEGER = 1102967664;
				static const unsigned int TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITEINTEGER_FEATURE_COUNT = 0;
				static const unsigned int TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITEINTEGER_OPERATION_COUNT = 0;
				
				//FunctionBehavior FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::fb_writeBoolean
				static const unsigned long TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITEBOOLEAN = 54149987;
				static const unsigned int TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITEBOOLEAN_FEATURE_COUNT = 0;
				static const unsigned int TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITEBOOLEAN_OPERATION_COUNT = 0;
				
				//FunctionBehavior FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::fb_writeString
				static const unsigned long TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITESTRING = 512413595;
				static const unsigned int TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITESTRING_FEATURE_COUNT = 0;
				static const unsigned int TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITESTRING_OPERATION_COUNT = 0;
				
				//FunctionBehavior FoundationalModelLibrary::BasicInputOutput::TextOutputChannel::fb_writeLine
				static const unsigned long TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITELINE = 766667557;
				static const unsigned int TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITELINE_FEATURE_COUNT = 0;
				static const unsigned int TEXTOUTPUTCHANNEL_FUNCTIONBEHAVIOR_FB_WRITELINE_OPERATION_COUNT = 0;
				
			
			//Activity FoundationalModelLibrary::BasicInputOutput::WriteLine
			static const unsigned long BASICINPUTOUTPUT_ACTIVITY_WRITELINE = 1760325101;
			static const unsigned int BASICINPUTOUTPUT_ACTIVITY_WRITELINE_FEATURE_COUNT = 0;
			static const unsigned int BASICINPUTOUTPUT_ACTIVITY_WRITELINE_OPERATION_COUNT = 0;
			
			
			
	};
}
#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_BASICINPUTOUTPUT_METAMODELPACKAGE_HPP */
