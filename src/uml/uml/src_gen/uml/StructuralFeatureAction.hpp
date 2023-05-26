//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STRUCTURALFEATUREACTION_HPP
#define UML_STRUCTURALFEATUREACTION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;


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

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class Activity;
	class ActivityEdge;
	class ActivityGroup;
	class ActivityPartition;
	class Classifier;
	class Comment;
	class Constraint;
	class Dependency;
	class ExceptionHandler;
	class InputPin;
	class InterruptibleActivityRegion;
	class Namespace;
	class OutputPin;
	class StringExpression;
	class StructuralFeature;
	class StructuredActivityNode;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Action.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	StructuralFeatureAction is an abstract class for all Actions that operate on StructuralFeatures.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API StructuralFeatureAction : virtual public Action
	{
		public:
 			StructuralFeatureAction(const StructuralFeatureAction &) {}

		protected:
			StructuralFeatureAction(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~StructuralFeatureAction() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The InputPin from which the object whose StructuralFeature is to be read or written is obtained.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::InputPin>& getObject() const = 0;
			/*!
			The InputPin from which the object whose StructuralFeature is to be read or written is obtained.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setObject(const std::shared_ptr<uml::InputPin>&) = 0;
			/*!
			The StructuralFeature to be read or written.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::StructuralFeature>& getStructuralFeature() const = 0;
			/*!
			The StructuralFeature to be read or written.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setStructuralFeature(const std::shared_ptr<uml::StructuralFeature>&) = 0;

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
			/*!
			The InputPin from which the object whose StructuralFeature is to be read or written is obtained.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::InputPin> m_object;
			/*!
			The StructuralFeature to be read or written.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::StructuralFeature> m_structuralFeature;
	};
}
#endif /* end of include guard: UML_STRUCTURALFEATUREACTION_HPP */
