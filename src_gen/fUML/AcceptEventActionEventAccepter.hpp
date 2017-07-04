//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_ACCEPTEVENTACTIONEVENTACCEPTER_HPP
#define FUML_ACCEPTEVENTACTIONEVENTACCEPTER_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#include <string>
#include <map>
#include <vector>
#include "SubsetUnion.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/any.hpp"

//*********************************
// generated Includes

//Forward Declaration for used types
namespace fUML 
{
	class AcceptEventActionActivation;
}

namespace fUML 
{
	class EventAccepter;
}

// base class includes
#include "EventAccepter.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class AcceptEventActionEventAccepter:virtual public EventAccepter	{
		public:
 			AcceptEventActionEventAccepter(const AcceptEventActionEventAccepter &) {}
			AcceptEventActionEventAccepter& operator=(AcceptEventActionEventAccepter const&) = delete;
	
		protected:
			AcceptEventActionEventAccepter(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~AcceptEventActionEventAccepter() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<fUML::AcceptEventActionActivation > getActionActivation() const = 0;
			
			/*!
			 */
			virtual void setActionActivation(std::shared_ptr<fUML::AcceptEventActionActivation> _actionActivation_actionActivation) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<fUML::AcceptEventActionActivation > m_actionActivation;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			 
	};

}
#endif /* end of include guard: FUML_ACCEPTEVENTACTIONEVENTACCEPTER_HPP */
