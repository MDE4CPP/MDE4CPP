//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_VALUEPIN_HPP
#define UML_VALUEPIN_HPP


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
	class Action;
	class Activity;
	class ActivityEdge;
	class ActivityGroup;
	class ActivityPartition;
	class AddStructuralFeatureValueAction;
	class Behavior;
	class CallOperationAction;
	class Classifier;
	class Comment;
	class Dependency;
	class DestroyObjectAction;
	class InterruptibleActivityRegion;
	class InvocationAction;
	class Namespace;
	class RemoveStructuralFeatureValueAction;
	class State;
	class StringExpression;
	class StructuralFeatureAction;
	class StructuredActivityNode;
	class Type;
	class ValueSpecification;
	class WriteStructuralFeatureAction;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/InputPin.hpp"

// enum includes
#include "uml/ObjectNodeOrderingKind.hpp"
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A ValuePin is an InputPin that provides a value by evaluating a ValueSpecification.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API ValuePin : virtual public InputPin
	{
		public:
 			ValuePin(const ValuePin &) {}

		protected:
			ValuePin(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ValuePin() {}

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
			The ValueSpecification that is evaluated to obtain the value that the ValuePin will provide.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::ValueSpecification>& getValue() const = 0;
			/*!
			The ValueSpecification that is evaluated to obtain the value that the ValuePin will provide.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setValue(const std::shared_ptr<uml::ValueSpecification>&) = 0;

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
			The ValueSpecification that is evaluated to obtain the value that the ValuePin will provide.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::ValueSpecification> m_value;
	};
}
#endif /* end of include guard: UML_VALUEPIN_HPP */
