//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STARTCLASSIFIERBEHAVIORACTION_HPP
#define UML_STARTCLASSIFIERBEHAVIORACTION_HPP


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
	A StartClassifierBehaviorAction is an Action that starts the classifierBehavior of the input object.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API StartClassifierBehaviorAction : virtual public Action
	{
		public:
 			StartClassifierBehaviorAction(const StartClassifierBehaviorAction &) {}

		protected:
			StartClassifierBehaviorAction(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~StartClassifierBehaviorAction() {}

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
			The InputPin that holds the object whose classifierBehavior is to be started.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::InputPin>& getObject() const = 0;
			/*!
			The InputPin that holds the object whose classifierBehavior is to be started.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setObject(const std::shared_ptr<uml::InputPin>&) = 0;

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
			/*!
			The InputPin that holds the object whose classifierBehavior is to be started.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::InputPin> m_object;
	};
}
#endif /* end of include guard: UML_STARTCLASSIFIERBEHAVIORACTION_HPP */
