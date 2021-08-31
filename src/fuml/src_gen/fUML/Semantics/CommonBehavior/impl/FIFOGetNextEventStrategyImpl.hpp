//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIOR_FIFOGETNEXTEVENTSTRATEGYFIFOGETNEXTEVENTSTRATEGYIMPL_HPP
#define FUML_SEMANTICS_COMMONBEHAVIOR_FIFOGETNEXTEVENTSTRATEGYFIFOGETNEXTEVENTSTRATEGYIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../FIFOGetNextEventStrategy.hpp"

#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/GetNextEventStrategyImpl.hpp"

//*********************************
namespace fUML::Semantics::CommonBehavior 
{
	class FUML_API FIFOGetNextEventStrategyImpl : virtual public GetNextEventStrategyImpl, virtual public FIFOGetNextEventStrategy 
	{
		public: 
			FIFOGetNextEventStrategyImpl(const FIFOGetNextEventStrategyImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			FIFOGetNextEventStrategyImpl& operator=(FIFOGetNextEventStrategyImpl const&); 

		protected:
			friend class fUML::Semantics::CommonBehavior::CommonBehaviorFactoryImpl;
			FIFOGetNextEventStrategyImpl();
			virtual std::shared_ptr<FIFOGetNextEventStrategy> getThisFIFOGetNextEventStrategyPtr() const;
			virtual void setThisFIFOGetNextEventStrategyPtr(std::weak_ptr<FIFOGetNextEventStrategy> thisFIFOGetNextEventStrategyPtr);


		public:
			//destructor
			virtual ~FIFOGetNextEventStrategyImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			
			//*********************************
			// Union Getter
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
			

			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<FIFOGetNextEventStrategy> m_thisFIFOGetNextEventStrategyPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_FIFOGETNEXTEVENTSTRATEGYFIFOGETNEXTEVENTSTRATEGYIMPL_HPP */
