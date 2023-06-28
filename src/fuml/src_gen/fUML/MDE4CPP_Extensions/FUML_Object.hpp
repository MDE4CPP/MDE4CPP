//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_MDE4CPP_EXTENSIONS_FUML_OBJECT_HPP
#define FUML_MDE4CPP_EXTENSIONS_FUML_OBJECT_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 


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
namespace fUML::Semantics::CommonBehavior 
{
	class EventAccepter;
	class EventOccurrence;
	class ObjectActivation;
	class ParameterValue;
}
namespace fUML::Semantics::Loci 
{
	class Locus;
}
namespace ecore 
{
	class EAnnotation;
}
namespace uml 
{
	class Class;
	class Classifier;
	class Comment;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "uml/Element.hpp"




//*********************************
namespace fUML::MDE4CPP_Extensions 
{
	
	class FUML_API FUML_Object : virtual public uml::Element
	{
		public:
 			FUML_Object(const FUML_Object &) {}

		protected:
			FUML_Object(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~FUML_Object() {}

			//*********************************
			// Operations
			//*********************************
			virtual void _register(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter>& accepter) = 0;
			virtual void destroy() = 0;
			virtual const std::shared_ptr<Bag<uml::Classifier>>& getTypes() const = 0;
			virtual void send(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence) = 0;
			virtual void startBehavior(const std::shared_ptr<uml::Class>& classifier, const std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>& inputs) = 0;
			virtual void unregister(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter>& accepter) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<fUML::Semantics::Loci::Locus>& getLocus() const = 0;
			virtual void setLocus(const std::shared_ptr<fUML::Semantics::Loci::Locus>&) = 0;
			virtual const std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation>& getObjectActivation() const = 0;
			virtual void setObjectActivation(const std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation>&) = 0;

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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			std::shared_ptr<fUML::Semantics::Loci::Locus> m_locus;
			std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> m_objectActivation;
	};
}
#endif /* end of include guard: FUML_MDE4CPP_EXTENSIONS_FUML_OBJECT_HPP */
