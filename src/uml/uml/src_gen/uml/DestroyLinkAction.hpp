//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_DESTROYLINKACTION_HPP
#define UML_DESTROYLINKACTION_HPP


#include <memory>
#include <string>
// forward declarations


//*********************************
// generated Includes

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
	class LinkEndData;
	class Namespace;
	class OutputPin;
	class StringExpression;
	class StructuredActivityNode;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/WriteLinkAction.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A DestroyLinkAction is a WriteLinkAction that destroys links (including link objects).
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API DestroyLinkAction : virtual public WriteLinkAction
	{
		public:
 			DestroyLinkAction(const DestroyLinkAction &) {}

		protected:
			DestroyLinkAction(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~DestroyLinkAction() {}

			//*********************************
			// Operations
			//*********************************

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

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
	};
}
#endif /* end of include guard: UML_DESTROYLINKACTION_HPP */
