//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_REMOVESTRUCTURALFEATUREVALUEACTION_HPP
#define UML_REMOVESTRUCTURALFEATUREVALUEACTION_HPP


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
#include "uml/WriteStructuralFeatureAction.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A RemoveStructuralFeatureValueAction is a WriteStructuralFeatureAction that removes values from a StructuralFeature.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API RemoveStructuralFeatureValueAction : virtual public WriteStructuralFeatureAction
	{
		public:
 			RemoveStructuralFeatureValueAction(const RemoveStructuralFeatureValueAction &) {}

		protected:
			RemoveStructuralFeatureValueAction(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~RemoveStructuralFeatureValueAction() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies whether to remove duplicates of the value in nonunique StructuralFeatures.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsRemoveDuplicates() const = 0;
			/*!
			Specifies whether to remove duplicates of the value in nonunique StructuralFeatures.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsRemoveDuplicates (bool _isRemoveDuplicates)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			An InputPin that provides the position of an existing value to remove in ordered, nonunique structural features. The type of the removeAt InputPin is UnlimitedNatural, but the value cannot be zero or unlimited.
			<p>From package UML::Actions.</p>
			*/
			
			virtual const std::shared_ptr<uml::InputPin>& getRemoveAt() const = 0;
			/*!
			An InputPin that provides the position of an existing value to remove in ordered, nonunique structural features. The type of the removeAt InputPin is UnlimitedNatural, but the value cannot be zero or unlimited.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setRemoveAt(const std::shared_ptr<uml::InputPin>&) = 0;

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
			Specifies whether to remove duplicates of the value in nonunique StructuralFeatures.
			<p>From package UML::Actions.</p>
			*/
			
			bool m_isRemoveDuplicates= false;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			An InputPin that provides the position of an existing value to remove in ordered, nonunique structural features. The type of the removeAt InputPin is UnlimitedNatural, but the value cannot be zero or unlimited.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::InputPin> m_removeAt;
	};
}
#endif /* end of include guard: UML_REMOVESTRUCTURALFEATUREVALUEACTION_HPP */
