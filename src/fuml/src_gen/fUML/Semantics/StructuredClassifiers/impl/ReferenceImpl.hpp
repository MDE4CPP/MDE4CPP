//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_REFERENCEREFERENCEIMPL_HPP
#define FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_REFERENCEREFERENCEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../Reference.hpp"

#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/StructuredValueImpl.hpp"

//*********************************
namespace fUML::Semantics::StructuredClassifiers 
{
	class FUML_API ReferenceImpl : virtual public fUML::Semantics::SimpleClassifiers::StructuredValueImpl, virtual public Reference 
	{
		public: 
			ReferenceImpl(const ReferenceImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ReferenceImpl& operator=(ReferenceImpl const&); 

		protected:
			friend class fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactoryImpl;
			ReferenceImpl();
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> getThisReferencePtr() const;
			virtual void setThisReferencePtr(std::weak_ptr<fUML::Semantics::StructuredClassifiers::Reference> thisReferencePtr);


		public:
			//destructor
			virtual ~ReferenceImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Values::Value> _copy() ;
			virtual void assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature,std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values,int position) ;
			virtual void destroy() ;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatch(std::shared_ptr<uml::Operation> operation) ;
			virtual bool equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue) ;
			virtual std::shared_ptr<Bag<uml::Classifier> > getTypes() ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value> > getValues(std::shared_ptr<uml::StructuralFeature> feature,std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues) ;
			virtual std::shared_ptr<fUML::Semantics::Values::Value> new_() ;
			virtual void removeValue(std::shared_ptr<uml::StructuralFeature> feature,std::shared_ptr<fUML::Semantics::Values::Value> value) ;
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature) ;
			virtual std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue> > retrieveFeatureValues() ;
			virtual void send(std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> signalInstance) ;
			virtual void send(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence) ;
			virtual void setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature,std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values,int position) ;
			virtual void startBehavior(std::shared_ptr<uml::Class> classifier,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> inputs) ;
			virtual std::string toString() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> getReferent() const ;
			virtual void setReferent(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object>) ;
			
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
			std::weak_ptr<fUML::Semantics::StructuredClassifiers::Reference> m_thisReferencePtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_REFERENCEREFERENCEIMPL_HPP */
