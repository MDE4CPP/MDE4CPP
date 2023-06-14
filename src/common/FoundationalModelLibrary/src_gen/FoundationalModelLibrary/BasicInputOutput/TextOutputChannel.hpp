//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_BASICINPUTOUTPUT_TEXTOUTPUTCHANNEL__HPP
#define FOUNDATIONALMODELLIBRARY_BASICINPUTOUTPUT_TEXTOUTPUTCHANNEL__HPP




//Forward declarations for used types
namespace FoundationalModelLibrary::Common 
{
	struct Status;
}

// base class includes
#include "FoundationalModelLibrary/BasicInputOutput/OutputChannel.hpp"



namespace FoundationalModelLibrary::BasicInputOutput
{
	class TextOutputChannel:virtual public OutputChannel	{
		protected:
			TextOutputChannel(){}

		public:
			//destructor
			virtual ~TextOutputChannel() {}

			//*********************************
			// Getter Setter
			//*********************************
			
			
			
			//*********************************
			// Operations
			//*********************************
			//Methods defined by Operations
			virtual void writeBoolean(bool value, std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus)  = 0;
			virtual void writeInteger(int value, std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus)  = 0;
			virtual void writeLine(std::string value, std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus)  = 0;
			virtual void writeNewLine(std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus)  = 0;
			virtual void writeReal(double value, std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus)  = 0;
			virtual void writeString(std::string value, std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus)  = 0;
			virtual void writeUnlimitedNatural(int value, std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus)  = 0;


		protected:
			//*********************************
			// Members
			//*********************************
			
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			
	};
}
#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_BASICINPUTOUTPUT_TEXTOUTPUTCHANNEL__HPP */
