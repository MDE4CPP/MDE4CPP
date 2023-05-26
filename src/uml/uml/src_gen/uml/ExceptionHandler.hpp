//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXCEPTIONHANDLER_HPP
#define UML_EXCEPTIONHANDLER_HPP


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
	class Classifier;
	class Comment;
	class ExecutableNode;
	class ObjectNode;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Element.hpp"




//*********************************
namespace uml 
{
	/*!
	An ExceptionHandler is an Element that specifies a handlerBody ExecutableNode to execute in case the specified exception occurs during the execution of the protected ExecutableNode.
	<p>From package UML::Activities.</p>
	*/
	
	class UML_API ExceptionHandler : virtual public Element
	{
		public:
 			ExceptionHandler(const ExceptionHandler &) {}

		protected:
			ExceptionHandler(){}
			//Additional constructors for the containments back reference
			ExceptionHandler(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			ExceptionHandler(std::weak_ptr<uml::ExecutableNode> par_protectedNode);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ExceptionHandler() {}

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
			An ObjectNode within the handlerBody. When the ExceptionHandler catches an exception, the exception token is placed on this ObjectNode, causing the handlerBody to execute.
			<p>From package UML::Activities.</p>
			*/
			
			virtual const std::shared_ptr<uml::ObjectNode>& getExceptionInput() const = 0;
			/*!
			An ObjectNode within the handlerBody. When the ExceptionHandler catches an exception, the exception token is placed on this ObjectNode, causing the handlerBody to execute.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setExceptionInput(const std::shared_ptr<uml::ObjectNode>&) = 0;
			/*!
			The Classifiers whose instances the ExceptionHandler catches as exceptions. If an exception occurs whose type is any exceptionType, the ExceptionHandler catches the exception and executes the handlerBody.
			<p>From package UML::Activities.</p>
			*/
			
			virtual const std::shared_ptr<Bag<uml::Classifier>>& getExceptionType() const = 0;
			/*!
			An ExecutableNode that is executed if the ExceptionHandler catches an exception.
			<p>From package UML::Activities.</p>
			*/
			
			virtual const std::shared_ptr<uml::ExecutableNode>& getHandlerBody() const = 0;
			/*!
			An ExecutableNode that is executed if the ExceptionHandler catches an exception.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setHandlerBody(const std::shared_ptr<uml::ExecutableNode>&) = 0;
			/*!
			The ExecutableNode protected by the ExceptionHandler. If an exception propagates out of the protectedNode and has a type matching one of the exceptionTypes, then it is caught by this ExceptionHandler.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::weak_ptr<uml::ExecutableNode> getProtectedNode() const = 0;
			/*!
			The ExecutableNode protected by the ExceptionHandler. If an exception propagates out of the protectedNode and has a type matching one of the exceptionTypes, then it is caught by this ExceptionHandler.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setProtectedNode(std::weak_ptr<uml::ExecutableNode>) = 0;

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
			An ObjectNode within the handlerBody. When the ExceptionHandler catches an exception, the exception token is placed on this ObjectNode, causing the handlerBody to execute.
			<p>From package UML::Activities.</p>
			*/
			
			std::shared_ptr<uml::ObjectNode> m_exceptionInput;
			/*!
			The Classifiers whose instances the ExceptionHandler catches as exceptions. If an exception occurs whose type is any exceptionType, the ExceptionHandler catches the exception and executes the handlerBody.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Classifier>> m_exceptionType;
			/*!
			An ExecutableNode that is executed if the ExceptionHandler catches an exception.
			<p>From package UML::Activities.</p>
			*/
			
			std::shared_ptr<uml::ExecutableNode> m_handlerBody;
			/*!
			The ExecutableNode protected by the ExceptionHandler. If an exception propagates out of the protectedNode and has a type matching one of the exceptionTypes, then it is caught by this ExceptionHandler.
			<p>From package UML::Activities.</p>
			*/
			
			std::weak_ptr<uml::ExecutableNode> m_protectedNode;
	};
}
#endif /* end of include guard: UML_EXCEPTIONHANDLER_HPP */
