//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef NEWMODEL_PRIMECHECKER_FBPRINTISPRIME_EXECUTION_HPP
#define NEWMODEL_PRIMECHECKER_FBPRINTISPRIME_EXECUTION_HPP

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif
#include <iostream>

#include "impl/OpaqueBehaviorExecutionImpl.hpp"

//Included from function behavior "fbPrintIsPrime"
#include <iostream>

namespace NewModel 
{
	class FbPrintIsPrimeExecution : public fUML::OpaqueBehaviorExecutionImpl 
	{
		public:
		    //constructor
		    FbPrintIsPrimeExecution(const FbPrintIsPrimeExecution &obj);
		    FbPrintIsPrimeExecution();
		    //destructor
		    virtual ~FbPrintIsPrimeExecution();
		
		    virtual void doBody(std::vector<fUML::ParameterValue * > *  inputParameters,std::vector<fUML::ParameterValue * > *  outputParameters);
		    virtual ecore::EObject * copy() const;
	};
}
#endif /* end of include guard: NEWMODEL_PRIMECHECKER_FBPRINTISPRIME_EXECUTION_HPP */
