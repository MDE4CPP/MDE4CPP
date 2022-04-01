//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_DURATIONOBSERVATION_HPP
#define UML_DURATIONOBSERVATION_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 

class Any;

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
	class Comment;
	class Dependency;
	class Namespace;
	class Package;
	class StringExpression;
	class TemplateParameter;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Observation.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A DurationObservation is a reference to a duration during an execution. It points out the NamedElement(s) in the model to observe and whether the observations are when this NamedElement is entered or when it is exited.
	<p>From package UML::Values.</p>
	*/
	
	class UML_API DurationObservation: virtual public Observation
	{
		public:
 			DurationObservation(const DurationObservation &) {}

		protected:
			DurationObservation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~DurationObservation() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The multiplicity of firstEvent must be 2 if the multiplicity of event is 2. Otherwise the multiplicity of firstEvent is 0.
			if (event->size() = 2)
			  then (firstEvent->size() = 2) else (firstEvent->size() = 0)
			endif
			*/
			 
			virtual bool first_event_multiplicity(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < std::shared_ptr<Any>, std::shared_ptr<Any>>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			The value of firstEvent[i] is related to event[i] (where i is 1 or 2). If firstEvent[i] is true, then the corresponding observation event is the first time instant the execution enters event[i]. If firstEvent[i] is false, then the corresponding observation event is the time instant the execution exits event[i].
			<p>From package UML::Values.</p>
			*/
			 
			virtual std::shared_ptr<Bag<bool>> isFirstEvent() const = 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The DurationObservation is determined as the duration between the entering or exiting of a single event Element during execution, or the entering/exiting of one event Element and the entering/exiting of a second.
			<p>From package UML::Values.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::NamedElement>> getEvent() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const = 0;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;
			

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
			/*!
			The value of firstEvent[i] is related to event[i] (where i is 1 or 2). If firstEvent[i] is true, then the corresponding observation event is the first time instant the execution enters event[i]. If firstEvent[i] is false, then the corresponding observation event is the time instant the execution exits event[i].
			<p>From package UML::Values.</p>
			*/
			
			mutable std::shared_ptr<Bag<bool>> m_firstEvent;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The DurationObservation is determined as the duration between the entering or exiting of a single event Element during execution, or the entering/exiting of one event Element and the entering/exiting of a second.
			<p>From package UML::Values.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::NamedElement>> m_event;
	};
}
#endif /* end of include guard: UML_DURATIONOBSERVATION_HPP */
