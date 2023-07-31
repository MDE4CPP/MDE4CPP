//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_SIMPLECLASSIFIERS_ENUMERATIONVALUEENUMERATIONVALUEIMPL_HPP
#define FUML_SEMANTICS_SIMPLECLASSIFIERS_ENUMERATIONVALUEENUMERATIONVALUEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../EnumerationValue.hpp"

#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/Values/impl/ValueImpl.hpp"

//*********************************
namespace fUML::Semantics::SimpleClassifiers 
{
	class FUML_API EnumerationValueImpl : virtual public fUML::Semantics::Values::ValueImpl, virtual public EnumerationValue 
	{
		public: 
			EnumerationValueImpl(const EnumerationValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			EnumerationValueImpl& operator=(EnumerationValueImpl const&); 

		protected:
			friend class fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactoryImpl;
			EnumerationValueImpl();
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> getThisEnumerationValuePtr() const;
			virtual void setThisEnumerationValuePtr(std::weak_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> thisEnumerationValuePtr);


		public:
			//destructor
			virtual ~EnumerationValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Values::Value> _copy() ;
			virtual bool equals(const std::shared_ptr<fUML::Semantics::Values::Value>& otherValue) ;
			virtual std::shared_ptr<Bag<uml::Classifier>> getTypes() ;
			virtual std::shared_ptr<fUML::Semantics::Values::Value> new_() ;
			virtual std::shared_ptr<uml::ValueSpecification> specify() ;
			virtual std::string toString() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual const std::shared_ptr<uml::EnumerationLiteral>& getLiteral() const ;
			virtual void setLiteral(const std::shared_ptr<uml::EnumerationLiteral>&) ;
			virtual const std::shared_ptr<uml::Enumeration>& getType() const ;
			virtual void setType(const std::shared_ptr<uml::Enumeration>&) ;
			
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
			std::weak_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> m_thisEnumerationValuePtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_SIMPLECLASSIFIERS_ENUMERATIONVALUEENUMERATIONVALUEIMPL_HPP */
