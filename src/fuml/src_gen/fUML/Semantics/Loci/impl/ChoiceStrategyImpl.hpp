//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_LOCI_CHOICESTRATEGYCHOICESTRATEGYIMPL_HPP
#define FUML_SEMANTICS_LOCI_CHOICESTRATEGYCHOICESTRATEGYIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../ChoiceStrategy.hpp"

#include "fUML/Semantics/Loci/impl/LociFactoryImpl.hpp"
#include "fUML/Semantics/Loci/impl/SemanticStrategyImpl.hpp"

//*********************************
namespace fUML::Semantics::Loci 
{
	class FUML_API ChoiceStrategyImpl : virtual public SemanticStrategyImpl, virtual public ChoiceStrategy 
	{
		public: 
			ChoiceStrategyImpl(const ChoiceStrategyImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			ChoiceStrategyImpl& operator=(ChoiceStrategyImpl const&); 

		protected:
			friend class fUML::Semantics::Loci::LociFactoryImpl;
			ChoiceStrategyImpl();
			virtual std::shared_ptr<fUML::Semantics::Loci::ChoiceStrategy> getThisChoiceStrategyPtr() const;
			virtual void setThisChoiceStrategyPtr(std::weak_ptr<fUML::Semantics::Loci::ChoiceStrategy> thisChoiceStrategyPtr);


		public:
			//destructor
			virtual ~ChoiceStrategyImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual int choose(int size) ;
			virtual std::string getName() ;
			
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
			std::weak_ptr<fUML::Semantics::Loci::ChoiceStrategy> m_thisChoiceStrategyPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_LOCI_CHOICESTRATEGYCHOICESTRATEGYIMPL_HPP */
