//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_MDE4CPP_EXTENSIONS_FUML_SIGNALINSTANCE_HPP
#define FUML_MDE4CPP_EXTENSIONS_FUML_SIGNALINSTANCE_HPP


#include <memory>
#include <string>
// forward declarations


//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
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
namespace ecore 
{
	class EAnnotation;
}
namespace uml 
{
	class Comment;
	class Signal;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "uml/Element.hpp"




//*********************************
namespace fUML::MDE4CPP_Extensions 
{
	
	class FUML_API FUML_SignalInstance : virtual public uml::Element
	{
		public:
 			FUML_SignalInstance(const FUML_SignalInstance &) {}

		protected:
			FUML_SignalInstance(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~FUML_SignalInstance() {}

			//*********************************
			// Operations
			//*********************************
			virtual const std::shared_ptr<uml::Signal>& getType() const = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
	};
}
#endif /* end of include guard: FUML_MDE4CPP_EXTENSIONS_FUML_SIGNALINSTANCE_HPP */