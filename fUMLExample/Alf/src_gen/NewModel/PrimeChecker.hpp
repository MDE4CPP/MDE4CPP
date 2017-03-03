//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef NEWMODEL_PRIMECHECKER__HPP
#define NEWMODEL_PRIMECHECKER__HPP

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif
#include <iostream>

#include <boost/any.hpp>
#include <string>
#include <map>
#include <vector>

//Forward Declaration for used types


// base class includes

#include "Class.hpp"

// enum includes





//Included from operation "printIsPrime"
#include <iostream>

//Included from operation "printNotPrime"
#include <iostream>

//*********************************

namespace NewModel
{
	class PrimeChecker : virtual public uml::Class 
	{
		private:    
			PrimeChecker(const PrimeChecker& that) = delete;

		protected:
			PrimeChecker(){}

		public:
			//destructor
			virtual ~PrimeChecker() {}

			//*********************************
			// Getter Setter
			//*********************************
			virtual int getDivider() const = 0;
			virtual void setDivider (int _divider)= 0; 
			virtual int getNumber() const = 0;
			virtual void setNumber (int _number)= 0; 
			
			
			//*********************************
			// Operations
			//*********************************
			virtual bool divides(  ) = 0;
			virtual bool isNotFinished(  ) = 0;
			virtual bool isOdd(  ) = 0;
			virtual void next(  ) = 0;
			virtual void printIsPrime(  ) = 0;
			virtual void printNotPrime(  ) = 0;
			
			
		protected:
			//*********************************
			// Members
			//*********************************
			int m_divider =  3 /*defined default value*/ ;
			int m_number =  8191 /*defined default value*/ ;
			
	
	};
}
#endif /* end of include guard: NEWMODEL_PRIMECHECKER__HPP */
