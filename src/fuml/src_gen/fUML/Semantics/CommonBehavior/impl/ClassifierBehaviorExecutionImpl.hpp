//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIOR_CLASSIFIERBEHAVIOREXECUTIONCLASSIFIERBEHAVIOREXECUTIONIMPL_HPP
#define FUML_SEMANTICS_COMMONBEHAVIOR_CLASSIFIERBEHAVIOREXECUTIONCLASSIFIERBEHAVIOREXECUTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../ClassifierBehaviorExecution.hpp"

#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace fUML::Semantics::CommonBehavior 
{
	class FUML_API ClassifierBehaviorExecutionImpl : virtual public ecore::EModelElementImpl,
virtual public ClassifierBehaviorExecution 
	{
		public: 
			ClassifierBehaviorExecutionImpl(const ClassifierBehaviorExecutionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ClassifierBehaviorExecutionImpl& operator=(ClassifierBehaviorExecutionImpl const&); 

		protected:
			friend class fUML::Semantics::CommonBehavior::CommonBehaviorFactoryImpl;
			ClassifierBehaviorExecutionImpl();
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> getThisClassifierBehaviorExecutionPtr() const;
			virtual void setThisClassifierBehaviorExecutionPtr(std::weak_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> thisClassifierBehaviorExecutionPtr);


		public:
			//destructor
			virtual ~ClassifierBehaviorExecutionImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void _startObjectBehavior() ;
			virtual void execute(std::shared_ptr<Bag<uml::Class>> classifier,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> inputs) ;
			virtual void terminate() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<uml::Class> getClassifier() const ;
			virtual void setClassifier(std::shared_ptr<uml::Class>) ;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> getExecution() const ;
			virtual void setExecution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>) ;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> getObjectActivation() const ;
			virtual void setObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation>) ;
			
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
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> m_thisClassifierBehaviorExecutionPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_CLASSIFIERBEHAVIOREXECUTIONCLASSIFIERBEHAVIOREXECUTIONIMPL_HPP */
