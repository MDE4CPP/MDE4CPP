//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_ACTIVITYEXECUTIONACTIVITYEXECUTIONIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_ACTIVITYEXECUTIONACTIVITYEXECUTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../ActivityExecution.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/ExecutionImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class FUML_API ActivityExecutionImpl : virtual public fUML::Semantics::CommonBehavior::ExecutionImpl, virtual public ActivityExecution 
	{
		public: 
			ActivityExecutionImpl(const ActivityExecutionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ActivityExecutionImpl& operator=(ActivityExecutionImpl const&); 

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			ActivityExecutionImpl();
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> getThisActivityExecutionPtr() const;
			virtual void setThisActivityExecutionPtr(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> thisActivityExecutionPtr);


		public:
			//destructor
			virtual ~ActivityExecutionImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<Any> _copy() ;
			virtual void execute() ;
			virtual std::shared_ptr<Any> new_() ;
			virtual void terminate() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> getActivationGroup() const ;
			virtual void setActivationGroup(const std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup>&) ;
			virtual std::shared_ptr<uml::Activity> getActivity() const ;
			virtual void setActivity(const std::shared_ptr<uml::Activity>&) ;
			/*Additional Setter for 'Execution::behavior' redefined by reference 'activity'*/
			virtual void setBehavior(const std::shared_ptr<uml::Behavior>&) ;
			
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
			std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> m_thisActivityExecutionPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_ACTIVITYEXECUTIONACTIVITYEXECUTIONIMPL_HPP */
