//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_OPERATION_HPP
#define UML_OPERATION_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
template<class T, class ... U> class Subset;

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
	class Behavior;
	class Class;
	class Classifier;
	class Comment;
	class Constraint;
	class DataType;
	class Dependency;
	class ElementImport;
	class Interface;
	class PackageImport;
	class PackageableElement;
	class Parameter;
	class ParameterSet;
	class StringExpression;
	class TemplateBinding;
	class TemplateParameter;
	class TemplateSignature;
	class Type;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/BehavioralFeature.hpp"
#include "uml/ParameterableElement.hpp"
#include "uml/TemplateableElement.hpp"

// enum includes
#include "uml/CallConcurrencyKind.hpp"
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An Operation is a BehavioralFeature of a Classifier that specifies the name, type, parameters, and constraints for invoking an associated Behavior. An Operation may invoke both the execution of method behaviors as well as other behavioral responses. Operation specializes TemplateableElement in order to support specification of template operations and bound operations. Operation specializes ParameterableElement to specify that an operation can be exposed as a formal template parameter, and provided as an actual parameter in a binding of a template.
	<p>From package UML::Classification.</p>
	*/
	
	class UML_API Operation : virtual public BehavioralFeature, virtual public ParameterableElement, virtual public TemplateableElement
	{
		public:
 			Operation(const Operation &) {}

		protected:
			Operation(){}
			//Additional constructors for the containments back reference
			Operation(std::weak_ptr<uml::Class> par_class);

			//Additional constructors for the containments back reference
			Operation(std::weak_ptr<uml::DataType> par_datatype);

			//Additional constructors for the containments back reference
			Operation(std::weak_ptr<uml::Interface> par_interface);

			//Additional constructors for the containments back reference
			Operation(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			Operation(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			Operation(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Operation() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			An Operation can have at most one return parameter; i.e., an owned parameter with the direction set to 'return.'
			self.ownedParameter->select(direction = ParameterDirectionKind::return)->size() <= 1
			*/
			 
			virtual bool at_most_one_return(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			If this operation has a return parameter, lower equals the value of lower for that parameter. Otherwise lower has no value.
			result = (if returnResult()->notEmpty() then returnResult()->any(true).lower else null endif)
			<p>From package UML::Classification.</p>
			*/
			 
			virtual int getLower() = 0;
			/*!
			Retrieves the (only) return result parameter for this operation.
			*/
			 
			virtual std::shared_ptr<uml::Parameter> getReturnResult() = 0;
			
			/*!
			If this operation has a return parameter, upper equals the value of upper for that parameter. Otherwise upper has no value.
			result = (if returnResult()->notEmpty() then returnResult()->any(true).upper else null endif)
			<p>From package UML::Classification.</p>
			*/
			 
			virtual int getUpper() = 0;
			/*!
			If this operation has a return parameter, isOrdered equals the value of isOrdered for that parameter. Otherwise isOrdered is false.
			result = (if returnResult()->notEmpty() then returnResult()-> exists(isOrdered) else false endif)
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool isOrdered() = 0;
			/*!
			If this operation has a return parameter, isUnique equals the value of isUnique for that parameter. Otherwise isUnique is true.
			result = (if returnResult()->notEmpty() then returnResult()->exists(isUnique) else true endif)
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool isUnique() = 0;
			virtual bool matches(std::shared_ptr<uml::Operation> comparedOperation) = 0;
			/*!
			A bodyCondition can only be specified for a query Operation.
			bodyCondition <> null implies isQuery
			*/
			 
			virtual bool only_body_for_query(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The query returnResult() returns the set containing the return parameter of the Operation if one exists, otherwise, it returns an empty set
			result = (ownedParameter->select (direction = ParameterDirectionKind::return)->asSet())
			<p>From package UML::Classification.</p>
			*/
			 
			virtual std::shared_ptr<uml::Parameter> returnResult() = 0;
			virtual void setIsOrdered(bool newIsOrdered) = 0;
			virtual void setIsUnique(bool newIsUnique) = 0;
			virtual void setLower(int newLower) = 0;
			virtual void setType(std::shared_ptr<uml::Type> newType) = 0;
			virtual void setUpper(int newUpper) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies whether the return parameter is ordered or not, if present.  This information is derived from the return result for this Operation.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsOrdered() const = 0;
			/*!
			Specifies whether an execution of the BehavioralFeature leaves the state of the system unchanged (isQuery=true) or whether side effects may occur (isQuery=false).
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsQuery() const = 0;
			/*!
			Specifies whether an execution of the BehavioralFeature leaves the state of the system unchanged (isQuery=true) or whether side effects may occur (isQuery=false).
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsQuery (bool _isQuery)= 0;
			/*!
			Specifies whether the return parameter is unique or not, if present. This information is derived from the return result for this Operation.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsUnique() const = 0;
			/*!
			Specifies the lower multiplicity of the return parameter, if present. This information is derived from the return result for this Operation.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual int getLower() const = 0;
			/*!
			The upper multiplicity of the return parameter, if present. This information is derived from the return result for this Operation.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual int getUpper() const = 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			An optional Constraint on the result values of an invocation of this Operation.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<uml::Constraint> getBodyCondition() const = 0;
			/*!
			An optional Constraint on the result values of an invocation of this Operation.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setBodyCondition(std::shared_ptr<uml::Constraint>) = 0;
			/*!
			The Class that owns this operation, if any.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::weak_ptr<uml::Class> getClass() const = 0;
			/*!
			The Class that owns this operation, if any.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setClass(std::weak_ptr<uml::Class>) = 0;
			/*!
			The DataType that owns this Operation, if any.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::weak_ptr<uml::DataType> getDatatype() const = 0;
			/*!
			The DataType that owns this Operation, if any.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setDatatype(std::weak_ptr<uml::DataType>) = 0;
			/*!
			The Interface that owns this Operation, if any.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::weak_ptr<uml::Interface> getInterface() const = 0;
			/*!
			The Interface that owns this Operation, if any.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setInterface(std::weak_ptr<uml::Interface>) = 0;
			virtual std::shared_ptr<Bag<uml::Parameter>> getProperty_OwnedParameter() const = 0;
			/*!
			An optional set of Constraints specifying the state of the system when the Operation is completed.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> getPostcondition() const = 0;
			/*!
			An optional set of Constraints on the state of the system when the Operation is invoked.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> getPrecondition() const = 0;
			/*!
			The Operations that are redefined by this Operation.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Operation, uml::RedefinableElement>> getRedefinedOperation() const = 0;
			/*!
			The return type of the operation, if present. This information is derived from the return result for this Operation.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<uml::Type> getType() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			The Classifiers that have this Feature as a feature.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Classifier>> getFeaturingClassifier() const = 0;
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const = 0;
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
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> getOwnedMember() const = 0;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;
			/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const = 0;
			/*!
			The contexts that this element may be redefined from.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Classifier>> getRedefinitionContext() const = 0;
			

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
			Specifies whether the return parameter is ordered or not, if present.  This information is derived from the return result for this Operation.
			<p>From package UML::Classification.</p>
			*/
			
			bool m_isOrdered= false;
			/*!
			Specifies whether an execution of the BehavioralFeature leaves the state of the system unchanged (isQuery=true) or whether side effects may occur (isQuery=false).
			<p>From package UML::Classification.</p>
			*/
			
			bool m_isQuery= false;
			/*!
			Specifies whether the return parameter is unique or not, if present. This information is derived from the return result for this Operation.
			<p>From package UML::Classification.</p>
			*/
			
			bool m_isUnique= true;
			/*!
			Specifies the lower multiplicity of the return parameter, if present. This information is derived from the return result for this Operation.
			<p>From package UML::Classification.</p>
			*/
			
			int m_lower= 1;
			/*!
			The upper multiplicity of the return parameter, if present. This information is derived from the return result for this Operation.
			<p>From package UML::Classification.</p>
			*/
			
			int m_upper= 1;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			An optional Constraint on the result values of an invocation of this Operation.
			<p>From package UML::Classification.</p>
			*/
			
			std::shared_ptr<uml::Constraint> m_bodyCondition;
			/*!
			The Class that owns this operation, if any.
			<p>From package UML::Classification.</p>
			*/
			
			std::weak_ptr<uml::Class> m_class;
			/*!
			The DataType that owns this Operation, if any.
			<p>From package UML::Classification.</p>
			*/
			
			std::weak_ptr<uml::DataType> m_datatype;
			/*!
			The Interface that owns this Operation, if any.
			<p>From package UML::Classification.</p>
			*/
			
			std::weak_ptr<uml::Interface> m_interface;
			/*!
			An optional set of Constraints specifying the state of the system when the Operation is completed.
			<p>From package UML::Classification.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> m_postcondition;
			/*!
			An optional set of Constraints on the state of the system when the Operation is invoked.
			<p>From package UML::Classification.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> m_precondition;
			/*!
			The Operations that are redefined by this Operation.
			<p>From package UML::Classification.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Operation, uml::RedefinableElement>> m_redefinedOperation;
			/*!
			The return type of the operation, if present. This information is derived from the return result for this Operation.
			<p>From package UML::Classification.</p>
			*/
			
			std::shared_ptr<uml::Type> m_type;
	};
}
#endif /* end of include guard: UML_OPERATION_HPP */
