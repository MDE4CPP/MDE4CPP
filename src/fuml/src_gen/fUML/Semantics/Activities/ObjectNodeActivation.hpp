//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_OBJECTNODEACTIVATION_HPP
#define FUML_SEMANTICS_ACTIVITIES_OBJECTNODEACTIVATION_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T> class Bag; 



//*********************************
// generated Includes

#include <map>

namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace fUML
{
	class fUMLFactory;
}

//Forward Declaration for used types
namespace fUML::Semantics::Activities 
{
	class ActivityEdgeInstance;
}

namespace uml 
{
	class ActivityNode;
}

namespace fUML::Semantics::Activities 
{
	class ActivityNodeActivation;
}

namespace fUML::Semantics::Activities 
{
	class ActivityNodeActivationGroup;
}

namespace fUML::Semantics::Activities 
{
	class Token;
}

// base class includes
#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"

// enum includes


//*********************************
namespace fUML::Semantics::Activities 
{
	
	class ObjectNodeActivation:virtual public ActivityNodeActivation
	{
		public:
 			ObjectNodeActivation(const ObjectNodeActivation &) {}
			ObjectNodeActivation& operator=(ObjectNodeActivation const&) = delete;

		protected:
			ObjectNodeActivation(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ObjectNodeActivation() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual void addToken(std::shared_ptr<fUML::Semantics::Activities::Token>  token) = 0;
			
			 
			virtual void clearTokens() = 0;
			
			 
			virtual int countOfferedValues() = 0;
			
			 
			virtual int countUnofferedTokens() = 0;
			
			 
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > getUnofferedTokens() = 0;
			
			 
			virtual int removeToken(std::shared_ptr<fUML::Semantics::Activities::Token>  token) = 0;
			
			 
			virtual void run() = 0;
			
			 
			virtual void sendOffers(std::shared_ptr<Bag<fUML::Semantics::Activities::Token> >  tokens) = 0;
			
			 
			virtual void sendUnofferedTokens() = 0;
			
			 
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > takeUnofferedTokens() = 0;
			
			 
			virtual void terminate() = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			 
			virtual int getOfferedTokenCount() const = 0;
			
			 
			virtual void setOfferedTokenCount (int _offeredTokenCount)= 0; 
			
			//*********************************
			// Reference
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			 
			int m_offeredTokenCount = 0;
			
			
			//*********************************
			// Reference Members
			//*********************************
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_OBJECTNODEACTIVATION_HPP */
