//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_LOCI_FIRSTCHOICESTRATEGYFIRSTCHOICESTRATEGYIMPL_HPP
#define FUML_SEMANTICS_LOCI_FIRSTCHOICESTRATEGYFIRSTCHOICESTRATEGYIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../FirstChoiceStrategy.hpp"

#include "fUML/Semantics/Loci/impl/LociFactoryImpl.hpp"
#include "fUML/Semantics/Loci/impl/ChoiceStrategyImpl.hpp"

//*********************************
namespace fUML::Semantics::Loci 
{
	class FUML_API FirstChoiceStrategyImpl : virtual public ChoiceStrategyImpl, virtual public FirstChoiceStrategy 
	{
		public: 
			FirstChoiceStrategyImpl(const FirstChoiceStrategyImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			FirstChoiceStrategyImpl& operator=(FirstChoiceStrategyImpl const&); 

		protected:
			friend class fUML::Semantics::Loci::LociFactoryImpl;
			FirstChoiceStrategyImpl();
			virtual std::shared_ptr<fUML::Semantics::Loci::FirstChoiceStrategy> getThisFirstChoiceStrategyPtr() const;
			virtual void setThisFirstChoiceStrategyPtr(std::weak_ptr<fUML::Semantics::Loci::FirstChoiceStrategy> thisFirstChoiceStrategyPtr);


		public:
			//destructor
			virtual ~FirstChoiceStrategyImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual int choose(int size) ;
			
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
			std::weak_ptr<fUML::Semantics::Loci::FirstChoiceStrategy> m_thisFirstChoiceStrategyPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_LOCI_FIRSTCHOICESTRATEGYFIRSTCHOICESTRATEGYIMPL_HPP */
