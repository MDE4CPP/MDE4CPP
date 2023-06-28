//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_DISPATCHSTRATEGYDISPATCHSTRATEGYIMPL_HPP
#define FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_DISPATCHSTRATEGYDISPATCHSTRATEGYIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../DispatchStrategy.hpp"

#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/Loci/impl/SemanticStrategyImpl.hpp"

//*********************************
namespace fUML::Semantics::StructuredClassifiers 
{
	class FUML_API DispatchStrategyImpl : virtual public fUML::Semantics::Loci::SemanticStrategyImpl, virtual public DispatchStrategy 
	{
		public: 
			DispatchStrategyImpl(const DispatchStrategyImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			DispatchStrategyImpl& operator=(DispatchStrategyImpl const&); 

		protected:
			friend class fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactoryImpl;
			DispatchStrategyImpl();
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::DispatchStrategy> getThisDispatchStrategyPtr() const;
			virtual void setThisDispatchStrategyPtr(std::weak_ptr<fUML::Semantics::StructuredClassifiers::DispatchStrategy> thisDispatchStrategyPtr);


		public:
			//destructor
			virtual ~DispatchStrategyImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatch(const std::shared_ptr<uml::Element>& object, const std::shared_ptr<uml::Operation>& operation) ;
			virtual std::string getName() ;
			virtual std::shared_ptr<uml::Behavior> retrieveMethod(const std::shared_ptr<uml::Element>& object, const std::shared_ptr<uml::Operation>& operation) ;
			
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
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

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
			std::weak_ptr<fUML::Semantics::StructuredClassifiers::DispatchStrategy> m_thisDispatchStrategyPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_DISPATCHSTRATEGYDISPATCHSTRATEGYIMPL_HPP */
