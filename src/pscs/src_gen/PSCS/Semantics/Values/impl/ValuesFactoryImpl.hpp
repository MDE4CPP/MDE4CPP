//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_VALUESFACTORYIMPL_HPP
#define PSCS_SEMANTICS_VALUESFACTORYIMPL_HPP

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/impl/EFactoryImpl.hpp"

#include "PSCS/Semantics/Values/ValuesFactory.hpp"

namespace Values 
{	class CS_OpaqueExpressionEvaluation;
}

namespace PSCS::Semantics::Values 
{
	class PSCS_API ValuesFactoryImpl : virtual public ecore::EFactoryImpl , virtual public ValuesFactory 
	{
		private:    
			ValuesFactoryImpl(ValuesFactoryImpl const&) = delete;
			ValuesFactoryImpl& operator=(ValuesFactoryImpl const&) = delete;

		protected:
			friend class ValuesFactory;
			// Constructor
			ValuesFactoryImpl();

		public:
			virtual ~ValuesFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 virtual std::shared_ptr<PSCS::Semantics::Values::CS_OpaqueExpressionEvaluation> createCS_OpaqueExpressionEvaluation(const int metaElementID = ValuesPackage::CS_OPAQUEEXPRESSIONEVALUATION_CLASS) const ;
			 

		private:
			static ValuesFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_VALUESFACTORYIMPL_HPP */
