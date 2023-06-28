//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_BEHAVIORALFEATURE_HPP
#define UML_BEHAVIORALFEATURE_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
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
	class Behavior;
	class Classifier;
	class Comment;
	class Constraint;
	class Dependency;
	class ElementImport;
	class PackageImport;
	class PackageableElement;
	class Parameter;
	class ParameterSet;
	class StringExpression;
	class Type;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Feature.hpp"
#include "uml/Namespace.hpp"

// enum includes
#include "uml/CallConcurrencyKind.hpp"
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A BehavioralFeature is a feature of a Classifier that specifies an aspect of the behavior of its instances.  A BehavioralFeature is implemented (realized) by a Behavior. A BehavioralFeature specifies that a Classifier will respond to a designated request by invoking its implementing method.
	<p>From package UML::Classification.</p>
	*/
	
	class UML_API BehavioralFeature : virtual public Feature, virtual public Namespace
	{
		public:
 			BehavioralFeature(const BehavioralFeature &) {}

		protected:
			BehavioralFeature(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~BehavioralFeature() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			Creates a return result parameter with the specified name and type.
			*/
			 
			virtual std::shared_ptr<uml::Parameter> createReturnResult(std::string name, const std::shared_ptr<uml::Type>& type) = 0;
			/*!
			The ownedParameters with direction in and inout.
			result = (ownedParameter->select(direction=ParameterDirectionKind::_'in' or direction=ParameterDirectionKind::inout))
			<p>From package UML::Classification.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Parameter>> inputParameters() = 0;
			/*!
			The ownedParameters with direction out, inout, or return.
			result = (ownedParameter->select(direction=ParameterDirectionKind::out or direction=ParameterDirectionKind::inout or direction=ParameterDirectionKind::return))
			<p>From package UML::Classification.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Parameter>> outputParameters() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies the semantics of concurrent calls to the same passive instance (i.e., an instance originating from a Class with isActive being false). Active instances control access to their own BehavioralFeatures.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual uml::CallConcurrencyKind getConcurrency() const = 0;
			/*!
			Specifies the semantics of concurrent calls to the same passive instance (i.e., an instance originating from a Class with isActive being false). Active instances control access to their own BehavioralFeatures.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setConcurrency (uml::CallConcurrencyKind _concurrency)= 0;
			/*!
			If true, then the BehavioralFeature does not have an implementation, and one must be supplied by a more specific Classifier. If false, the BehavioralFeature must have an implementation in the Classifier or one must be inherited.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsAbstract() const = 0;
			/*!
			If true, then the BehavioralFeature does not have an implementation, and one must be supplied by a more specific Classifier. If false, the BehavioralFeature must have an implementation in the Classifier or one must be inherited.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsAbstract (bool _isAbstract)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			A Behavior that implements the BehavioralFeature. There may be at most one Behavior for a particular pairing of a Classifier (as owner of the Behavior) and a BehavioralFeature (as specification of the Behavior).
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Behavior>>& getMethod() const = 0;
			/*!
			The ordered set of formal Parameters of this BehavioralFeature.
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::Parameter, uml::NamedElement>>& getOwnedParameter() const = 0;
			/*!
			The ParameterSets owned by this BehavioralFeature.
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement>>& getOwnedParameterSet() const = 0;
			/*!
			The Types representing exceptions that may be raised during an invocation of this BehavioralFeature.
			<p>From package UML::Classification.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Type>>& getRaisedException() const = 0;

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
			/*!
			Specifies the semantics of concurrent calls to the same passive instance (i.e., an instance originating from a Class with isActive being false). Active instances control access to their own BehavioralFeatures.
			<p>From package UML::Classification.</p>
			*/
			
			uml::CallConcurrencyKind m_concurrency= uml::CallConcurrencyKind::SEQUENTIAL;
			/*!
			If true, then the BehavioralFeature does not have an implementation, and one must be supplied by a more specific Classifier. If false, the BehavioralFeature must have an implementation in the Classifier or one must be inherited.
			<p>From package UML::Classification.</p>
			*/
			
			bool m_isAbstract= false;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			A Behavior that implements the BehavioralFeature. There may be at most one Behavior for a particular pairing of a Classifier (as owner of the Behavior) and a BehavioralFeature (as specification of the Behavior).
			<p>From package UML::Classification.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Behavior>> m_method;
			/*!
			The ordered set of formal Parameters of this BehavioralFeature.
			<p>From package UML::Classification.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Parameter, uml::NamedElement>> m_ownedParameter;
			/*!
			The ParameterSets owned by this BehavioralFeature.
			<p>From package UML::Classification.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement>> m_ownedParameterSet;
			/*!
			The Types representing exceptions that may be raised during an invocation of this BehavioralFeature.
			<p>From package UML::Classification.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Type>> m_raisedException;
	};
}
#endif /* end of include guard: UML_BEHAVIORALFEATURE_HPP */
