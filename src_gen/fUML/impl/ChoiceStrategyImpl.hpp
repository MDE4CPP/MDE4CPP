//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_CHOICESTRATEGYCHOICESTRATEGYIMPL_HPP
#define FUML_CHOICESTRATEGYCHOICESTRATEGYIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ChoiceStrategy.hpp"

#include "fUML/impl/SemanticStrategyImpl.hpp"

//*********************************
namespace fUML 
{
	class ChoiceStrategyImpl :virtual public SemanticStrategyImpl, virtual public ChoiceStrategy 
	{
		public: 
			ChoiceStrategyImpl(const ChoiceStrategyImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ChoiceStrategyImpl& operator=(ChoiceStrategyImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ChoiceStrategyImpl();
			virtual std::shared_ptr<ChoiceStrategy> getThisChoiceStrategyPtr();
			virtual void setThisChoiceStrategyPtr(std::weak_ptr<ChoiceStrategy> thisChoiceStrategyPtr);



		public:
			//destructor
			virtual ~ChoiceStrategyImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual int choose(int size)  ;
			
			/*!
			 */ 
			virtual std::string retrieveName()  ;
			
			
			
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
			std::weak_ptr<ChoiceStrategy> m_thisChoiceStrategyPtr;
	};
}
#endif /* end of include guard: FUML_CHOICESTRATEGYCHOICESTRATEGYIMPL_HPP */
