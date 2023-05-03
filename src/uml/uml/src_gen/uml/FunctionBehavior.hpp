//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_FUNCTIONBEHAVIOR_HPP
#define UML_FUNCTIONBEHAVIOR_HPP


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

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class BehavioralFeature;
	class CollaborationUse;
	class Comment;
	class ConnectableElement;
	class Connector;
	class Constraint;
	class DataType;
	class Dependency;
	class ElementImport;
	class Extension;
	class Feature;
	class Generalization;
	class GeneralizationSet;
	class InterfaceRealization;
	class Operation;
	class Package;
	class PackageImport;
	class Parameter;
	class ParameterSet;
	class Port;
	class Property;
	class Reception;
	class StringExpression;
	class Substitution;
	class TemplateBinding;
	class TemplateParameter;
	class TemplateSignature;
	class UseCase;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/OpaqueBehavior.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A FunctionBehavior is an OpaqueBehavior that does not access or modify any objects or other external data.
	<p>From package UML::CommonBehavior.</p>
	*/
	
	class UML_API FunctionBehavior : virtual public OpaqueBehavior
	{
		public:
 			FunctionBehavior(const FunctionBehavior &) {}

		protected:
			FunctionBehavior(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~FunctionBehavior() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The hasAllDataTypeAttributes query tests whether the types of the attributes of the given DataType are all DataTypes, and similarly for all those DataTypes.
			result = (d.ownedAttribute->forAll(a |
			    a.type.oclIsKindOf(DataType) and
			      hasAllDataTypeAttributes(a.type.oclAsType(DataType))))
			<p>From package UML::CommonBehavior.</p>
			*/
			 
			virtual bool hasAllDataTypeAttributes(const std::shared_ptr<uml::DataType>& d) = 0;

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
#endif /* end of include guard: UML_FUNCTIONBEHAVIOR_HPP */
