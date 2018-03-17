//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_WRITESTRUCTURALFEATUREACTIONACTIVATION_HPP
#define FUML_WRITESTRUCTURALFEATUREACTIONACTIVATION_HPP

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
	class FUMLFactory;
}

//Forward Declaration for used types
namespace fUML 
{
	class ActivityEdgeInstance;
}

namespace uml 
{
	class ActivityNode;
}

namespace fUML 
{
	class ActivityNodeActivationGroup;
}

namespace fUML 
{
	class InputPinActivation;
}

namespace fUML 
{
	class OutputPinActivation;
}

namespace fUML 
{
	class PinActivation;
}

namespace fUML 
{
	class StructuralFeatureActionActivation;
}

namespace fUML 
{
	class Token;
}

namespace fUML 
{
	class Value;
}

// base class includes
#include "fUML/StructuralFeatureActionActivation.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class WriteStructuralFeatureActionActivation:virtual public StructuralFeatureActionActivation
	{
		public:
 			WriteStructuralFeatureActionActivation(const WriteStructuralFeatureActionActivation &) {}
			WriteStructuralFeatureActionActivation& operator=(WriteStructuralFeatureActionActivation const&) = delete;

		protected:
			WriteStructuralFeatureActionActivation(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~WriteStructuralFeatureActionActivation() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual int position(std::shared_ptr<fUML::Value>  value,std::shared_ptr<Bag<fUML::Value> >  list,int startAt)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<Union<fUML::PinActivation>> getPinActivation() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_WRITESTRUCTURALFEATUREACTIONACTIVATION_HPP */
