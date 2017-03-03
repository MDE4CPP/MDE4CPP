//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef NEWMODEL_PRIMECHECKER_EXECUTION_HPP
#define NEWMODEL_PRIMECHECKER_EXECUTION_HPP

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif
#include <iostream>

#include "fUML/impl/ObjectImpl.hpp"
#include "PrimeChecker.hpp"

namespace NewModel 
{
	class PrimeCheckerExecution : public fUML::ObjectImpl 
	{
		public:
		    //constructors
		    PrimeCheckerExecution(PrimeCheckerExecution &obj);
		    PrimeCheckerExecution(PrimeChecker*);
		 	PrimeCheckerExecution();
		    //destructor
		    virtual ~PrimeCheckerExecution();
		
		    virtual ecore::EObject* copy();
			
			PrimeChecker* getUmlValue() const;
			void setUmlValue(PrimeChecker*);
		
		protected:
			PrimeChecker* m_umlValue = nullptr;
	};
}
#endif /* end of include guard: NEWMODEL_PRIMECHECKER_EXECUTION_HPP */
