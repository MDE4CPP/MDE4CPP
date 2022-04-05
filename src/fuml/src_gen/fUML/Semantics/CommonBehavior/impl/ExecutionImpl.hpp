//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIOR_EXECUTIONEXECUTIONIMPL_HPP
#define FUML_SEMANTICS_COMMONBEHAVIOR_EXECUTIONEXECUTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../Execution.hpp"

#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"
#include "uml/impl/ElementImpl.hpp"
#include "fUML/Semantics/Loci/impl/SemanticVisitorImpl.hpp"

//*********************************
namespace fUML::Semantics::CommonBehavior 
{
	class FUML_API ExecutionImpl : virtual public uml::ElementImpl, virtual public fUML::Semantics::Loci::SemanticVisitorImpl, virtual public Execution 
	{
		public: 
			ExecutionImpl(const ExecutionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			ExecutionImpl& operator=(ExecutionImpl const&); 

		protected:
			friend class fUML::Semantics::CommonBehavior::CommonBehaviorFactoryImpl;
			ExecutionImpl();
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> getThisExecutionPtr() const;
			virtual void setThisExecutionPtr(std::weak_ptr<fUML::Semantics::CommonBehavior::Execution> thisExecutionPtr);


		public:
			//destructor
			virtual ~ExecutionImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<Any> _copy() ;
			virtual void destroy() ;
			virtual void execute() ;
			
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> getOutputParameterValues() ;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> getParameterValue(std::shared_ptr<uml::Parameter> parameter) ;
			virtual std::shared_ptr<Any> new_() ;
			virtual void setParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue) ;
			virtual void terminate() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<uml::Behavior> getBehavior() const ;
			virtual void setBehavior(std::shared_ptr<uml::Behavior>) ;
			virtual std::shared_ptr<uml::Element> getContext() const ;
			virtual void setContext(std::shared_ptr<uml::Element>) ;
			virtual std::shared_ptr<fUML::Semantics::Loci::Locus> getLocus() const ;
			virtual void setLocus(std::shared_ptr<fUML::Semantics::Loci::Locus>) ;
			
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> getParameterValues() const ;
			virtual std::shared_ptr<Bag<uml::Classifier>> getTypes() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			
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
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::CommonBehavior::Execution> m_thisExecutionPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_EXECUTIONEXECUTIONIMPL_HPP */
