//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXECUTABLENODE_HPP
#define UML_EXECUTABLENODE_HPP


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
	class Dependency;
	class ExceptionHandler;
	class InterruptibleActivityRegion;
	class Namespace;
	class StringExpression;
	class StructuredActivityNode;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/ActivityNode.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An ExecutableNode is an abstract class for ActivityNodes whose execution may be controlled using ControlFlows and to which ExceptionHandlers may be attached.
	<p>From package UML::Activities.</p>
	*/
	
	class UML_API ExecutableNode : virtual public ActivityNode
	{
		public:
 			ExecutableNode(const ExecutableNode &) {}

		protected:
			ExecutableNode(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ExecutableNode() {}

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
			A set of ExceptionHandlers that are examined if an exception propagates out of the ExceptionNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual const std::shared_ptr<Subset<uml::ExceptionHandler, uml::Element>>& getHandler() const = 0;

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
			A set of ExceptionHandlers that are examined if an exception propagates out of the ExceptionNode.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ExceptionHandler, uml::Element>> m_handler;
	};
}
#endif /* end of include guard: UML_EXECUTABLENODE_HPP */
