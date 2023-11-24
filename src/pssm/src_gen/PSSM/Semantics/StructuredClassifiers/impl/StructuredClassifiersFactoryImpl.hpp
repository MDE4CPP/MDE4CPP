//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSSM_SEMANTICS_STRUCTUREDCLASSIFIERSFACTORYIMPL_HPP
#define PSSM_SEMANTICS_STRUCTUREDCLASSIFIERSFACTORYIMPL_HPP

// namespace macro header include
#include "PSSM/PSSM.hpp"

#include "ecore/impl/EFactoryImpl.hpp"

#include "PSSM/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"

namespace StructuredClassifiers 
{	class SM_RedefinitionBasedDispatchStrategy;
}

namespace PSSM::Semantics::StructuredClassifiers 
{
	class PSSM_API StructuredClassifiersFactoryImpl : virtual public ecore::EFactoryImpl , virtual public StructuredClassifiersFactory 
	{
		private:    
			StructuredClassifiersFactoryImpl(StructuredClassifiersFactoryImpl const&) = delete;
			StructuredClassifiersFactoryImpl& operator=(StructuredClassifiersFactoryImpl const&) = delete;

		protected:
			friend class StructuredClassifiersFactory;
			// Constructor
			StructuredClassifiersFactoryImpl();

		public:
			virtual ~StructuredClassifiersFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 virtual std::shared_ptr<PSSM::Semantics::StructuredClassifiers::SM_RedefinitionBasedDispatchStrategy> createSM_RedefinitionBasedDispatchStrategy(const int metaElementID = StructuredClassifiersPackage::SM_REDEFINITIONBASEDDISPATCHSTRATEGY_CLASS) const ;
			 

		private:
			static StructuredClassifiersFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: PSSM_SEMANTICS_STRUCTUREDCLASSIFIERSFACTORYIMPL_HPP */
