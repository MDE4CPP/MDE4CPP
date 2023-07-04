//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_SIMPLECLASSIFIERS_SIGNALINSTANCESIGNALINSTANCEIMPL_HPP
#define FUML_SEMANTICS_SIMPLECLASSIFIERS_SIGNALINSTANCESIGNALINSTANCEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../SignalInstance.hpp"

#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/CompoundValueImpl.hpp"

//*********************************
namespace fUML::Semantics::SimpleClassifiers 
{
	class FUML_API SignalInstanceImpl : virtual public CompoundValueImpl, virtual public SignalInstance 
	{
		public: 
			SignalInstanceImpl(const SignalInstanceImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			SignalInstanceImpl& operator=(SignalInstanceImpl const&); 

		protected:
			friend class fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactoryImpl;
			SignalInstanceImpl();
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> getThisSignalInstancePtr() const;
			virtual void setThisSignalInstancePtr(std::weak_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> thisSignalInstancePtr);


		public:
			//destructor
			virtual ~SignalInstanceImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Values::Value> _copy() ;
			virtual std::shared_ptr<Bag<uml::Classifier> > getTypes() const ;
			virtual std::shared_ptr<fUML::Semantics::Values::Value> new_() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<uml::Signal>& getType() const ;
			virtual void setType(const std::shared_ptr<uml::Signal>&) ;
			
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
			virtual const std::shared_ptr<ecore::EClass>& eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, const Any& newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> m_thisSignalInstancePtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_SIMPLECLASSIFIERS_SIGNALINSTANCESIGNALINSTANCEIMPL_HPP */
