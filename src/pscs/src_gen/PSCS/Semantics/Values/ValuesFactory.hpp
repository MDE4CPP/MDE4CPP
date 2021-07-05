//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_VALUESFACTORY_HPP
#define PSCS_SEMANTICS_VALUESFACTORY_HPP

#include <map>
#include <memory>

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/EFactory.hpp"
#include "PSCS/Semantics/Values/ValuesPackage.hpp"




namespace PSCS::Semantics::Values 
{
	class PSCS_API ValuesFactory : virtual public ecore::EFactory 
	{
		private:    
			ValuesFactory(ValuesFactory const&) = delete;
			ValuesFactory& operator=(ValuesFactory const&) = delete;
		protected:
			ValuesFactory(){}
		
			//Singleton Instance and Getter
			private:
				static std::shared_ptr<ValuesFactory> instance;
			public:
				static std::shared_ptr<ValuesFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			virtual std::shared_ptr<PSCS::Semantics::Values::CS_OpaqueExpressionEvaluation> createCS_OpaqueExpressionEvaluation(const int metaElementID = ValuesPackage::CS_OPAQUEEXPRESSIONEVALUATION_CLASS) const = 0;
			
			
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_VALUESFACTORY_HPP */
