//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_DISPATCHSTRATEGYDISPATCHSTRATEGYIMPL_HPP
#define FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_DISPATCHSTRATEGYDISPATCHSTRATEGYIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../DispatchStrategy.hpp"

#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/Loci/impl/SemanticStrategyImpl.hpp"

//*********************************
namespace fUML::Semantics::StructuredClassifiers 
{
	class DispatchStrategyImpl : virtual public fUML::Semantics::Loci::SemanticStrategyImpl, virtual public DispatchStrategy 
	{
		public: 
			DispatchStrategyImpl(const DispatchStrategyImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			DispatchStrategyImpl& operator=(DispatchStrategyImpl const&) = delete;

		protected:
			friend class fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactoryImpl;
			DispatchStrategyImpl();
			virtual std::shared_ptr<DispatchStrategy> getThisDispatchStrategyPtr() const;
			virtual void setThisDispatchStrategyPtr(std::weak_ptr<DispatchStrategy> thisDispatchStrategyPtr);



		public:
			//destructor
			virtual ~DispatchStrategyImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatch(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object>  object,std::shared_ptr<uml::Operation>  operation) ;
			
			 
			virtual std::string getName() ;
			
			 
			virtual std::shared_ptr<uml::Behavior> retrieveMethod(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object>  object,std::shared_ptr<uml::Operation>  operation) ;
			
			
			
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
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<DispatchStrategy> m_thisDispatchStrategyPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_DISPATCHSTRATEGYDISPATCHSTRATEGYIMPL_HPP */
