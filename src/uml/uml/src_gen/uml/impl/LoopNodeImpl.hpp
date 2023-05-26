//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LOOPNODELOOPNODEIMPL_HPP
#define UML_LOOPNODELOOPNODEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../LoopNode.hpp"

#include "uml/impl/StructuredActivityNodeImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API LoopNodeImpl : virtual public StructuredActivityNodeImpl, virtual public LoopNode 
	{
		public: 
			LoopNodeImpl(const LoopNodeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			LoopNodeImpl& operator=(LoopNodeImpl const&); 

		protected:
			friend class umlFactoryImpl;
			LoopNodeImpl();
			virtual std::shared_ptr<uml::LoopNode> getThisLoopNodePtr() const;
			virtual void setThisLoopNodePtr(std::weak_ptr<uml::LoopNode> thisLoopNodePtr);

			//Additional constructors for the containments back reference
			LoopNodeImpl(std::weak_ptr<uml::Activity> par_Activity, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			LoopNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			LoopNodeImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			LoopNodeImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			LoopNodeImpl(std::weak_ptr<uml::ActivityGroup> par_superGroup);

		public:
			//destructor
			virtual ~LoopNodeImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			If true, the test is performed before the first execution of the bodyPart. If false, the bodyPart is executed once before the test is performed.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsTestedFirst() const ;
			/*!
			If true, the test is performed before the first execution of the bodyPart. If false, the bodyPart is executed once before the test is performed.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsTestedFirst (bool _isTestedFirst);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The OutputPins on Actions within the bodyPart, the values of which are moved to the loopVariable OutputPins after the completion of each execution of the bodyPart, before the next iteration of the loop begins or before the loop exits.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::OutputPin>> getBodyOutput() const ;
			/*!
			The set of ExecutableNodes that perform the repetitive computations of the loop. The bodyPart is executed as long as the test section produces a true value.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ExecutableNode>> getBodyPart() const ;
			/*!
			An OutputPin on an Action in the test section whose Boolean value determines whether to continue executing the loop bodyPart.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::OutputPin> getDecider() const ;
			/*!
			An OutputPin on an Action in the test section whose Boolean value determines whether to continue executing the loop bodyPart.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setDecider(const std::shared_ptr<uml::OutputPin>&) ;
			/*!
			A list of OutputPins that hold the values of the loop variables during an execution of the loop. When the test fails, the values are moved to the result OutputPins of the loop.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::OutputPin, uml::Element>> getLoopVariable() const ;
			/*!
			A list of InputPins whose values are moved into the loopVariable Pins before the first iteration of the loop.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::InputPin>> getLoopVariableInput() const ;
			/*!
			A list of OutputPins that receive the loopVariable values after the last iteration of the loop and constitute the output of the LoopNode.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::OutputPin>> getResult() const ;
			/*!
			The set of ExecutableNodes executed before the first iteration of the loop, in order to initialize values or perform other setup computations.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ExecutableNode>> getSetupPart() const ;
			/*!
			The set of ExecutableNodes executed in order to provide the test result for the loop.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ExecutableNode>> getTest() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const std::shared_ptr<Any>& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID,const std::shared_ptr<Bag<Any>>& arguments) ;

		private:
			std::weak_ptr<uml::LoopNode> m_thisLoopNodePtr;
	};
}
#endif /* end of include guard: UML_LOOPNODELOOPNODEIMPL_HPP */
