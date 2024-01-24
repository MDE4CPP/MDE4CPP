//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_ACTIONSFACTORY_HPP
#define PSSM_SEMANTICS_ACTIONSFACTORY_HPP
// namespace macro header include
#include "PSSM/PSSM.hpp"

#include <map>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EFactory.hpp"
#include "PSSM/Semantics/Actions/ActionsPackage.hpp"




namespace PSSM::Semantics::Actions 
{
	class PSSM_API ActionsFactory : virtual public ecore::EFactory 
	{
		private:    
			ActionsFactory(ActionsFactory const&) = delete;
			ActionsFactory& operator=(ActionsFactory const&) = delete;
		protected:
			ActionsFactory(){}
		
			//Singleton Getter
			public:
				static std::shared_ptr<ActionsFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			virtual std::shared_ptr<PSSM::Semantics::Actions::SM_ReadSelfActionActivation> createSM_ReadSelfActionActivation(const int metaElementID = ActionsPackage::SM_READSELFACTIONACTIVATION_CLASS) const = 0;
			
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_ACTIONSFACTORY_HPP */