//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_CLASSIFIERBEHAVIOREXECUTIONACTIVITYCLASSIFIERBEHAVIOREXECUTIONACTIVITYIMPL_HPP
#define FUML_CLASSIFIERBEHAVIOREXECUTIONACTIVITYCLASSIFIERBEHAVIOREXECUTIONACTIVITYIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ClassifierBehaviorExecutionActivity.hpp"


#include "ecore/impl/EObjectImpl.hpp"

//*********************************
namespace fUML 
{
	class ClassifierBehaviorExecutionActivityImpl :virtual public ecore::EObjectImpl,
virtual public ClassifierBehaviorExecutionActivity 
	{
		public: 
			ClassifierBehaviorExecutionActivityImpl(const ClassifierBehaviorExecutionActivityImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ClassifierBehaviorExecutionActivityImpl& operator=(ClassifierBehaviorExecutionActivityImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ClassifierBehaviorExecutionActivityImpl();
			virtual std::shared_ptr<ClassifierBehaviorExecutionActivity> getThisClassifierBehaviorExecutionActivityPtr();
			virtual void setThisClassifierBehaviorExecutionActivityPtr(std::weak_ptr<ClassifierBehaviorExecutionActivity> thisClassifierBehaviorExecutionActivityPtr);



		public:
			//destructor
			virtual ~ClassifierBehaviorExecutionActivityImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, boost::any newValue) ;

		private:
			std::weak_ptr<ClassifierBehaviorExecutionActivity> m_thisClassifierBehaviorExecutionActivityPtr;
	};
}
#endif /* end of include guard: FUML_CLASSIFIERBEHAVIOREXECUTIONACTIVITYCLASSIFIERBEHAVIOREXECUTIONACTIVITYIMPL_HPP */
